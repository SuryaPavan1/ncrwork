#include<stdio.h>
struct Date
{
	int day;
	int month;
	int year;
};
const int monthDays[12] = { 31, 28, 31, 30, 31, 30,
31, 31, 30, 31, 30, 31 };
int count_Leap(Date d)
{
	int year = d.year;
	if (d.month <= 2)
		year--;
	return year / 4 - year / 100 + year / 400;
}
int Diff_dates(Date dt1, Date dt2)
{
	long int n1 = dt1.year * 365 + dt1.day;
	for (int i = 0; i < dt1.month - 1; i++)
		n1 += monthDays[i];
	n1 += count_Leap(dt1);

	long int n2 = dt2.year * 365 + dt2.day;
	for (int i = 0; i < dt2.month - 1; i++)
		n2 += monthDays[i];
	n2 += count_Leap(dt2);

	return (n2 - n1);
}
int main()
{
	struct Date d1, d2;
	int difference;
	printf("Enter the date in dd-mm-yyyy :");
	scanf_s("%d-%d-%d", &d1.day, &d1.month, &d1.year);
	printf("\nEnter the date in dd-mm-yyyy :");
	scanf_s("%d-%d-%d", &d2.day, &d2.month, &d2.year);
	difference = Diff_dates(d1, d2);
	printf("The difference is %d", difference);
	getchar();
	getchar();
	return 0;
}