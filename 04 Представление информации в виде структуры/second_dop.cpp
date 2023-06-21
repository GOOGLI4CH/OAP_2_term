#include <iostream>
#include <string>
#include <Windows.h>

#define SIZE 8

using namespace std;

struct TRAIN
{
	string station;
	string trainNumber;
	string time;

	void input()
	{
		cin.ignore();
		cout << "Введите станцию: ";
		getline(cin, station);
		cout << "Введите номер поезда: ";
		getline(cin, trainNumber);
		cout << "Введите время отправления (hh:mm): ";
		getline(cin, time);
	}

	void output()
	{
		cout << "Станция: " << station << endl;
		cout << "Номер поезда: " << trainNumber << endl;
		cout << "Время отправления: " << time << endl;
	}

	bool trainSearch(string time)
	{
		bool flag = false;

		if (this->time >= time)
		{
			output();
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

	int choice = 0;
	TRAIN trains[SIZE];

	do
	{
		cout << "Выберите вариант:" << endl;
		cout << "1 - Ввести данные в массив" << endl;
		cout << "2 - Поиск и вывод по времени" << endl;
		cout << "3 - Выход " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			for (int i = 0; i < SIZE; i++)
			{
				cout << "Введите данные " << i + 1 << "-ого поезда" << endl;
				trains[i].input();
			}
			break;
		}
		case 2:
		{
			cout << "Введите время (hh:mm)" << endl;
			string time;
			cin.ignore();
			getline(cin, time);

			bool check[SIZE] = {};

			for (int i = 0; i < SIZE; i++)
			{
				check[i] = trains[i].trainSearch(time);
			}

			int counterFalse = 0;

			for (int i = 0; i < SIZE; i++)
			{
				if (!check[i])
				{
					counterFalse++;
				}
				if (counterFalse == SIZE)
				{
					cout << "Поездов не найдено!" << endl;
				}
			}
			break;
		}
		case 3:
		{
			break;
		}
		}
	} while (choice != 3);
}