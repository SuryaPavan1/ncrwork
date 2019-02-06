#include<stdio.h>
int main() {
	int n, b, count = 0, temp;
	printf("enter the number:");
	scanf_s("%d", &n);
	printf("enter the positions to be shifted");
	scanf_s("%d", &b);
	temp = n;
	while (temp > 0)
	{
		count++;
		temp = temp / 10;
	}
	int a[30];
	temp = n;
	int r, i = count - 1;

	while (temp > 0)
	{
		
		r = temp % 10;
		temp = temp / 10;
		a[i--] = r;
	}
	int h;
	printf("The resultant number is  ");
	for (h = count - b; h != count - b-1; h = (h + 1) % count)
	{
		printf("%d", a[h]);
	}

	printf("%d", a[h]);
	return 0;
}
