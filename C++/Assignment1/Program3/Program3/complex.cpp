#include<iostream>
using namespace std;
class Complex
{
	float real;
	float imaginary;
public :
	Complex()
	{
		real = imaginary = 0.0;
	}
	Complex(float a)
	{
		real = imaginary = a;
	}
	Complex(float a, float b)
	{
		real = a;
		imaginary = b;
	}
	friend Complex Addcomplex(Complex c1, Complex c2);
	friend Complex MultiplyComplex(Complex c1, Complex c2);
	void display()
	{
		printf("%f + %fi", real, imaginary);
	}
};
Complex Addcomplex(Complex c1, Complex c2)
{
	Complex c;
	c.real = c1.real + c2.real;
	c.imaginary = c1.imaginary + c2.imaginary;
	return c;
}
Complex MultiplyComplex(Complex c1, Complex c2)
{
	Complex c;
	c.real = c1.real*c1.real - c2.imaginary*c2.imaginary;
	c.imaginary = c1.real*c2.real - c2.real*c1.imaginary;
	return c;
}
int main()
{
	Complex c1(5, 6), c2(4, 4),c3,c4;
	c3 = Addcomplex(c1, c2);
	cout<<"The sum of the two complex numbers is ";
	c3.display();
	cout << "\nThe product is :";
	c4 = MultiplyComplex(c1, c2);
	c4.display();
	getchar();
	getchar();
	return 0;
}