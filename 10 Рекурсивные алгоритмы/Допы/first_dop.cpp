#include <iostream>
#include <fstream>

using namespace std;

const int MAX_DIGITS = 10;

void generate_numbers(int A, int* digits, int index, ofstream& file) 
{
    if (index == A) 
    {
        int number = 0;
        for (int i = 0; i < A; i++) 
        {
            number = number * 10 + digits[i];
        }
        if (file.is_open()) 
        {
            file << number << endl;
        }
    }
    else 
    {
        for (int i = 0; i <= A; i++) 
        {
            if (i == A) 
            {
                continue;
            }
            digits[index] = i;
            generate_numbers(A, digits, index + 1, file);
        }
    }
}

int main()
{
    int A;
    cout << "Введите A: ";
    cin >> A;

    int digits[MAX_DIGITS];

    ofstream file("numbers.txt");

    generate_numbers(A, digits, 0, file);

    file.close();

    cout << "Записано в файл!" << endl;
}