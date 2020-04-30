#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <conio.h>
#include <fstream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int sum = 0, sign, word_weight;
	cout << "2-ое вариантное задание\n";
	int i = 0,j=0, n = 255, alph_weight;//  alph_weight - размер алфавита
	unsigned int choice;//переменная для выбора строки
	char* word = new char[n];
	char* alp = new char[n]; //алфавит
	char seps[] = " .,!?";//символы исключения
	char* tword;
	ifstream  fin("file.txt");
	ifstream  alp_file("alph.txt");
	if (!fin || !alp_file)
	{
		cout << "ошибка открытия файла" << endl;
		return 1;
	}
	cout << "Введите строку, с которой будете работать(для 8-го варианта строка 3) - "; cin >> choice;
	while (i != choice)
	{
		fin.getline(word, n);
		i++;
	}
	fin.close();
	i = 0;
	word_weight = strlen(word); //нужен для передачи размера новому массиву
	char* final_word = new char[word_weight-4]; //новый массив
	alp_file.getline(alp, n);
	alph_weight = strlen(alp); //размер алфавита
	cout << word << endl;
	
	for (i = 0; i < alph_weight; i++)
	{
		tword = strtok(word, seps);

		while (tword != NULL)
		{
			tword[0] = tolower(tword[0]);
			if (tword[0] == alp[i])
			{
				sign = strlen(tword); //размер каждого выбранного слова
				sign += sum;
				int it = 0;
				for (int up = sum; up < sign; up++)//посимвольное призваивание
				{
				
					final_word[up] = tword[it];
					sum++;
					it++;
				}
				final_word[sign] = ' ';
				sum++;
			}
			tword = strtok(NULL, seps);
		}
		fin.open("file.txt"); //переносим указатель на начало строки
		while (j != choice)
		{
			fin.getline(word, n);
			j++;
		}
		j = 0;
		fin.close();
	}
	cout << "Алфавит";
	for (i = 0; i < alph_weight; i++)
		cout << " " << alp[i];
	int wf_weight;
	wf_weight = strlen(final_word);
	final_word[word_weight-1] = word[word_weight-1];//знак на конце
	final_word[0] = final_word[0]-32;//перевод в верхний регистр
	cout <<"\n Преобразованная строка - "<<final_word;
	cout << "\n Изначальная строка " <<word<<endl;

	system("pause");
	return 0;
}
