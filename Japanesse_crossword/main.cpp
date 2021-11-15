#include <iostream>
using namespace std;

//убирает расстановку из нонограммы по номеру строки
void delete_i_way_string(int ii, int nonogram[41][41], int n)
{
    for(int i = 0; i < n; i++)
    {
        nonogram[ii][i] = 0;
    }
}
void delete_i_way_column(int ii, int nonogram[41][41], int n)
{
    for(int i = 0; i < n; i++)
    {
        nonogram[i][ii] = 0;
    }
}

//подсчет кол-ва возможных перестановок дощечек
int count_ways(int ii, int string[41][11], int n)
{
	//считает кол-во расстановок групп перестановок в строке или столбце
	//учитывает, что в строке или столбце могут попадаться закрашеные клетки
    return 0;
}
int count_ways(int ii, int column[11][41], int m)
{
	//считает кол-во расстановок групп перестановок в строке или столбце
	//учитывает, что в строке или столбце могут попадаться закрашеные клетки
    return 0;
}

//вставка i расстановки в нонограмму
void put_i_way(int ii, int string[41][11], int nn, int nonogram[41][41])
{

}
void put_i_way(int ii, int column[11][41], int mm, int nonogram[41][41])
{

}

bool color_picture(int string[41][11], int n, int column[11][41], int m, int nonogram[41][41])
{
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += string[i][1];
    }
    for(int i = 1; i <= m; i++)
    {
        sum += column[1][i];
    }
    if(sum == 0) return true; //база

    int min = count_ways(0, string, n);
    bool f = true; //знать, со строкой или столбцом работаем
    for(int i = 1; i <= n; i++)
    {
        if(string[i][1] != 0)
        {
            if(count_ways(i, string, n) < min)
            min = count_ways(i, string, n);
        }
    }
    for(int i = 1; i <= m; i++)
    {
        if(column[1][i] != 0)
        {
            if(count_ways(i, column, m) < min)
            {
                min = count_ways(i, column, m);
                f = false;
            }
        }
    }
    for(int i = 0; i < min; i++)
    {
        if(f)
        {
            put_i_way(i, string, n, nonogram);
            if(color_picture(string, n, column, m, nonogram))
            return true;
            delete_i_way_string(i, nonogram, n);
        }
        else if(!f)
        {
            put_i_way(i, column, m, nonogram);
            if(color_picture(string, n, column, m, nonogram))
            return true;
            delete_i_way_column(i, nonogram, n);
        }
    }
	return false;
}
void printnonogram(int string[41][11], int n, int column[11][41], int m, int nonogram[41][41])
{
    if(color_picture(string, n, column, m, nonogram))
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
    else
    {
        cout << "impossible\n";
    }
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
      string[i][1] = 0;//пометка о незакрашенности
      for(int j = 2; j <= a + 1; j++)
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
        column[1][i] = 0; //пометка о незакрашенности
        for(int j = 2; j <= a + 1; j++)
        {
            cin >> column[j][i];
        }
    }
    int nonogram[41][41]{-1};
    printnonogram(string, n, column, m, nonogram);
    return EXIT_SUCCESS;
}