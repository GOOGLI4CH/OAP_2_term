#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

struct Stack1
{
	char symbol;
	Stack1* next;
	Stack1* head;
};

struct Stack2
{
	char symbol;
	Stack2* next;
	Stack2* head;
};

void push1(Stack1*& st, char value)
{
	Stack1* pHead = new Stack1;
	pHead->symbol = value;
	pHead->next = st->head;
	st->head = pHead;
}

void push2(Stack2*& st, char value)
{
	Stack2* pHead = new Stack2;
	pHead->symbol = value;
	pHead->next = st->head;
	st->head = pHead;
}

void print1(Stack1*& st)
{
	Stack1* pHead = st->head;
	char value;

	if (pHead == NULL)
	{
		cout << "Стек 1 пуст" << endl;
	}
	else
	{
		while (pHead != NULL)
		{
			value = pHead->symbol;
			cout << value;
			pHead = pHead->next;
		}
	}
}

void print2(Stack2*& st)
{
	Stack2* pHead = st->head;
	char value;

	if (pHead == NULL)
	{
		cout << "Стек 2 пуст" << endl;
	}
	else
	{
		while (pHead != NULL)
		{
			value = pHead->symbol;
			cout << value;
			pHead = pHead->next;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Stack1* st1 = new Stack1;
	st1->head = NULL;
	Stack2* st2 = new Stack2;
	st2->head = NULL;

	cout << "Введите слово" << endl;
	string str;
	getline(cin, str);

	int size = str.length();
	
	for (int i = 0; i < size/2; i++)
	{
		push1(st1, str[i]);
	}

	for (int i = size/2; i < size; i++)
	{
		push2(st2, str[i]);
	}

	print1(st1);
	print2(st2);
}