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
void display_list(struct Node* headptr);


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

    struct Node* head = NULL;
    create_list(&head, 10);
    display_list(head);
    
    // Create an iterator for growing the linked list
    
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
    Traverse a linkedlist and print the data of each node.
 */
void display_list(struct Node* headptr){
    
    // Create an iterator, to traverse the given linkedlist
    struct Node* iterator = headptr;
    printf("Linkedlist contents are: ");
    // Using while loop
    while(iterator!=NULL){
        // Print data of current node and move to next node
        printf("%d ", iterator->data);
        iterator = iterator->next;
    }
    printf("\n");
}
