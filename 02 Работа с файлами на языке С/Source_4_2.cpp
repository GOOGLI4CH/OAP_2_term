#include <iostream>
#include <stdio.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	FILE* fileF, *fileG;
	
	fopen_s(&fileF, "f.txt", "r");
	fopen_s(&fileG, "g.txt", "w");
	
	if (fileF == NULL || fileG == NULL)
	{
		perror("Ошибка открытия файла f.txt или g.txt\n");
		return EXIT_FAILURE;
	}
	else
	{
		printf("Файлы открыты!\n");
	}
	
	printf("Введите число для сравнения: ");
	int number;
	scanf_s("%d", &number);

	while (!feof(fileF))
	{
		int numberF;
		fscanf_s(fileF, "%d", &numberF);
		if (numberF > number)
		{
			fprintf(fileG, "%d ", numberF);
		}
	}

	printf("Результат записан в файл g.txt\n");
}