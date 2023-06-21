#include <iostream>

using namespace std;

class BinaryHeap
{
private:
	int* heap;
	int capacity;
	int size;
	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return 2 * i + 1; }
	int right(int i) { return 2 * i + 2; }
	void heapify_up(int i)
	{
		if (i && heap[parent(i)] > heap[i])
		{
			swap(heap[i], heap[parent(i)]);
			heapify_up(parent(i));
		}
	}
	void heapify_down(int i)
	{
		int l = left(i), r = right(i), smallest = i;
		if (l < size && heap[l] < heap[smallest]) { smallest = l; }
		if (r < size && heap[r] < heap[smallest]) { smallest = r; }
		if (smallest != i)
		{
			swap(heap[i], heap[smallest]);
			heapify_down(smallest);
		}
	}

public:
	BinaryHeap(int cap)
	{
		capacity = cap;
		size = 0;
		heap = new int[cap];
	}
	~BinaryHeap()
	{
		delete[] heap;
	}
	void insert(int key)
	{
		if (size == capacity)
		{
			throw out_of_range("Heap overflow");
		}
		heap[size] = key;
		int index = size;
		size++;
		heapify_up(index);
	}
	int extract_min()
	{
		if (size == 0)
		{
			std::cerr << "Балбес, куча пуста" << std::endl;
			exit(1);
		}
		int min = heap[0];
		heap[0] = heap[size - 1];
		size--;
		heapify_down(0);
		return min;
	}
	int extract_max()
	{
		if (size == 0)
		{
			std::cerr << "Балбес, куча пуста" << std::endl;
			exit(1);
		}
		int max = heap[0];
		for (int i = 1; i < size; i++)
		{
			if (heap[i] > max)
			{
				max = heap[i];
			}
		}
		return max;
	}
	int get_ith_element(int i)
	{
		if (i >= size)
		{
			std::cerr << "Нет такого индекса, калыван!" << std::endl;
			exit(1);
		}
		return heap[i];
	}
	int get_size() { return size; }

	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << heap[i] << " ";
		}
		cout << endl;
	}

};

BinaryHeap merge(BinaryHeap& h1, BinaryHeap& h2)
{
	BinaryHeap h(h1.get_size() + h2.get_size());
	for (int i = 0; i < h1.get_size(); i++)
	{
		h.insert(h1.get_ith_element(i));
	}
	for (int i = 0; i < h2.get_size(); i++)
	{
		h.insert(h2.get_ith_element(i));
	}
	return h;
}


int main()
{
	setlocale(LC_ALL, "rus");
	int choice = 0, value = 0, size;
	cout << "Введите максимальный размер кучи: "; cin >> size;
	BinaryHeap heap(size);

	do
	{
		cout << "Выберите вариант:" << endl;
		cout << "1 - Добавить элемент" << endl;
		cout << "2 - Вывести кучу" << endl;
		cout << "3 - Максимальный элемент" << endl;
		cout << "4 - Минимальный элемент" << endl;
		cout << "5 - I-тый элемент" << endl;
		cout << "6 - Объединение двух куч" << endl;
		cout << "0 - Выход" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Вводите значения (0 - остановка ввода)" << endl;
			do
			{
				cin >> value;
				if (value != 0) { heap.insert(value); }
			} while (value);
			break;
		}
		case 2:
		{
			cout << "Куча:" << endl;
			heap.print();
			break;
		}
		case 3:
		{
			cout << "Максимальный элемент:" << heap.extract_max() << endl;
			break;
		}
		case 4:
		{
			cout << "Минимальный элемент:" << heap.extract_min() << endl;
			break;
		}
		case 5:
		{
			int i;
			cout << "Введите i:"; cin >> i;
			cout << "i-тый элемент" << heap.get_ith_element(i) << endl;
			break;
		}
		case 6:
		{
			cout << "Введите максимальный размер второй кучи:"; cin >> size;
			BinaryHeap heap_s(size);
			cout << "Добавьте элементы во вторую кучу" << endl;
			cout << "Вводите значения (0 - остановка ввода)" << endl;
			do
			{
				cin >> value;
				if (value != 0) { heap_s.insert(value); }
			} while (value);
			cout << "Новая куча:" << endl;
			merge(heap, heap_s).print();
			break;
		}
		default:
			break;
		}
	} while (choice != 0);
}