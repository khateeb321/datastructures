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

/// double refereance, again we need head
void append (struct node **head_ref, int new_data)
{
	struct node *new_node = malloc(sizeof(struct node));
	
	new_node->data = new_data;
	new_node->next = NULL;
	
	if (*head_ref == NULL)  // if no node, make new node head
	{
		*head_ref = new_node;
		return;
	}
	
	struct node *last = *head_ref;
	while (last->next != NULL)   // traverse till last to make it second last
	{
		last = last->next;
	}
	last->next = new_node;
	
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
	
	append(&head, 4);
	
	printList(head);
	
	getch();
}
