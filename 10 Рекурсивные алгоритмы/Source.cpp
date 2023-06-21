#include <iostream>

using namespace std;

double sum_cos(double x, int n) 
{
	if (n == 1) { return cos(x); }
	else { return cos(n * x) + sum_cos(x, n - 1); }
}

double factorial(double x, unsigned int n)
{
	if (n == 0) { return 1; }
	if (n == 1) { return x; }
	return x * x / n / (n - 1) * factorial(x, n - 2);
}

int main()
{
	setlocale(LC_ALL, "rus");

	cout << "Задание 12" << endl;
	double X;
	int N;
	cout << "Введите X: "; cin >> X;
	cout << "Введите N: "; cin >> N;
	cout << "Результат: " << sum_cos(X, N);

	cout << endl << "Задание 14" << endl;

	double x;
	unsigned int n;
	cout << "Введите X: "; cin >> x;
	cout << "Введите N: "; cin >> n;
	cout << "Результат: " << factorial(x, n);
}