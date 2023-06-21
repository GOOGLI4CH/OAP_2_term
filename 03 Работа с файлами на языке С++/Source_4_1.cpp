#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	ifstream fin("dataFileEx4.txt");
	ofstream fout("resultFileEx4.txt");

	if (fin.fail() || fout.fail())
	{
		cout << "Ошибка открытия файлов!" << endl;
		exit(1);
	}
	else
	{
		cout << "Файлы открыты!" << endl;
	}

	string str;
	int counter = 0;

	while (getline(fin, str))
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] >= '1' && str[i] <= '9')
			{
				counter++;
				break;
			}
		}
		if (counter == 0)
		{
			fout << str << "\n";
		}

		counter = 0;
	}

	cout << "Строки записаны в файл" << endl;
	fin.close();
	fout.close();

	ifstream fileForCount("resultFileEx4.txt");
	string tmp;
	counter = 0;

	while (getline(fileForCount, tmp))
	{
		if (tmp[0] == 'A' || tmp[0] == 'А')
		{
			counter++;
		}
	}

	cout << "Количество строк, которые начинаются на букву «А» в файле FILE2: " << counter << endl;

	fout.close();
}
