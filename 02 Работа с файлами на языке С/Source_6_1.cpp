#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main() 
{
	setlocale(LC_ALL, "rus");

	float diff, min = 100, y = 0, number;
	FILE* fA;
	int num;
	printf("Введите число для сравнения: ");
	cin >> num;

	fopen_s(&fA, "fA.txt", "w");

	if (fA == NULL) {
		perror("Ошибка открытия файла\n");
		return EXIT_FAILURE;
	}
	printf("Числа записаны в файл\n");
	srand((unsigned)time(NULL));
	for (int i = 0; i < 20; i++)
	{
		y = 0.1 * (rand() % 1001 - 500);
		fprintf(fA, "%.1f ", y);
	}
	fclose(fA);
	fopen_s(&fA, "fA.txt", "r");
	if (fA == NULL) {
		perror("Ошибка открытия файла\n");
		return EXIT_FAILURE;
	}
	printf("Числа считаны из файла\n");
	for (int i = 0; i < 20; i++)
	{
		fscanf_s(fA, "%f", &y);
		diff = abs(y - num);
		if (min > diff) {
			min = diff;
			number = y;
		}

	}
	printf("Число ближайшее к введенному %.1f ", number);
	fclose(fA);
}