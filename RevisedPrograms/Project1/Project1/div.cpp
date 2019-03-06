#include<stdio.h>
#include<stdlib.h>
float division(float a, float b)
{ 
	float result;
	if (b == 0) {
		printf("error");
		exit(0);
	}
	else {
		result = a / b;
	}
	return result;
}