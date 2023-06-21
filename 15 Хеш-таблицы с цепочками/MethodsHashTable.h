#pragma once
#include "TemplateHashTable.h"

template<class Data, class Key>
HashTable<Data, Key>::HashTable(const int max_size)
{
	capacity = max_size;
	size = 0;
	table = new Node * [capacity] {nullptr};
}

template<class Data, class Key>
HashTable<Data, Key>::~HashTable()
{
	if (size != 0)
	{
		for (int i = 0; i < capacity; i++)
		{
			Node* current = table[i];
			while (current != nullptr)
			{
				Node* temp = current;
				current = current->next;
				delete temp;
			}
		}
		delete[] table;
	}
}

template<class Data, class Key>
void HashTable<Data, Key>::insert(const Data& data, const Key& key)
{
	int index = hash(key);
	Node* current = table[index];
	if (table[index] == nullptr)
	{
		current = new Node(data, key);
		table[index] = current;
	}
	else
	{
		while (current != nullptr)
		{
			if (current->next == nullptr)
			{
				Node* new_element = new Node(data, key);
				current->next = new_element;
				new_element->prev = current;
				break;
			}
			current = current->next;
		}
	}
	size++;
}

template<class Data, class Key>
typename HashTable<Data, Key>::Node* HashTable<Data, Key>::search(const Key& key)
{
	int index = hash(key);
	Node* current = table[index];

	if (current != nullptr && current->key == key)
	{
		return current;
	}
	else if (current != nullptr && current->key != key)
	{
		while (current != nullptr)
		{
			current = current->next;
			if (current != nullptr && current->key == key)
			{
				return current;
			}
		}
	}

	return nullptr;
}

template<class Data, class Key>
void HashTable<Data, Key>::remove(const Key& key)
{
	int index = hash(key);
	Node* current = table[index];

	if (current != nullptr && current->key == key)
	{
		Node* temp = current;
		table[index] = current->next;
		delete temp;
	}
	else if (current != nullptr && current->key != key)
	{
		while (current != nullptr)
		{
			current = current->next;
			if (current->key == key)
			{
				if (current->next != nullptr)
				{
					current->next->prev = current->prev;
				}
				if (current->prev != nullptr)
				{
					current->prev->next = current->next;
				}
				delete current;
				break;
			}
		}
	}
	size--;
}

template<class Data, class Key>
void HashTable<Data, Key>::print()
{
	if (size == 0)
	{
		std::cout << "Hash table is empty" << std::endl;
		return;
	}
	for (int i = 0; i < capacity; i++)
	{
		Node* current = table[i];
		if (current != nullptr)
		{
			std::cout << "Index: " << i << ". Data: " << current->value << "\t\tKey: " << current->key << std::endl;
			while (current->next != nullptr)
			{
				current = current->next;
				std::cout << "\t\tData: " << current->value << "\t\tKey: " << current->key << std::endl;
			}
		}
	}
}

template<class Data, class Key>
void HashTable<Data, Key>::printNode(Node* node)
{
	if (node == nullptr)
	{
		std::cout << "No element" << std::endl;
		return;
	}
	std::cout << "Data: " << node->value << " Key: " << node->key << std::endl;
}

std::ostream& operator<<(std::ostream& out, const apartments& value)
{
	out << "Номер квартиры: " << value.apartment_number << " Жильцы: " << value.lodgers;
	return out;
}