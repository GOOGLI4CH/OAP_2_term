#include<stdio.h>
#include<stdlib.h>
#include<iostream>

int main() 
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	FILE* fileA;
	fopen_s(&fileA, "fileAEx16.txt", "w");
	if (fileA == NULL)
	{
		printf("Файл не найден");
	}
	else
	{
		int randomNumber[32] = { 0 };
		for (int i = 0; i < 32; i++)
		{
			randomNumber[i] = rand() % 100;
			fprintf(fileA, "%d\n", randomNumber[i]);
		}
		fclose(fileA);
	}
	FILE* fileB;
	fopen_s(&fileB, "fileBEx16.txt", "w");
	if (fileB == NULL)
	{
		printf("Файл не найден");
	}
	else
	{
		int randomNumber_2[32] = { 0 };
		for (int i = 0; i < 32; i++)
		{
			randomNumber_2[i] = rand() % 100;
			fprintf(fileB, "%d\n", randomNumber_2[i]);
		}
		fclose(fileB);
	}
	FILE* fileC;
	fopen_s(&fileC, "fileCEx16.txt", "w");
	fopen_s(&fileA, "fileAEx16.txt", "r");
	fopen_s(&fileB, "fileBEx16.txt", "r");
	char tmp1[40];
	char tmp2[40];
	char* ptmp1 = tmp1;
	char* ptmp2 = tmp2;
	int firstValue;
	int secondValue;
	int resultValue;
	if (fileA == NULL || fileB == NULL || fileC == NULL)
	{
		printf("Файл не найден");
	}
	else
	{
		while (!feof(fileA) && !feof(fileB))
		{
			fgets(ptmp1, 40, fileA);
			fgets(ptmp2, 40, fileB);
			firstValue = std::atoi(ptmp1);
			secondValue = std::atoi(ptmp2);
			resultValue = firstValue + secondValue;
			fprintf(fileC, "%d\n", resultValue);
		}
		printf("Файлы успешно сложены \n");
		fclose(fileA);
		fclose(fileB);
		fclose(fileC);
	}
}