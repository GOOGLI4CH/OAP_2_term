#include <iostream>
#include <string>
#include <Windows.h>

#define SIZE 50

using namespace std;

struct student
{
	string FIO;
	string numberOfExams;
	string marks;

	void input()		//Ввод структуры
	{
		cin.ignore();
		cout << "Введите ФИО студента: ";
		getline(cin, FIO);
		cout << "Введите кол-во экзаменов: ";
		getline(cin, numberOfExams);
		cout << "Введите оценки (через пробел): ";
		getline(cin, marks);
	}


	void output()		//Вывод структуры
	{
		cout << "ФИО: " << FIO << endl;
		cout << "Кол-во экзаменов: " << numberOfExams << endl;
		cout << "Оценка: " << marks << endl;
	}

	bool search(string name)		//Поиск структуры по ФИО
	{
		bool flag = false;

		if (this->FIO == name)
		{
			flag = true;
		}

		return flag;
	}

	void del_struct(string name)		//Удаление структуры
	{
		if (this->FIO == name)
		{
			FIO = "";
			numberOfExams = "";
			marks = "";
			cout << "Успешно удалено" << endl;
		}
	}

	bool checkMarks()			//Проверка оценок студента
	{
		bool flag = false;
		int numberOfMarks = 0, positiveMarks = 0;

		for (int i = 0; i < marks.length(); i++)
		{
			if (marks[i] != ' ' && marks[i] != '\n' && marks[i] != '\0')
			{
				numberOfMarks++;
				if (marks[i] == '4' || marks[i] == '5')
				{
					positiveMarks++;
				}
			}
		}
		if (positiveMarks == numberOfMarks)
		{
			flag = true;
		}

		return flag;
	}

	bool checkStudent()		//Проверка на существования студента
	{
		bool flag = false;

		if (this->FIO != "")
		{
			flag = true;
		}

		return flag;
	}
};

float result(student student[SIZE])
{
	float result = 0, numAllStudents = 0, numGoodStudents = 0;

	for (int i = 0; i < SIZE; i++)
	{
		if (student[i].checkStudent())
		{
			numAllStudents++;
			if (student[i].checkMarks())
			{
				numGoodStudents++;
			}
		}
	}

	result = (numGoodStudents / numAllStudents) * 100;

	return result;
}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice = 0;
	student student[SIZE];

	do
	{
		cout << "Выберите вариант: " << endl;
		cout << "1 - Добавить информацию о студенте" << endl;
		cout << "2 - Вывод инфомарции о студенте" << endl;
		cout << "3 - Удалить информацию о студенте" << endl;
		cout << "4 - Поиск студента по ФИО" << endl;
		cout << "5 - Проверка оценок студента" << endl;
		cout << "6 - Отношение числа студентов, сдавших экзамены на 4 и 5, к общему числу студентов, в процентах" << endl;
		cout << "7 - Выход" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Введите кол-во студентов Вы хотите добавить:" << endl;

			int num = 0;
			cin >> num;

			for (int i = 0; i < num; i++)
			{
				student[i].input();
			}
			break;
		}
		case 2:
		{
			cout << "Введите ФИО студента" << endl;
			cin.ignore();
			string FIO;
			bool flag = false;
			getline(cin, FIO);

			for (int i = 0; i < SIZE; i++)
			{
				if (student[i].search(FIO))
				{
					student[i].output();
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
			cout << "Введите ФИО студента: ";
			string name;
			cin.ignore();
			getline(cin, name);
			for (int i = 0; i < SIZE; i++)
			{
				student[i].del_struct(name);
			}
			break;
		}
		case 4:
		{
			cout << "Введите ФИО студента: ";
			string name;
			bool flag;
			cin.ignore();
			getline(cin, name);
			for (int i = 0; i < SIZE; i++)
			{
				flag = student[i].search(name);
				if (flag)
				{
					student[i].output();
					break;
				}
			}
			if (!flag)
			{
				cout << "Не найдено" << endl;
			}
			break;
		}
		case 5:
		{
			cout << "Введите ФИО студента: ";
			string name;
			bool flag;
			cin.ignore();
			getline(cin, name);
			for (int i = 0; i < SIZE; i++)
			{
				flag = student[i].search(name);
				if (flag)
				{
					if (student[i].checkMarks())
					{
						cout << "У студента оценки 4 и 5" << endl;
					}
					else
					{
						cout << "У студента есть другие оценки кроме 4 и 5" << endl;
					}
					break;
				}
			}
			if (!flag)
			{
				cout << "Студент не найден" << endl;
			}
			break;
		}
		case 6:
		{
			cout << "Отношение числа студентов, сдавших экзамены на 4 и 5, к общему числу студентов = " << result(student) << " %" << endl;
		}
		case 7:
		{
			break;
		}
		}

	} while (choice != 7);
}