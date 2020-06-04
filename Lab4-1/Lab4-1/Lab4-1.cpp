#include <iostream>
using namespace std;

int i=0;
void absolute(int abs);
int rec_absolute(int abs, int n);

int main()
{
	setlocale(LC_ALL, "");
	int abs,n = 1;
	cout << "Введите факториал - ";
	cin >> abs;
	cout << "Не рекурсивная функция\n";
	absolute(abs);
	cout << "Pекурсивная функция\n";
	cout <<"Факториал - "<<rec_absolute(abs,n)<<endl;


	system("pause");
	return 0;
}


void absolute(int abs) //не рекурсивная функция
{
	int n = 1;

	for (i = 1; i <= abs; i++)
		n *= i;
	cout << "Факториал - " << n<<endl;
}

int rec_absolute(int abs, int n)
{
	n *= abs;
	abs--;
	if (abs != 1)
		return rec_absolute(abs, n);
	else return n;
}

