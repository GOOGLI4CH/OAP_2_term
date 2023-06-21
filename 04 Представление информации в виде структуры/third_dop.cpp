#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>

#define SIZE 5

using namespace std;

struct SANATORIUM
{
	string name;
	string location;
	string profile;
	string numOfVouchers;

	bool search(string searchName)
	{
		bool flag = false;

		if (this->name == searchName)
		{
			flag = true;
		}

		return flag;
	}

	void output()
	{
		cout << "Название санатория " << name << endl;
		cout << "Расположение санатория " << location << endl;
		cout << "Профиль санатория " << profile << endl;
		cout << "Количество путёвок " << numOfVouchers << endl;
	}

	void output_sort()
	{
		cout << profile << "\t\t\t|\t" << name << "\t|\t" << location << "\t|\t" << numOfVouchers << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	SANATORIUM element[SIZE];

	//Отступы в строках не убирать (говнокод для представления таблицы в консоли)
	element[0].name = "Сосновый бор"; element[0].location = "Минск   "; element[0].profile = "Зрение"; element[0].numOfVouchers = "45";
	element[1].name = "Солнышко"; element[1].location = "Брест   "; element[1].profile = "Зрение"; element[1].numOfVouchers = "31";
	element[2].name = "Приозерный"; element[2].location = "Гомель   "; element[2].profile = "Сердце"; element[2].numOfVouchers = "12";
	element[3].name = "Ружанский"; element[3].location = "Ружаны   "; element[3].profile = "Сердце"; element[3].numOfVouchers = "43";
	element[4].name = "Нарочанка"; element[4].location = "Могилёв "; element[4].profile = "Общий"; element[4].numOfVouchers = "39";

	cout << "Табличное представление данных" << endl;
	cout << "Лечебный профиль" << "\t|\t" << "Название" << "\t|\t" << "Расположение" << "\t|\t" << "Кол-во путёвок" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		element[i].output_sort();
	}
	int choice = 0;
	string sanName;
	bool flag = false;
	do
	{
		cout << "Введите вариант:" << endl;
		cout << "1 - Поиск и вывод информации" << endl;
		cout << "2 - Выход" << endl;
		cin >> choice;

		if (choice == 1)
		{
			cout << "Введите название санатория" << endl;
			cin.ignore();
			getline(cin, sanName);

			for (int i = 0; i < SIZE; i++)
			{
				if (element[i].search(sanName))
				{
					element[i].output();
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				cout << "Санаторий не найден!" << endl;
			}
		}

	} while (choice != 2);
}