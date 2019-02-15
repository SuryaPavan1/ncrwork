#include<stdio.h>
#include<malloc.h>
void strrev(char *str)
{
	if (*str)
	{
		strrev(str + 1);
		printf("%c", *str);
	}
}
int main()
{
	char *str;
	str = (char *)malloc(30 * sizeof(char));
	printf("enter the string");
	scanf_s("%[^\n]s", str,30);
	strrev(str);
	getchar();
	getchar();
	return 0;
}