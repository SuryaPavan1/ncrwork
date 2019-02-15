#include<stdio.h>
#include<malloc.h>
void rotate(char *str)
{
	int i,count=0,j=0;
	for (i = 0; str[i] != '\0'; i++)
	{
		count++;
	}
	for (i = 0; i < count; i++)
	{
		if (i != 0)
		{
			for (j = i; (j != i - 1); j = (j + 1) % count)
			{

				printf("%c", str[j]);

			}
			printf("%c  ", str[j]);
		}
		else
		{
			printf("%s ", str);
		}
	}
}
int main()
{
	char *str;
	str = (char *)malloc(sizeof(char) * 30);
	printf("enter the string :");
	scanf_s("%[^\n]s", str,30);
	rotate(str);
	getchar();
	getchar();
	return 0;

}