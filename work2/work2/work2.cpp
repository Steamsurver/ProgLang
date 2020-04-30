#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <ctime>
#include <fstream>
#include <conio.h>
using namespace std;
void func(char* word, int verb_weight, char* mass, int& sum);

int main()
{
	setlocale(LC_ALL, "");
	srand(static_cast<unsigned int>(time(0)));
	ifstream  file_word("word.txt");
	int n = 255,i = 0;
	int zero = 0;
	int& sum = zero;//передаем 0

	char* article= new char[n]; // артикли
	char* verb = new char[n]; // глаголы
	char* noun= new char[n]; // существительное
	char* pr= new char[n]; // предлоги
	char* word = new char[n]; //наше предложение
	int verb_weight = 0;
	file_word.getline(article, n);
	file_word.getline(verb, n);
	file_word.getline(noun, n);
	file_word.getline(pr, n);
	cout << "Сами массивы: \n";
	cout << "\narticle:" << article << "\nГлаголы: " << verb;
	cout << "\nСуществительное:" << noun << "\nПредлог:" << pr << "\n";
	func(word, verb_weight, article, sum);
	func(word, verb_weight, noun, sum);
	func(word, verb_weight, verb, sum);
	func(word, verb_weight, pr, sum);
	func(word, verb_weight, article, sum);
	func(word, verb_weight, noun, sum);
	word[0] = toupper(word[0]);
	word[sum] = '.';
	cout << "\n";
	while (word[i] != '.')
	{
		cout << word[i];
		i++;
	}
	cout << word[i]<<endl;
	system("pause");
	return 0;
}

void func(char* word, int verb_weight, char* mass, int& sum)
{
	int rand_numb;
	int f_void = 1;
	verb_weight = strlen(mass);
	rand_numb = rand() % verb_weight;//выбираем точку появления
	while (f_void != 0)
	{
		if (mass[rand_numb] == ';')//выбираем новую точку появления так как ;-конец файла
			rand_numb = rand() % verb_weight;
		if (mass[rand_numb] == ' ')//пробел - начало любого слова
		{
			rand_numb++;
			if (isalpha(mass[rand_numb]))
			{
				while (mass[rand_numb] != ' ')//пока не упремся в другой пробел
				{
					word[sum] = mass[rand_numb];
					rand_numb++;
					sum++;
				}
				f_void = 0;
			}
		}
		if (isalpha(mass[rand_numb]))
			rand_numb++;
	}
	word[sum] = ' ';
	sum++;
}
