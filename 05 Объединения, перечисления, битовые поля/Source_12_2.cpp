#include <iostream>
#include <string>
#include <Windows.h>

#define SIZE 5

using namespace std;

union NOTE
{
	struct a_note
	{
		string FIO;
		string date;
		string adress;
		string phoneNumber;
		string placeWorkStudy;
		string jobTitle;
	};
};

struct NOTEBOOK
{
	string FIO;
	string date;
	string adress;
	string phoneNumber;
	string placeWorkStudy;
	string jobTitle;

	void input(NOTE::a_note note)
	{
		FIO = note.FIO;
		date = note.date;
		adress = note.adress;
		phoneNumber = note.phoneNumber;
		placeWorkStudy = note.placeWorkStudy;
		jobTitle = note.jobTitle;
	}

	void output()
	{
		cout << "ФИО: " << FIO << endl;
		cout << "Дата рождения: " << date << endl;
		cout << "Адрес: " << adress << endl;
		cout << "Номер телефона: " << phoneNumber << endl;
		cout << "Место работы/учёбы: " << placeWorkStudy << endl;
		cout << "Должность: " << jobTitle << endl;
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

	int choice;
	NOTEBOOK book[SIZE];
	NOTE::a_note note;
	do
	{
		cout << "Выберите вариант: " << endl;
		cout << "1 - Добавить записку" << endl;
		cout << "2 - Вывести записку" << endl;
		cout << "3- Поиск записки по фамилии" << endl;
		cout << "4 - Выход" << endl;

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
				cin.ignore();
				cout << "Введите ФИО" << endl;
				getline(cin, note.FIO);
				cout << "Введите дату рождения" << endl;
				getline(cin, note.date);
				cout << "Введите адрес" << endl;
				getline(cin, note.adress);
				cout << "Введите номер телефона" << endl;
				getline(cin, note.phoneNumber);
				cout << "Введите место учёбы/работы" << endl;
				getline(cin, note.placeWorkStudy);
				cout << "Введите должность" << endl;
				getline(cin, note.jobTitle);
				book[number - 1].input(note);
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
				book[number - 1].output();
			}
			else
			{
				cout << "Ошибка!" << endl;
			}
			break;
		}
		case 3:
		{
			cout << "Введите фамилию: ";
			string surname;
			cin.ignore();
			getline(cin, surname);

			for (int i = 0; i < SIZE; i++)
			{
				if (book[i].search(surname))
				{
					book[i].output();
				}
			}
			break;
		}
		}
	} while (choice != 4);
}