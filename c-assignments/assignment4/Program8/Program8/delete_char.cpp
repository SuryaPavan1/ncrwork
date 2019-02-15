#include<stdio.h>
#include<malloc.h>
void deleteChar(char *str, char c)
{
	int i = 0,j;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{  
			j = i;
			while (str[j] != '\0')
			{
				str[j] = str[j + 1];
				j++;
			}
		}
		i++;
	}
}
int main()
{
	char *str,c;
	str = (char *)malloc(30 * sizeof(char));
	printf("enter the string :");
	scanf_s("%[^\n]s", str,30);
	getchar();
	printf("\nenter the character you want to delete from the string :");
	scanf_s("%c", &c);
	deleteChar(str, c);
	printf("the resultant string is : %s",str);
	getchar();
	getchar();
}