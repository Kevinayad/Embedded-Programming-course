#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
 
//#### Constants ##### 
#define MAX 5   
 
// ##### typedefs          #### 
typedef struct q{ 
        int number; 
        struct q *next; 
        struct q *prev; 
} REGTYPE; 
 
// ##### Function declarations   ##### 
 
REGTYPE* random_list(void); 
REGTYPE* add_first(REGTYPE* temp, int data); 
void printList(REGTYPE *head);
 
//###### Main program ####### 
int main(int argc, char *argv[]) 
{ 
    int nr=0; 
 
    REGTYPE *act_post , *head=NULL; 
 
    srand(time(0));  //   Random seed  
    head=random_list(); 
    act_post=head; 
    while( act_post!=NULL){ 
           printf("\n Post nr %d : %d" , nr++, act_post->number); 
           act_post=act_post->next; 
    }   
     printf("\n");
     printList(add_first(head, 1)); // Adds a node with value 1 as the head, and prints out the list in both in normal and reverse ordering.
 // --- Free the allocated memory  --- 
 
  while((act_post=head)!=NULL){ 
     head=act_post->next; 
     free(act_post); 
  } 
   

    return 0; 
} 
 
// ====     End of main   ====================================== 
 
REGTYPE* random_list(void) { 
    int randomNumber = rand() % 100;
    REGTYPE *head = NULL, *prevPointer, *nextPointer; // Create head of list

    for (int i = 0; i < MAX; i++) {
        REGTYPE *node = (struct q*)malloc(sizeof(struct q)); // Allocate memory for new struct instance
        randomNumber = rand() % 100; // Generate random number for the list node
        node -> number = randomNumber; // Set the node number to the random number
        if (head == NULL) { // If head is NULL we set the current node to be the head.
            node -> prev = NULL; // Because we know the linked list is empty we set both prev and next pointers to point to null.
            node -> next = NULL;
            head = node; // Head is now set to our current node
        } else {
            REGTYPE *currentHead = head; // Creates a pointer to our head
            while (currentHead -> next != NULL) // Using this new pointer we traverse the list until we find the tail.
            {
                currentHead = currentHead -> next;
            }
            currentHead -> next = node;
            node -> prev = currentHead;
            node -> next = NULL;
        }
    }
    return head;
} 

void printList(REGTYPE *head)  {
    REGTYPE *current = head; // Pointer to head
    REGTYPE *tail;
    while (current != NULL) {    // Loops over the list
        if (current->next == NULL) // Once we hit the tail we save it to the tail variable
            tail = current;     
        printf(" <- %i ->", current->number); // We print the current node number at every iteration
        current = current -> next; // Sets current node to equal next node to traverse list
    }
     printf("\r");
    while (tail != NULL) { // We know traverse the list backwards to make sure the prev pointers all point to the correct node
        printf(" <- %i ->", tail->number); // Print current node value.
        tail = tail -> prev; // Set new node to the prev of current node to traverse it in reverse.
    }
     printf("\r");
}
//==========================================================                 
 
REGTYPE* add_first(REGTYPE* temp, int data) {
    REGTYPE *node = (struct q*)malloc(sizeof(struct q)); // Allocates memory to new node
    node -> number = data; // Sets node value to data 
    node -> next = temp; // Makes the nodes next pointer point to the previous head of the linked list
    temp -> prev = node; // Makes the previous heads prev pointer point to the new head. 
    return node; // Returns new head
}