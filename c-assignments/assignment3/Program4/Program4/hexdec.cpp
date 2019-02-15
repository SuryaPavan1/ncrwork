#include<stdio.h>
int main()
{
	int hex,op,op1;
	printf("Enter the hexadecimal number");
	scanf_s("%x", &hex);
	printf("enter your choice :\n");
	printf("1.Hexadecimal equivalent of 1's complement \n");
	printf("2.Hexadecimal equivalent after masking operation \n");
	printf("3.Hexadecimal equivalent of 1's complement after bit shifting .\n");
	printf("4.exit");
	scanf_s("%d", &op);
	if (op == 1)
	{
		printf("Hexadecimal equivalent of 1's complement is %x ", (hex) ^ (0xFFFFFFFF));
	}
	else if (op == 2)
	{
		int temp;
		printf("Enter the type of masking");
		scanf_s("%d", &op1);
		printf("enter the masking value in hexadecimal format :");
		scanf_s("%x", &temp);
		printf("enter your choice: 1.and 2.or 3.ex-or");
		switch (op1)
		{
		case 1:
			printf("The hexadecimal equivalent is %x\n", hex&temp);
		case 2:
			printf("The hexadecimal equivalent is %x\n", hex&temp);
		case 3:
			printf("The hexadecimal equivalent is %x\n", hex&temp);
		default:
			printf("enter correct choice.");
		}

	}
	else if (op == 3)
	{
		int sh, op2;
		printf("enter the shifting operation 1. Right 2.left");
		scanf_s("%d", &op2);
		printf("enter the number of bits to be shifted");
		scanf_s("%d", &sh);
		if (op2 == 1)
		{
			printf(" %x", hex >> sh);
		}
		else if (op2 == 2)
		{
			printf(" %x ", hex << sh);

		}
		else
			printf("enter correct choice");
	}
	getchar();
	getchar();
}