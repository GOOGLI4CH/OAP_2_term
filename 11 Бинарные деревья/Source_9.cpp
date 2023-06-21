#include <iostream>
#include <string>
#include "BinaryTree.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int choice = 0, key = 0, value = 0;
	Tree<int> tree;
	do
	{
		cout << "Выберите вариант:" << endl;
		cout << "1 - Добавить узел" << endl;
		cout << "2 - Удалить узел" << endl;
		cout << "3 - Найти узел" << endl;
		cout << "4 - Вывести дерево" << endl;
		cout << "5 - Очистить дерево" << endl;
		cout << "6 - Кол-во вершин значение которых равно k" << endl;
		cout << "0 - Выход" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			int num = 0;
			cout << "Сколько элементов вы хотите добавить? "; cin >> num;
			for (int i = 0; i < num; i++)
			{
				cout << "Введите число: "; cin >> value;
				cout << "Введите ключ: "; cin >> key;
				tree.insert(value, key);
			}
			break;
		}
		case 2:
		{
			cout << "Введите ключ: "; cin >> key;
			tree.remove(key);
			break;
		}
		case 3:
		{
			cout << "Введите ключ: "; cin >> key;
			tree.printNode(tree.search(key));
			break;
		}
		case 4:
		{
			cout << "Дерево:" << endl;
			tree.print(tree.getRoot());
			break;
		}
		case 5:
		{
			tree.clear();
			break;
		}
		case 6:
		{
			int k;
			cout << "Введите k: "; cin >> k;
			cout << "Количество вершин равных k: " << tree.count(tree.getRoot(), k) << endl;
			break;
		}
		default:
		{
			break;
		}
		}
	} while (choice != 0);
}