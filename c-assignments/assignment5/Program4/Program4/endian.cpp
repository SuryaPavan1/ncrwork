#include <stdio.h>
int main()
{
	unsigned int x = 0x7654321;
	char *c = (char*)&x;

	printf("*c is: 0x%x\n", *c);
	if (*c == 0x21)
	{
		printf("given processor is little endian. \n");
	}
	else
	{
		printf("given processor is big endian. \n");
	}
	getchar();
	getchar();
	return 0;
}