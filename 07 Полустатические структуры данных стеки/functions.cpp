#include "header.h"

void push(Stack*& st, int value)
{
	Stack* pHead = new Stack;
	pHead->number = value;
	pHead->next = st->head;
	st->head = pHead;
}

int pop(Stack*& st)
{
	if (st->head == NULL)
	{
		cout << "Стек пуст!" << endl;
		return -1;
	}
	else
	{
		Stack* temp = st->head;
		int value = st->head->number;
		st->head = st->head->next;
		delete temp;
		cout << "Элемент извлечён" << endl;
		return value;
	}
}

void print(Stack*& st)
{
	Stack* pHead = st->head;
	int value;

	if (pHead == NULL)
	{
		cout << "Стек пуст!" << endl;
	}
	else
	{
		while (pHead != NULL)
		{
			value = pHead->number;
			cout << value << " ";
			pHead = pHead->next;
		}
		cout << endl;
	}
}

void clear(Stack*& st)
{
	if (st->head == NULL)
	{
		cout << "Стек пуст!" << endl;
	}
	else
	{
		while (st->head != NULL)
		{
			Stack* temp = st->head;
			st->head = st->head->next;
			delete temp;
		}
		cout << "Стек очищен!" << endl;
	}
}

void toFile(Stack*& st, string path)
{
	fstream file(path, ios::out);

	if (file.is_open())
	{
		if (st->head == NULL)
		{
			cout << "Стек пуст" << endl;
		}
		else
		{
			while (st->head != NULL)
			{
				file << st->head->number << " ";
				st->head = st->head->next;
			}
			cout << "Успешно записано!" << endl;
		}
	}
	else
	{
		cout << "Ошибка открытия файла" << endl;
		exit(1);
	}
	file.close();
}

void fromFile(Stack*& st, string path)
{
	fstream file(path, ios::in);

	if (file.is_open())
	{
		int value;
		while (file >> value)
		{
			Stack* pHead = new Stack;
			pHead->number = value;
			pHead->next = st->head;
			st->head = pHead;
		}
		cout << "Успешно считано!" << endl;
	}
	else
	{
		cout << "Ошибка открытия файла" << endl;
		exit(1);
	}
	file.close();
}

void main_task(Stack*& st, Stack*& st1, Stack*& st2)
{
	Stack* pHead = st->head;
	int value;
	if (pHead == NULL)
	{
		cout << "Стек пуст!" << endl;
	}
	else
	{

		while (pHead != NULL)
		{
			value = pHead->number;
			if (value % 2 == 0)
			{
				Stack* pHead1 = new Stack;
				pHead1->number = value;
				pHead1->next = st1->head;
				st1->head = pHead1;
			}
			else
			{
				Stack* pHead2 = new Stack;
				pHead2->number = value;
				pHead2->next = st2->head;
				st2->head = pHead2;
			}
			pHead = pHead->next;
		}
	}
}

void main_task1(Stack*& st, Stack*& st1, Stack*& st2)
{
	Stack* pHead = st->head;
	int value;
	if (pHead == NULL)
	{
		cout << "Стек пуст!" << endl;
	}
	else
	{

		while (pHead != NULL)
		{
			value = pHead->number;
			if (value > 0)
			{
				Stack* pHead1 = new Stack;
				pHead1->number = value;
				pHead1->next = st1->head;
				st1->head = pHead1;
			}
			if (value < 0)
			{
				Stack* pHead2 = new Stack;
				pHead2->number = value;
				pHead2->next = st2->head;
				st2->head = pHead2;
			}
			pHead = pHead->next;
		}
	}
}