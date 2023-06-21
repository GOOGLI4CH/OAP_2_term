//Второе задание.
#include <iostream>
#include <stdio.h>

int main()
{
	setlocale(LC_ALL, "rus");

	FILE* nameA_file, * nameB_file, * nameC_file, * nameD_file;

	fopen_s(&nameA_file, "nameA.txt", "r");
	fopen_s(&nameB_file, "nameB.txt", "r");
	fopen_s(&nameC_file, "nameC.txt", "r");
	fopen_s(&nameD_file, "nameD.txt", "w");

	if (nameA_file == NULL || nameB_file == NULL || nameC_file == NULL || nameD_file == NULL)
	{
		perror("Ошибка открытия файлов\n");
		return EXIT_FAILURE;
	}
	else
	{
		printf("Файлы открыты\n");
	}

	fseek(nameA_file, 0, SEEK_END);			//Определение размера содержимого файла с помощью переноса указателя в конец файла.
	long fsize = ftell(nameA_file);
	fseek(nameA_file, 0, SEEK_SET);			//Установка указателя на начало файла.

	int numA, numB, numC;

	while (!feof(nameA_file))				//Пока не достигнут конец файла (размер файлов одинаков по условию).
	{
		if (!fscanf(nameA_file, "%d", &numA))	//Считывание и запись элемента файла + проверка.
		{
			perror("Ошибка!");
			return EXIT_FAILURE;
		}
		if (!fscanf(nameB_file, "%d", &numB))
		{
			perror("Ошибка!");
			return EXIT_FAILURE;
		}
		if (!fscanf(nameC_file, "%d", &numC))
		{
			perror("Ошибка!");
			return EXIT_FAILURE;
		}
		
		if (numA < numB && numA < numC)
		{
			fprintf(nameD_file, "%d ", numA);
		}
		else if (numB < numA && numB < numC)
		{
			fprintf(nameD_file, "%d ", numB);
		}
		else if (numC < numA && numC < numB)
		{
			fprintf(nameD_file, "%d ", numC);
		}
		else
		{
			perror("Существует несколько минимальных элементов!");
			return EXIT_FAILURE;
		}
	}

	printf("Результат записан в файл nameD.txt\n");

	fclose(nameA_file);
	fclose(nameB_file);
	fclose(nameC_file);
	fclose(nameD_file);
}