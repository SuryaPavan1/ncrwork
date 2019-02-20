#include<iostream>
using namespace std;
struct node
{
	int data;
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
	void Insert_first(int data);
	void Insert_last(int data);
	void Insert_afer(int pos, int data);
	void Insert_before(int pos, int data);
	int Delete_beg();
	int Delete_last();
	int Delete_dat(int data);
	void display();
};
void Linked_list::Insert_first(int data)
{
	struct node *temp;
	temp = new node;
	temp->data = data;
	temp->next = NULL;
	start = temp;
}
void Linked_list::Insert_last(int data)
{
	struct node *temp;
	temp = new node;
	temp->data = data;
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
void Linked_list::Insert_afer(int pos,int data)
{
	if (start != NULL)
	{
		struct node *curr;
		curr = start;
		while (curr != NULL && curr->data != pos)
		{
			curr = curr->next;
		}
		if (curr != NULL)
		{
			struct node *temp;
			temp = new node;
			temp->data = data;
			temp->next = NULL;
			curr->next = temp;
		}
		else
			cout << "not found";
	}
	else cout << "empty";
}
void Linked_list::Insert_before(int pos, int data)
{
	if (start != NULL)
	{
		if (start->data == pos)
		{
			struct node *temp;
			temp = new node;
			temp->data = data;
			temp->next = start;
			start = temp;
		}
		else
		{
			struct node *curr;
			curr = start;
			while (curr->next != NULL && curr->next->data != pos)
			{
				curr = curr->next;
			}
			if (curr->next != NULL)
			{
				struct node *temp;
				temp = new node;
				temp->data = data;
				temp->next = curr->next;
				curr->next = temp;
			}
			else
				cout << "not found";
		}
	}
}
void Linked_list::display()
{
	if (start!=NULL)
	{
		struct node *curr;
		curr = start;
		while (curr != NULL)
		{
			cout << curr->data<<" ";
			curr = curr->next;
		}
	}
}
int Linked_list::Delete_beg()
{
	int X = -999;
	if (start != NULL)
	{
		struct node *temp;
		temp = start;
		start = start->next;
		X = temp->data;
	}
	return X;
	
}
int Linked_list::Delete_last()
{
	int X = -999;
	if (start != NULL)
	{
		struct node *temp,*curr;
		curr=start;
		while (curr->next->next != NULL)
		{
			curr = curr->next;
		}
		temp = curr->next;
		X = temp->data;
		delete temp;
		curr->next = NULL;
	}
	return X;
}
int Linked_list::Delete_dat(int data)
{
	int X = -999;
	if (start != NULL)
	{
		struct node *temp, *curr;
		curr = start;
		if (start->data == data)
		{
			temp = start;
			start = start->next;
			X = temp->data;
		}
		while (curr->next != NULL && curr->next->data != data)
		{
			curr = curr->next;
		}
		if (curr->next != NULL)
		{
			temp = curr->next;
			curr->next = temp->next;
		}
	}
	return X;
}
int main()
{
	Linked_list List;
	List.Insert_first(10);
	List.Insert_last(20);
	List.Insert_afer(20, 30);
	List.Insert_before(10, 5);
	List.Insert_before(20, 15);
	List.Delete_beg();
	List.Delete_last();
	List.Delete_dat(5);
	List.display();
	system("pause");
	return 0;

}