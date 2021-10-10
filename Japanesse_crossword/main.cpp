///для кроссвордов <= 40x40 и < 10 групп раскраски в строках и столбцах///
///1 - клетка закрашена, 0 - клетка пустa, -1 - неизвестная клетка
#include <iostream>
using namespace std;

void print(int nonogram[41][41], int n, int m);
bool color_the_picture(int string[11][41], int n, int column[41][11], int m, int nonogram[41][41], int k);
int number_of_ways(int i, int string[11][41], int n);
void put_i_way(int i, int string[11][41], int n, int nonogram[41][41]);
void delete_i_way(int ii, int nonogram[41][41], int m);
bool checking_by_columns(int i, int column[41][11], int m, int string[11][41], int n);


void printnonogram(int string[11][41], int n, int column[41][11], int m, int nonogram[41][41])
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

bool color_the_picture(int string[11][41], int n, int column[41][11], int m, int nonogram[41][41], int k)
{
    if(k == 0)
    {
        return true;
    }
    for(int i = 1; i <= number_of_ways(n - k, string, n); i++)
    {
        put_i_way(i, string, n, nonogram);
        if(checking_by_columns(i, column, m, string, n))
        {
            color_the_picture(string, n, column, m, nonogram, k - 1);
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
int number_of_ways(int i, int string[11][41], int n)
{
    int ans = 0;
    return ans;
}

//вставляет в нонограму расстановук по номеру i
void put_i_way(int i, int string[11][41], int n, int nonogram[41][41])
{

}

//убирает расстановку из монограмы по номеру строки
void delete_i_way(int ii, int nonogram[41][41], int m)
{
    for(int i = 0; i < m; i++)
    {
        nonogram[ii][i] = -1;
    }
}

//проверят строчную расстановку на соответсвие столбикам
bool checking_by_columns(int i, int column[41][11], int m, int string[11][41], int n)
{
    return true;
}

int main()
{
    int n = 0;
    cin >> n;//вводится число строк
    int string[11][41]{-1}; ///хранит описание строк
    for(int i = 0; i < n; i++)
    {
      int a = 0;//вводится число групп в строке
      cin >> a; ///можно хранить, но нужно ли оно?
      for(int j = 0; j < a; j++)
      {
        cin >> string[i][j]; //длины груп
      }
    }
    int column[41][11]{-1}; ///хранит описание столбцов
    //число столбцов, число групп, пробел, длины групп
    int m = 0;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int a = 0;
        cin >> a;
        for(int j = 0; j < a; j++)
        {
            cin >> column[i][j];
        }
    }
    int nonogram[41][41]{-1};
    printnonogram(string, n, column, m, nonogram);
    return EXIT_SUCCESS;
}
