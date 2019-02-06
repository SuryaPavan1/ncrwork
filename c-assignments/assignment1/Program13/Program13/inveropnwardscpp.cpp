#include<stdio.h>
#include<math.h>
int bin, count = 0, bin1, p;
int rec(int n) {
	if (n <= 0) {
		return 1;
	}
	int temp, l;
	rec(n / 2);
	p--;
	l = temp = n % 2;
	bin = 10 * bin + temp;
	++count;
	if (p <= 0) {
		if (l == 1) {
			l = 0;
		}
		else if (l == 0) {
			l = 1;
		}
	}
	bin1 = 10 * bin1 + l;
}
int main()
{
	int dec, temp;
	printf("enter the number");
	scanf_s("%d", &dec);
	printf("enter the position");
	scanf_s("%d", &p);
	p = p + 1;
	rec(dec);
	printf("The resultant number is %d%d", bin, bin1);
	return 0;
}
