#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <conio.h>
#include <fstream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int sum = 0;
	cout << "2-ое вариантное задание\n";
	int i = 0, n = 255;
	unsigned int choice;
			char* word = new char[n];
			char seps[] = " .";
			char* tword;
			ifstream  fin("file.txt");
			if (!fin)
			{
				cout << "ошибка открытия файла" << endl;
				return 1;
			}
			cout << "Введите строку, с которой будете работать - "; cin >> choice;
				while (i != choice)
				{
					fin.getline(word, n);
					i++;
				}
				cout << word << endl;
				tword = strtok(word, seps);
				while (tword != NULL)
				{
					cout << tword << endl;
					tword = strtok(NULL, seps);
					sum++;
				}
				cout << "\n Кол-во слов - " << sum << endl;
			
	system("pause");
	return 0;
}



