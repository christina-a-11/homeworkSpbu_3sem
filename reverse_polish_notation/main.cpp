#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int f(int a, int b, char x)
{
	switch (x)
	{
	case '+':
		return a + b;
	case '-':
		return b - a;
	case '/':
		return b / a;
	case '*':
		return a * b;
	}
}
int f2()
{
	stack <int> arr;
	char x = '0';
	while (cin >> x)
	{
		if (isdigit(x))
		{
			cin.putback(x);
			int n = 0;
			cin >> n;
			arr.push(n);
		}
		else
		{
			int a = 0;
			int b = 0;
			a = arr.top();
			arr.pop();
			b = arr.top();
			arr.pop();
			arr.push(f(a, b, x));
		}
	}
	return arr.top();
}
void print(vector<char> a)
{
	for (auto x : a)
	{
		cout << x << " ";
	}
}

void f1()
{
	stack <char> arr;
	vector <char> ans;
	char x;
	while (cin >> x)
	{
		if (isdigit(x))
		{
			cout << x << " ";
			//ans.push_back(x);
		}
		else
		{
			if (x == '(')
			{
				arr.push(x);
			}
			else if (x == ')')
			{
				while (arr.top() != '(')
				{
					cout << arr.top() << " ";
					//ans.push_back(arr.top());
					arr.pop();
				}
				arr.pop();
			}
			else
			{
				if (!arr.empty())
				{
					if (arr.top() != '(')
					{
						if (x == '+' || x == '-')
						{
							while (arr.size() > 0)
							{
								cout << arr.top() << " ";
								//ans.push_back(arr.top());
								arr.pop();
							}
						}
						else if (x == '*' || x == '/')
						{
							while (arr.top() == '*' || arr.top() == '/')
							{
								cout << arr.top() << " ";
								//ans.push_back(arr.top());
								arr.pop();
							}
						}
					}
				}
				arr.push(x);
			}
		}
	}
	while (!arr.empty())
	{
		cout << arr.top();
		//ans.push_back(arr.top());
		arr.pop();
	}
	print(ans);
}
int main()
{
	//cout << f2();
	f1();
	system("pause>nul");
	return 0;
}
