#include<stdio.h>
struct member1
{
	int integer;
	char character;
};
union member2
{
	int integer;
	char character;
};
int main()
{
	struct member1 p;
	union member2 s;
	printf("size of member1 = %d", sizeof(p));
	printf("\nsize of member2 = %d ", sizeof(s));
	getchar();
	getchar();
	return 0;
}