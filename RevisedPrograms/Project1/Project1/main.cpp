#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define ERROR -99999
#include"Arithmetic.h"
#define _CRT_SECURE_NO_WARNINGS
struct Stack
{
	float data;
	struct Stack* next;
};

struct Stack* newNode(float data)
{
	struct Stack* Node =
		(struct Stack*) malloc(sizeof(struct Stack));
	Node->data = data;
	Node->next = NULL;
	return Node;
} 
void push(struct Stack** head, float data)
{
	struct Stack* Node = newNode(data);
	Node->next = *head;
	*head = Node;
}
int isEmpty(struct Stack *head)
{
	return !head;
}
float  pop(struct Stack** head)
{
	if (isEmpty(*head))
		return ERROR;
	struct Stack* temp = *head;
	*head = (*head)->next;
	float pop = temp->data;
	free(temp);
    return pop;
}

float peek(struct Stack* head)
{
	if (isEmpty(head))
		return ERROR;
	return head->data;
}
int precedence(char c)
{
	if (c == '/' || c == '*')
		return 2;
	else if (c == '-' || c == '+')
		return 1;
	else if (c == '(' || c == '[')
		return -2;
	else
		return -1;
}
char* infix_post()
{
	char *str1 = (char *)malloc(sizeof(char) * 30);
	char *temp = (char *)malloc(sizeof(char) * 30);
	char *str = (char *)malloc(sizeof(char) * 30);
	char ch;
	int k = 0,i;
	printf("enter the expression :");
	scanf_s("%[^\n]s", str1,30);
	for (i = 0; str1[i] != '\0'; i++)
	{
		if (isdigit(str1[i]))
		{
			str[k++] = str1[i++];
			while (str1[i] != '/0'&&isdigit(str1[i]))
			{
				str[k++] = str1[i++];

			}
			str[k++] = '@';
		}
		if (str1[i] != '\0')
			str[k++] = str1[i];
		else
		{
			break;
		}
	}
	str[k] = '\0';
	struct Stack* root = NULL;
	for (int i = 0; str[i] != '\0'; i++)
	{   
		
		ch = str[i];
		
		if (ch == '*' || ch == '+' || ch == '-' || ch == '/')
		{
			if (isEmpty(root))
			{
				push(&root,ch);
			}
			else
			{
				if (precedence(ch) > precedence(peek(root)))
				{
					push(&root, ch);
				}
				else
				{
					while ((!isEmpty(root)) && (precedence(ch) <= precedence(peek(root))))
					{
						temp[k] = pop(&root);
						k++;
					}
					push(&root, ch);
				}
			}

		}
		else if (ch == '(' || (ch == '['))
		{
			push(&root, ch);
		}
		else if (ch == ')' || ch == ']')
		{
			if (str[i + 1] != '\0' &&str[i+1]==')'&&str[i+1]==']'&&(str[i + 1] != '+') && (str[i + 1] != '-') && (str[i + 1] != '*') && (str[i + 1] != '/'))
			{
				printf("Invalid expression");
				getchar();
				getchar();
				exit(0);
			}
			while ((!isEmpty(root)) && ((peek(root) != '['&&ch == ']') || (peek(root) != '('&&ch == ')')))
			{
				temp[k] = pop(&root);
				k++;
			}
			if(isEmpty(root))
				{
				printf("Invalid expression");
				getchar();
				getchar();
				exit(0);
			    }
			pop(&root);
		}
		else
		{   
			if (!isdigit(str[i]))
			{
				printf("Invalid expression");
				getchar();
				getchar();
				exit(0);
			}
			else
			{
				
				while (str[i] != '@')
				{
					temp[k++] = str[i++];
				}
				temp[k] = str[i];
				k++;
			}
		}
	}
	while (!isEmpty(root))
	{

		temp[k] = pop(&root);
		k++;
	}
	
		temp[k] = '\0';
		free(str);
		return temp;

}
int main()
{
	char *str = (char *)malloc(sizeof(char) * 30);
	float a, b,temp;
	float res;
	struct Stack* root = NULL;
	str = infix_post();
	if (str!=NULL)
	{
		
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
				push(&root,temp);
			}
			else if (str[i] == '*')
			{
				a = pop(&root);
				b = pop(&root);
				if (a == ERROR || b == ERROR)
				{
					printf("Invalid expression");
					getchar();
					getchar();
					exit(0);
				}
				push(&root, mul(b, a));
			}
			else if (str[i] == '-')
			{
				a = pop(&root);
				b = pop(&root);
				if (a == ERROR || b == ERROR)
				{
					printf("Invalid expression");
					exit(0);
				}
				push(&root, sub(b, a));
			}
			else if (str[i] == '/')
			{
				a = pop(&root);
				b = pop(&root);
				if (a == ERROR || b == ERROR)
				{
					printf("Invalid expression");
					exit(0);
				}
				push(&root, division(b, a));
	       
			}
			else if (str[i] == '+')
			{
				a = pop(&root);
				b = pop(&root);
				if (a == ERROR || b == ERROR)
				{
					printf("Invalid expression");
					exit(0);
				}
				push(&root, add(b, a));
			}
		}
		
		res = pop
		
		(&root);
		if (res != ERROR)
		{
			printf("the result is %f", res);
		}
		else
			printf("Invalid expression");
	}
	else
		printf("Invalid expression ");
	getchar();
	getchar();
	return 0;
}