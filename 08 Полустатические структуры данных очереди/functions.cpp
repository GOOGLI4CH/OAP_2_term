#include "Header.h"

void insert(Queue*& begin, Queue*& end, char value)
{
	Queue* ptr = new Queue;
	ptr->next = NULL;
	ptr->data = value;

	if (begin == NULL)
	{
		begin = end = ptr;
	}
	else
	{
		end->next = ptr;
		end = ptr;
	}
}

void print(Queue*& begin)
{
	Queue* ptr = begin;

	if (ptr == NULL)
	{
		cout << "Очередь пуста!" << endl;
	}
	else
	{
		while (ptr != NULL)
		{
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
		cout << endl;
	}
}

void del(Queue*& begin)
{
	Queue* ptr = begin, * temp;

	if (ptr == NULL)
	{
		cout << "Очередь пуста!" << endl;
	}
	else
	{
		while (ptr != NULL)
		{
			temp = ptr;
			ptr = ptr->next;
			delete temp;
		}
		begin = NULL;
		cout << "Очередь очищена!" << endl;
	}
}

int size_count(Queue*& begin)
{
	Queue* ptr = begin;
	int size = 0;

	while (ptr != NULL)
	{
		size++;
		ptr = ptr->next;
	}

	return size;
}