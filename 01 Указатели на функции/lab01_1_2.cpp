#include <iostream>

using namespace std;
int fmin(int num, int first, ...) {

	int* ptr = &first;
	int* numbers = new int[num];
	for (int i = 0; i < num; i++)
	{

		*(numbers + i) = *(ptr + i);
		ptr++;
	}
	int min = *numbers;
	
	for (int i = 0; i < num; i++)
	{
		if (min > *(numbers + i))
		{
			min = *(numbers + i);
		}
	}
	
	return min;
};
int main()
{
	cout << fmin(4, 10, 22, 5, 7);
}