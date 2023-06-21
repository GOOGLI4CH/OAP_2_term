#include <iostream>

using namespace std;

void compress(int n, char* text, ...) 
{
    char* p = text, * str;
    for (int i = 0; i < n; ++i)
    {
        str = p;
        while (*p)
        {
            if (*p != ' ')
            {
                *str++ = *p;
            }
            ++p;
        }
        *str = '\0';
        ++p;
    }
}

int main() 
{
    setlocale(LC_ALL, "rus");
    
    char text_1[] = "Hello world";
    
    compress(1, text_1);
    cout << text_1 << endl;
    
    char text_2[] = "Текст для проверки";
    char text_3[] = "аоооаво оарворвао враарвро";
    
    compress(2, text_2, text_3);
    cout << text_2 << endl << text_3 << endl;
}
