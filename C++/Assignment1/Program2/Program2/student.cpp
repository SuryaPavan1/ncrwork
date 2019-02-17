#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class student
{
	char *name;
	char grade;
	int m1, m2, m3;
public:
	void setdata(char *Studentname, char g, int marks1, int marks2, int marks3)
	{
		name = (char*)malloc(20);
		strcpy(name, Studentname);
		grade = g;
		m1 = marks1;
		m2 = marks2;
		m3 = marks3;
	}
	int average(int m1, int m2, int m3)
	{
		return (m1 + m2 + m3) / 3;
	}
	char compute_grade(int avg)
	{
		if (avg > 60)
		{
			cout << "first class";
			return 'A';
		}
		else if (50 < avg&&avg > 60)
		{
			cout << "Second class";
			return 'B';
		}
		else if (40 < avg && 50 > avg)
		{
			cout << "Third Class";
			return 'C';
		}

		else
		{
			cout << "FAIL";
			return 'F';
		}
	}
	void display()
	{
		cout << "\n\n Student name is :" << name;
		cout << "\n Grade:" << grade;
		cout << "\n Marks:" << m1;
		cout << " " << m2;
		cout << " " << m3;
	}
};
int main()
{
	student s1;
	char name[10];
	cout << "enter student name ";
	cin >> name;
	int m1, m2, m3;
	cout << "Enter marks ";
	cin >> m1;
	cin >> m2;
	cin >> m3;
	int avg;
	avg = s1.average(m1, m2, m3);
	char grade = s1.compute_grade(avg);
	s1.setdata(name, grade, m1, m2, m3);
	s1.display();
	getchar();
	getchar();
	return 0;
}