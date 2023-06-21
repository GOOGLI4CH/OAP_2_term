#include <iostream>

using namespace std;

struct Queue
{
	double data;
	Queue* next;
};

void insert(Queue*& begin, Queue*& end, double value)
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

Queue* search_max(Queue*& begin)
{
	Queue* ptr = begin, * pMax = ptr;
	double max;

	if (ptr == NULL)
	{
		cout << "Очередь пуста" << endl;
	}
	else
	{
		max = begin->data;
		while (ptr != NULL)
		{
			if (ptr->data > max)
			{
				max = ptr->data;
				pMax = ptr;
			}
			ptr = ptr->next;
		}
	}
	return pMax;
}

int main()
{
	setlocale(LC_ALL, "rus");

	Queue* begin = NULL, * end = NULL;
	int size;
	double value = 0;
	cout << "Введите размер очереди: ";
	cin >> size;

	while (size)
	{
		cout << "Введите элемент: ";
		cin >> value;
		insert(begin, end, value);
		size--;
	}

	cout << "Очередь:" << endl;
	print(begin);
	Queue* current;
	while (begin != search_max(begin))
	{
		current = begin;
		value = current->data;
		insert(begin, end, value);
		begin = begin->next;
		delete current;
	}
	print(begin);
}