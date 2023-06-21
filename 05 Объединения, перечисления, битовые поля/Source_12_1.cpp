#include <iostream>
#include <string>
#include <Windows.h>

#define SIZE 5

using namespace std;

struct NOTEBOOK
{
	string FIO;
	struct DATE_BIRTH
	{
		unsigned int day : 5;
		unsigned int month : 4;
		unsigned int year : 11;
	} date = { 0, 0, 0 };
	string adress;
	string phoneNumber;
	string placeWorkStudy;
	string jobTitle;

	void input()
	{
		unsigned int day = 0, month = 0, year = 0;
		cin.ignore();
		cout << "Введите ФИО" << endl;
		getline(cin, FIO);
	REPEAT_DATE:cout << "Введите дату рождения (00 00 0000)" << endl;
		cin >> day >> month >> year;
		if (day < 32 && month < 13 && year < 2049)
		{
			date.day = day;
			date.month = month;
			date.year = year;
		}
		else
		{
			cout << "Ошибка ввода даты!" << endl;
			goto REPEAT_DATE;
		}
		cin.ignore();
		cout << "Введите адрес" << endl;
		getline(cin, adress);
		cout << "Введите номер телефона" << endl;
		getline(cin, phoneNumber);
		cout << "Введите место работы/учёбы" << endl;
		getline(cin, placeWorkStudy);
		cout << "Введите должность" << endl;
		getline(cin, jobTitle);
	}

	void output()
	{
		cout << "ФИО: " << FIO << endl;
		cout << "Дата рождения: " << date.day << " " << date.month << " " << date.year << endl;
		cout << "Адрес: " << adress << endl;
		cout << "Номер телефона: " << phoneNumber << endl;
		cout << "Место работы/учёбы: " << placeWorkStudy << endl;
		cout << "Должность: " << jobTitle << endl;
	}

	void del_note()
	{
		FIO = "";
		date = { 0, 0, 0 };
		adress = "";
		phoneNumber = "";
		placeWorkStudy = "";
		jobTitle = "";
		cout << "Успешно удалено!" << endl;
	}

	bool search(string surname)
	{
		bool flag = false;

		if (this->FIO.find(surname) != -1)
		{
			flag = true;
		}

		return flag;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	NOTEBOOK note[SIZE];
	int choice;
	do
	{
		cout << "Выберите вариант: " << endl;
		cout << "1 - Добавить записку" << endl;
		cout << "2 - Вывести записку" << endl;
		cout << "3 - Удалить записку" << endl;
		cout << "4 - Поиск записки по фамилии" << endl;
		cout << "5 - Выход" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Введите номер пустой записки" << endl;
			int number;
			cin >> number;
			if (number <= SIZE)
			{
				note[number - 1].input();
			}
			else
			{
				cout << "Ошибка!" << endl;
			}
			break;
		}
		case 2:
		{
			cout << "Введите номер записки" << endl;
			int number;
			cin >> number;
			if (number <= SIZE)
			{
				note[number - 1].output();
			}
			else
			{
				cout << "Ошибка!" << endl;
			}
			break;
		}
		case 3:
		{
			cout << "Введите номер записки" << endl;
			int number;
			cin >> number;
			if (number <= SIZE)
			{
				note[number - 1].del_note();
			}
			else
			{
				cout << "Ошибка!" << endl;
			}
			break;
		}
		case 4:
		{
			cout << "Введите фамилию: ";
			string surname;
			cin.ignore();
			getline(cin, surname);

			for (int i = 0; i < SIZE; i++)
			{
				if (note[i].search(surname))
				{
					note[i].output();
				}
			}
			break;
		}
		}
	} while (choice != 5);
}