#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

struct list
{
	int number;
	list* next;
} *pHead;

void insert(list*& pHead, int value)
{
	list* newP = new list;

	if (newP != NULL)
	{
		newP->number = value;
		newP->next = pHead;
		pHead = newP;
	}
	else
	{
		cout << "Добавление не выполнено :(" << endl;
	}
}

int del(list*& pHead, int value)
{
	list* current, * prev, * temp;

	if (pHead->number == value)
	{
		temp = pHead;
		pHead = pHead->next;
		delete temp;
		return value;
	}
	else
	{
		prev = pHead;
		current = pHead->next;
		while (current != NULL && current->number != value)
		{
			prev = current;
			current = current->next;
		}
		if (current != NULL)
		{
			temp = current;
			prev->next = current->next;
			delete temp;
			return value;
		}
	}
}

list* search(list*& pHead, int value)
{
	if (pHead == NULL)
	{
		cout << "Список пуст!" << endl;
	}
	else
	{
		while (pHead != NULL && pHead->number != value)
		{
			pHead = pHead->next;
		}
	}

	return pHead;
}

void print(list*& pHead)
{
	if (pHead == NULL)
	{
		cout << "Список пуст" << endl;
	}
	else
	{
		cout << "Список:" << endl;
		while (pHead != NULL)
		{
			cout << "-->" << pHead->number;
			pHead = pHead->next;
		}
		cout << "-->NULL" << endl;
	}
}

void writeToFile(list*& pHead)
{
	list buf;
	ofstream fin;
	fin.open("data.txt");

	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
		exit(1);
	}

	while (pHead)
	{
		buf = *pHead;
		fin.write((char*)&buf, sizeof(list));
		pHead = pHead->next;
	}

	fin.close();
	cout << "Успешно записано!" << endl;
}

void readFromFile(list*& pHead)
{
	ifstream fout;
	fout.open("data.txt");

	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
		exit(1);
	}

	list buf, * first;

	fout.read((char*)&buf, sizeof(list));
	while (!fout.eof())
	{
		insert(first, buf.number);
		cout << "-->" << buf.number;
		fout.read((char*)&buf, sizeof(list));
	}
	cout << "-->NULL" << endl;
	fout.close();
}

int sum(list*& pHead)
{
	int sum = 0;

	if (pHead != NULL)
	{
		while (pHead != NULL)
		{
			if (pHead->number > 0)
			{
				sum += pHead->number;
			}
			pHead = pHead->next;
		}
		if (sum == 0)
		{
			cout << "Таких элементов нет!" << endl;
		}
	}
	else
	{
		cout << "Список пуст!" << endl;
	}

	return sum;
}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	list* first = nullptr;
	int choice = 0, value = 0;

	do
	{
		cout << "Выберите вариант:" << endl;
		cout << "1 - Добавить в список" << endl;
		cout << "2 - Считать список" << endl;
		cout << "3 - Удалить из списка (по значению)" << endl;
		cout << "4 - Найти в списке" << endl;
		cout << "5 - Записать список в файл" << endl;
		cout << "6 - Вывести список из файла" << endl;
		cout << "7 - Сумма двузначных элементов" << endl;
		cout << "8 - Выход" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Введите значение: ";
			cin >> value;
			insert(first, value);
			break;
		}
		case 2:
		{
			print(first);
			break;
		}
		case 3:
		{
			cout << "Введите значение: ";
			cin >> value;
			del(first, value);
			break;
		}
		case 4:
		{
			cout << "Введите значение: ";
			cin >> value;
			if (search(first, value) != NULL)
			{
				cout << "Найдено!" << endl;
				print(first);
			}
			else
			{
				cout << "Не найдено!" << endl;
			}
			break;
		}
		case 5:
		{
			writeToFile(first);
			break;
		}
		case 6:
		{
			readFromFile(first);
			break;
		}
		case 7:
		{
			cout << "Результат: " << sum(first) << endl;
			break;
		}
		}
	} while (choice != 8);
}