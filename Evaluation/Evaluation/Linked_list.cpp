
#include<stdio.h>
#include<malloc.h>
struct List
{
	int data;
	struct node *next;
};
void addAtBeginning(struct List **start, int data)
{
	struct List *newNode = (struct List*)malloc(sizeof(struct List));
	newNode->data = data;
	newNode->next = NULL;
	newNode->next = *start;
	*start = newNode;
}
void addAtEnd(struct List **start, int data)
{

	if (*start == NULL)
	{
		addAtBeginning(start, data);
	}
	else
	{
		struct List *newNode = (struct List*)malloc(sizeof(struct List));
		newNode->data = data;
		newNode->next = NULL;
		struct List *currentPosition;
		currentPosition = (*start);
		while (currentPosition->next != NULL)
		{
			currentPosition = currentPosition->next;
		}
		currentPosition->next = newNode;

	}

}
void AddAtPosition(struct List **start, int position, int data)
{
	if (position == 1)
	{
		addAtBeginning(start, data);
	}
	else
	{
		struct List *currentPosition;
		currentPosition = *start;
		while (currentPosition != NULL && position >= 2)
		{
			if (position == 2)
			{
				struct List *newNode = (struct List*)malloc(sizeof(struct List));
				newNode->data = data;
				newNode->next = currentPosition->next;
				currentPosition->next = newNode;
				return;
			}
			else
			{
				currentPosition = currentPosition->next;
				position--;
			}

		}
		printf("Position out of bounds");
	}
}
void display(struct List *start)
{
	struct List *ptr;
	ptr = start;
	while (ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
}
int main()
{
	struct List *list1 = NULL;
	addAtEnd(&list1, 9);
	addAtBeginning(&list1, 3);
	addAtBeginning(&list1, 5);
	addAtEnd(&list1, 99);
	AddAtPosition(&list1, 1, 44);
	AddAtPosition(&list1, 2, 484);
	AddAtPosition(&list1, 7, 4842);
	display(list1);
}

