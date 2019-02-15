#include<iostream>
#include<string.h>
using namespace std;
class student
{

	char studentName[30];
	char grade;
	int marks1, marks2, marks3;
    public:
		char *getStudentName()
		{
			return studentName;
	     }
		char getGrade()
		{
			return grade;
		}
	void stud(char studName[30])
	{
		strcpy_s(studentName, studName);
	}
	void grad(char ch)
	{
		grade = ch;
	}
	void marks(int  m1, int m2, int m3)
	{
		marks1 = m1;
		marks2 = m2;
		marks3 = m3;
	}
	int m1()
	{
		return marks1;
	}
	int m2()
	{
		return marks2;
	}
	int m3()
	{
		return marks3;
	}
};
class CollegeCourse
{
	int avg;
 public:
	student set_Data(char studentName[30], char grade, int  marks1, int marks2, int mark3)
	{
		student s;
		s.stud(studentName);
		s.grad(grade);
		s.marks(marks1, marks2, mark3);
		return s;
	}
	void calculateAverage(student &s)
	{
		avg= (s.m1() + s.m2() + s.m3()) / 3.0;
	}
	void ComputeGrade()
	{
		if (avg > 60)
			cout << "first class";
		else if (avg > 50 && avg > 60)
			cout << "second class";
		else if (avg > 40 && avg < 50)
			cout << "third class";
		else
			cout << "fail";
	}
	void display(student &s)
	{
		cout<<"StudentName :"<< s.getStudentName()<<endl;
		cout << "grade :" << s.getGrade();

	}

};
int main()
{
	CollegeCourse c1;
	char st[30] = "surya";
	student s1;
	s1= c1.set_Data(st, 'a', 90, 90, 90);
	c1.display(s1);
	c1.ComputeGrade();

	system("pause");
}
