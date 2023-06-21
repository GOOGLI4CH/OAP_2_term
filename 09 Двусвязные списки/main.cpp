#include "header.h"

ADDRESS* head = NULL, * tail = NULL;

int main()
{
	setlocale(LC_ALL, "rus");
	int choice = 0;
	do
	{
		cout << "Выберите вариант:" << endl;
		cout << "1 - Добавить элемент" << endl;
		cout << "2 - Вывести список" << endl;
		cout << "3 - Удаление по имени" << endl;
		cout << "4 - Запись списка в файл" << endl;
		cout << "5 - Чтение списка из файла" << endl;
		cout << "6 - Функция из задания" << endl;
		cout << "7 - Выход" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			insert(set(), head, tail);
			break;
		}
		case 2:
		{
			print(head);
			break;
		}
		case 3:
		{
			cin.ignore();
			string name;
			cout << "Введите имя" << endl;
			getline(cin, name);
			del(name, head, tail);
			break;
		}
		case 4:
		{
			toFile(head);
			break;
		}
		case 5:
		{
			fromFile(head, tail);
			break;
		}
		case 6:
		{
			cin.ignore();
			string value;
			cout << "Введите значение" << endl;
			getline(cin, value);
			delX(value, head, tail);
			break;
		}
		default:
			break;
		}
	} while (choice != 7);
}