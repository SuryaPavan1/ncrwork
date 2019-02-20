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
int precedence(char c)
{
	if (c == '/' || c == '*')
		return 2;
	if (c == '-' || c == '+')
		return 1;
	if (c == '('||c=='[')
		return -2;
}
char* infix_post()
{
	char str[20];
	char *temp = new char[30];
	char ch;
	int k = 0;
	cout << "enter the expression :";
	cin >> str;
	Stack s1(20);
	for (int i = 0; str[i] != '\0'; i++)
	{
		ch = str[i];
		if (ch == '*' || ch == '+' || ch == '-' || ch == '/')
		{
			if (s1.isEmpty())
			{
				s1.Push(ch);
			}
			else
			{
				if (precedence(ch) > precedence(s1.peek()))
				{
					s1.Push(ch);
				}
				else
				{
					while ((!s1.isEmpty()) && (precedence(ch) <= precedence(s1.peek())))
					{
						temp[k] = s1.pop();
						k++;
					}
					s1.Push(ch);
				}
			}

		}
		else if (ch == '('||(ch=='['))
		{
			s1.Push(ch);
		}
		else if (ch == ')'||ch==']')
		{
			while ((!s1.isEmpty())&&((s1.peek() != '['&&ch==']')|| (s1.peek() != '('&&ch == ')')) )
			{
				temp[k] = s1.pop();
				k++;
			}
			s1.pop();
		}
		else
		{
			temp[k] = str[i];
			k++;
		}
	}
	while (!s1.isEmpty())
	{

		temp[k] = s1.pop();
		k++;
	}
	if (s1.isEmpty())
	{
		temp[k] = '\0';
		cout << "The post fix expression is " << temp << endl;
		return temp;
	}
	else
	{
		cout << "invalid";
		return NULL;
	}

}
int main()
{
	char *str=new char[30];
	int a,b,res;
	Stack s1(20);
	str = infix_post();
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 48 && str[i] < 58)
		{
			s1.Push(int(str[i] - 48));
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
			s1.Push(b/a);
		}
		else if (str[i] == '+')
		{
			a = s1.pop();
			b = s1.pop();
			s1.Push(b+a);
		}
	}
	res = s1.pop();
	cout << "the result is" << res;
	getchar();
	getchar();
	return 0;
}
