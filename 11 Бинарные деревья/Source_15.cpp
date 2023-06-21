#include <iostream>
#include <string>
#include "BinaryTree.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int choice = 0, key;
	Tree<string> tree;
	string str;

	do
	{
		cout << "Выберите вариант:" << endl;
		cout << "1 - Добавить узел" << endl;
		cout << "2 - Удалить узел" << endl;
		cout << "3 - Найти узел" << endl;
		cout << "4 - Вывести дерево" << endl;
		cout << "5 - Очистить дерево" << endl;
		cout << "6 - Подсчёт элементов правой ветви (15 вариант)" << endl;
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
				cin.ignore();
				cout << "Введите строку" << endl;
				getline(cin, str);
				cout << "Введите ключ: "; cin >> key;
				tree.insert(str, key);
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
			tree.print();
			break;
		}
		case 5:
		{
			tree.clear();
			break;
		}
		case 6:
		{
			cout << "Количество элементов в правой ветви: " << tree.count_right_nodes() << endl;
			break;
		}
		default:
		{
			break;
		}
		}
	} while (choice != 0);
}