#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	ofstream fout("fileEx6.txt");

	if (fout.fail())
	{
		cout << "Ошибка открытия файла!" << endl;
		exit(1);
	}
	else
	{
		cout << "Файл открыт! (чтение)" << endl;
	}

	string str;
	cout << "Введите строку: " << endl;

	getline(cin, str);
	fout << str;
	fout.close();

	ifstream fin("fileEx6.txt");

	if (fin.fail())
	{
		cout << "Ошибка открытия файла!" << endl;
		exit(1);
	}
	else
	{
		cout << "Файл открыт! (чтение)" << endl;
	}

	string tmp;

	while (fin >> tmp)
	{
		if (tmp.length() % 2 == 0)
		{
			cout << tmp << ' ';
		}
	}
	
	fout.close();
}