#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Queue
{
	char data;
	Queue* next;
};

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
			cout << ptr->data;
			ptr = ptr->next;
		}
		cout << endl;
	}
}

void clear(Queue*& begin)
{
	Queue* ptr = begin;

	while (begin != NULL)
	{
		ptr = begin;
		begin = begin->next;
		delete ptr;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	Queue* begin = NULL, * end, * ptr;
	fstream fin("data.txt", ios::in);
	fstream fout("output.txt", ios::out);

	if (!fin.is_open() || !fout.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
		return 1;
	}

	string str;

	while (!fin.eof())
	{
		getline(fin, str);

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				insert(begin, end, str[i]);
			}
		}

		cout << "Очередь:" << endl;
		print(begin);

		fout << str;
		ptr = begin;
		while (ptr != NULL)
		{
			fout << ptr->data;
			ptr = ptr->next;
		}
		fout << '\n';
		clear(begin);
	}

	fin.close();
	fout.close();
}