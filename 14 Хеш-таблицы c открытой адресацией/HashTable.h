#pragma once
#include "HashTableTemplate.h"

template<class Data, class Key>
HashTable<Data, Key>::HashTable(int max_size)
{
	capacity = max_size;
	size = 0;
	table = new Node * [max_size] {nullptr};
}

template<class Data, class Key>
HashTable<Data, Key>::~HashTable()
{
	for (int i = 0; i < capacity; i++)
	{
		delete table[i];
	}
	delete[] table;
}

template<class Data, class Key>
int HashTable<Data, Key>::hash(const Key& key)
{
	return static_cast<int>(key) % capacity;
}

template<class Data, class Key>
int HashTable<Data, Key>::hash(const Key& key, const int& size)
{
	return static_cast<int>(key) % size;
}

template<class Data, class Key>
void HashTable<Data, Key>::resize(const int& new_capacity)
{
	Node** new_table = new Node * [new_capacity] {nullptr};

	for (int i = 0; i < capacity; i++)
	{
		if (table[i] != nullptr)
		{
			int index = hash(table[i]->key, new_capacity);

			if (new_table[index] == nullptr)
			{
				new_table[index] = table[i];
			}
			else
			{
				int probe = 0;

				while (probe < new_capacity)
				{
					index = (index + 1) % new_capacity;
					if (new_table[index] == nullptr)
					{
						new_table[index] = table[i];
						break;
					}
					probe++;
				}
			}
		}
	}

	delete[] table;
	table = new_table;
	capacity = new_capacity;
}

template<class Data, class Key>
void HashTable<Data, Key>::print()
{
	for (int i = 0; i < capacity; i++)
	{
		Node* current = table[i];
		if (current != nullptr)
		{
			std::cout << "Key: " << current->key << " Data: " << current->value << std::endl;
		}
	}
}

template<class Data, class Key>
void HashTable<Data, Key>::insert(const Data& value, const Key& key)
{
	if (size == capacity / 2)
	{
		resize(capacity * 2);
	}

	int index = hash(key);

	if (table[index] == nullptr)
	{
		table[index] = new Node(value, key);
		size++;
		return;
	}

	int probe = 0;

	while (probe < capacity)
	{
		index = (index + 1) % capacity;
		if (table[index] == nullptr)
		{
			table[index] = new Node(value, key);
			size++;
			return;
		}
		probe++;
	}
}

template<class Data, class Key>
typename HashTable<Data, Key>::Node* HashTable<Data, Key>::search(const Key& key)
{
	int index = hash(key), i = 0;
	while (i < capacity)
	{
		if (table[index] != nullptr && table[index]->key == key)
		{
			return table[index];
		}
		i++;
		index = (index + 1) % capacity;
	}
	return nullptr;
}

template<class Data, class Key>
void HashTable<Data, Key>::remove(const Key& key)
{
	int index = hash(key), i = 0;
	while (i < capacity)
	{
		if (table[index] != nullptr && table[index]->key == key)
		{
			delete table[index];
			table[index] = nullptr;
		}
		i++;
		index = (index + 1) % capacity;
	}
}

template<class Data, class Key>
Data& HashTable<Data, Key>::getValue(Node* node) { return node->value; }

template<class Data, class Key>
bool HashTable<Data, Key>::isEmpty() { return size == 0; }