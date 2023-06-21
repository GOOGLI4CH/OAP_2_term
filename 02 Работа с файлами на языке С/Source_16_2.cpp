#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	FILE* file1;
	fopen_s(&file1, "file1Ex16.txt", "w");
	if (file1 == NULL)
	{
		printf("Файл не найден");
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			fprintf(file1, "%d\n", rand() % 25 + 20);
		}
		for (int i = 0; i < 5; i++)
		{
			fprintf(file1, "%d\n", rand() % 50 - 100);
		}
		fclose(file1);
	}

	fopen_s(&file1, "file1Ex16.txt", "r");
	FILE* file2;
	fopen_s(&file2, "file2Ex16.txt", "w");
	char tmp[4];
	int value = 0;

	if (file1 == NULL || file2 == NULL)
	{
		printf("Файл не найден");
	}
	else
	{
		while (!feof(file1))
		{
			fgets(tmp, 4, file1);
			value = std::atoi(tmp);
			if (value != 0)
			{
				fprintf(file2, "%d\n", abs(value));
			}
		}

		fclose(file1);
		fopen_s(&file1, "file1Ex16.txt", "r");

		if (file1 == NULL)
		{
			printf("Файл не найден");
		}
		else
		{
			while (!feof(file1))
			{
				fgets(tmp, 4, file1);
				value = std::atoi(tmp);
				if (value != 0)
				{
					if (value > 0)
					{
						fprintf(file2, "%d\n", abs(value) * (-1));
					}
					else
					{
						fprintf(file2, "%d\n", value);
					}
				}

			}
			printf("Файлы успешно записаны");
			fclose(file1);
		}
		fclose(file2);
	}
}