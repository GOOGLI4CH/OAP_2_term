#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	ofstream fout("dataEx2.txt");
	if (fout.fail())
	{
		cout << "Ошибка открытия файла dataEx2.txt (запись)" << endl;
		exit(1);
	}
	else
	{
		cout << "Файл открыт для записи" << endl;
	}

	cout << "Введите строку" << endl;

	SetConsoleCP(1251);			//Установка кодировки для ввода (корректное отображение информации в файле).
	string str;
	getline(cin, str);
	fout << str;
	fout.close();
	SetConsoleCP(866);			//Установка кодировки по умолчанию.

	cout << "Данные записаны, файл закрыт" << endl;

	fout.close();

	ifstream fin("dataEx2.txt");

	if (fin.fail())				//Проверка на открытие файла.
	{
		cout << "Ошибка открытия файла dataEx2.txt (чтение)" << endl;
		exit(1);
	}
	else
	{
		cout << "Файл открыт для чтения" << endl;
	}

	string tmp;
	int counter = 0;
	bool flag = false;

	fin >> tmp;
	for (int i = 0; i < tmp.length(); i++)
	{
		if (tmp[i] == ',')
		{
			counter++;
			flag = true;
		}
	}

	if (!flag)
	{
		cout << "Нет запятых" << endl;
	}
	else
	{
		cout << "Кол-во запятых " << counter;
	}

	fin.close();
}