#include<iostream>
using namespace std;
int n;
int u=-1;
struct node
{
	int data;
	struct node *next;
};
class Linked_list
{
public:
	node *start;
	Linked_list()
	{
		start = NULL;
	}
	node* Insert_first(int data);
	void Insert_last(int data);
	void Insert_afer(int pos, int data);
	void Insert_before(int pos, int data);
	int Delete_beg();
	int Delete_last();
	int Delete_dat(int data);
	void display();
};
node*  Linked_list::Insert_first(int data)
{
	struct node *temp;
	temp = new node;
	temp->data = data;
	temp->next = NULL;
	start = temp;
	return start;
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
void Linked_list::Insert_afer(int pos, int data)
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
	if (start != NULL)
	{
		struct node *curr;
		curr = start;
		while (curr != NULL)
		{
			cout << curr->data << " ";
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
		struct node *temp, *curr;
		curr = start;
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
int adjust(node *s)
{
	if (s == NULL) {
		u = 0;
		return 0;
	}
	if (s->data == n) {
		u = 1;
		return 1;
	}
	adjust(s->next);
	if (u==1) {
		int temp;
		temp = s->data;
		s->data = s->next->data;
		s->next->data = temp;
	}

}

int main()
{
	Linked_list s;
	struct node *temp,*temp1;
	s.Insert_first(10);
	s.Insert_last(20);
	s.Insert_last(30);
	cin >> n;
	temp = s.start;
	adjust(s.start);
	if (u == 0) {
		temp1 = s.Insert_first(n);
		temp1->next = temp;
		s.start = temp1;
	}
	else
	{
		s.start = temp;
	}
	s.display();
	system("pause");
}
	/*#include<iostream>
	#include<list>
	using namespace std;
	int main()
	{
		list<int> a;
		int n,temp;
		a.push_front(50);
		a.push_front(30);
		a.push_front(20);
		a.push_front(10);

		int flag = 0;
		cout<< "enter the number";
		cin>> n;
		for (auto i = a.begin(); i != a.end(); ++i)
		{
			if (*i == n)
			{
				auto g=i;
				while (i != a.begin())
				{

					g = i--;
					temp = *g;
					*g = *i;
					*i = temp;
				}
				flag = 1;
				break;
			}

		}
		if (flag == 0)
		{
			a.push_front(n);
		}
		for (auto i = a.begin(); i != a.end(); ++i)
		{
			cout << *i<<endl;
		}
		system("pause");
		return 0;
	}
	*/
