#include<stdio.h>
#include<malloc.h>
int main()
{
	int n;
	printf("enter the seize of the array :");
	scanf_s("%d", &n);
	int *a = (int *)malloc(n * sizeof(int));
	int i = 0;
	for (i = 0; i < n; i++) {
		scanf_s("%d", a+i);
	}
	int k = 0,temp,j;
	while (a[k] < 0)
	{
		k++;
	}
	for (j = k; j < n; j++)
	{
		
		i = j;
		if (a[i] < 0)
		{
			while ((i-1>=k) && (i < n))
			{
				temp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = temp;
				i--;

			}
			k++;
	    }
	}
	printf("The resultant order is :");
	for (i = 0; i < n; i++)
	{
		
		printf("  %d  ",a[i]);
	}
	getchar();
	getchar();
	return 0;
}