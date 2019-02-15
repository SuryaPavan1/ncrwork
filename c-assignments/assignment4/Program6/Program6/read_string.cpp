#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char *s[30];
	int j,n,i;
	printf("enter the number of strings");
	scanf_s("%d", &n);
	j = n;
	for (i = 0; i < n; i++)
	{
		s[i] = (char *)malloc(30);
	}
	i = 0;
	while (n > 0)
	{
		printf("\n Enter the string :");
		getchar();
		scanf_s("%[^\n]s", s[i], 30);
		i++;
		n--;
	}
	for (i = 0; i < j; i++)
	{
		printf("\n %s", s[i]);
		free(s[i]);
	}
	getchar();
	getchar();
	return 0;

}
