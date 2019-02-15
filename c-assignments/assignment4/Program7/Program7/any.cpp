#include<stdio.h>
#include<malloc.h>
int any(char *s1, char *s2)
{
	int i;
	for (i = 0; (s1[i] != '\0') && (s2[i] != '\0'); i++)
	{
		if (s1[i] == s2[i])
		{
			return i;
		}
	}
	return -1;

 }

int main()
{
	char *s1, *s2;
	int n;
	s1 = (char *)malloc(30 * sizeof(char));
	s2 = (char *)malloc(30 * sizeof(char));
	printf("enter the first string ");
	scanf_s("%[^\n]s", s1,30);
	getchar();
	printf("\nenter the second string ");
	scanf_s("%[^\n]s", s2,30);
	n=any(s1, s2);
	if (n == -1)
	{
		printf("no match");
	}
	else
	{
		printf("\n The location of the first index of string s1 which matches with s2 is %d ", n+1);
	}
	getchar();
	getchar();
}