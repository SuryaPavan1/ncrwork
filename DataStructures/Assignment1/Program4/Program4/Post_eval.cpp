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
	for (int i = 0; i < n + 1; i++)
	{
		cout << sta.s[i] << " ";
	}
}

int main()
{
	char str[30];
	int a, b, res,c,temp;
	Stack s1(20);
	cout << "enter the postfix expression";
	cin >> str;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 48 && str[i] <= 58)
		{
			temp = 0;
			while (str[i] != '@')
			{
				temp = int(str[i] - 48) + temp * 10;
				i++;
			}
			s1.Push(temp);
		}
		else if (str[i] == '*')
		{
			a = s1.pop();
			b = s1.pop();
			s1.Push(b*a);
		}
		else if (str[i] == '-')
		{
			a = s1.pop();
			b = s1.pop();
			s1.Push(b - a);
		}
		else if (str[i] == '/')
		{
			a = s1.pop();
			b = s1.pop();
			s1.Push(b / a);
		}
		else if (str[i] == '+')
		{
			a = s1.pop();
			b = s1.pop();
			s1.Push(b + a);
		}
	}
	res = s1.pop();
	cout << "the result is" << res;
	getchar();
	getchar();
	return 0;
}
