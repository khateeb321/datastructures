#include <stdio.h>
#include <conio.h>

/// for explanation http://quiz.geeksforgeeks.org/linked-list-set-1-introduction/

struct node
{
	int data;
	struct node *next;
};

void printList(struct node *n)
{
	while (n != NULL)
	{
		printf(" %d ", n->data);
     	n = n->next;
	}
}

int main()
{
	struct node *head = NULL;
	struct node *second = NULL;
	struct node *third = NULL;
	
	head = malloc(sizeof(struct node));
	second = malloc(sizeof(struct node));
	third = malloc(sizeof(struct node));
	
	head -> data = 1;
	head -> next = second;
	second -> data = 2;
	second -> next = third;
	third -> data = 3;
	third -> next = NULL;
	
	printList(head);
	
	getch();
}
