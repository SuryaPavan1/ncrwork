#include<stdio.h>
int  binDecimal(int binary)
{
	int temp = 0, decimal=0;
	while (binary > 0)
	{
		temp = binary % 10;
		binary = binary / 10;
		decimal = decimal * 2 + temp;
	}
	return decimal;
}
int decBinary(int decimal)
{
	int binary;
	int temp;
	if (decimal == 0) {
		return 0;
	}
	else if(decimal==1)
	{
		return 1;
	}
	else
	{
		binary=decBinary(decimal / 2);
		temp = decimal % 2;
		binary = 10 * binary + temp;
		return binary;
	}
}
int main()
{
	int binary=0, decimal = 0,option;
	printf("Enter the option: \n");
	printf("1: binary to decimal \n");
	printf("2: decimal to binary  ");
	scanf_s("%d", &option);
	if (option == 1)
	{
		printf("\n enter the binary number");
		scanf_s("%d", &binary);
		decimal=binDecimal(binary);
		printf("The equivalent decimal number is : %d", decimal);
	}
	else if (option == 2)
	{
		printf("\n enter the decimal number");
		scanf_s("%d", &decimal);
		binary=decBinary(decimal);
		printf("The equivalent decimal number is : %d", binary);
	}
	
	getchar();
	getchar();
	return 0;
}

