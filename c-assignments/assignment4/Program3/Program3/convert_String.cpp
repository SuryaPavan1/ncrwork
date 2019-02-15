/* 
  Write a program to convert lower case string to upper case string and
  vice versa.
 */
#include<stdio.h>
#include<malloc.h>
int main()
{
	char *str;
	int i;
	str = (char *)malloc(30 * sizeof(char));
	printf("enter the string");
	scanf_s("%[^\n]s", str,30);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a'&&str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
		else if(str[i] >='A'&&str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
	}
	printf("\n Resultant string after case conversion is: ");
	printf("%s ", str);
	getchar();
	getchar();

}