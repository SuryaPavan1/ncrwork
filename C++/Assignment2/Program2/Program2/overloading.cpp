#include<iostream>
#include<String>
using namespace std;
class Student
{
	long int roll;
	string Student_Name;
	int marks1, marks2, marks3;
	int total_marks;
	char grade;
	
public:
	static int student_count;
	Student()
	{
	}
	friend istream & operator>>(istream &in, Student &s);
	friend ostream & operator<<(ostream &out, Student &s);
	friend void results(Student *s, int n);
};
int Student::student_count = 1;
ostream & operator << (ostream &out, Student &s)
{
	out << s.roll << "\t \t" << s.Student_Name << " \t \t " << s.marks1 << "\t \t" << s.marks2 << "\t \t" << s.marks3 << "\t \t" << s.total_marks << "\t \t "<<s.grade<<endl;
	return out;
}
istream & operator>>(istream &in, Student &s)
{
	{
		cout << "\n Enter student name : ";
		in >> s.Student_Name;
		s.roll = Student::student_count;
		Student::student_count = Student::student_count + 1;
		cout << "\n Enter three subject marks : " << endl;
		in >> s.marks1;
		in >> s.marks2;
		in >> s.marks3;
		return in;
	}
}
void results(Student *s, int n)
{
	int i = 0, avg;
	for (i = 0; i < n; i++)
	{
		s[i].total_marks = s[i].marks1 + s[i].marks2 + s[i].marks3;
		avg = s[i].total_marks / 3;
		if (avg > 60)
		{
			s[i].grade = 'A';
		}
		else if (50 < avg && 60 > avg)
		{
			s[i].grade = 'B';
		}
		else if (40 < avg && 50 > avg)
		{
			s[i].grade = 'C';
		}

		else
		{
			s[i].grade = 'F';
		}
	}
}
int main()
{
	int n, i;
	cout << "\n Enter number of students : ";
	cin >> n;
	Student *s = new Student[n];
	for (i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	results(s, n);
	cout << "Roll number \t Name \t \t Marks1 \t Marks2 \t Marks3 \t Total Marks \t Grade" << endl;
	for (i = 0; i < n; i++)
	{
		cout << s[i];
	}
	system("pause");
	return 0;
}