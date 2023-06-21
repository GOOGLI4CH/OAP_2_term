#pragma once
#include <iostream>
#include <fstream>

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
	void print() const;
	void printNode(Node*) const;
	void clear(Node*);
	void clear();
	void remove(const int&);
	void mixedTraversal(Node*) const;
	void mixedTraversal() const;
	void in_orderTraversal(Node*) const;
	void in_orderTraversal() const;
	void toFile(Node*, std::ostream&);
	void writeToFile();
	void readFromFile();
	int count_even(Node*) const;
	int count_even() const;
	int count_letters(Node*, const char&) const;
	int count_letters(const char&) const;
	int getHeight(Node*);
	bool isBalanced(Node*);
	Node* getRoot();
	Node* search(const int&);
	Node* removeNode(Node*, const int&);
	Node* minValueNode(Node*);
};