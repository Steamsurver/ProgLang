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
	int i = 0, n = 255,sent = 0;
	int word_weight = 0;
	unsigned int choice;
	char* word = new char[n];
	char seps[] = " .,:!?";
	char* tword;
	ifstream  fin("file.txt");
	if (!fin)
	{
		cout << "ошибка открытия файла" << endl;
		return 1;
	}
	cout << "Сколько строк проверить в файле? - "; cin >> choice;
	while (i != choice)
	{
		fin.getline(word, n);
		i++;
		cout << word << endl;
		word_weight = strlen(word);
		for (int it = 0; it < word_weight; it++)
		{
			if (word[it] == '.' || word[it] == '!' || word[it] == '?')
				sent++;
		}
		tword = strtok(word, seps);
		while (tword != NULL)
		{
			cout << tword << endl;
			tword = strtok(NULL, seps);
			sum++;
		}
		cout << "\n Кол-во слов - " << sum << endl;
	}
	cout << "\n Кол-во предложений " << sent << endl;
	system("pause");
	return 0;
}



