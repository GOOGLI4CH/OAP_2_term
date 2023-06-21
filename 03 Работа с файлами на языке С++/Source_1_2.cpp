#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	ofstream fout("fileEx1.txt");

	if (fout.fail())
	{
		cout << "Невозможно открыть файл" << endl;
		exit(1);
	}
	else
	{
		cout << "Файл открыт!" << endl;
	}

	cout << "Введите строку" << endl;
	string str;
	getline(cin, str);
	fout << str;
	fout.close();

	ifstream fin("fileEx1.txt");

	if (fin.fail())
	{
		cout << "Невозможно открыть файл" << endl;
		exit(1);
	}
	else
	{
		cout << "Файл открыт!" << endl;
	}

	int number = 0;

	while (fin >> str)
	{
		if (str >= "1" && str <= "9")
		{
			number = stoi(str);
			
			if (number % 2 != 0)
			{
				cout << number << endl;
			}
		}
	}

	fin.close();
}