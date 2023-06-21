#include <iostream>

const int N = 5;

void print_array(int* arr, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void swap(int& a, int& b) 
{
    int temp = a;
    a = b;
    b = temp;
}

void generate_permutations(int* arr, int start, int end) 
{
    if (start == end) 
    {
        print_array(arr, end);
    }
    else {
        for (int i = start; i < end; i++) 
        {
            swap(arr[start], arr[i]);
            generate_permutations(arr, start + 1, end);
            swap(arr[start], arr[i]);
        }
    }
}

int main()
{
    int arr[N] = { 1, 2, 3, 4, 5 };

    generate_permutations(arr, 0, N);
}
