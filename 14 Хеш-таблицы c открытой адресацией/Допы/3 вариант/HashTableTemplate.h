#pragma once
#include <iostream>
#include <cmath>

template<class Data, class Key>
class HashTable
{
private:
	class Node
	{
	public:
		Data value;
		Key key;
		Node(const Data& value, const Key& key)
		{
			this->value = value;
			this->key = key;
		}
	};

	Node** table;
	int size;
	int capacity;

	int hash(const Key&);
	int hash(const Key& key, const int& size);
public:
	HashTable(int);
	~HashTable();
	void insert(const Data&, const Key&);
	void resize(const int&);
	void print();
	void remove(const Key&);
	bool isEmpty();
	Node* search(const Key&);
	Data& getValue(Node*);
};