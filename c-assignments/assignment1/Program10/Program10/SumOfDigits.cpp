#include<stdio.h>
int main()
{
	int num, sum = 0, temp;
	printf("Enter the number ");
	scanf_s("%d", &num);
	while (num > 0)
	{
		temp = num % 10;
		num = num / 10;
		sum += temp;
	}
	printf("The sum of digits of a given number is %d", sum);
	return 0;
}
