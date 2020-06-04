#include <iostream>
using namespace std;

int sumN(int i, int* mass, int n, int sum);
int main()
{
	setlocale(LC_ALL, "");
	int i, n, sum = 0;
	cout << "Введите размер массива - "; cin >> n;
	int* mass = new int[n];
	for (i = 0; i < n; i++)
	{
		mass[i] = rand() % 10;
		cout << i <<" - "<< mass[i] << endl;
	}
	i = 0;
	cout << "Сумма всех нечетных эл-ов - " << sumN(i, mass, n, sum) <<endl;

	system("pause");
	return 0;
}
int sumN(int i, int* mass, int n, int sum)
{
	if (i == n)
	{
		cout << sum<<endl;
		return sum;
	}
	if (mass[i] % 2 != 0)
	{
		
		sum += mass[i];
		i++;
		return sumN(i, mass, n, sum);
	}
	if (mass[i] % 2 == 0)
	{
		i++;
		return sumN(i, mass, n, sum);
	}
}