#include<iostream>
using namespace std;
class Polar
{
	int angle;
	int radius;
	static int count;
public:
	Polar()
	{
		count++;
		angle = radius = 0;
	}
	Polar(int a, int r)
	{
		count++;
		angle = a;
		radius = r;
	}
    void PrintCount()
	{
		cout << "\n The count is " << count;
	}
};
int Polar::count = 0;
int main()
{
	Polar p1, p2;
	p2.PrintCount();
	Polar p3;
	p3.PrintCount();
	system("pause");
}