#include <iostream>
using namespace std;
int funk(int n);
int main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введитек число n которое выведем в обратном порядке - "; cin >> n;
	funk(n);
	

	system("pause");
	return 0;
}

int funk(int n)
{
	if (n > 10)
	{
		cout << n % 10;
		n = n / 10;
		return funk(n);
	}
	if (n < 10)
	{
		cout << n << endl;
		return 1;
	}
}