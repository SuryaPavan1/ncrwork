#include<iostream>
#include<math.h>
using namespace std;
class Point
{
	int x_coordinate;
	int y_coordinate;
public:
	Point()
	{
		x_coordinate = y_coordinate = 0;
	}
	Point(int x, int y)
	{
		x_coordinate = x;
		y_coordinate = y;
	}
	void display()
	{
		cout << "(" << x_coordinate << "," << y_coordinate << ")";
	}
	friend float distance(Point p1, Point p2);
};
float  distance(Point p1, Point p2)
{
	float result;
	result = sqrtf(powf(p1.x_coordinate - p2.x_coordinate, 2) + powf(p1.y_coordinate - p2.y_coordinate, 2));
		return result;
 }
int main()
{
	int a, b, c, d;
	float res;
	cout << "Enter the x and y coordinates";
	cin >> a >> b;
	cout << "Enter the x and y coordinates";
	cin >> c >> d;
	Point p1(a, b), p2(c, d);
	res = distance(p1, p2);
	cout << "\nThe distance betwwen two points is " << res;
	getchar();
	getchar();
	return 0;
}