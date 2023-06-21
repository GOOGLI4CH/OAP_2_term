#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

#define SIZE 50

using namespace std;

void success()
{
	cout << "\nУспешно" << endl;
}
void error()
{
	cout << "\nОшибка" << endl;
}

struct state
{
	string name;
	string capital;
	string population;
	string square;
	string surnamePresident;

	void input()		//Ввод структуры
	{
		cin.ignore();
		cout << "Введите название государства: ";
		getline(cin, name);
		cout << "Введите название столицы: ";
		getline(cin, capital);
		cout << "Введите население: ";
		getline(cin, population);
		cout << "Введите площадь: ";
		getline(cin, square);
		cout << "Введите фамилию президента: ";
		getline(cin, surnamePresident);
		success();
	}


	void output()		//Вывод структуры
	{
		cout << "Название государства: " << name << endl;
		cout << "Столица государства: " << capital << endl;
		cout << "Население: " << population << endl;
		cout << "Площадь: " << square << endl;
		cout << "Фамилия президента: " << surnamePresident << endl;
	}

	bool search(string nameCountry)		//Поиск структуры по названию страны
	{
		bool flag = false;

		if (this->name == nameCountry)
		{
			flag = true;
		}

		return flag;
	}

	void del_struct(string nameCountry)		//Удаление структуры
	{
		if (this->name == nameCountry)
		{
			name = "";
			capital = "";
			population = "";
			square = "";
			surnamePresident = "";
			success();
		}
	}

	void write(string path)		//Запись структуры в файл
	{
		fstream file;
		file.open(path, fstream::app);		//Открытие файла для записи (добавление в конец)
		if (!file.is_open())
		{
			error();
			exit(1);
		}

		cin.ignore();

		cout << "Введите название государства: ";
		getline(cin, name);
		cout << "Введите столицу государства: ";
		getline(cin, capital);
		cout << "Введите кол-во населения: ";
		getline(cin, population);
		cout << "Введите площадь государства: ";
		getline(cin, square);
		cout << "Введите фамилию президента: ";
		getline(cin, surnamePresident);

		file << name << endl;
		file << capital << endl;
		file << population << endl;
		file << square << endl;
		file << surnamePresident << endl;
		file << endl;
		file.close();
	}

	void read(string path)		//Чтение структуры из файла
	{
		fstream file;
		file.open(path, fstream::in);		//Открытие файла для чтения
		if (!file.is_open())
		{
			error();
			exit(1);
		}

		getline(file, name);
		getline(file, capital);
		getline(file, population);
		getline(file, square);
		getline(file, surnamePresident);
		output();
		file.close();
	}
};


int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string path = "data.txt";

	state country[SIZE];
	int choice;
	do
	{
		cout << "Выберите вариант: " << endl;
		cout << "1 - Добавить страну" << endl;
		cout << "2 - Вывод страны" << endl;
		cout << "3 - Удалить страну" << endl;
		cout << "4 - Поиск страны по названию" << endl;
		cout << "5 - Запись данных о стране в файл" << endl;
		cout << "6 - Чтение данных о стране из файла" << endl;
		cout << "7 - Выход" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Введите кол-во стран вы хотите добавить: " << endl;
			
			int num;
			cin >> num;
			
			for (int i = 0; i < num; i++)
			{
				country[i].input();
			}
			break;
		}
		case 2:
		{
			cout << "Введите название страны" << endl;
			cin.ignore();
			string countryName;
			bool flag = false;
			getline(cin, countryName);

			for (int i = 0; i < SIZE; i++)
			{
				if (country[i].search(countryName))
				{
					country[i].output();
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				cout << "Санаторий не найден!" << endl;
			}
			break;
		}
		case 3:
		{
			cout << "Введите название страны: ";
			string nameCountry;
			cin.ignore();
			getline(cin, nameCountry);
			for (int i = 0; i < SIZE; i++)
			{
				country[i].del_struct(nameCountry);
			}
			break;
		}
		case 4:
		{
			cout << "Введите название страны: ";
			string nameCountry;
			bool flag;
			cin.ignore();
			getline(cin, nameCountry);
			for (int i = 0; i < SIZE; i++)
			{
				flag = country[i].search(nameCountry);
				if (flag)
				{
					country[i].output();
					break;
				}
			}
			if (!flag)
			{
				cout << "Страна не найдена" << endl;
			}
			break;
		}
		case 5:
		{
			country[49].write(path);
			break;
		}
		case 6:
		{
			country[49].read(path);
			break;
		}
		case 7:
		{
			break;
		}
		default:
		{
			break;
		}
		}
	} while (choice != 7);
}