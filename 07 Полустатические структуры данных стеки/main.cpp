#include "header.h"

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string path = "data.txt";
	int choice = 0;
	Stack* st = new Stack;
	st->head = NULL;
	Stack* st1 = new Stack;
	st1->head = NULL;
	Stack* st2 = new Stack;
	st2->head = NULL;

	do
	{
		cout << "Выберите вариант:" << endl;
		cout << "1 - Добавить элемент" << endl;
		cout << "2 - Извлечь элемент" << endl;
		cout << "3 - Показать стек" << endl;
		cout << "4 - Очистка стека" << endl;
		cout << "5 - Запись стека в файл" << endl;
		cout << "6 - Чтение стека из файла" << endl;
		cout << "7 - Функция из задания" << endl;
		cout << "8 - Выход" << endl;
		cin >> choice;

		int value = 0;
		switch (choice)
		{
		case 1:
		{
			cout << "Введите значение: ";
			cin >> value;
			push(st, value);
			break;
		}
		case 2:
		{
			pop(st);
			break;
		}
		case 3:
		{
			print(st);
			break;
		}
		case 4:
		{
			clear(st);
			break;
		}
		case 5:
		{
			toFile(st, path);
			break;
		}
		case 6:
		{
			fromFile(st, path);
			break;
		}
		case 7:
		{
			main_task(st, st1, st2);
			cout << "Первый стек" << endl;
			print(st1);
			cout << "Второй стек" << endl;
			print(st2);
			break;
		}
		}
	} while (choice != 8);
}