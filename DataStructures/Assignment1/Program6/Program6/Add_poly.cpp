#include<iostream>
using namespace std;
struct node
{
	int data;
	int pow;
	struct node *next;
};
class Linked_list
{
	node *start;
public:
	Linked_list()
	{
		start = NULL;
	}
	void Insert_last(int data,int pow);
	void display();
	friend Linked_list Add(Linked_list l1, Linked_list l2);
};

void Linked_list::Insert_last(int data,int pow)
{
	struct node *temp;
	temp = new node;
	temp->data = data;
	temp->pow = pow;
	temp->next = NULL;
	if (start == NULL)
	{
		start = temp;
	}
	else
	{
		struct node *curr;
		curr = start;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = temp;
	}
}

void Linked_list::display()
{
	if (start != NULL)
	{
		struct node *curr;
		curr = start;
		while (curr != NULL)
		{
			cout <<"+"<< curr->data << "x"<<curr->pow;
			curr = curr->next;
		}
	}
}
Linked_list Add(Linked_list L1, Linked_list L2)
{
	Linked_list l3;
	int n;
	struct node *currl1, *currl2;
	currl1 = L1.start;
	currl2 = L2.start;
	while (currl1 != NULL && currl2 != NULL)
	{
		if (currl1->pow == currl2->pow)
		{
			n = currl1->data + currl2->data;
			l3.Insert_last(n, currl1->pow);

			if (currl1->next == NULL)
			{
				while (currl2->next!= NULL)
				{
					l3.Insert_last(currl2->data, currl2->pow);
					currl2 = currl2->next;
				}
			}
			else if (currl2->next == NULL)
			{
				while (currl1->next != NULL)
				{
					l3.Insert_last(currl1->data, currl1->pow);
					currl1 = currl1->next;
				}
			}
			else
			{
				currl1 = currl1->next;
				currl2 = currl2->next;
			}
		}
		else if (currl1->pow > currl2->pow)
		{
			l3.Insert_last(currl1->data, currl1->pow);
			if (currl1->next == NULL)
			{
				while (currl2!= NULL)
				{
					l3.Insert_last(currl2->data, currl2->pow);
					currl2 = currl2->next;
				}
			}
			else
			{
				currl1 = currl1->next;
			}

		}
		else if (currl1->pow < currl2->pow)
		{
			l3.Insert_last(currl2->data, currl2->pow);
			if (currl2->next == NULL)
			{
				while (currl1!= NULL)
				{
					l3.Insert_last(currl1->data, currl1->pow);
					currl1 = currl1->next;
				}
			}
			else
			{
				currl2 = currl2->next;
			}
		}
		
	}
	return l3;
}
	int main()
	{
		Linked_list l1, l2,l3;
		l1.Insert_last(5, 4);
		l2.Insert_last(6, 3);
		l1.Insert_last(5, 3);
		l2.Insert_last(6, 1);
		l1.Insert_last(5, 2);
		l3 = Add(l1, l2);
		l3.display();
		getchar();
		getchar();
		return 0;
	}


