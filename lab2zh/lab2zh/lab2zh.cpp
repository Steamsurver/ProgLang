#include <iostream>
#include"time.h"
using namespace std;
void show(char** field);
void bot(char** field);
void check_player(char** field);
void win(char** a);
int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	int it, i, j;
	int hard = 3;
	char** field;
	field = new char* [hard];
	for (i = 0; i < hard; i++)
		field[i] = new char[hard];
	cout.width(3);
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			field[i][j] = '-';
		}
	}
	for (it= 1; it < 10; it++)
	{
		check_player(field);
		show(field);
	    bot(field);
		show(field);
		win(field);
	}
	system("pause");
	return 0;
}

void show(char** field) //вывод массива
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << field[i][j];
		}
		cout << endl;
	}
}

void bot(char** field) //ход бота
{
	cout << "Ход компьютера\n";
	int x1, x2, check = 1;
	x1 = rand() % 3;
	x2 = rand() % 3;
	while (check != 0)
	{
		if (field[x1][x2] == 'O' || field[x1][x2] == 'X')
		{
			x1 = rand() % 3;
			x2 = rand() % 3;
		}
		else
		 check = 0;
	}
	field[x1][x2] = 'O';
}

void check_player(char** field)//ход игрока
{
	int i, j;
	int check = 1;
	cout << "Введите координаты клетки от 1 до 3\n";
	cout << "i - "; cin >> i; cout << "j - "; cin >> j;
	while (i > 3 || 1 > i || j > 3 || 1 > j)
	{
		cout << "Введите координаты клетки от 1 до 3 не иначе\n";
		cout << "i - "; cin >> i; cout << "j - "; cin >> j;
	}
	while (check != 0)
	{
		if (field[i - 1][j - 1] == 'O' || field[i - 1][j - 1] == 'X')
		{
			cout << "Нельзя отметить те клетки, которые уже были отмечены\n";
			cout << "Введите координаты клетки от 1 до 3 не иначе\n";
			cout << "i - "; cin >> i; cout << "j - "; cin >> j;
		}
		else check = 0;
	}
	field[i - 1][j - 1] = 'X';
}

void win(char** a)
{
	int sum = 0;
	while (sum != 9)
	{
		if ((a[sum][0] == 'X' && a[sum][1] == 'X' && a[sum][2] == 'X') ||
			(a[0][sum] == 'X' && a[1][sum] == 'X' && a[2][sum] == 'X') ||
			(a[0][0] == 'X' && a[1][1] == 'X' && a[2][2] == 'X') ||
			(a[0][2] == 'X' && a[1][1] == 'X' && a[2][0] == 'X'))
		{
			cout << "Ты победил!";
			sum = 9;
			exit(0);
		}
		else
		{
			if (sum != 2)
				sum++;
			else
				sum = 9;
		}
		
	}
	sum = 0;
	while (sum != 9)
	{
		if ((a[sum][0] == 'O' && a[sum][1] == 'O' && a[sum][2] == 'O') ||
			(a[0][sum] == 'O' && a[1][sum] == 'O' && a[2][sum] == 'O') ||
			(a[0][0] == 'O' && a[1][1] == 'O' && a[2][2] == 'O') ||
			(a[0][2] == 'O' && a[1][1] == 'O' && a[2][0] == 'O'))
		{
			cout << "Победил комп !";
			sum = 9;
			exit(0);
		}
		else
		{
			if (sum != 2)
				sum++;
			else
				sum = 9;
		}

	}
}