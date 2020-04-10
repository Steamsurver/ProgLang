#include <iostream>
#include "time.h"
using namespace std;
void filling(int n, int i, int m, int** arch);
void comparison(int n, int i, int m, int** arch);

int main()
{
	setlocale(LC_ALL, "");
	srand(static_cast<unsigned int>(time(0)));
	int n, m, i, j;
	cout << "Введите кол-во стрелков - "; cin >> n;
	cout << "Введите кол-во выстрелов - "; cin >> m;
	int** arch;
	arch = new int* [n];
	for (i = 0; i < n; i++)
		arch[i] = new int[m + 1];
	filling(n, i, m, arch);
	comparison(n, i, m, arch);
	system("pause");
	return 0;
}

void filling(int n, int i, int m, int** arch) //заполнение
{
	int j;
	for (i = 0; i < n; i++)
	{
		cout.width(2);
		cout << i + 1 << "-ый стрелок  ";
		for (j = 0; j < m; j++)
		{
			cout.width(5);
			arch[i][j] = rand() % 11;
			cout << arch[i][j] << " ";
		}
		cout << endl;
	}
}

void comparison(int n, int i, int m, int** arch)
{
	int j, sum;
	for (i = 0; i < n; i++)
	{
		sum = 0;
		for (j = 0; j < m + 1; j++)
		{
			if (j == m)
				arch[i][m] = sum;
			else sum += arch[i][j];
		}
		
	}
	sum = 0;
	for (i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			for (j = 0; j < n - 1; j++)
			{
				if (arch[j][m] > sum)
					sum = arch[j][m];
			}
		}
		if (i == 1)
		{
			for (j = 0; j < n - 1; j++)
			{
				if (arch[j][m] == sum)
					cout << "Победитель - " << j + 1 << "-й игрок\n";
			}
		}
	}
}


