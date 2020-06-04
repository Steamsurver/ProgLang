#include <iostream>
using namespace std;

int F(int n, int i, int value);

int main()
{
	setlocale(LC_ALL, "");
	int value = 0, n;
	int i = 1;
	cout << "Введите число n - ";
	cin >> n;
	F(n, i, value);

	system("pause");
	return 0;
}
int F(int n, int i, int value)
{
	if (i == 1)
	{
		value = 3;
		i++;
		cout << value << endl;
		return F(n, i, value);
	}
	if (i <= n)
	{
		value = value * (i - 1);
		i++;
		cout << value << endl;
		return F(n, i, value);
	}
	else
		return value;
}

