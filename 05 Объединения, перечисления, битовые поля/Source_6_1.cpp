#include <iostream>
#include <string>
#include <Windows.h>

#define SIZE 5

using namespace std;

enum BRAND
{
	Audi = 1, Bentley, BMW, Lexus, MercedesBenz
};

struct NOTEBOOK_CAR
{
	string brand;
	string color;
	string WIN;
	struct DATEISSUE
	{
		unsigned int day : 5;
		unsigned int month : 4;
		unsigned int year : 11;
	} dateIssue = { 0,0,0 };
	string type;
	string inspectionDate;
	string owner;

	void input()
	{
		cin.ignore();
		cout << "Выберите марку авто (1 - AUDI, 2 - Bentley, 3 - BMW, 4 - Lexus, 5 - MercedesBenz)" << endl;
		unsigned int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case BRAND::Audi:
		{
			brand = "Audi";
			break;
		}
		case BRAND::Bentley:
		{
			brand = "Bentley";
			break;
		}
		case BRAND::BMW:
		{
			brand = "BMW";
			break;
		}
		case BRAND::Lexus:
		{
			brand = "Lexus";
			break;
		}
		case BRAND::MercedesBenz:
		{
			brand = "Mercedes-Benz";
			break;
		}
		default:
		{
			cout << "Выбран неверный вариант" << endl;
			break;
		}
		}
		cin.ignore();
		cout << "Введите цвет авто" << endl;
		getline(cin, color);
		cout << "Введите WIN" << endl;
		getline(cin, WIN);
	REPEAT_DATE:cout << "Введите дату выпуска авто (00 00 0000)" << endl;
		unsigned int day = 0, month = 0, year = 0;
		cin >> day >> month >> year;
		if (day < 32 && month < 13 && year < 2049)
		{
			dateIssue.day = day;
			dateIssue.month = month;
			dateIssue.year = year;
		}
		else
		{
			cout << "Ошибка ввода даты!" << endl;
			goto REPEAT_DATE;
		}
		cin.ignore();
		cout << "Введите тип кузова (седан, универсал и т.п.)" << endl;
		getline(cin, type);
		cout << "Введите дату последнего тех.осмотра" << endl;
		getline(cin, inspectionDate);
		cout << "Введите владельца" << endl;
		getline(cin, owner);
	}

	void output()
	{
		cout << "Марка авто: " << brand << endl;
		cout << "Цвет авто: " << color << endl;
		cout << "WIN авто: " << WIN << endl;
		cout << "Дата выпуска авто: " << dateIssue.day << " " << dateIssue.month << " " << dateIssue.year << endl;
		cout << "Тип кузова: " << type << endl;
		cout << "Дата последнего тех.осмотра " << inspectionDate << endl;
		cout << "Владелец авто: " << owner << endl;
	}

	void del_note()
	{
		brand = "";
		color = "";
		WIN = "";
		dateIssue = { 0,0,0 };
		type = "";
		inspectionDate = "";
		owner = "";
	}

	bool search(string WIN)
	{
		bool flag = false;

		if (this->WIN == WIN)
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

	NOTEBOOK_CAR note_car[SIZE];
	int choice;
	do
	{
		cout << "Выберите вариант: " << endl;
		cout << "1 - Добавить заметку" << endl;
		cout << "2 - Вывести заметку" << endl;
		cout << "3 - Удалить заметку" << endl;
		cout << "4 - Поиск заметки по WIN" << endl;
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
				note_car[number - 1].input();
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
				note_car[number - 1].output();
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
				note_car[number - 1].del_note();
			}
			else
			{
				cout << "Ошибка!" << endl;
			}
			break;
		}
		case 4:
		{
			cout << "Введите WIN: ";
			string WIN;
			cin.ignore();
			getline(cin, WIN);

			for (int i = 0; i < SIZE; i++)
			{
				if (note_car[i].search(WIN))
				{
					note_car[i].output();
				}
			}
			break;
		}
		}
	} while (choice != 5);
}