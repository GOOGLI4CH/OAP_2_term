//Вторая часть лабы (задание из второй таблицы)
#include <iostream>

using namespace std;

bool check(int num, int first, ...)			//возвращает 1, если есть отрицательные. возвращает 0, если нет отрицательных.
{
	int* ptr = &first;
	int counter = 0;

	for (int i = 0; i < num; i++)
	{

		if (*(ptr + i) > 0)
		{
			counter++;
		}
		//cout << *(ptr+i) << "\t" << (ptr+i) << endl;
		ptr++;
	}
	//cout << counter << endl;
	if (counter == num)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void deleting_negative(int num, int first, ...)		//удаление отрицательных (замена на 0)
{
	int* ptr = &first, * arr = new int[num], * newArr = new int[num];
	int counter = 0;

	cout << "первоначальный массив" << endl;
	for (int i = 0; i < num; i++)
	{
		*(arr + i) = *(ptr + i);		//запись аргументов в динамический массив.
		ptr++;

		cout << *(arr + i) << " ";

		if (*(arr + i) < 0)				//подсчет отрицательных элементов.
		{
			counter++;
		}
	}
	cout << endl;
	int j = 0;
	*newArr = *arr;								//запись первого элемента в новый массив.
	for (int i = 0; i < num; i++)
	{
		if (*(arr + i) >= 0)
		{
			*(newArr + j) = *(arr + i);			//запись положительных в новый массив.
			j++;
		}
	}
	
	int position = num - counter;		//позиция первого отрицательного элемента.
	for (int i = 0; i < counter; i++)
	{
		*(newArr + position) = 0;		//запись нулей в конец массива.
		position++;
	}

	cout << "результат" << endl;
	for (int i = 0; i < num; i++)
	{
		cout << *(newArr + i) << " ";
	}
	delete[] arr, newArr;
}

int main()
{
	setlocale(LC_ALL, "rus");

	if (check(5, -1, -2, -3, -4, 5))
	{
		cout << "есть отрицательные" << endl;

		deleting_negative(5, -1, -2, -3, -4, 5);		//вызов функции удаления отрицательных, параметры вводить те же, что и в функции check.
	}
	else
	{
		cout << "нет отрицательных" << endl;
	}
}