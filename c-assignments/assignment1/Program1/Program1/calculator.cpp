#include<stdio.h>
#include"Source.h"
int result;
int main()
{
	int op;
	int a, b;
	printf("enter the numbers:");
	scanf_s("%d %d", &a, &b);
	printf("Enter the operation to be performed: \n 1. Addition \n 2.Subtraction");
	printf("\n 3.Multiplication \n 4.Division  ");
	scanf_s("%d", &op);
	switch (op)
	{
	case 1:
		add(a,b);
		printf("\n %d + %d = %d", a, b, result);
		break;
	case 2:
		sub(a, b);
		printf("\n %d - %d = %d", a, b, result);
		break;
	case 3:
		mul(a, b);
		printf("\n %d * %d = %d", a, b, result);
		break;
	case 4:
	    div(a, b);
		printf("\n %d / %d = %d", a, b, result);
		break;
	default:
		printf("enter the correct option");
	}
	getchar();
	getchar();
	return 0;

}