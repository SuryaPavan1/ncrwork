#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class Student
{
	int x;
	char *name;
public:
	Student(int z, char *y)
	{
		int size = strlen(y);
		x = z;
		name = new char[size + 1];
		strcpy(name, y);

	}
	Student(const Student &s)
	{
		int p = strlen(s.name);
		name = new char[p + 1];
		x = s.x;
		strcpy(name, s.name);
	}
	void display()
	{
		cout << x << " " << name << endl;
	}
};
int main()
{
	char n[10];
	cin >> n;
	Student s1(1, n);
	s1.display();
	Student s2 = s1;
	s2.display();
	getchar();
	getchar();
	return 0;
}