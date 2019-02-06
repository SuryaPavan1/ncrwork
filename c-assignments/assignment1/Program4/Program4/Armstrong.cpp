#include <stdio.h>

int main()
{
	int number, sum = 0, rem = 0, temp;

	printf("enter a number");
	scanf_s("%d", &number);
	temp = number;
	while (number != 0)
	{
		rem = number % 10;
		sum = sum + rem*rem*rem;
		number = number / 10;
	}
	if (sum == temp)
		printf("The given number is  an armstrong number");
	else
		printf("The given number is not a armstrong number");
	return 0;
}
