#include<stdio.h.>
#include<malloc.h>
void str_tok(char *str, char c)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			str[i] = '\n';
		}
		i++;
	}
}
int main()
{
	char *str,c;
	str = (char *)malloc(30 * (sizeof(char)));
	printf("enter the string :");
	scanf_s("%[^\n]s", str,30);
	getchar();
	printf("\nenter the delimiter :");
	scanf_s("%c", &c);
	str_tok(str, c);
	printf("The tokens are :");
	printf("%s", str);
	getchar();
	getchar();
}