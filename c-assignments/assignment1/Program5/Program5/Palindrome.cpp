#include <stdio.h>
int main()
{
	int n, rev = 0, rem, Integer;

	printf("Enter an integer: ");
	scanf_s("%d", &n);

	Integer = n;
	while (n != 0)
	{
		rem = n % 10;
		rev = rev * 10 + rem;
		n /= 10;
	}
	if (Integer == rev)
		printf("%d is a palindrome.",Integer);
	else
		printf("%d is not a palindrome.",Integer);

	return 0;
}