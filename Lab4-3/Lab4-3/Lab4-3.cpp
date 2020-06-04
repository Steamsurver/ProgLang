#include <iostream>

using namespace std;
int i = 0;
int power(int n, int sum);
int main()
{
	setlocale(LC_ALL, "");
	int n, sum = 0;
	cout << "Введите любое натуральное число - ";
	cin >> n;
	if (power(n, sum) == 1)
		cout << "YES\n";
	else
		cout << "NO\n";

	system("pause");
	return 0;
}

int power(int n, int sum)
{
	
	if (n % 2 == 0)
	{
		n /= 2;
		sum++;
		return power(n, sum);
	}
	if (n == 1)
	{
		cout << "Это число - " << sum << "-я степень 2-ки\n";
		return 1;
	}
	else
		return 0;
		
}