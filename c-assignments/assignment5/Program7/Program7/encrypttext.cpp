#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	FILE *fptr;
	int i;
	char data[100],fname[20],temp[100];
	char ch;
	printf("Enter the file name to save the one's complement ");
	scanf("%s", fname);
	getchar();
	fptr = fopen(fname, "w+");
	printf("enter the text :");
	scanf("%[^\n]s", data);
	for (i = 0; data[i] != '\0'; i++)
	{
		ch = ~data[i];
		fputc(ch, fptr);
	}
	fclose(fptr);
	
	fptr = fopen(fname, "r");
	fgets(temp, 100, fptr);
	printf("\n The text in one's complement form is :");
	printf("%s", temp);
	for (i = 0; temp[i] != '\0'; i++)
	{
		temp[i] = ~temp[i];
	}
	printf("\nThe original text is :");
	printf("%s", temp);
	getchar();
	getchar();
}