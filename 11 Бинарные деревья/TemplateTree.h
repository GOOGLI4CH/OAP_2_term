#pragma once
#include <iostream>
#include <iomanip>

template<typename T>
class Tree
{
private:
	class Node
	{
	public:
		T data;
		int key;
		Node* left;
		Node* right;

		Node(T data = T(), int key = 0, Node* left = nullptr, Node* right = nullptr)
		{
			this->data = data;
			this->key = key;
			this->left = left;
			this->right = right;
		}
	};

	Node* root;

public:
	Tree();
	~Tree();
	void insert(const T&, const int&);
	void print(Node*, int indent = 0) const;
	void printNode(Node*) const;
	void clear(Node*);
	void clear();
	void remove(const int&);
	int count_even(Node*) const;
	int count_even() const;
	int count_letters(Node*, const char&) const;
	int count_letters(const char&) const;
	int count_node(Node*) const;
	int count_right_nodes(Node*) const;
	int count_right_nodes() const;
	int sumOfLeaves(Node*) const;
	int sumOfLeaves() const;
	double sum_element(Node*) const;
	double average() const;
	Tree<T>::Node* getRoot();
	Tree<T>::Node* search(const int&);
	Tree<T>::Node* removeNode(Node*, const int&);
	Tree<T>::Node* minValueNode(Node*);
	int count(Node*, T) const;
};