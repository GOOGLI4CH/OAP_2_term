#include <iostream>
#include <string>
#include <Windows.h>

#define SIZE 5

using namespace std;

enum JOB_TITLE
{
	CEO = 1, CFO, CVO, COO, CIO
};

struct HUMAN_RESOURCES_DEPARTMENT
{
	string FIO;
	string education;
	string speciality;
	string subdivision;
	string jobTitle;
	string salary;
	struct DATE
	{
		unsigned int day : 5;
		unsigned int month : 4;
		unsigned int year : 11;
	} date = { 0,0,0 };

	void input()
	{
		cin.ignore();
		cout << "Введите ФИО" << endl;
		getline(cin, FIO);
		cout << "Введите образование" << endl;
		getline(cin, education);
		cout << "Введите специальность" << endl;
		getline(cin, speciality);
		cout << "Введите подразделение" << endl;
		getline(cin, subdivision);
		cout << "Введите должность (1 - CEO, 2 - CFO, 3 - CVO, 4 - COO, 5 - CIO" << endl;
		unsigned int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case JOB_TITLE::CEO:
		{
			jobTitle = "Генеральный директор";
			break;
		}
		case JOB_TITLE::CFO:
		{
			jobTitle = "Финансовый директор";
			break;
		}
		case JOB_TITLE::CVO:
		{
			jobTitle = "Исполнительный директор";
			break;
		}
		case JOB_TITLE::COO:
		{
			jobTitle = "Главный операционный директор";
			break;
		}
		case JOB_TITLE::CIO:
		{
			jobTitle = "Зам. генерального директора по IT";
			break;
		}
		default:
		{
			cout << "Выбран неверный вариант" << endl;
			break;
		}
		}
		cin.ignore();
	REPEAT_DATE:cout << "Введите дату (00 00 0000)" << endl;
		unsigned int day = 0, month = 0, year = 0;
		cin >> day >> month >> year;
		if (day < 32 && month < 13 && year < 2049)
		{
			date.day = day;
			date.month = month;
			date.year = year;
		}
		else
		{
			cout << "Дата введена неверно!" << endl;
			goto REPEAT_DATE;
		}
	}

	void output()
	{
		cout << "ФИО: " << FIO << endl;
		cout << "Образование: " << education << endl;
		cout << "Специальность: " << speciality << endl;
		cout << "Подразделение: " << subdivision << endl;
		cout << "Должность: " << jobTitle << endl;
		cout << "Оклад: " << salary << endl;
		cout << "Дата поступления на предприятие: " << date.day << " " << date.month << " " << date.year << endl;
	}

	void del_data()
	{
		FIO = "";
		education = "";
		speciality = "";
		subdivision = "";
		jobTitle = "";
		salary = "";
		date = { 0,0,0 };
	}

	bool search(unsigned int exp)
	{
		//2023 - текущий год => стаж вычисляется относительно настоящего года. Значение стажа будет в годах
		unsigned int experience = 2023 - date.year;
		bool flag = false;

		if (experience == exp)
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

	HUMAN_RESOURCES_DEPARTMENT humans[SIZE];
	int choice;
	do
	{
		cout << "Выберите вариант: " << endl;
		cout << "1 - Добавить кадр" << endl;
		cout << "2 - Вывести кадр" << endl;
		cout << "3 - Удалить кадр" << endl;
		cout << "4 - Поиск кадра по стажу" << endl;
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
				humans[number - 1].input();
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
				humans[number - 1].output();
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
				humans[number - 1].del_data();
			}
			else
			{
				cout << "Ошибка!" << endl;
			}
			break;
		}
		case 4:
		{
			cout << "Введите стаж: ";
			unsigned int experience;
			bool flag = false;
			cin.ignore();
			cin >> experience;

			for (int i = 0; i < SIZE; i++)
			{
				if (humans[i].search(experience))
				{
					humans[i].output();
					flag = true;
				}
			}
			if (!flag)
			{
				cout << "Кадр с таким стажем не найден!" << endl;
			}
			break;
		}
		}
	} while (choice != 5);
}