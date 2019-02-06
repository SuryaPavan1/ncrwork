#include<stdio.h>
int bin;
int rec(int n) {
	if (n <= 0) {
		return 1;
	}
	int temp;
	rec(n / 2);
	temp = n % 2;
	bin = 10 * bin + temp;
}
int main()
{
	int dec, temp;
	printf("enter the number :");
	scanf_s("%d", &dec);
	if (dec > 0 && dec < 32)
	{
		rec(dec);
		printf("The binary equivalent is %d", bin);
	}
	else
	{
		printf("Out of range");
	}
	return 0;
}