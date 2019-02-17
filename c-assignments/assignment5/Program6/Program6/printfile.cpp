#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *ptr;
	char c[100];
	fopen_s(&ptr, "text.txt", "r");
	if (ptr == NULL)
	{
		printf("Error! opening file");

	}
	else
	{
		//fgets(c, 50, ptr);
		fscanf(ptr, "%[^\n]s", c);
		printf("%s\n", c);
	}
	fclose(ptr);
	system("pause");
	
	return 0;
}