#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
int main()
{
	int i = 0;//для 1-го условия
	setlocale(LC_ALL, "");
	char button;
	ifstream inf;
	cout << "1 - для 1-го условия\n";
	cout << "2 - для 2-го условия\n";
	cout << "0 - выход\n";
	button = _getche();
	while (button != '0')
	{
		switch (button)
		{
		case '1'://1-ое условие
		{
			inf.open("file.txt");
			if (inf.is_open())
			{
				int integ;
				cout << "\nВсе норм\n";
				while (!inf.eof()) //*.get - возвращает true пока есть символы, .eof - true - когда достигает конца файла
				{
					inf >> integ;
					if (integ < 0)
					{
						i++;	//выясняем размер массива
					}
				}
			}
			else
			{
				cout << "\nВсе не норм(\n";
			}
			inf.close();

			inf.open("file.txt", ofstream::app);
			int* mass = new int[i];
			int integ;
			int sum = 0;

			while (!inf.eof()) //заполняем массив
			{
				inf >> integ;
				if (integ < 0)
				{
					mass[sum] = integ;
					sum++;
				}
				integ = 0;
			}

			inf.close();

			int step = i / 2;
			while (step > 0)
			{
				for (int f = 0; f < (i - step); f++) //сортируем по Шеллу
				{
					int j = f;
					while (j >= 0 && mass[j] > mass[j + step])
					{
						int temp = mass[j];
						mass[j] = mass[j + step];
						mass[j + step] = temp;
						j--;
					}
				}
				step = step / 2;
			}
			for (int f = 0; f < i; f++)
			{
				cout << mass[f] << endl;
			}
			i = 0;
			delete[] mass;
		}
		break;


		case'2': //2-ое условие
		{
			int n, a, b, k, member = 0;
			cout << "\nКакого размера должен быть массив?\n";
			cin >> n;
			cout << "введите левую границу интервала [a,b]\n";
			cin >> a;
			cout << "введите правую границу интервала [a,b]\n";
			cin >> b;
			while (b < a && b == a)
			{
				cout << "правая граница не может быть меньше или равна левой\nвведите правую границу интервала [a,b]\n";
				cin >> b;
			}
			cout << "Введите число k\n";
			cin >> k;
			srand(time(NULL));
			int* mass = new int[n];
			for (int f = 0; f < n; f++)
			{

				mass[f] = rand() % (b - a) + a + 1;//создание первого массива
				cout << mass[f] << endl;
				if (mass[f] % 2 != 0)
				{
					member++;
				}
			}
			member += n;

			int* mass2 = new int[member];
			int mass_rem = 0;

			cout << "------------------------------\n";
			int it = 0;
			for (it = 0; it < member; it++) //преобразование второго массива
			{
				mass2[it] = mass[mass_rem];
				if (mass2[it] % 2 != 0)
				{
					mass2[it] = k;
					mass2[it + 1] = mass[mass_rem];
					it++;
				}
				mass_rem++;
			}
			cout << " meber is = " << member << endl;
			for (it = 0; it < member; it++)
			{
				cout << it << " - - - " << mass2[it] << endl;
			}
			delete[] mass;
			delete[] mass2;
		}
		break;
		}
		cout << "1 - для 1-го условия\n";
		cout << "2 - для 2-го условия\n";
		cout << "0 - выход\n";
		button = _getche();
	}
	system("pause");
	return 0;
}


