#include<iostream>
using namespace std;
class Distance2;
class Distance1
{
	int meters;
	int centimeters;
public:
	Distance1() {
		meters = centimeters = 0;
	}
	Distance1(int a,int  b) {


		meters = a;
		centimeters = b;
	}
	friend Distance1 Add_1(Distance1 d1, Distance2 d2);
	friend Distance2 Add_2(Distance1 d1, Distance2 d2);
	void display()
	{
		cout <<endl<<meters << "meters " << centimeters << "centimeters";
	}
	
};
class Distance2
{
	int feet;
	int inches;
public:
	Distance2() {


		feet = inches = 0;
	}
	Distance2(int a, int  b) {


		feet = a;
		inches = b;
	}
	void display()
	{
		cout << feet << " feet " << inches << " inches ";
	}
	friend Distance1 Add_1(Distance1 d1, Distance2 d2);
	friend Distance2 Add_2(Distance1 d1, Distance2 d2);
};
Distance1 Add_1(Distance1 d1, Distance2 d2)
{
	Distance1 d3;
	int temp;
	temp = d1.meters * 100 + d1.centimeters + (d2.feet * 12 + d2.inches)*2.54;
	d3.meters = temp / 100;
	d3.centimeters= temp % 100;
	return d3;
}
Distance2 Add_2(Distance1 d1, Distance2 d2)
{
	Distance2 d3;
	int temp;
	temp = (d1.meters * 100 + d1.centimeters + (d2.feet * 12 + d2.inches)*2.54)/2.54;
	d3.feet = temp /12;
	d3.inches = temp %12;
	return d3;
}
int main()
{
	int a, b,c,d;
	cout<<"enter the distance in meters and cm :";
	cin>> a>> b;
	printf("enter the distance in feet and inches :");
	cin>>c>>d;
	Distance1 d1(a,b), d2;
	Distance2 d3(c,d), d4;
	d2 = Add_1(d1, d3);
	d4 = Add_2(d1, d3);
	d2.display();
	d4.display();
	getchar();
	getchar();
	return 0;
}