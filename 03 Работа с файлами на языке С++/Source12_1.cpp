#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	ifstream fin("FILE1.txt");
	ofstream fout("FILE2.txt");

	if (fin.fail())				//Проверка на открытие файлов (методом из лабы).
	{
		cout << "Ошибка открытия файла FILE1.txt" << endl;
		exit(1);
	}
	if (fout.fail())
	{
		cout << "Ошибка открытия файла FILE2.txt" << endl;
		exit(1);
	}
	if (!fout.fail() && !fin.fail())
	{
		cout << "Файлы открыты!" << endl;
	}

	string word, str;

	fin >> word;			//Считывание первого слова из файла.
	getline(fin, str);		//Считывание первой строки из файла.

	fout << word << str << "\n";	//Запись первой строки в файл, т.к. она по умолчанию содержит первое слово.
	while (!fin.eof())
	{
		getline(fin, str);				//Считывание строки из файла.
		if (str.find(word) != -1)		//Проверка на наличие слова в строке.
		{
			fout << str << "\n";
		}
	}

	cout << "Данные записаны в файл FILE2.txt" << endl;

	fin.close();
	fout.close();

	ifstream fileForCount("FILE2.txt");

	if (fileForCount.fail())				//Проверка на открытие файла.
	{
		cout << "Ошибка открытия файла FILE2.txt (чтение)" << endl;
		exit(1);
	}
	if (!fileForCount.fail())
	{
		cout << "Файл FILE2.txt открыт для чтения" << endl;
	}

	int counter = 0;
	char ch;
	
	while (!fileForCount.eof())
	{
		fileForCount.get(ch);
		if (ch == '\n')
		{
			counter++;
		}
	}

	fileForCount.close();

	ifstream fileForOutput("FILE2.txt");
	
	for (int i = 0; i < (counter - 1); i++)
	{
		getline(fileForOutput, str);				//Переменная str сохранит последнюю строку файла (кроме \n, т.к. counter - 1).
	}

	string consonant = "BbCcDdFfGgHhJjKkLlMmNnPpQqRrSsTtVvWwXxYyZz";	//Все согласные англ. яз. (Y как согл. так и гл.)
	counter = 0;
	
	for (int i = 0; i < str.length(); i++)
	{
		if (consonant.find(str[i]) != -1)		//Проверка на наличие согласной в строке.
		{
			counter++;
		}
	}

	cout << "Количество согласных букв в последней строке файла FILE2.txt = " << counter;

	fileForOutput.close();
}