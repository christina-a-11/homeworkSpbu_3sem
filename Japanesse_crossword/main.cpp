///для кроссвордов <= 40x40 и <= 10 групп раскраски в строках и столбцах///
///1 - клетка закрашена, 0 - клетка пустa, -1 - неизвестная клетка
#include <iostream>
#include <math.h>
using namespace std;

void print(int nonogram[41][41], int n, int m); //печать нонoграграмы
bool color_the_picture(int string[41][11], int n, int column[11][41], int m, int nonogram[41][41], int k); //раскраска 
int number_of_ways(int ii, int string[41][11], int n); 
void put_i_way(int ii, int string[41][11], int count, int n, int nonogram[41][41]);
void delete_i_way(int ii, int nonogram[41][41], int m);
bool checking_by_columns(int i, int column[11][41], int m, int string[41][11], int n);

//печатать, если данные корректны
void printnonogram(int string[41][11], int n, int column[11][41], int m, int nonogram[41][41])
{
    if(color_the_picture(string, n, column, m, nonogram, n))
    {
        print(nonogram, n, m);
    }
    else
    {
        cout << "impossible\n";
    }
}

void print(int nonogram[41][41], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << nonogram[i][j] << " ";
        }
        cout << '\n';
    }
}

//убирает расстановку из монограмы по номеру строки
void delete_i_way(int ii, int nonogram[41][41], int m)
{
    for(int i = 0; i < m; i++)
    {
        nonogram[ii][i] = -1;
    }
}

bool color_the_picture(int string[41][11], int n, int column[11][41], int m, int nonogram[41][41], int k)
{
    //к - количество незакрашеных строк
    if(k == 0)
    {
        return true;
    }
    for(int i = 1; i <= number_of_ways(n - k, string, n); i++)
    {
        put_i_way(i, string, n - k, n, nonogram);
        if(checking_by_columns(i, column, m, string, n))
        {
            return color_the_picture(string, n, column, m, nonogram, k - 1);
        }
        else
        {
            delete_i_way(i, nonogram, m);
            continue;
        }
    }
    return false;
}

//считает кол-во перестановок групп
int number_of_ways(int ii, int string[41][11], int nn)
{
    int sum = 0;
	int n = string[ii][0]; //кол-во групп раскраски
	for(int i = 0; i < n; i++)
	{
		sum += string[ii][i];
		if(i != n - 1)
		{
			sum += 1;
		}
	}
	if(sum > nn)
	{
        return 0;
	}
	else if(sum == nn)
	{
        return 1;
	}
	else
	{
		int ans = 0;
		int s = (nn - sum) * (pow(n , n - 1)); //нижнее число в таблице переборов нулей по системе счисления
		cout << "s = " << s << endl;
		for(int i = 0; i <= s; i++)
		{
			int tmp = 0;
			int t = i;
			for(int j = 0; j < n; j++)
			{
				tmp += t % n;
				t = t / n;
				cout << "t = " << t << endl;
			}
			if(tmp < n)
			{
				ans++;
			}
		}
		return ans;
	}
}

//вставляет в нонограму расстановку по номеру i
void put_i_way(int ii, int string[41][11], int count, int nn, int nonogram[41][41])
{
	int sum = 0;
    int n = string[ii][0]; //кол-во групп раскраски
    for(int i = 1; i <= n; i++)
	{
		    sum += string[ii][i];
		    if(i != n - 1)
		    {
			    sum += 1;
		    }
	}
	int c = 0;
	int s = (nn - sum) * (pow(n , n - 1)); //нижнее число в таблице переборов нулей по системе счисления
	for(int i = 0; i <= s; i++)
	{
		int tmp = 0;
		int t = i;
		for(int j = 0; j < n; j++)
		{
			tmp += t % n;
			t = t / n;
		}
		if(tmp < n)
		{
			c++;
		}
		if(c == count) // начинаем раскраску строки
		{
		     tmp = 0;
		     t = i;
		     int index = nn - 1;
		     for(int l = n; l > 0; l--) //цикл по элементам групп раскраски
		     {
		        tmp = t % n;
		        t = t / n;
		        if(l != n)
		        {
		            for(int m = 0; m <= tmp; m++)
		            {
		                nonogram[ii][index] = 0;
		                index--;
		            }
		          }
		        else
		        {
		            for(int m = 0; m < tmp; m++)
		            {
		                nonogram[ii][index] = 0;
		                index--;
		            }
		        }
		        for(int m = 0; m < string[ii][l]; m++)
		        {
		            nonogram[ii][index] = 1;
		            index--;
		        }
		    }
		}
		if(c == count)
		{
		    break;
		}
	}
	//получили раскраску в обратном порядке, теперь делаем в прямом
	while(nonogram[0][0] == -1)
	{
	    for(int i = 0; i < nn - 1; i++)
	    {
	        nonogram[ii][i] = nonogram[ii][i + 1];
	    }
	    nonogram[ii][nn - 1] = 0;
	}
}

//проверят строчную расстановку на соответсвие столбикам
bool checking_by_columns(int i, int column[11][41], int m, int string[41][11], int n)
{
    return true;
}

int main()
{
    int n = 0;
    cin >> n;//вводится число строк
    int string[41][11]{-1}; ///хранит описание строк
    for(int i = 0; i < n; i++)
    {
      int a = 0;//вводится число групп в строке
      cin >> a; //храню, пригодится
      string[i][0] = a;
      for(int j = 1; j <= a; j++)
      {
        cin >> string[i][j]; //длины груп
      }
    }
    int column[11][41]{-1}; ///хранит описание столбцов
    //число столбцов, число групп, пробел, длины групп
    int m = 0;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int a = 0;
        cin >> a;
        column[0][i] = a;
        for(int j = 1; j < a; j++)
        {
            cin >> column[j][i];
        }
    }
    int nonogram[41][41]{-1};
    printnonogram(string, n, column, m, nonogram);
    return EXIT_SUCCESS;
}