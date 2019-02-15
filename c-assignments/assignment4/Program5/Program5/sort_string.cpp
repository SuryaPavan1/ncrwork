#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include<stdlib.h>
#include<string.h>
void sort(char **s, int n)
{
	int i = 0, j = 0;
	char *temp = (char *)malloc(20);
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (strcmp(s[j], s[j + 1]) > 0)
			{
				strcpy(temp, s[j]);
				strcpy(s[j], s[j + 1]);
				strcpy(s[j + 1], temp);
			}
		}
	}
}
int main()
{
	int n, j, len, i = 0;
	printf("Enter the number of strings:");
	scanf_s("%d", &n);
	j = n;
	char *name = (char *)malloc(20);
	char **s = (char **)malloc(n * sizeof(char *));
	for (i = 0; i < n; i++)
	{
		s[i] = (char *)malloc(20);
	}
	i = 0;
	while (n > 0)
	{
		printf("\n Enter the string :");
		getchar();
		scanf_s("%[^\n]s", s[i], 20);
		i++;
		n--;
	}
	sort(s, j);
	for (i = 0; i < j; i++)
	{
		printf("\n %s", s[i]);
	}
	free(s);
	getchar();
	getchar();
	return 0;
}