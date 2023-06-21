#include <iostream>
#include <fstream>
#include <string>

const int TABLE_SIZE = 100;

struct HashNode {
    int key;
    HashNode* next;
    HashNode(int k) : key(k), next(nullptr) {}
};

class HashTable {
public:
    HashTable();
    ~HashTable();
    void insert(int key);
    bool search(int key);

private:
    HashNode** m_data;
    int hash(int key)
    {
        return key % TABLE_SIZE;
    }
};

HashTable::HashTable() {
    m_data = new HashNode * [TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        m_data[i] = nullptr;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* node = m_data[i];
        while (node != nullptr) {
            HashNode* prev = node;
            node = node->next;
            delete prev;
        }
    }
    delete[] m_data;
}

void HashTable::insert(int key) {
    int index = hash(key);
    HashNode* node = new HashNode(key);
    if (m_data[index] != nullptr) {
        node->next = m_data[index];
    }
    m_data[index] = node;
}

bool HashTable::search(int key) {
    int index = hash(key);
    HashNode* node = m_data[index];
    while (node != nullptr) {
        if (node->key == key)
        {
            return true;
        }
    }
    return false;
}

void readNumbers(const std::string& filename, HashTable& table) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file " << filename << std::endl;
        return;
    }

    int number;
    while (file >> number) {
        table.insert(number);
    }

    file.close();
}

int main()
{
    setlocale(LC_ALL, "rus");

    std::string path = "data.txt";
    HashTable table;

    readNumbers(path, table);

    int num;
    std::cout << "Введите искомое значение: "; std::cin >> num;

    if (table.search(num))
    {
        std::cout << "Элемент " << num << " найден" << std::endl;
    }
    else
    {
        std::cout << "Элемент " << num << " не найден" << std::endl;
    }
}