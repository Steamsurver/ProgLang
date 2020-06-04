#include <iostream>
using namespace std;
int ff(int i, int f, int g, int value, int nf, int ng);
int fg(int i, int f, int g, int value, int nf, int ng);

int main()
{
	setlocale(LC_ALL, "");
	int i = 1, f = 0, g = 0, value, ng = 0, nf = 0; //ng передаем значение g-1;  //nf передаем значение f-1; 
	cout << "До какого значения вычислять? - "; cin >> value;
	ff(i, f, g, value, nf, ng);
	
	system("pause");
	return 0;
}

int ff(int i, int f, int g, int value, int nf, int ng) //F(n) функция
{
	if (i < 2)
	{
		f = -2;
		cout << "F = " << f;
		return fg(i, f, g, value, nf, ng);
	}
	if (i <= value)
	{
		nf = f;
		f = 5 * nf - g;
		cout << "F = " << f;
		return fg(i, f, g, value, nf, ng);
	}
}

int fg(int i, int f, int g, int value, int nf, int ng)  //G(n) функция
{
	if (i < 2)
	{
		g = 2;
		cout << "  G = " << g << endl;
		i++;
		return ff(i, f, g, value, nf, ng);
	}
	if (i <= value)
	{
		ng = g;
		g = 2 * nf - ng;
		cout << "  G = " << g<<endl;
		i++;
		return ff(i, f, g, value, nf, ng);
	}
}