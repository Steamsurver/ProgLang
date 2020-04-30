#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <conio.h>
#include <fstream>
using namespace std;
int conversion(char* word, int lenght, int train);

int main()
{
	setlocale(LC_ALL, "");
	cout << "1-ое вариантное задание";
			int lenght, i, max = 0, min = 0, memb, train = 0; //train для передачи значения в функ.
			float sum = 0; //сумматор
			char* word = new char[255];
			cout << "\nВведите строку(для плавающей точки использовать '.') - ";
			cin.getline(word, 255);
			lenght = strlen(word);
			cout << "Длина строки - " << lenght << endl;
			i = 0;
			while (word[i] != '.') //считываем размер с левой стороны(до точки)
			{
				if (isdigit(word[i]))
					max++;
				i++;
			}
			i = max + 1;
			while (word[i] != isalpha(word[i]))//размер после точки
			{
				if (isdigit(word[i]))
					min++;
				i++;
			}
			memb = max;
			for (i = 0; i < max; i++)//переводим в целые числа
			{
				sum += conversion(word, lenght, train) * pow(10, memb - 1);
				train++;
				memb--;
			}
			cout.precision(max + min + 1);
			train++;
			for (i = 0; i < min; i++)//переводим в числа после запятой
			{
				sum += conversion(word, lenght, train) * pow(10, (i + 1) * -1);
				train++;
			}

			cout << "Число - " << sum << endl;
	system("pause");
	return 0;
}

int conversion(char* word, int lenght, int train) //функция для перевода из строки(1-ое задание)
{
	if (word[train] == '1')
		return 1;
	if (word[train] == '2')
		return 2;
	if (word[train] == '3')
		return 3;
	if (word[train] == '4')
		return 4;
	if (word[train] == '5')
		return 5;
	if (word[train] == '6')
		return 6;
	if (word[train] == '7')
		return 7;
	if (word[train] == '8')
		return 8;
	if (word[train] == '9')
		return 9;
	if (word[train] == '0')
		return 0;
}

