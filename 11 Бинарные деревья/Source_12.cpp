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
		cout << "6 - Подсчёт количества букв" << endl;
		cout << "7 - Количество чётных узлов" << endl;
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
			char c;
			cout << "Введите символ: "; cin >> c;
			cout << "Количество символов " << c << " равно " << tree.count_letters(c) << endl;
			break;
		}
		case 7:
		{
			cout << "Количество чётных узлов: " << tree.count_even() << endl;
			break;
		}
		default:
		{
			break;
		}
		}
	} while (choice != 0);
}