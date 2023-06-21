#include <iostream>
#include <string>

struct LetterCount
{
    char letter;
    int count;
};

const int TABLE_SIZE = 26;

class HashTable 
{
public:
    HashTable();
    void insert(char letter);
    bool search(char letter);
    void print();

private:
    LetterCount m_data[TABLE_SIZE];
    int hash(char letter);
};

HashTable::HashTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        m_data[i].letter = 'a' + i;
        m_data[i].count = 0;
    }
}

int HashTable::hash(char letter) 
{
    return (letter - 'a') % TABLE_SIZE;
}

void HashTable::insert(char letter) 
{
    int index = hash(letter);
    while (m_data[index].count > 0 && m_data[index].letter != letter) 
    {
        index = (index + 1) % TABLE_SIZE;
    }
    m_data[index].letter = letter;
    m_data[index].count++;
}

bool HashTable::search(char letter) 
{
    int index = hash(letter);
    while (m_data[index].count > 0)
    {
        if (m_data[index].letter == letter)
        {
            return true;
        }
        index = (index + 1) % TABLE_SIZE;
    }
    return false;
}

void HashTable::print() 
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        std::cout << m_data[i].letter << ": " << m_data[i].count << std::endl;
    }
}

int main() 
{
    setlocale(LC_ALL, "rus");
    std::string str;
    std::cout << "Введите строку" << std::endl;
    std::getline(std::cin, str);
    HashTable table;
    for (char c : str) 
    {
        table.insert(c);
    }
    table.print();

    char targetLetter;
    std::cout << "Введите искомую букву "; std::cin >> targetLetter;
    if (table.search(targetLetter))
    {
        std::cout << "Буква " << targetLetter << " найдена" << std::endl;
    }
    else
    {
        std::cout << "Буква " << targetLetter << " не найдена" << std::endl;
    }

    return 0;
}
