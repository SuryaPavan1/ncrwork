#include<stdio.h>
int main()
{
	int val = 0xCAFE;
	int sim = 0x000F;
	int test, count1=0;
	int n;
	test = val & sim;
	while (test > 0) {
		n = test % 2;
		if (n == 1) {
			count1++;
		}
		test = test / 2;
	}
	if (count1 >= 3)
	{
		printf("The three of last four bits are on \n");
	}
	else
		printf("not on ");

	int c = val & 0xFF00;
	int v = 0x00FF & val;
	c = c / 256;
	v = v * 256;
	printf("Reversed byte order is  %X  \n", c | v);

	int k = (val & 0x000F) * 256 * 16;
	int k1 = (val & 0x00F0) / 16;
	int k2 = (val & 0x0F00) / 16;
	int k3 = (val & 0xF000) / 16;
	printf("Rotated bits are  %X", k | k1 | k2 | k3);
	getchar();
	getchar();
	return 0;
}
