#include<stdio.h>
struct Time {
	int hours;
	int minutes;
	int seconds;
};
int main()
{
	struct Time p1;
	printf("enter the day in hours,minutes,seconds :");
	scanf_s("%d,%d,%d", &p1.hours, &p1.minutes, &p1.seconds);
	printf("\n %d:%d:%d",p1.hours, p1.minutes, p1.seconds);
	getchar();
	getchar();
	return 0;
}
