#include<iostream>
using namespace std;
struct _stack_ 
{
	int *s;
	int top;
	int size;
};
class Stack
{
	struct _stack_ sta;
public:
	Stack() {
	 sta.s = NULL;
	 sta.top = -1;
	 sta.size = 0;
	}
	Stack(int n)
	{
		sta.size = n;
		sta.top = -1;
		sta.s = new int[n];
	}
	void Push(int);
	int pop();
	int peek();
	bool isEmpty();
	bool isFull();
	void display();
};
void Stack::Push(int a)
{
	if (!isFull())
	{
		sta.s[++sta.top] = a;
	}
	else
		cout << "stack is full";
}
int Stack::pop()
{
	if (!isEmpty())
	{
		return sta.s[sta.top--];
	}
	else
	{
		cout << "stack is empty";
		return -999;
	}
}
int Stack::peek()
{
	int x = -1;
	if (sta.top == -1 || sta.top == sta.size - 1)
	{
		return x;
	}
	else
	return sta.s[sta.top];
}

bool Stack::isEmpty()
{
	return (sta.top == -1);
}
bool Stack::isFull()
{
	return(sta.top == sta.size - 1);
}
void Stack::display()
{
	int n = sta.top;
	cout << n << endl;
	for (int i = 0; i <n+1; i++)
	{
		cout << sta.s[i]<<" ";
	}
}
int main()
{
	char c[30],ch;
	Stack s1(30);
	cout << "enter the expression :";
	cin >> c;
	for (int i = 0; c[i] != '\0'; i++)
	{
		ch = c[i];
		if (ch == '(' || ch == '[' || ch == '{')
		{
			s1.Push(ch);
		}
   		else if (ch==')'||ch==']'||ch=='}')
		{
			if ((s1.peek() == '('&&ch == ')') || (s1.peek() == '['&&ch == ']') || (s1.peek() == '{'&&ch == '}'))
			{
				s1.pop();
			}
			else
			{
				cout << "Th given string is not balanced";
				system("pause");
				exit(0);
			}
		}
			 
	}
	if (s1.isEmpty())
	{
		cout << "the given expression is balanced";
	}
	getchar();
	getchar();
	return 0;
}