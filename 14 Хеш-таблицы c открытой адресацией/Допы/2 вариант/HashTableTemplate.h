#pragma once
#include <iostream>
#include <ctime>

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
	
	int universal_hash(const Key&, const int&);
	int universal_hash(const Key&);
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