#include <stdio.h>
void reverseNum(int n)
{
	long  rev = 0, temp, rem;
	temp = n;
	while (n > 0)
	{
		rem = n % 10;
		rev = rev * 10 + rem;
		n /= 10;
	}
	printf("Reverse of %d is = %ld \n", temp, rev);
}

int main()
{
	long  num;
	printf("Enter the number\n");
	scanf_s("%ld", &num);
	reverseNum(num);
	getchar();
	return 0;
}