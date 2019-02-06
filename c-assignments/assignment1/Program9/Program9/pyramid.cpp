#include<stdio.h>
int main()
{
	int i, j, k, y, n;
	printf("enter the length of the pyramid");
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = n - i; j > 0; j--)
		{
			printf(" ");
		}
		for (k = i; k > 0; k--)
		{
			printf("%d", k);
		}
		for (y = 2; y <= i; y++)
		{
			printf("%d", y);
		}
		printf("\n");

	}

	return 0;
}
