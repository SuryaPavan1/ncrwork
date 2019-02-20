#include<iostream>
using namespace std;
struct _stack_
{
	char *s;
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
		sta.s = new char[n];
	}
	void Push(char);
	char pop();
	char peek();
	bool isEmpty();
	bool isFull();
	void display();
};
void Stack::Push(char a)
{
	if (!isFull())
	{
		sta.s[++sta.top] = a;
	}
	else
		cout << "stack is full";
}
char Stack::pop()
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
char Stack::peek()
{
	char x = -1;
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
int main()
{
	char str[20], temp[20],ch;
	int k=0;
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
					while ((!s1.isEmpty())&&(precedence(ch) <= precedence(s1.peek())))
					{
						temp[k]=s1.pop();
						cout << " k  " << temp[k] << endl;
						k++;
				    }
					s1.Push(ch); 
				}
			}

		}
		else if (ch == '(' || (ch == '['))
		{
			s1.Push(ch);
		}
		else if (ch == ')' || ch == ']')
		{
			while ((!s1.isEmpty()) && ((s1.peek() != '['&&ch == ']') || (s1.peek() != '('&&ch == ')')))
			{
				if (s1.peek() == '(' || s1.peek() == '[')
				{
					cout << "invalid";
					return -1;
				}
				temp[k] = s1.pop();
				k++;
			}
			if (!s1.isEmpty())
			{
				s1.pop();
			}
		}
		else
		{
			temp[k] = str[i];
			k++;
		}
	}
	while (!s1.isEmpty()&&(s1.peek()!='('&&s1.peek()!='['))
	{ 
		
		temp[k] = s1.pop();
		k++;
	}
	if (s1.isEmpty())
	{
		temp[k] = '\0';
		cout << temp;
	}
	else
	{
		cout << "invalid";
		system("pause");
	}
	getchar();
	getchar();
	return 0;
}