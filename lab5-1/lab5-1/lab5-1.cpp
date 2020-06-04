#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	struct TestS
	{
		string name;
		int day;
		int month;
		double year;
	};

	TestS john;
	john.name = "John";
	john.day = 12;
	john.month = 2;
	john.year = 2000;

	cout << john.name << ": " << john.day << "." << john.month << "." << john.year<<endl;


	system("pause");
	return 0;
}

