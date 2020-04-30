#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	bool exit = 1;
	char* word = new char[255];
	int i = 0, sum = 0;
	cout << "Введите слово(ОБЯЗАТЕЛЬНО закончить его '.','!' или '?') - ";
	cin.getline(word, 255);
		i = 0;
	while ((word[i] != '.') && (word[i] != '!') && (word[i] != '?'))
	{
		cout << "- " << word[i] << endl;
		i++;
		sum++;
	}
	
	cout << "Кол-во символов в строке - " << sum<<endl;
	system("pause");
	return 0;
}

