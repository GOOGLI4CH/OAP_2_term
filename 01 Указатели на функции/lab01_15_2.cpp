#include <iostream>
#include <stdlib.h>

using namespace std;

void binary(int n,int first,...) 
{
	int* ptr = &first;
	char tmp[33];
	while (n--)
	{
		_itoa_s(*ptr, tmp, 2);
		cout << *ptr << " = " << tmp << endl;
		ptr += 2;
	}
}

int main() 
{
	binary(1, 6);
	binary(2, 3, 8, 7);
	binary(4, 11, 65, 23,323);
}