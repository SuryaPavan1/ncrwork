#include<stdio.h>
#define num 100
#define tokenpaster(n) printf ("token" #n " = %d", token##n)
int main()
{
#ifdef num
	printf("The num is defined and value is %d ", num);
#endif
	int token42 = 50;
	tokenpaster(42);
	getchar();
	getchar();
	return 0;
}

