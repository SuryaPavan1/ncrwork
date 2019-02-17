#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <malloc.h> 
#include <string.h>

int main()
{
	FILE *fptr;
	int j = 0, k = 0;
	int  c;
	char capital[20];
	char *temp = (char *)malloc(20 * sizeof(char));
	char *state = (char *)malloc(20 * sizeof(char));
	fptr = fopen("data.txt", "w");
	while (j < 3)
	{
		printf("Enter the state-capital ");
		scanf("%s", temp);
		fputs(temp, fptr);
		fputs("\n", fptr);
		fflush(stdin);
		getchar();
		j++;
	}
	fclose(fptr);
	fptr = fopen("data.txt", "r");
	printf("Enter your option 1. find capital 2.find state 3. Terminate");
	scanf("%d", &c);
	switch (c)
	{
	case 1:
		printf("Enter the state");
		scanf("%s", state);
		while (k<3)
		{
			fgets(temp, 20, fptr);
			char *tok = strtok(temp, "-");
			if (strcmp(tok, state) == 0)
			{

				tok = strtok(NULL, "-");
				printf("The capital is %s ", tok);
			}
			k++;
		}
		
		break;
	case 2:
		printf("enter the capital: ");
		scanf("%s", capital);
		while (k < 3)
		{

			fgets(temp, 20, fptr);
			char *tok = strtok(temp, "-");

			temp = tok;
			tok = strtok(NULL, "\n");
			if (strcmp(tok, capital) == 0)
			{
				printf("state is %s ", temp);
			}
			k++;
		}
		break;
	case 3:
		return 1;
		break;
	default:
		printf("enter correct choice.");
	}
	getchar();
	getchar();
	return 0;
}
