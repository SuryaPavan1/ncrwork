#include <stdio.h>
long int factorial(int n)
{
	if (n >= 1)
		return n * factorial(n - 1);
	else
		return 1;
}
int main()
{
	int n;
	printf("Enter a positive integer: ");
	scanf_s("%d", &n);
	printf("Factorial of %d = %ld", n, factorial(n));
	getchar();
	getchar();
	return 0;
}
