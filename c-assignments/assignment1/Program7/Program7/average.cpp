#include<stdio.h>
int main()
{
	int inp[100],count=0,max=0,min=0xffff;
	float sum=0,average;
	printf("Enter the numbers");
	while (1)
	{
		scanf_s("%d", &inp[count]);
		if (inp[count] > 0)
		{
			sum += inp[count];
			if (max < inp[count])
			{
				max = inp[count];
			}
			if (min > inp[count])
			{
				min = inp[count];
			}
			count++;
		}
		else
			break;
	}
	average = sum / count;
	printf("The number of positive values entered : %d \n", count);
	printf("The largest number : %d \n",max);
	printf("The smallest number : %d \n",min);
	printf("The average of the given numbers : %lf \n", average);
	return 0;

}