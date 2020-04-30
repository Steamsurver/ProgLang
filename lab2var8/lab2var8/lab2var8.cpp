#include <iostream>
#include "time.h"
#include <iomanip>
using namespace std;
int green(int i, int j, int size, int** mass, int& coord1, int& coord2);
int red(int i, int j, int size, int** mass, int& coord3, int& coord4);
void output(int i, int j, int size, int** mass);

int main()
{
	setlocale(LC_ALL, "");
	srand(static_cast<unsigned int>(time(0)));
	int a, b, size,i,j, coord1, coord2, coord3, coord4, eq1, eq2;
	cout << "Введите минимальный эл-т из интервала\n";
	cin >> a;
	cout << "Введите максимальный эл-т из интервала\n";
	cin >> b;
	cout << "Введите размер массива\n";
	cin >> size;
	int** mass;
	mass = new int*[size];
	for (i = 0; i < size; i++)
	{
		mass[i] = new int[size];
	}

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			cout.width(2);
			mass[i][j] = rand() % (b - a + 1) + a;
			cout <<mass[i][j];
		}
		cout << "\n";
	}
	cout << endl;
	system("cls");
    eq1 = green(i, j, size, mass, coord1, coord2);
	 eq2 = red(i, j, size, mass, coord3, coord4);
	 mass[coord1][coord2] = eq2;
	 mass[coord3][coord4] = eq1;
	output(i, j, size, mass);
	system("pause");
	return 0;
	
}

int green(int i, int j, int size, int** mass, int &coord1, int &coord2) //зеленая область
{
	int min = 0;
	for (i = 0; i < size; i++)
	{
		cout << setw(i*3);
		cout << "";
		for (j = i; j < size - i; j++)
		{
			cout.width(3);
			cout << mass[i][j];
			if (mass[i][j] < min)
			{
				min = mass[i][j];
				coord1 = i;
				coord2 = j;
			}
		}
		cout << endl;
	}
	cout << "Минимальный элемент - " << min<<endl;
	return min;
}

int red(int i, int j, int size, int** mass, int& coord3, int& coord4) //красная область
{
	int max = 0;

	for (i = size/2; i < size; i++)
	{
		cout << setw((size - i - 1)*3);
		cout << "";
		for (j = size-i-1; j < size - (size-i) + 1 ; j++)
		{
			
			cout.width(3);
			cout << mass[i][j];
			if (mass[i][j] > max)
			{
				max = mass[i][j];
				coord3 = i;
				coord4 = j;
			}
		}
		cout << endl;
	}
	cout <<"\n\n";
	cout << "Максимальный элемент - " << max << endl;
	return max;
}

void output(int i, int j, int size, int** mass)
{
	cout << "\n\n";
	for (i = 0; i < size; i++)
	{
		cout << setw(i * 3);
		cout << "";
		for (j = i; j < size - i; j++)
		{
			cout.width(3);
			cout << mass[i][j];
		}
		cout << endl;
	}

	for (i = size / 2; i < size; i++)
	{
		cout << setw((size - i - 1) * 3);
		cout << "";
		for (j = size - i - 1; j < size - (size - i) + 1; j++)
		{

			cout.width(3);
			cout << mass[i][j];
		}
		cout << endl;
	}
}