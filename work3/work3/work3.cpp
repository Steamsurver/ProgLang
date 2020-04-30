#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;
bool polindr(char* word, int word_weight);

int main()
{
	setlocale(LC_ALL, "");
	int n = 255;
	int i = 0, word_weight;
	char* word = new char[n];
	cout << "Введите строку ";
	cin.getline(word, n);
	word_weight = strlen(word);
	cout << "Размер строки " << word_weight<<endl;
	if (polindr(word, word_weight) == 0)
	{
		cout << "\nПолиндром\n";
	}
	else cout << "\nне полиндром\n";
	system("pause");
	return 0;
}

bool polindr(char* word, int word_weight)
{
	bool polf = 0;
	int train = 0, sum = 0, j = 0;
	cout << "тест массива - " << word << endl;
	cout << "Преобразованная строка ";
	if (word_weight % 2 == 0)
	{
		 train = (word_weight / 2) - 1;
	}
	else 
		train =word_weight/2;

	for (int i = word_weight-1; i > train; i--)
	{
		word[i] = tolower(word[i]); //i  переводим в нижний регистр
		if (!isalpha(word[i]) && !isdigit(word[i])) //если символ не является буквой или цифрой но спускаемся ниже
			while (!isalpha(word[i]) && !isdigit(word[i]))
			{
				i--;
				word[i] = tolower(word[i]);
			}


		word[j] = tolower(word[j]); //j
			if (!isalpha(word[j]) && !isdigit(word[j]))
				while (!isalpha(word[j]) && !isdigit(word[j]))
				{
					j++;
					word[j] = tolower(word[j]);
				}



		cout << "-" << word[i]; cout << word[j]; //проверка символов 
		if (word[i] != word[j])
		{
			sum++;
		}
		j++;
	}
	if (sum == 0)
	{
		return 0;
	}
	else
		return 1;
}