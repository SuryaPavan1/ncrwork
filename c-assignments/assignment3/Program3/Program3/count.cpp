#include<stdio.h>
int main()
{
	int num,temp,count=0;
	int op;
	char c;
	printf("enter your choice ");
	printf("1.Number 2.character  ");
	scanf_s("%d", &op);
	getchar();
	if (op == 1)
	{
		printf("enter the number to find the 1's ");
		scanf_s("%d", &num);
		while (num > 0)
		{
			temp = num % 2;
			if (temp == 1) count++;
			num = num / 2;
		}
		printf("the number of 1 bits  in the given number is %d", count);
	}
	else if (op == 2)
	{
		
		printf("enter the character :");
		scanf_s("%c", &c);
		num = c;
		while (num > 0)
		{
			temp = num % 2;
			if (temp == 1) count++;
			num = num / 2;
		}
		printf("the number of 1 bits  in the given character is %d", count);
	}
	else
	{
		printf("enter the correct choice");
	}
	getchar();
	getchar();
	return 0;
}