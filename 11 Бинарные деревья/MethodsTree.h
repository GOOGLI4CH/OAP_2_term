#pragma once
#include "TemplateTree.h"

template<typename T>
Tree<T>::Tree() { root = nullptr; }

template<typename T>
Tree<T>::~Tree() { clear(getRoot()); }

template<typename T>
void Tree<T>::insert(const T& data, const int& key)
{
	if (!root)
	{
		root = new Node(data, key);
		return;
	}
	else
	{
		Node* current = root;
		while (current)
		{
			if (key < current->key)
			{
				if (!current->left)
				{
					current->left = new Node(data, key);
					break;
				}
				else { current = current->left; }
			}
			else if (key > current->key)
			{
				if (!current->right)
				{
					current->right = new Node(data, key);
					break;
				}
				else { current = current->right; }
			}
			else { break; }
		}
	}
}

template<typename T>
void Tree<T>::print(Node* node, int indent) const
{
	if (node == nullptr) { return; }
	if (node->right != nullptr) { print(node->right, indent + 4); }
	if (indent > 0) { std::cout << std::setw(indent) << " "; }
	if (node->right != nullptr) { std::cout << " /\n" << std::setw(indent) << " "; }
	std::cout << node->data << "\n ";
	if (node->left != nullptr) 
	{
		std::cout << std::setw(indent) << " " << " \\\n";
		print(node->left, indent + 4);
	}
}

template<typename T>
void Tree<T>::printNode(Node* node) const
{
	if (node) { std::cout << node->data << std::endl; }
	else { std::cout << "Не найдено" << std::endl; }
}

template<typename T>
void Tree<T>::clear(Node* node)
{
	if (!node) { return; }
	clear(node->left);
	clear(node->right);
	delete node;
}

template<typename T>
void Tree<T>::clear()
{
	clear(getRoot());
	root = nullptr;
}

template<typename T>
typename Tree<T>::Node* Tree<T>::search(const int& key)
{
	if (!root)
	{
		std::cout << "Дерево пустое" << std::endl;
		return root;
	}
	else
	{
		Node* current = root;

		while (current)
		{
			if (key < current->key) { current = current->left; }
			else if (key > current->key) { current = current->right; }
			else { return current; }
		}
	}
}

template<typename T>
typename Tree<T>::Node* Tree<T>::getRoot() { return root; }

template<typename T>
void Tree<T>::remove(const int& key) { removeNode(root, key); }

template<typename T>
typename Tree<T>::Node* Tree<T>::removeNode(Node* node, const int& key)
{
	if (!node) { return node; }
	if (key < node->key) { node->left = removeNode(node->left, key); }
	else if (key > node->key) { node->right = removeNode(node->right, key); }
	else
	{
		if (node->left == nullptr)
		{
			Node* temp = node->right;
			delete node;
			return temp;
		}
		else if (node->right == nullptr)
		{
			Node* temp = node->left;
			delete node;
			return temp;
		}
		Node* temp = minValueNode(node->right);
		node->key = temp->key;
		node->right = removeNode(node->right, temp->key);
	}
	return node;
}

template<typename T>
typename Tree<T>::Node* Tree<T>::minValueNode(Node* node)
{
	Node* current = node;
	while (current->left != nullptr) { current = current->left; }
	return current;
}

template<typename T>
int Tree<T>::count_letters(Node* node, const char& value) const
{
	if (node == nullptr) { return 0; }
	int counter = 0;
	std::string str = std::string(node->data);
	for (char c : str)
	{
		if (c == value) { counter++; }
	}
	return counter + count_letters(node->left, value) + count_letters(node->right, value);
}

template<typename T>
int Tree<T>::count_letters(const char& value) const { return count_letters(root, value); }

/*<-------------------12 Вариант------------------->*/

template<typename T>
int Tree<T>::count_even(Node* node) const
{
	if (node == nullptr) { return 0; }
	int counter = 0;
	if (node->key % 2 == 0) { counter = 1; }
	return counter + count_even(node->left) + count_even(node->right);
}

template<typename T>
int Tree<T>::count_even() const { return count_even(root); }

/*<-------------------14 Вариант------------------->*/

template<typename T>
int Tree<T>::count_node(Node* node) const
{
	if (node == nullptr) { return 0; }
	int counter = 1;
	return counter + count_node(node->left) + count_node(node->right);
}

template<typename T>
double Tree<T>::sum_element(Node* node) const
{
	if (node == nullptr) { return 0; }
	double sum = double(node->data);
	return sum + sum_element(node->left) + sum_element(node->right);
}

template<typename T>
double Tree<T>::average() const { return sum_element(root) / count_node(root); }

/*<-------------------15 Вариант------------------->*/

template<typename T>
int Tree<T>::count_right_nodes(Node* node) const
{
	if (!node) { return 0; }
	if (node->right) { return 1 + count_right_nodes(node->right) + count_right_nodes(node->left); }
	else { return count_right_nodes(node->left); }
}

template<typename T>
int Tree<T>::count_right_nodes() const { return count_right_nodes(root); }

/*<-------------------16 Вариант------------------->*/

template<typename T>
int Tree<T>::sumOfLeaves(Node* node) const
{
	if (!node) { return 0; }
	if (!node->left && !node->right) { return node->data; }
	return sumOfLeaves(node->left) + sumOfLeaves(node->right);
}

template<typename T>
int Tree<T>::sumOfLeaves() const { return sumOfLeaves(root); }

/*<-------------------9 Вариант------------------->*/

template<typename T>
int Tree<T>::count(Node* node, T data) const
{
	if (node == nullptr) { return 0; }
	int counter = 0;
	if (node->data == data) { counter++; }
	counter += count(node->left, data);
	counter += count(node->right, data);
	return counter;
}