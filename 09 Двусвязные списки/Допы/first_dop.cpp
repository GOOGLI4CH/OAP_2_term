#include <iostream>
#include <string>

using namespace std;

struct country
{
	string name;
	string capital;
	string population;
	string square;
	string surname;

	country()
	{
		this->name = name;
		this->capital = capital;
		this->population = population;
		this->square = square;
		this->surname = surname;
	}
	
	void setCountry()
	{
		cin.ignore();
		cout << "Введите название государства: ";
		getline(cin, name);
		cout << "Введите название столицы: ";
		getline(cin, capital);
		cout << "Введите население: ";
		getline(cin, population);
		cout << "Введите площадь: ";
		getline(cin, square);
		cout << "Введите фамилию президента: ";
		getline(cin, surname);
	}
};

template<typename T>
class List
{
private:
	template<typename T>
	class Node
	{
	public:
		T data;
		Node* next;
		Node* prev;

		Node(T data = T(), Node* prev = nullptr, Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
	};

	int size;
	Node<T>* head;
	Node<T>* tail;

public:
	List();
	~List();

	/*<------------------standard methods------------------>*/

	T& operator[](const int index);
	void delete_value(T data);
	void push_back(T data);
	void push_front(T data);
	void pop_back();
	void pop_front();
	void printList();
	void clear();
	int getSize();
	T& getFront();
	T& getBack();
	T& search(T data);

	/*<------------------methods for struct------------------>*/

	friend bool operator==(const country& c1, const country& c2);
	friend ostream& operator<<(ostream& out, const country& data);
};

/*<------------------standard methods------------------>*/
template<typename T>
List<T>::List()
{
	size = 0;
	head = tail = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = tail = new Node<T>(data);
	}
	else
	{
		Node<T>* ptr = new Node<T>(data);

		tail->next = ptr;
		ptr->next = nullptr;
		ptr->prev = tail;
		tail = ptr;
	}
	size++;
}

template<typename T>
void List<T>::push_front(T data)
{
	if (head == nullptr)
	{
		head = tail = new Node<T>(data);
	}
	else
	{
		Node<T>* ptr = new Node<T>(data);

		head->prev = ptr;
		ptr->prev = nullptr;
		ptr->next = head;
		head = ptr;
	}

	size++;
}

template<typename T>
void List<T>::pop_back()
{
	Node<T>* temp = tail;
	tail = tail->prev;
	delete temp;
	size--;
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->next;
	delete temp;
	size--;
}

template<typename T>
void List<T>::clear()
{
	while (size)
	{
		pop_back();
	}
}

template<typename T>
void List<T>::printList()
{
	Node<T>* current = this->head;

	while (current != nullptr)
	{
		cout << current->data << endl;
		current = current->next;
	}
}

template<typename T>
int List<T>::getSize() { return size; }

template<typename T>
T& List<T>::getFront() { return head->data; }

template<typename T>
T& List<T>::getBack() { return tail->data; }

template<typename T>
T& List<T>::operator[](const int index)
{
	Node<T>* current = this->head;
	int counter = 0;

	while (current != nullptr)
	{
		if (counter == index) { return current->data; }
		current = current->next;
		counter++;
	}
}

template<typename T>
T& List<T>::search(T data)
{
	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (current->data == data) { return current->data; }
		current = current->next;
	}
}

template<typename T>
void List<T>::delete_value(T data)
{
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (current->data == data)
		{
			Node<T>* temp = current;
			if (current->next != nullptr) { current->next->prev = current->prev; }
			if (current->prev != nullptr) { current->prev->next = current->next; }
			else { head = current->next; }
			delete temp;
			break;
		}
		current = current->next;
	}
}

/*<------------------methods for struct------------------>*/

ostream& operator<<(ostream& out, const country& data)
{
	out << "Название государства: " << data.name << endl;
	out << "Столица государства: " << data.capital << endl;
	out << "Население: " << data.population << endl;
	out << "Площадь: " << data.square << endl;
	out << "Фамилия президента: " << data.surname << endl;

	return out;
}

bool operator==(const country& c1, const country& c2) { return c1.name == c2.name && c1.capital == c2.capital && c1.population == c2.population && c1.square == c2.square && c1.surname == c2.surname; }


int main()
{
	setlocale(LC_ALL, "rus");
	
	List<country> list;
	country element;
	
	int choice;
	do
	{
		cout << "Выберите вариант: " << endl;
		cout << "1 - Добавить элемент в начало списка" << endl;
		cout << "2 - Добавить элемент в конец списка" << endl;
		cout << "3 - Удалить элемент в начале списка" << endl;
		cout << "4 - Удалить элемент в конце списка" << endl;
		cout << "5 - Вывести список" << endl;
		cout << "6 - Очистить список" << endl;
		cout << "7 - Вывести первый элемент списка" << endl;
		cout << "8 - Вывести последний элемент списка" << endl;
		cout << "9 - Найти элемент по значению" << endl;
		cout << "10 - Вывести размер списка" << endl;
		cout << "11 - Удалить элемент по значению" << endl;
		cout << "0 - Выход" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			element.setCountry();
			list.push_front(element);
			break;
		}
		case 2:
		{
			element.setCountry();
			list.push_back(element);
			break;
		}
		case 3:
		{
			list.pop_front();
			break;
		}
		case 4:
		{
			list.pop_back();
			break;
		}
		case 5:
		{
			list.printList();
			break;
		}
		case 6:
		{
			list.clear();
			break;
		}
		case 7:
		{
			cout << list.getFront() << endl;
			break;
		}
		case 8:
		{
			cout << list.getBack() << endl;
			break;
		}
		case 9:
		{
			element.setCountry();
			cout << endl << list.search(element) << endl;
			break;
		}
		case 10:
		{
			cout << "Размер списка: " << list.getSize() << endl;
			break;
		}
		case 11:
		{
			element.setCountry();
			list.delete_value(element);
			break;
		}
		case 0:
		{
			break;
		}
		default:
		{
			cout << "Неверный ввод" << endl;
			break;
		}
		}
	} while (choice != 0);
}