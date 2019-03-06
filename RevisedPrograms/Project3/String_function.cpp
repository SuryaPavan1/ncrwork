#include<stdio.h>
#include<malloc.h>
char *strrev(char *str)
{
	int count = 0, i;
		while (str[++count] != '\0');
	for (i = 0; i < count / 2; i++)
	{
		str[i] = str[i] + str[count - i - 1];
		str[count - i - 1] = str[i] - str[count - i - 1];
		str[i] = str[i] - str[count - i - 1];
	}
	return str;
}
void strcpy(char *Destination, char *Source)
{
	for (int i = 0; (Destination[i] = Source[i]) != '\0'; i++);
}
void strrcat(char *Destination, char *Source)
{
	int i = -1, j=0;
	while (Destination[++i] != '\0');
	while((Destination[i++] = Source[j++]) != '\0');
}
int strcmp(char *str1, char *str2)
{
	int i = 0;
	while (str1[i] == str2[i])
	{
		i++;
	}
	if (str1[i] == '\0'&&str2[i] == '\0')
	{
		return 0;
	}
	else if (str1[i] == '\0')
	{
			return str2[i]; 
	}
	else if (str2[i] == '\0')
    {
			return str1[i];
	}
	else if (str1[i] != str2[i])
			return str1[i] - str2[i];

}

int main()
{
	char *str, *str1;
	int option,n;
	str = (char *)malloc(sizeof(char) * 30);
	str1 = (char *)malloc(sizeof(char) * 30);
	printf("enter the string :");
	scanf_s("%[^\n]s", str, 30);
	printf("enter the operation to be performed :");
	printf("1.string reversal \n2.string copy \n3.string concatenation \n4.stringcompare ");
	scanf_s("%d", &option);
	switch (option)
	{
	case 1:
		str = strrev(str);
		printf("%s", str);
		break;
	case 2:
		strcpy(str1, str);
		printf("The content in str1 is %s", str1);
		break;
	case 3:
		getchar();
		printf("Enter the string to be concatenated ");
		scanf_s("%[^\n]s", str1, 30);

		strrcat(str, str1);
		printf("\n The concatenated string is :");
		printf("%s", str);
		break;
	case 4:
		printf("enter the second string");
		scanf_s("%s", str1, 30);
		n=strcmp(str1, str);
		if (n == 0)
		{
			printf("the strings are equal");
		}
		else
		{
			printf("the strings are not equal");
		}
		break;
	default:
		printf("enter the correct choice.");
	}
	getchar();
	getchar();
	return 0;
}