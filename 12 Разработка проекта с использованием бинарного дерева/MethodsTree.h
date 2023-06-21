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
void Tree<T>::print() const
{
	if (!root)
	{
		std::cout << "Дерево пустое" << std::endl;
		return;
	}
	Node* current = root;
	Node* prev = nullptr;
	while (current)
	{
		if (!current->left)
		{
			std::cout << current->data << " ";
			current = current->right;
		}
		else
		{
			prev = current->left;
			while (prev->right && prev->right != current)
			{
				prev = prev->right;
			}
			if (!prev->right)
			{
				prev->right = current;
				current = current->left;
			}
			else
			{
				prev->right = nullptr;
				std::cout << current->data << " ";
				current = current->right;
			}
		}
	}
	std::cout << std::endl;
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

template<typename T>
void Tree<T>::mixedTraversal(Node* node) const
{
	if (node == nullptr) { return; }
	if (node->left != nullptr) { mixedTraversal(node->left); }
	if (node->right != nullptr) { mixedTraversal(node->right); }
	std::cout << node->data << " ";
}

template<typename T>
void Tree<T>::mixedTraversal() const { mixedTraversal(root); }

template<typename T>
void Tree<T>::in_orderTraversal(Node* node) const
{
	if (node == nullptr) { return; }
	in_orderTraversal(node->left);
	std::cout << node->data << " ";
	in_orderTraversal(node->right);
}

template<typename T>
void Tree<T>::in_orderTraversal() const { in_orderTraversal(root); }

template<typename T>
void Tree<T>::toFile(Node* node, std::ostream& out)
{
	if (node != nullptr)
	{
		out << node->key << " " << node->data << std::endl;
		toFile(node->left, out);
		toFile(node->right, out);
	}
}

template<typename T>
void Tree<T>::writeToFile()
{
	std::ofstream file("data.txt");

	if (!file.is_open())
	{
		std::cout << "Ошибка открытия файла" << std::endl;
		return;
	}

	toFile(root, file);
	file.close();
}

template<typename T>
void Tree<T>::readFromFile()
{
	std::ifstream file("data.txt");

	if (!file.is_open())
	{
		std::cout << "Ошибка открытия файла" << std::endl;
		return;
	}

	clear();
	T value;
	int key;

	while (file >> key)
	{
		file >> value;
		insert(value, key);
	}

	file.close();
}

template<typename T>
bool Tree<T>::isBalanced(Node* node) 
{
	if (node == nullptr) { return true; }
	int left = getHeight(node->left);
	int right = getHeight(node->right);
	if (std::abs(left - right) <= 1 && isBalanced(node->right) && isBalanced(node->left)) { return true; }
	return false;
}

template<typename T>
int Tree<T>::getHeight(Node* node) 
{
	if (node == nullptr) { return 0; }
	int left = getHeight(node->left);
	int right = getHeight(node->right);
	if (std::abs(left - right) > 1) { return 0; }
	return std::max(left, right) + 1;
}

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