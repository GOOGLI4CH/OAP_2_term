#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Stack
{
	int length;
	Stack* next;
	Stack* head;
};

void push(Stack*& st, int value)
{
	Stack *pHead = new Stack;
	pHead->length = value;
	pHead->next = st->head;
	st->head = pHead;
}

void print(Stack*& st)
{
	Stack* pHead = st->head;
	int value;

	if (pHead == NULL)
	{
		cout << "Стек пуст" << endl;
	}
	else
	{
		while (pHead != NULL)
		{
			value = pHead->length;
			cout << value << " ";
			pHead = pHead->next;
		}
		cout << endl;
	}
}

void min_str(Stack*& st, int counter)
{
	Stack *pHead = st->head;
	int *arr = new int[counter], i = 0, num = 0, num_str = 0;
	if (pHead == NULL)
	{
		cout << "Стек пуст!" << endl;
	}
	else
	{
		while (pHead != NULL)
		{
			*(arr + i) = pHead->length;
			i++;
			pHead = pHead->next;
		}

		int min_symbol = *arr;

		for (int i = 0; i < counter; i++)
		{
			if (min_symbol > *(arr + i))
			{
				min_symbol = *(arr + i);
			}
		}

		for (int i = 0; i < counter; i++)
		{
			if (min_symbol != *(arr + i))
			{
				num++;
			}
			else
			{
				break;
			}
		}

		num_str = counter - num;		//Номер строки с минимальным количеством символов
		
		cout << "Номер самой короткой строки: " << num_str << ". Кол-во символов в самой короткой строке: " << min_symbol << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	Stack* st = new Stack;
	st->head = NULL;
	string path = "file.txt";
	string str;
	int length, counter_str = 0;
	fstream file(path, ios::in);

	if (!file.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
		exit(1);
	}
	else
	{
		while (!file.eof())
		{
			getline(file, str);
			length = str.length();
			push(st, length);
			counter_str++;
		}
	}

	cout << "Стек:" << endl;
	print(st);
	min_str(st, counter_str);
}