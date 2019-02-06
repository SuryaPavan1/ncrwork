#include<stdio.h>
#include"add.cpp"
#include"sub.cpp"
#include"mul.cpp"
#include"div.cpp"
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
		result=add(a,b);
		printf("\n %d + %d = %d", a, b, result);
		break;
	case 2:
		result=sub(a, b);
		printf("\n %d - %d = %d", a, b, result);
		break;
	case 3:
		result=mul(a, b);
		printf("\n %d * %d = %d", a, b, result);
		break;
	case 4:
	    result=div(a, b);
		printf("\n %d / %d = %d", a, b, result);
		break;
	default:
		printf("enter the correct option");
	}
	getchar();
	return 0;

}