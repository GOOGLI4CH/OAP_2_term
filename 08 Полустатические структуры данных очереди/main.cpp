#include "Header.h"

int main()
{
	setlocale(LC_ALL, "rus");

	Queue* begin = NULL, * end;

	char symbol;
	int choice = 0, MAX_SIZE, size = 0;
	bool flag = false;

	cout << "Введите максимальный размер очереди" << endl;
	cin >> MAX_SIZE;

	do
	{
		cout << "Выберите вариант:" << endl;
		cout << "1 - Добавить в очередь" << endl;
		cout << "2 - Вывести очередь" << endl;
		cout << "3 - Очистить очередь" << endl;
		cout << "4 - Определить размер очереди" << endl;
		cout << "5 - Выход" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Введите кол-во элементов вы хотите добавить" << endl;
			cin >> size;
			if ((size + size_count(begin)) > MAX_SIZE)
			{
				cout << "Не хватит места!" << endl;
			}
			else
			{
				while (size)
				{
					cout << "Введите значение: ";
					cin >> symbol;
					insert(begin, end, symbol);
					if (flag && begin->data == symbol)
					{
						print(begin);
						int size_queue = size_count(begin);
						cout << "Размер очереди: " << size_queue << endl;
						break;
					}
					flag = true;
					size--;
				}
			}
			break;
		}
		case 2:
		{
			print(begin);
			break;
		}
		case 3:
		{
			del(begin);
			flag = false;
			break;
		}
		case 4:
		{
			int size_queue = size_count(begin);
			cout << "Размер очереди: " << size_queue << endl;
		}
		}
	} while (choice != 5);
}