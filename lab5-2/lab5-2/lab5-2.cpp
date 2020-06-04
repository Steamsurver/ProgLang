
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <cctype>


using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	char exit[50]; //для поиска конца файла
	int n=0, i;
	ifstream fin("count.txt");
	
	struct Guitars
	{
		char type[10]; //тип гитары
		int cost;//стоимость гитары
		int frets;//лады
		char firm[10]; //фирма
	};
	while (exit[0] != '!')//узнаем кол-во автобусов в файле
	{
		n++;
		fin.getline(exit, 50);
	}
	n--;

	Guitars* str_guitar = new Guitars[n]; //создаем динам. массив
	fin.seekg(0, ios_base::beg);//возвращаемся в начало файла
	for (i = 0; i < n; i++)
	{
		fin >> str_guitar[i].cost;
		fin >> str_guitar[i].frets;
		fin.getline(str_guitar[i].type, 8, ' ');
		fin.getline(str_guitar[i].firm, 10, ' ');
		
		cout << "Тип гитары: " << str_guitar[i].type << "   ";
		cout << "Фирма: " << str_guitar[i].firm << "   ";
		cout << "Стоимость: " << str_guitar[i].cost << "       ";
		cout << "Кол-во ладов: " << str_guitar[i].frets << endl;
	}
	system("pause");
	return 0;
}