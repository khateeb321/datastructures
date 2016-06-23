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

/// Double pointer is used because function catches the value in aurguments, if we don't send address and does not change at address level, then we are just changing values, not values at addresses.
void push(struct node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
  
    /* 2. put in the data  */
    new_node->data  = new_data;
  
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);
  
    /* 4. move the head to point to the new node */
    (*head_ref)    = new_node;  //When we traverse, we start from head, here we are assigning new node the referance of head, new node is head now. Old head refereance? It's in new node's next.
    
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
	
	push(&head, 0);
	printList(head);
	
	getch();
}
