#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Subscriber
{
    string phoneNumber;
    string owner;
    string tariff;

    bool operator<(const Subscriber& other) const
    {
        return phoneNumber < other.phoneNumber;
    }
};

template <typename T>
class BinaryTree
{
private:
    struct Node
    {
        T data;
        Node* left;
        Node* right;

        Node(const T& data) :
            data(data), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insert(Node*& node, const T& data) {
        if (!node)
        {
            node = new Node(data);
        }
        else if (data < node->data)
        {
            insert(node->left, data);
        }
        else
        {
            insert(node->right, data);
        }
    }

    void print(Node* node)
    {
        if (node)
        {
            print(node->left);
            cout << node->data.phoneNumber << " " << node->data.owner << " " << node->data.tariff << endl;
            print(node->right);
        }
    }

    Node* find(Node* node, const string& phoneNumber)
    {
        if (!node) {
            return nullptr;
        }
        else if (phoneNumber == node->data.phoneNumber)
        {
            return node;
        }
        else if (phoneNumber < node->data.phoneNumber)
        {
            return find(node->left, phoneNumber);
        }
        else {
            return find(node->right, phoneNumber);
        }
    }

    void countTariffs(Node* node, map<string, int>& counter)
    {
        if (node)
        {
            countTariffs(node->left, counter);
            counter[node->data.tariff]++;
            countTariffs(node->right, counter);
        }
    }

public:
    BinaryTree() :
        root(nullptr) {}

    void insert(const T& data)
    {
        insert(root, data);
    }

    void print()
    {
        print(root);
    }

    Subscriber* find(const string& phoneNumber)
    {
        Node* node = find(root, phoneNumber);
        return node ? &node->data : nullptr;
    }

    string mostPopularTariff()
    {
        map<string, int> counter;
        countTariffs(root, counter);

        string mostPopular;
        int maxCount = 0;
        for (const auto& entry : counter)
        {
            if (entry.second > maxCount)
            {
                mostPopular = entry.first;
                maxCount = entry.second;
            }
        }

        return mostPopular;
    }
};

int main()
{

    setlocale(LC_ALL, "rus");
    BinaryTree<Subscriber> tree;

    tree.insert({ "375291234567", "Первый", "Средняк" });
    tree.insert({ "375331212121", "Второй", "Средняк" });
    tree.insert({ "375449894744", "Третий", "База" });
    tree.insert({ "375291245324", "Четвёртый", "Крутой" });

    cout << "Все абоненты:" << endl;
    tree.print();

    cout << "Владелец номера 375331212121:  " << tree.find("375331212121")->owner << endl;

    cout << "Самый популярный тариф: " << tree.mostPopularTariff() << endl;
}