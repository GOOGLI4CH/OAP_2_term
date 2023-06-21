#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	string str;
	cout << "Введите строку, состоящую из цифр и слов, разделенных пробелами: ";
	getline(cin, str);

	ofstream fout("fileEx4.txt");
	ifstream fin("fileEx4.txt");

	if (fin.fail() || fout.fail())
	{
		cout << "Ошибка открытия файлов!" << endl;
		exit(1);
	}
	else
	{
		cout << "Файлы открыты!" << endl;
	}
	
	fout << str;
	fout.close();

	int max = 0;
	while (getline(fin, str))
	{
		int counter = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ')
			{
				counter++;
			}
			else
			{
				if (counter > max)
				{
					max = counter;
				}
				counter = 0;
			}
		}
		if (counter > max)
		{
			max = counter;
		}
	}
	cout << "Количество символов в самом длинном слове: " << max << endl;
	
	fin.close();
	fin.open("fileEx4.txt");
	
	while (getline(fin, str))
	{
		int counter = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ')
			{
				counter++;
			}
			else
			{
				if (counter == max)
				{
					for (int j = i - counter; j < i; j++)
					{
						cout << str[j];
					}
					cout << endl;
				}
				counter = 0;
			}
		}

	}
	fin.close();
}