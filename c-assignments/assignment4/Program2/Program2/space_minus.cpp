/*
Write a function ``replace'' which takes a pointer to a string as a
parameter, which replaces all spaces in that string by minus signs, and
delivers the number of spaces it replaced.
Thus
char *cat = "The cat sat";
n = replace( cat );
should set
cat to "The-cat-sat"

and
n to 2
*/
#include<stdio.h>
#include<malloc.h>
int replace(char *str)
{
	int i, count = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
		{
			str[i] = '-';
			count++;
		}
	}
	return count;
}
int main()
{
	char *str;
	str =(char *)malloc(30 * sizeof(char));
	int count;
	printf("enter the string :");
	scanf_s("%[^\n]s", str, 30);
	count = replace(str);
	
	printf("\n %s", str);
	printf("\nNumber pf spaces replaced are %d", count);
	getchar();
	getchar();
}
