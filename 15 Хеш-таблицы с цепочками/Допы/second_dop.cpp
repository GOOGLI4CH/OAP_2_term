#include <iostream>
#include <fstream>
#include <string>

struct HashNode 
{
    std::string key;
    HashNode* next;
    HashNode(std::string k) : key(k), next(nullptr) {}
};

class HashTable
{
public:
    HashTable(const int&);
    ~HashTable();
    void insert(std::string key);
    void remove(char s);
    void print();
    bool search(std::string key);

private:
    HashNode** m_data;
    int TABLE_SIZE;
    int hash(std::string key)
    {
        int sum = 0;
        for (char c : key) 
        {
            sum ^= c;
        }
        return sum % TABLE_SIZE;
    }
};

HashTable::HashTable(const int& size)
{
    TABLE_SIZE = size;
    m_data = new HashNode * [TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        m_data[i] = nullptr;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        HashNode* node = m_data[i];
        while (node != nullptr) 
        {
            HashNode* prev = node;
            node = node->next;
            delete prev;
        }
    }
    delete[] m_data;
}

void HashTable::print()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (m_data[i] != nullptr)
        {
            std::cout << m_data[i]->key << std::endl;
        }
    }
}

void HashTable::insert(std::string key)
{
    int index = hash(key);
    HashNode* node = new HashNode(key);
    if (m_data[index] != nullptr) 
    {
        node->next = m_data[index];
    }
    m_data[index] = node;
}

bool HashTable::search(std::string key)
{
    int index = hash(key);
    HashNode* node = m_data[index];
    while (node != nullptr)
    {
        if (node->key == key)
        {
            return true;
        }
        node = node->next;
    }
    return false;
}

void HashTable::remove(char s)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (m_data[i] != nullptr)
        {
            if (m_data[i]->key[0] == s)
            {
                delete m_data[i];
                m_data[i] = nullptr;
            }
        }
    }
}

void readStr(const std::string& filename, HashTable& table)
{
    std::ifstream file(filename);
    if (!file) 
    {
        std::cerr << "Error opening file " << filename << std::endl;
        return;
    }

    std::string str;
    while (file >> str) 
    {
        table.insert(str);
    }

    file.close();
}

int main()
{
    setlocale(LC_ALL, "rus");

    std::string path = "data.txt";
    int size;
    std::cout << "Введите размер таблицы: "; std::cin >> size;
    HashTable table(size);

    readStr(path, table);
    table.print();
    std::string str;
    std::cout << "Введите искомое значение: "; std::cin >> str;

    if (table.search(str))
    {
        std::cout << "Элемент " << str << " найден" << std::endl;
    }
    else
    {
        std::cout << "Элемент " << str << " не найден" << std::endl;
    }

    char symbol;
    std::cout << "Введите символ: "; std::cin >> symbol;
    table.remove(symbol);

    table.print();
}