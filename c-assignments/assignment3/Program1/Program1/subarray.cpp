#include<stdio.h>
#include<malloc.h>
int main()
{
	int *arr,n,sum,sum1=0;
	printf("enter the size of the array");
	scanf_s("%d", &n);
	arr = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", arr + i);
	}
	printf("\n");
	scanf_s("%d", &sum);
	int ind1 = 0, ind2 = 1,flag=0;
	for (ind2 = 0; ind2 < n; ind2++) {
		while (sum1 > sum&&ind1 < ind2 - 1) {
			sum1 = sum1 - arr[ind1++];
		}
		if (sum == sum1) {
			flag = 1;
			break;
		}

		
		if (ind2 < n) {
			sum1 = sum1 + arr[ind2];
		}
	}
	if (flag == 1) {
		printf("sum found between the index %d and %d", ind1, ind2);
	}
	else {
		printf("no subarray found");
	}
	getchar();
	getchar();
}