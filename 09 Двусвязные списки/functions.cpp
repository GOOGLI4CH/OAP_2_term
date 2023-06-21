#include "header.h"

void insert(ADDRESS* ptr, ADDRESS*& head, ADDRESS*& tail)
{
	ADDRESS* last = tail;

	if (last == NULL)
	{
		ptr->next = ptr->prev = NULL;
		head = tail = ptr;
	}
	else
	{
		last->next = ptr;
		ptr->next = NULL;
		ptr->prev = last;
		tail = ptr;
	}
}

ADDRESS* set()
{
	ADDRESS* ptr = new ADDRESS();

	if (!ptr)
	{
		cout << "Ошибка выделения памяти" << endl;
		return NULL;
	}

	cin.ignore();
	cout << "Введите целочисленное значение (для функции из задания): "; getline(cin, ptr->x);
	cout << "Введите имя: "; getline(cin, ptr->name);
	cout << "Введите город: "; getline(cin, ptr->city);
	ptr->next = NULL;
	ptr->prev = NULL;

	return ptr;
}

void print(ADDRESS*& head)
{
	ADDRESS* ptr = head;

	if (!ptr)
	{
		cout << "Список пуст:(" << endl;
	}
	else
	{
		while (ptr)
		{
			cout << ptr->x << " " << ptr->name << " " << ptr->city << endl;
			ptr = ptr->next;
		}
	}
}

void del(string name, ADDRESS*& head, ADDRESS*& tail)
{
	ADDRESS* ptr = head;

	while (ptr)
	{
		if (name.find(ptr->name) != -1) break;
		ptr = ptr->next;
	}

	if (!ptr)
	{
		cout << "Такого имени не найдено" << endl;
	}
	else
	{
		if (ptr == head)
		{
			head = ptr->next;
			if (head) head->prev = NULL;
			else tail = NULL;
		}
		else
		{
			ptr->prev->next = ptr->next;
			if (ptr != tail) ptr->next->prev = ptr->prev;
			else tail = ptr->prev;
		}
	}
	delete ptr;
}

void toFile(ADDRESS*& head)
{
	ADDRESS* ptr = head;
	ofstream fout("data.txt");

	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
		return;
	}

	while (ptr)
	{
		fout << ptr->x << endl << ptr->name << endl << ptr->city << endl;
		ptr = ptr->next;
	}

	fout.close();
}

void fromFile(ADDRESS*& head, ADDRESS*& tail)
{
	ADDRESS* ptr;
	ifstream fin("data.txt");

	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
		return;
	}

	while (!fin.eof())
	{
		ptr = new ADDRESS();

		getline(fin, ptr->x);
		getline(fin, ptr->name);
		getline(fin, ptr->city);
		if (ptr->x == "") break;
		insert(ptr, head, tail);
	}

	fin.close();
}

void delX(string value, ADDRESS*& head, ADDRESS*& tail)
{
	ADDRESS* ptr = head;

	while (ptr)
	{
		if (value.find(ptr->x) != -1) break;
		ptr = ptr->next;
	}

	if (!ptr)
	{
		cout << "Такого имени не найдено" << endl;
	}
	else
	{
		if (ptr == head)
		{
			head = ptr->next;
			if (head) head->prev = NULL;
			else tail = NULL;
		}
		else
		{
			ptr->prev->next = ptr->next;
			if (ptr != tail) ptr->next->prev = ptr->prev;
			else tail = ptr->prev;
		}
	}
	delete ptr;
}