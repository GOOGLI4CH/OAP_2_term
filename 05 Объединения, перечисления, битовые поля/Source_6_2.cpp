#include <iostream>
#include <string>
#include <Windows.h>

#define SIZE 5

using namespace std;

union STUFF
{
	struct HUMAN
	{
		string FIO;
		string education;
		string speciality;
		string subdivision;
		string jobTitle;
		string salary;
		string date;
	};
};

struct HUMAN_RESOURCES_DEPARTMENT
{
	string FIO;
	string education;
	string speciality;
	string subdivision;
	string jobTitle;
	string salary;
	string date;

	void input(STUFF::HUMAN human)
	{
		FIO = human.FIO;
		education = human.education;
		speciality = human.education;
		subdivision = human.subdivision;
		jobTitle = human.jobTitle;
		salary = human.salary;
		date = human.date;
	}

	void output()
	{
		cout << "ФИО: " << FIO << endl;
		cout << "Образование: " << education << endl;
		cout << "Специальность: " << speciality << endl;
		cout << "Подразделение: " << speciality << endl;
		cout << "Должность: " << jobTitle << endl;
		cout << "Оклад: " << salary << endl;
		cout << "Дата поступления на предприятие: " << date << endl;
	}

	bool search(string jobTitle)
	{
		bool flag = false;

		if (this->jobTitle == jobTitle)
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
	STUFF::HUMAN human;
	int choice = 0;
	do
	{
		cout << "Выберите вариант: " << endl;
		cout << "1 - Добавить кадр" << endl;
		cout << "2 - Вывести кадр" << endl;
		cout << "3- Поиск кадра по должности" << endl;
		cout << "4 - Выход" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Введите номер свободного кадра" << endl;
			int number;
			cin >> number;
			if (number <= SIZE)
			{
				cin.ignore();
				cout << "Введите ФИО" << endl;
				getline(cin, human.FIO);
				cout << "Введите образование" << endl;
				getline(cin, human.education);
				cout << "Введите специальность" << endl;
				getline(cin, human.speciality);
				cout << "Введите подразделение" << endl;
				getline(cin, human.subdivision);
				cout << "Введите должность" << endl;
				getline(cin, human.jobTitle);
				cout << "Введите оклад" << endl;
				getline(cin, human.salary);
				cout << "Введите дату поступления на предприятие" << endl;
				getline(cin, human.date);
				humans[number - 1].input(human);
			}
			else
			{
				cout << "Ошибка!" << endl;
			}
			break;
		}
		case 2:
		{
			cout << "Введите номер свободного кадра" << endl;
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
			cout << "Введите должность: ";
			string jobTitle;
			cin.ignore();
			getline(cin, jobTitle);

			for (int i = 0; i < SIZE; i++)
			{
				if (humans[i].search(jobTitle))
				{
					humans[i].output();
				}
			}
			break;
		}
		}
	} while (choice != 4);
}