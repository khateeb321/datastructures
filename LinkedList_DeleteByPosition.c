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

/* Given a reference (pointer to pointer) to the head of a list
   and a position, deletes the node at the given position */
void deleteNode(struct node **head_ref, int position)
{
   // If linked list is empty
   if (*head_ref == NULL)
      return;
 
   // Store head node
   struct node* temp = *head_ref;
 
    // If head needs to be removed
    if (position == 0)
    {
        *head_ref = temp->next;   // Change head
        free(temp);               // free old head
        return;
    }
 
    // Find previous node of the node to be deleted
    int i;
    for (i=0; temp!=NULL && i<position-1; i++)
         temp = temp->next;
 
    // If position is more than number of ndoes
    if (temp == NULL || temp->next == NULL)
         return;
 
    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    struct node *ahead = temp->next->next;
 
    // Unlink the node from linked list
    free(temp->next);  // Free memory
 
    temp->next = ahead;  // Unlink the deleted node from list
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
	
	deleteNode(&head, 1);
	
	printList(head);
	
	getch();
}
