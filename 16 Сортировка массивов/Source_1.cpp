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

void selection_sort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int min_index = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] > arr[min_index])
			{
				min_index = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
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
	int* B = new int[size / 2];
	int j = 0;

	cout << "Массив A:" << endl;
	for (int i = 0; i < size; i++)
	{
		A[i] = rand() % 100;
		cout << A[i] << " ";

		if (i % 2 == 0)
		{
			B[j] = A[i];
			j++;
		}
	}

	cout << endl << "Массив B:" << endl;
	for (int i = 0; i < size / 2; i++)
	{
		cout << B[i] << " ";
	}

	int choice = 0;

	while (true)
	{
		cout << "Выберите вариант:" << endl;
		cout << "1 - сортировка пузырьком" << endl;
		cout << "2 - сортировка вставками" << endl;
		cout << "0 - Выход" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			auto start = chrono::high_resolution_clock::now();
			bubble_sort(B, size / 2);
			auto end = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

			cout << endl << "Массив B (сортировка пузырьком):" << endl;
			print(B, size / 2);
			cout << endl << "Сортировка пузырьком заняла " << duration.count() << " ms" << endl;

			j = 0;
			for (int i = 0; i < size; i++)
			{
				if (i % 2 == 0)
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
			selection_sort(B, size / 2);
			auto end = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

			cout << endl << "Массив B (сортировка вставками):" << endl;
			print(B, size / 2);

			cout << endl << "Сортировка вставками заняла " << duration.count() << " ms" << endl;

			j = 0;
			for (int i = 0; i < size; i++)
			{
				if (i % 2 == 0)
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