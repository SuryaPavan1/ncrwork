#include<iostream>
using namespace std;
inline int add(int a, int b) { return a + b; }
inline int sub(int a, int b) {return a - b; }
inline int mul(int a, int b) { return a * b;}
inline int division(int a, int b) { return a / b; }
inline int modulo(int a, int b) { return a % b; }
int main()
{
	int a, b;
	cout << "enter the two numbers :";
	cin >> a >> b;
	cout << "The sum is " << add(a, b);
	cout << "\nThe differencr is " << sub(a, b);
	cout << "\nThe product  is " << mul(a, b);
	cout << "\nThe division is " << division(a, b);
	cout << "\n the modulus is " << modulo(a, b);
	getchar();
	getchar();
	return 0;

}