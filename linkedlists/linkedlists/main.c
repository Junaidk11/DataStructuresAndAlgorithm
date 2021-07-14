//
//  main.c
//  linkedlists
//
//  Created by jjkhan on 7/13/21.
//
#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node{
    int data;
    struct Node* next;
};

// Operations
struct Node* createNode(int data);
void create_list(struct Node** headptr, int size);
void display_list_iterative(struct Node* headptr);
void display_list_recursive(struct Node* headptr);

// Test Programs
int user_input(void);
void create_and_display_linkedlist(void);

int main(int argc, const char * argv[]) {
    // insert code here...
    create_and_display_linkedlist();
    
    return 0;
}

int user_input(void){
    int data;
    // Need a new line to take user input!
    printf("Enter node data:\n");
    scanf("%d", &data);
    return data;
}

// Test passed.
void create_and_display_linkedlist(void){

    // Create head of the linkedlist
    struct Node* head = NULL;
    create_list(&head, 3);
    display_list_iterative(head);
    display_list_recursive(head);
    printf("\n");
    
    
}

/*
    Given the head pointer of a linked list. Take user input, create node, link all nodes,
    to create a list.
    Number of nodes to create is given by size.
 
    The double pointer is needed because in C everything is passed by value.
        The double pointer stores the address of a pointer.
            Visually: headptr_address -> headptr -> firstNode
                        If you dereference once, you get the address stored in headptr, i.e. (*headptr_address)
                        If you dereference twice, you get the data stored in firstNode, i.e. *(*headptr_address)
            
    Note:
        The 'headptr' pointer from the called function has a different location than the
        'headptr' created in this function (i.e. only contents of headptr from calling function is
        passed into this function, not the place holder of the 'headptr'. Therefore,
        you pass the exact address of the 'headptr' to store the nodes created in this function.
     
 */
void create_list(struct Node** headptr_address, int size){
    
    // Headptr should be pointing to nothing to create a list of given 'size'
    // single dereferencing, you're accessing the address stored in the pointer pointed to by
    // headptr
    // double dereferencing is used to access the value in the address pointed to by the pointer
    // pointed by headptr.
    if((*headptr_address)!=NULL){
        printf("List population failed.\n");
        return;
    }else{
        
        // Create first node of the list
        int input = user_input();
        (*headptr_address) = createNode(input);
        size--;
        
        // Create a pointer to traverse the linkedlist
        // iterator pointing to first node right now
        struct Node* iterator = (*headptr_address);
        
        // Create the remaining nodes
        while(size!=0){
            // Get user input for data of the node
            input = user_input();
            // Create a node and initialize it with user data
            // and linked current node to the new node created
            iterator->next = createNode(input);
            // Move iterator forward to the new node
            iterator = iterator->next;
            size--;
        }
    }
}

/*
    Allocate Memory for a node in heap, initialize it with given data
    and return its memory.
 */
struct Node* createNode(int data){
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/*
    Traverse a linkedlist given the headpointer and print the data of each node.
 
    The headptr in this function argument is not the same address of the headptr
    in the main function -> i.e. the pointer to the function is passed by value.
    
    So, you can use the given headptr to traverse the list without having to create
    an iterator pointer to traverse the list, i.e. you won't lose the head of the list because
    the actual headptr address is different from the headptr used in this function, although both
    point to the same list.
    
 */
void display_list_iterative(struct Node* headptr){
    
    printf("Linkedlist contents are: ");
    
#if 1
    // Using while loop
    while(headptr!=NULL){
        // Print data of current node and move to next node
        printf("%d ", headptr->data);
        headptr = headptr->next;
    }
#elif 0
    // Using for-lopp
    for(;headptr!=NULL;headptr=headptr->next){
        // Print data of current node and move to next node
        printf("%d ", headptr->data);
    }
#endif
    printf("\n");
}

/*
    In this function, the linkedlist is traversed recursively.
    The work done here is simply printing, and we're visiting each node once, therefore, the time
    taken is O(n).
    The number of recursive calls for the linkedlist of n nodes is always n+1, because the
    recursion stops at NULL. Therefore, the space complexity is O(n) but n+1 activation records
    are created in stack.
 
    The time taken to traverse the list recursively and iteratively is the same -> O(n).
    However, recursive traversal takes more space in stack than an iterative traversal.
 
    Moreover, with recursion you can print the linkedlist in reverse by first going to the next node
    and printing/processing the current node when you return from the next node.
    
 */
void display_list_recursive(struct Node* headptr){
    
    // Recursion base case
    if(headptr!=NULL){
#if 1
        // For printing/process the nodes in reverse
        // i.e. last node processed first, first node
        // processed last
        
        // Process next node first
        display_list_recursive(headptr->next);
        // process the current node on return
        printf("%d ",headptr->data);
#elif 0
        // For printing/processing the current node first
        
        // process the current node first
        printf("%d ", headptr->data);
        // Process next node
        display_list_recursive(headptr->next);
        
#endif
    }
}
