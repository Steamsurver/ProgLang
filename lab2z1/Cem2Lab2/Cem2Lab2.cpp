#include <iostream>
#include "time.h"
#include <windows.h>
using namespace std;
void output(int x, int x1, int** field, int i);
void born(int x, int x1, int** field, int** field1, int i);
void alondeath(int x, int x1, int** field, int** field1, int i);
int main()
{
	setlocale(LC_ALL, "");
	srand(static_cast<unsigned int>(time(0)));
	int x, x1, i;
	int burth;
	cout << "Введите кол-во покалений - "; cin >> burth;
	int** field;
	int** field1;
	cout << "Введите размер массива х на х \n";
	cin >> x; cout << " на "; cin >> x1;
	field = new int* [x];
	for (i = 0; i < x; i++)
		field[i] = new int[x1];
	field1 = new int* [x];
	for (i = 0; i < x; i++)
		field1[i] = new int[x1];


	born(x, x1, field, field1, i);

	for (int y = 0; y < burth; y++)
	{
		alondeath(x, x1, field, field1, i);
		output(x, x1, field, i);
		Sleep(200);
		system("cls");
	}
	output(x, x1, field, i);

}

void output(int x, int x1, int** field, int i) //вывод массива
{
	for (i = 0; i < x; i++)
	{
		for (int j = 0; j < x1; j++)
		{
			cout.width(2);
			if (field[i][j] == 1)
				cout << field[i][j];
			if (field[i][j] == 0)
				cout << field[i][j];
			if (j == (x1 - 1))
				cout << endl;
		}
	}
}
void born(int x, int x1, int** field, int** field1, int i) //создание первого покаления
{
	for (i = 0; i < x; i++)
	{
		for (int j = 0; j < x1; j++)
		{
			if (j == 0 || i == 0 || i == x - 1 || j == x1 - 1)
			{
				field[i][j] = 3;
				field1[i][j] = 3;
			}
			else
			{
				field[i][j] = rand() % 2;
				field1[i][j] = rand() % 2;
			}
			cout.width(2);
			if (field[i][j] == 1)
				cout << field[i][j];
			if (field[i][j] == 0)
				cout << field[i][j];
			if (j == (x1 - 1))
				cout << endl; //переход на сл строку
		}
	}

}

void alondeath(int x, int x1, int** field, int** field1, int i)
{
	int sum = 0;
	for (i = 1; i < x - 1; i++)
	{
		for (int j = 1; j < x1 - 1; j++)
		{
			sum = 0;
			if (field[i - 1][j - 1] == 1) //1
				sum++;
			if (field[i - 1][j] == 1)
				sum++;
			if (field[i - 1][j + 1] == 1)
				sum++;
			if (field[i][j - 1] == 1)
				sum++;
			if (field[i][j + 1] == 1)
				sum++;
			if (field[i + 1][j - 1] == 1)
				sum++;
			if (field[i + 1][j] == 1)
				sum++;
			if (field[i + 1][j + 1] == 1) //8
				sum++;
			if (sum < 2 && field[i][j] == 1) //одинокая смерть
			{
				field1[i][j] = 0;

			}
			if ((sum == 2 || sum == 3) && field[i][j] == 1) //выживание
			{
				field1[i][j] = 1;

			}
			if (sum > 3 && field[i][j] == 1)
			{
				field1[i][j] = 0; //перенаселение

			}
			if (sum == 3 && field[i][j] == 0)
			{
				field1[i][j] = 1;

			}
		}
	}
	for (i = 1; i < x - 1; i++)
	{
		for (int j = 1; j < x1 - 1; j++)
		{
			field[i][j] = field1[i][j];
		}
	}
}
