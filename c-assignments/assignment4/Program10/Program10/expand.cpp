/*
Write a function expand (s1, s2) which expands shorthand notations of s1
like a-d into abcd and 0-9 to 0123456789 in s2. For example if the string
in s1 is 0123a-e1-4 then s1 is expanded in s2 to 0123abcde1234.
*/
#include<stdio.h>
#include<malloc.h>
#include<ctype.h>
void expand(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	
	while (s1[i] != '\0')
	{ 
		s2[j] = s1[i];
		j++;
		if (s1[i + 1] == '-')
		{
			if (((((isdigit(s1[i])) && (isdigit(s1[i + 2]))) || (((isalpha(s1[i])) && (isalpha(s1[i + 2])))))) && (s1[i] < s1[i + 2]))
			{

				while (s2[j - 1] < s1[i + 2])
				{
					s2[j] = s2[j - 1] + 1;
					j++;

				}
				i = i + 2;
			}
		}
			i++;
		
	
	}
	s2[j] = '\0';
}
int main()
{
	char *s1;
	char *s2=NULL;
	s1 = (char *)malloc(30 * sizeof(char));
	s2 = (char *)malloc(60 * sizeof(char));
	printf("enter the string");
	scanf_s("%[^\n]s", s1,30);
	expand(s1, s2);
	printf("%s", s2);
	getchar();
	getchar();
}