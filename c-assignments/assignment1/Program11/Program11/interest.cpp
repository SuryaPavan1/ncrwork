#include<stdio.h>
#include<math.h>
int main()
{
	int  rate = 12, time = 10, Amount = 500000;
	double simpleInterest = 0.0,InterestAnnual=0.0,InterestQuart=0.0;
	simpleInterest = Amount * time*rate / 100.0;
	InterestAnnual = Amount * pow((1 + rate / 100.0), time);
	InterestQuart = Amount * pow((1 + rate / 300.0),3* time);
	printf("simple interest= %lf \n", simpleInterest);
	printf("compound interest when compounding is done annually : Rs %lf \n", InterestAnnual);
	printf("compound interest when compounding is done Quarterly : Rs %lf \n", InterestQuart);
	return 0;

}