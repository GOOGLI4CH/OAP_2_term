#include<iostream>

using namespace std;

struct Item
{
	int data;
	Item* next;
};
Item* head, * tail;

bool empty(void)    //Проверка на пустоту
{
	return (head == NULL);
}
void pop()   //Извлечение элемента из начала
{
	if (empty())
		cout << "Очередь пуста" << endl;
	else
	{
		Item* p = head;
		head = head->next;
		delete p;
	}
}
void getFromHead()  //Получение элемента из начала
{
	if (empty())
	{
		cout << "Очередь пуста" << endl;
	}
	else
	{
		cout << "Начало = " << head->data << endl;
	}
}
void insert(int x)  //Добавление элемента в очередь 
{
	Item* p = new Item;      //новый указатель 
	p->data = x;
	p->next = NULL;
	Item* v = new Item;      //указатель для нового числа
	Item* p1 = new Item;
	Item* p2 = new Item;
	int i = 0;               //флажок
	if (empty())
	{
		head = tail = p;
	}
	else
	{
		p2 = head; p1 = head;
		while (p1 != NULL)  //пока очередь не закончится
		{
			if (i == 1)
			{
				if (x <= p1->data)  //число меньше, чем в очереди
				{
					v->data = x;
					v->next = p1;
					p2->next = v;
					return;
				}
				p2 = p2->next;      // следующее число
			}
			else
			{
				if (x <= p1->data)
				{
					v->data = x;
					v->next = p1;
					head = v;
					return;
				}
			}
			p1 = p1->next;
			i = 1;
		}
		if (p1 == NULL)
		{
			tail->next = p;
			tail = p;
		}
	}
}
void print()             //Вывод очереди
{
	Item* p = new Item;
	if (empty())
	{
		cout << "Очередь пуста" << endl;
	}
	else
	{
		cout << "Очередь = ";
		p = head;
		while (!empty())
		{
			if (p != NULL)
			{
				cout << p->data << " ";
				p = p->next;
			}
			else
			{
				cout << "NULL" << endl;
				return;
			}
		}
	}
}

void clear()           //Очистка очереди
{
	while (!empty())
	{
		pop();
	}
}
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int i = 1, choice = 1, value; head = NULL;  tail = NULL;
	while (choice != 0)
	{
		cout << "1 - добавить элемент" << endl;
		cout << "2 - получить элемент с начала" << endl;
		cout << "3 - извлечь элемент с начала" << endl;
		cout << "4 - вывести элементы" << endl;
		cout << "5 - очистить очередь" << endl;
		cout << "0 - выход" << endl;
		cout << "Выберите действие: ";  cin >> choice;

		switch (choice)
		{
		case 1: cout << "Введите элемент:  "; cin >> value;
			insert(value); print();  break;
		case 2: getFromHead(); break;
		case 3: pop();  break;
		case 4: print();  break;
		case 5: clear();    break;
		}
	}
	return 0;
}

#include<iostream>

using namespace std;

struct Item
{
	int data;
	Item* next;
};
Item* head, * tail;

bool empty(void)    //Проверка на пустоту
{
	return (head == NULL);
}
void pop()   //Извлечение элемента из начала
{
	if (empty())
		cout << "Очередь пуста" << endl;
	else
	{
		Item* p = head;
		head = head->next;
		delete p;
	}
}
void getFromHead()  //Получение элемента из начала
{
	if (empty())
	{
		cout << "Очередь пуста" << endl;
	}
	else
	{
		cout << "Начало = " << head->data << endl;
	}
}
void insert(int x)  //Добавление элемента в очередь 
{
	Item* p = new Item;      //новый указатель 
	p->data = x;
	p->next = NULL;
	Item* v = new Item;      //указатель для нового числа
	Item* p1 = new Item;
	Item* p2 = new Item;
	int i = 0;               //флажок
	if (empty())
	{
		head = tail = p;
	}
	else
	{
		p2 = head; p1 = head;
		while (p1 != NULL)  //пока очередь не закончится
		{
			if (i == 1)
			{
				if (x >= p1->data)  //число меньше, чем в очереди
				{
					v->data = x;
					v->next = p1;
					p2->next = v;
					return;
				}
				p2 = p2->next;      // следующее число
			}
			else
			{
				if (x >= p1->data)
				{
					v->data = x;
					v->next = p1;
					head = v;
					return;
				}
			}
			p1 = p1->next;
			i = 1;
		}
		if (p1 == NULL)
		{
			tail->next = p;
			tail = p;
		}
	}
}
void print()             //Вывод очереди
{
	Item* p = new Item;
	if (empty())
	{
		cout << "Очередь пуста" << endl;
	}
	else
	{
		cout << "Очередь = ";
		p = head;
		while (!empty())
		{
			if (p != NULL)
			{
				cout << p->data << " ";
				p = p->next;
			}
			else
			{
				cout << "NULL" << endl;
				return;
			}
		}
	}
}

void clear()           //Очистка очереди
{
	while (!empty())
	{
		pop();
	}
}
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int i = 1, choice = 1, value; head = NULL;  tail = NULL;
	while (choice != 0)
	{
		cout << "1 - добавить элемент" << endl;
		cout << "2 - получить элемент с начала" << endl;
		cout << "3 - извлечь элемент с начала" << endl;
		cout << "4 - вывести элементы" << endl;
		cout << "5 - очистить очередь" << endl;
		cout << "0 - выход" << endl;
		cout << "Выберите действие: ";  cin >> choice;

		switch (choice)
		{
		case 1: cout << "Введите элемент:  "; cin >> value;
			insert(value); print();  break;
		case 2: getFromHead(); break;
		case 3: pop();  break;
		case 4: print();  break;
		case 5: clear();    break;
		}
	}
	return 0;
}