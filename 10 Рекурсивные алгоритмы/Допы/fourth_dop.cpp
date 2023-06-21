#include <iostream>

using namespace std;

char generatechar(int n, char current_char)
{
    if (n == 1) { return current_char; }
    else 
    {
        char next_char = (current_char == 'z') ? 'a' : current_char + 1;
        return generatechar(n - 1, next_char);
    }
}


int main() 
{
    setlocale(LC_ALL, "rus");
    
    cout << "введите n" << endl;
    int n;
    cin >> n;

    char first_char = 'a';
    char n_th_char = generatechar(n, first_char);

    cout << n_th_char << endl;

    return 0;
}