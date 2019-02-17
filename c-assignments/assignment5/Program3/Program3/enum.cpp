#include<stdio.h>
#include<stdlib.h>
struct complex
{
	float real;
	float imaginary;
};
enum operations {Addition=1,Subtraction,Multiplication,Division};
int main()
{
	struct complex p1, p2 , res;
	int op;
	float den;
	printf("Enter the first complex number in a+i(b) format:");
	scanf_s("%f+i(%f)", &p1.real, &p1.imaginary);
	printf("\nEnter the second complex number in a+i(b) format:");
	scanf_s("%f+i(%f)", &p2.real, &p2.imaginary);
	printf("\n Enter the operation to be performed : 1.Additon 2.Subtraction 3.Multiplication 4.Division");
	scanf_s("%d", &op);
	switch (op)
	{
	case Addition:
		res.real = p1.real + p2.real;
		res.imaginary = p1.imaginary + p2.imaginary;
		break;
	case Subtraction:
		res.real = p1.real - p2.real;
		res.imaginary = p1.imaginary - p2.imaginary;
		break;
	case Multiplication:
		res.real = p1.real * p2.real - p1.imaginary * p2.imaginary;
		res.imaginary = p1.real * p2.imaginary + p1.imaginary * p2.real;
		break;
	case Division:
		 den = p2.real*p2.real + p2.imaginary*p2.imaginary;
		res.real = (p1.real * p2.real + p1.imaginary * p2.imaginary) / den;
		res.imaginary = (-p1.real * p2.imaginary + p1.imaginary * p2.real) / den;
		break;
	default:
		printf("invalid option");
		exit(0);
	}
printf("\nThe resultant complex number is : %f+i(%f)", res.real, res.imaginary);
getchar();
getchar();
return 0;
} 