#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main() 
{	
	setlocale(LC_ALL, "rus");
	
	FILE* file, * file1;
	char str[256];
	int N;
	printf("Введите количество строк, которое хотите ввести: ");
	cin >> N;

	fopen_s(&file, "F1.txt", "w");
	if (file == NULL) {
		perror("Ошибка открытия файла\n");
		return EXIT_FAILURE;
	}
	for (int i = 0; i <= N; i++)
	{
		cin.getline(str, 256);

		fprintf(file, "%s\n", str);
	}
	printf("\nСтроки записаны\n");
	fclose(file);

	fopen_s(&file, "F1.txt", "r");
	fopen_s(&file1, "F2.txt", "w");
	if (file == NULL) {
		perror("Ошибка открытия файла\n");
		return EXIT_FAILURE;
	}
	if (file1 == NULL) {
		perror("Ошибка открытия файла\n");
		return EXIT_FAILURE;
	}
	for (int i = 0; i <= N; i++)
	{
		fgets(str, 30, file);
		if (!(i % 2)) {
			fprintf(file1, "%s", str);
			printf("%s", str);
		}
	}
	return 0;
}