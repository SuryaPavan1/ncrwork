#include<iostream>
#include<string>
using namespace std;
class Employee
{
	string name;
	int emp_no;
	int salary;
public:
	static int emp_count;
	Employee()
	{
		emp_no = 0;
		salary = 0;
	}
	~Employee()
	{}
	friend istream & operator>>(istream &in, Employee &s);
	friend void display(Employee *s, int n);
};
int Employee::emp_count = 1;
istream & operator>>(istream &in, Employee &s)
{
	cout << "\n Enter Employee name : ";
	in >> s.name;
	s.emp_no = Employee::emp_count;
	Employee::emp_count = Employee::emp_count + 1;
	cout << "\n Enter Salary : " << endl;
	in >> s.salary;
	return in;
}

void display(Employee *s, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		cout << s[i].emp_no << "\t \t" << s[i].name << " \t \t " << s[i].salary << endl;
	}
}
int main()
{
	int n, i;
	cout << "\n Enter number of Employees : ";
	cin >> n;
	Employee *s = new Employee[n];
	for (i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	cout << "Employenumber \t Name \t \t Salary \t" << endl;
	display(s, n);
	system("pause");
}