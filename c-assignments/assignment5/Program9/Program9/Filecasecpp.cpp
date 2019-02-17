#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *ptr;
	char *temp;
	int i = 0;
	temp = (char *)malloc(50 * sizeof(char));
	ptr = fopen("test.txt", "w+");
	printf("enter the text :");
	scanf("%[^\n]s", temp);
	while (temp[i] != '\0')
	{
		if (temp[i] >= 65 && temp[i] <= 90)
		{
			temp[i] = temp[i] + 32;
		}
		else if (temp[i] >= 97 && temp[i] <= 122)
		{
			temp[i] = temp[i] - 32;
		}
		fputc(temp[i], ptr);
		i++;
	}
	fseek(ptr, 0, SEEK_SET);
	fgets(temp, 50, ptr);
	printf("The content of the file is %s", temp);
	fclose(ptr);
	system("pause");
	return 0;
}