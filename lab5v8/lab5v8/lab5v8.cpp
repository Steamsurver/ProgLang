
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <cctype>


using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	
	ifstream fin("count.txt");
	int n = 0, i = 0, j = 0;
	char exit[50];
	char name_check[10]; // запрашиваемая фамилия
	int name_len; //размер запрашиваемой фамилии
	struct bus
	{
		int number; //номер автобуса
		int number_route; //номер маршрута
		int distance;//продолжительность маршрута
		char FIO[50];//ФИО
	};
	while (exit[0] != '!')//узнаем кол-во автобусов в файле
	{
		n++;
		fin.getline(exit, 50);
	}
	n--;
	cout << "n = " << n<<endl;
	bus* arr_bus = new bus[n]; //создаем динам. массив на основе данных по кол-ву автобусов
	fin.seekg(0, ios_base::beg);//возвращаемся в начало файла
	for (i = 0; i < n; i++)
	{
		fin >> arr_bus[i].number;
		fin >> arr_bus[i].number_route;
		fin >> arr_bus[i].distance;
		fin.getline(arr_bus[i].FIO, 50);
		cout <<"Номер автобуса: "<<arr_bus[i].number<<"   ";
		cout <<"Номер маршрута: "<<arr_bus[i].number_route<<"   ";
		cout <<"ФИО: "<<arr_bus[i].FIO<<"       ";
		cout <<"Дистанция маршрута в минутах: "<<arr_bus[i].distance << endl;
	}

	cout << "\nВведите фамилию водителя чтобы знать на каком маршруте он не работает: "; 
	int memb_route = 0; //маршрут, который нам нужно запомнить
	fgets(name_check, 10, stdin);
	cout << name_check;
	name_len = strlen(name_check);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < name_len-1; j++)
		{
			if (name_check[j] != arr_bus[i].FIO[j])
			{
				cout << "\nВодитель " << name_check << " не работает на маршруте - " << arr_bus[i].number_route<<endl;
				break;
			}
		}
	}
	for (i = 65; i < 91; i++)//перебор по всем заглавным латинским буквам
	{
		for (j = 0; j < n; j++)
		{
			if ((arr_bus[j].FIO[0] == i) && (arr_bus[j].distance < 120))//расстановка в алфавитном порядке с использованием ascii кодов
			{
				cout << "Номер автобуса: " << arr_bus[j].number << "   ";
				cout << "Номер маршрута: " << arr_bus[j].number_route << "   ";
				cout << "ФИО: " << arr_bus[j].FIO << "       ";
				cout << "Дистанция маршрута в минутах: " << arr_bus[j].distance << endl;
			}
		}
	}
	system("pause");
	return 0;
}

