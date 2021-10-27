#include <iostream>
#include <math.h>
//считает кол-во перестановок групп
using namespace std;

int main()
{
	int sum = 0;
	int n = 3; //кол-во групп раскраски
	int k = 20; //количество клеток нонограмы
	int str[4] = {8, 4, 4}; //массив из групп раскраски
	for(int i = 0; i < n; i++)
	{
		sum += str[i];
		if(i != n - 1)
		{
			sum += 1;
		}
	}
	cout <<"sum = " << sum << endl;
	cout << "empty = " << k - sum << endl;
	if(sum > k)
	{
		cout << 0;
		//return 0;
	}
	else if(sum == k)
	{
		cout << 1;
		//return 1;
	}
	else
	{
		int ans = 0;
		int s = (k - sum) * pow(n , n - 1); //нижнее число в таблице переборов нулей по системе счисления
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
			cout << "i = " << i << endl;
			cout << "tmp = " << tmp << endl << endl;
			if(tmp < n)
			{
				ans++;
			}
		}
		cout << "ans = " << ans;
		//return ans;
	}
	system("pause>nul");
	return 0;
}
