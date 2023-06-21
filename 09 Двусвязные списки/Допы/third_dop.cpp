#include <iostream>

class Node {
public:
    int data;
    Node* next;
};
int main()
{

    int n = 10; // Количество людей в круге
    int k = 3; // Каждый k-й человек будет удален

    // Создание списка и заполнение его людьми
    Node* head = new Node();
    head->data = 1;
    Node* curr = head;
    for (int i = 2; i <= n; i++) {
        Node* new_node = new Node();
        new_node->data = i;
        curr->next = new_node;
        curr = new_node;
    }
    curr->next = head; // Соединяем последний элемент списка с первым, образуя круг
    // Отсчет и удаление каждого k-го человека
    Node* prev = nullptr;
    curr = head;
    while (curr->next != curr) { // Пока в списке остались люди
        for (int i = 1; i <= k; i++) { // Отсчет до k-го человека
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next; // Удаление k-го человека
        delete curr;
        curr = prev->next;
    }
    int last_person = head->data;
    std::cout << "Last person remaining is " << last_person << std::endl;
}

#include <iostream>
#include <vector>

using namespace std;

class Node 
{
public:
    int val;
    Node* next;
    Node(int value) : val(value), next(nullptr) {}
};

vector<int> removePeople(int n, int k)
{
    vector<int> res;
    Node* head = new Node(1);
    Node* cur = head;
    for (int i = 2; i <= n; i++) 
    {
        cur->next = new Node(i);
        cur = cur->next;
    }
    cur->next = head;
    cur = head;
    while (cur->next != cur) {
        for (int i = 1; i < k - 1; i++) 
        {
            cur = cur->next;
        }
        res.push_back(cur->next->val);
        cur->next = cur->next->next;
        cur = cur->next;
    }
    res.push_back(cur->val);
    return res;
}

int main() {
    int n = 100;
    int k = 3;
    vector<int> res = removePeople(n, k);
    cout << "Order of removal: ";
    for (int i = 0; i < res.size(); i++) 
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}


#include <iostream>
using namespace std;

struct Node 
{
	int data;
	Node* next;
	Node(int d) : data(d), next(nullptr) {}
};

void josephusCircle(int n, int k) 
{
	Node* head = new Node(1);
	Node* prev = head;

	for (int i = 2; i <= n; i++) 
	{
		prev->next = new Node(i);
		prev = prev->next;
	}

	prev->next = head;
	Node* curr = head;
	Node* prev2 = prev;

	while (curr->next != curr)
	{
		for (int i = 1; i < k; i++)
		{
			prev2 = curr;
			curr = curr->next;
		}

		prev2->next = curr->next;
		delete curr;
		curr = prev2->next;

		cout << curr->data << " ";
	}

	cout << "Последний: " << curr->data << endl;
	delete curr;
}

int main() 
{
	setlocale(LC_ALL, "rus");
	int n = 100, k = 3;
	cout << "Последовательность:" << endl;
	josephusCircle(n, k);
	cout << endl;
	return 0;
}