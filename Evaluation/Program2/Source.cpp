#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string.h>
class myString
{

	char *name;
	int length;

public:

	myString()
	{
		name = NULL;
		length = 0;
	}

	myString(const char *s)
	{
		name = new char[strlen(s) + 1];
		strcpy(name, s);
		length = strlen(s);
	}

	myString(const myString &s)
	{

		name = new char[s.length + 1];
		strcpy(name, s.name);
		length = s.length;
	}

	void printString()
	{
		cout << endl << name;
	}
	void getString()
	{
		name = new char[20];
		cin >> name;
	}


	~myString()
	{
		if (name != NULL)
			delete[]name;
	}

	myString operator=(myString c)
	{
		delete[]name;
		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
		length = c.length;
		return (*this);
	}


    myString operator+(myString &c)
	{

		myString temp;
		temp.length = length + c.length;
		temp.name = new char[temp.length + 1];
		strcpy(temp.name, name);
		strcat(temp.name, c.name);
		return temp.name;
	}
	char  operator[](int index)
	{
		if (index >= length)
			cout << "\n invalid arguments";
		else
			return (name[index]);
	}
	friend ostream& operator<<(ostream &cout, const myString &c);
	friend istream& operator>>(istream &cin, myString &c);
	friend void sort(myString names[], int size);
	friend int operator<(myString &s1, myString &s2);
};


ostream& operator<<(ostream &cout, const myString &c)
{
	cout << c.name;
	return cout;
}
istream& operator>>(istream &cin, myString &c)
{
	char buffer[100];
	cin >> buffer;
	c.name = new char[strlen(buffer) + 1];
	c.length = strlen(buffer);
	strcpy(c.name, buffer);
	return cin;
}
void sort(myString names[], int size)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (strcmp(names[j].name, names[j + 1].name) > 0) {
				myString temp;
				temp = names[j];
				names[j] = names[j + 1];
				names[j + 1] = temp;
			}
		}
	}
}
 int operator<(myString &s1, myString &s2) {
	 int i = strcmp(s1.name, s2.name);
	 return i;
 }
int main()
{
	myString test_str1, testStr2("Hello"), testStr3(testStr2), testStr4, testStr5,testStr6("Surya");
	cout << "Enter the string:";
	test_str1.getString();
	cout << "Entered string is :";
	cout << test_str1;
	cout << endl << "Parameterised constructer string contains :";
	testStr2.printString();
	cout << endl << "copy constructor string has :";
	testStr3.printString();
	testStr4 = testStr2;
	cout << endl << "deep copied string has :";
	testStr4.printString();
	cout << endl << "After concatinating ";
	testStr5 = testStr2 + testStr6;
	cout << testStr5 << endl;
	cout << testStr5[9];
	cout << "Performing bubble sort" << endl;
	cout << "enter the no of names you require" << endl;
	int namesize;
	cin >> namesize;
	myString *names = new myString[namesize];
	for (int i = 0; i < namesize; i++) {
		cin >> names[i];
	}
	sort(names, namesize);
	cout << "After sorting list is" << endl;
	for (int i = 0; i < namesize; i++) {
		cout << names[i] << endl;
	}
	system("pause");
	return 0;
}



