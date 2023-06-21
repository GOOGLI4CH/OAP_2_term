//[0; 3] - промежуток при тесте.
#include <iostream>

#define ACCURACY 0.001					//Точность

using namespace std;

double equationNum1(double x)			//Первое уравнение
{
	return pow(x, 2) + 4 * x - 2;
}

double equationNum2(double x)			//Второе уравнение
{
	return sin(x) + 0.1;
}

double dichotomy(double a, double b, double(*equation)(double x))
{
	double x = 0;

	while (b - a > ACCURACY)
	{
		x = (a + b) / 2;

		if ((*equation)(a) * (*equation)(x) < 0)
		{

			b = x;
		}
		else
		{

			a = x;
		}
	}
	return x;
}

int main()
{
	setlocale(LC_ALL, "rus");

	double (*ptrEquationNum1)(double x) = &equationNum1;			//Указатель на функцию, содержащую первое уравнение
	double (*ptrEquationNum2)(double x) = &equationNum2;		//Указатель на функцию, содержащую второе уравнение

	double a, b;

	cout << "Введите промежуток (a,b) для первого уравнения: " << endl;
	cin >> a >> b;

	cout << "Корень первого уравнения: " << dichotomy(a, b, ptrEquationNum1) << endl;

	cout << "Введите промежуток (a,b) для второго уравнения: " << endl;
	cin >> a >> b;

	cout << "Корень второго уравнения: " << dichotomy(a, b, ptrEquationNum2) << endl;
}