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

/* Given a node prev_node, insert a new node after the given
   prev_node */
void insertAfter(struct node* prev_node, int new_data)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL) 
    { 
       printf("the given previous node cannot be NULL");       
       return;  
    }  
          
    /* 2. allocate new node */
    struct node* new_node =(struct node*) malloc(sizeof(struct node));
  
    /* 3. put in the data  */
    new_node->data  = new_data;
  
    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next; 
  
    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node;
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
	
	insertAfter(second, 9);
	printList(head);
	
	getch();
}
