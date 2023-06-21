#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

void print(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void bubble_sort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void quick_sort(int arr[], int left, int right) 
{
	int i = left, j = right;
	int pivot = arr[(left + right) / 2];

	while (i <= j) {
		while (arr[i] > pivot) 
		{
			i++;
		}
		while (arr[j] < pivot) 
		{
			j--;
		}
		if (i <= j) 
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}
	if (left < j) 
	{
		quick_sort(arr, left, j);
	}
	if (i < right) 
	{
		quick_sort(arr, i, right);
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int size;
	cout << "Введите размер массива A" << endl;
	cin >> size;

	int* A = new int[size];

	cout << "Массив A:" << endl;
	for (int i = 0; i < size; i++)
	{
		A[i] = rand() % 100;
		cout << A[i] << " ";
	}

	int index_max_element = 0, max = A[0];

	for (int i = 0; i < size - 1; i++)
	{
		if (max < A[i + 1])
		{
			max = A[i + 1];
			index_max_element = i + 1;
		}
	}
	index_max_element += 1;	//Т.к. в массив нужно записывать элементы стоящие правее максимального (НЕ ВКЛЮЧАЯ МАКСИМУМ)
	int* B = new int[(size - index_max_element) / 2];
	int j = 0;
	for (int i = index_max_element; i < size; i++)
	{
		if (i % 2 != 0)	//Учитывать, что индексация начинается с 0
		{
			B[j] = A[i];
			j++;
		}
	}

	cout << endl << "Массив B:" << endl;
	print(B, (size - index_max_element) / 2);

	int choice = 0;

	while (true)
	{
		cout << "Выберите вариант:" << endl;
		cout << "1 - сортировка пузырьком" << endl;
		cout << "2 - сортировка Хоара" << endl;
		cout << "0 - Выход" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			auto start = chrono::high_resolution_clock::now();
			bubble_sort(B, (size - index_max_element) / 2);
			auto end = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

			cout << endl << "Массив B (сортировка пузырьком):" << endl;
			print(B, (size - index_max_element) / 2);
			cout << endl << "Сортировка пузырьком заняла " << duration.count() << " ms" << endl;

			j = 0;
			for (int i = index_max_element; i < size; i++)
			{
				if (i % 2 != 0)	//Учитывать, что индексация начинается с 0
				{
					B[j] = A[i];
					j++;
				}
			}
			break;
		}
		case 2:
		{
			auto start = chrono::high_resolution_clock::now();
			quick_sort(B, 0, (((size - index_max_element) / 2) - 1));
			auto end = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

			cout << endl << "Массив B (сортировка Хоара):" << endl;
			print(B, (size - index_max_element) / 2);

			cout << endl << "Сортировка Хоара заняла " << duration.count() << " ms" << endl;

			j = 0;
			for (int i = index_max_element; i < size; i++)
			{
				if (i % 2 != 0)	//Учитывать, что индексация начинается с 0
				{
					B[j] = A[i];
					j++;
				}
			}
			break;
		}
		case 0:
			return 0;
		default:
		{
			cout << "Некорректное значение" << endl;
		}
		}
	}
}