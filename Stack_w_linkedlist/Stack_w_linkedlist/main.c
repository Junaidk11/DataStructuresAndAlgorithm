//
//  main.c
//  Stack_w_linkedlist
//
//  Created by jjkhan on 8/19/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
   Node structure for creating stack contents. Here we're assuming the node data is of type int, could be changed as desired.
 */
typedef struct NODE node;
struct NODE {
    int data;
    node *next;
};

// Node Operations
node* create_node(int data);

/*
    The stack holds pointer to the top element of the Stack.
    Since the nodes are allocated memory from the Heap, the size of the stack is limited by heap allocating memory when requested.
        This can be used to determine if the stack is full by looking at the output of malloc call for new node creation.
 */
typedef struct STACK{
    node *top;
}stack;


// Stack Operation
void STACK_Init(stack *s);
void STACK_display(stack s);
void STACK_push(stack *s, int data);
int STACK_pop(stack *s);
int STACK_peak(stack s, int position);
int STACK_isEmpty(stack s);
int STACK_isFull(void);



// Program functions
void STACK_ADT_test(void);


int main(int argc, const char * argv[]) {
    
    STACK_ADT_test();
    return 0;
}

// Function testing all the operations of the stack implemented using a linkedlist -
void STACK_ADT_test(void){
    
    stack integerNumbers;
    STACK_Init(&integerNumbers);
        
    // Check if stack is empty
    printf("Is stack empty? %d\n", STACK_isEmpty(integerNumbers));
    
    // Check if stack is full
    printf("Is stack full? %d \n", STACK_isFull());
    
    // Just call push function to add to the stack
    STACK_push(&integerNumbers, 5);
    STACK_push(&integerNumbers, 11);
    STACK_push(&integerNumbers, 45);
    STACK_push(&integerNumbers, 98);
    STACK_push(&integerNumbers, 123);
    
    // Display stack
    STACK_display(integerNumbers);
    
    // Peak stack
    printf("Stack element at position 1: %d\n", STACK_peak(integerNumbers, 1));
    printf("Stack element at position 2: %d\n", STACK_peak(integerNumbers, 2));
    printf("Stack element at position 4: %d\n", STACK_peak(integerNumbers, 4));
    printf("Stack element at position 6: %d\n", STACK_peak(integerNumbers, 6));
    
    
    // Pop from stack
    printf("Element popped from the stack: %d\n", STACK_pop(&integerNumbers));
    STACK_display(integerNumbers);
    printf("Element popped from the stack: %d\n", STACK_pop(&integerNumbers));
    STACK_display(integerNumbers);
    printf("Element popped from the stack: %d\n", STACK_pop(&integerNumbers));
    STACK_display(integerNumbers);
    
    // Check if stack is empty
    printf("Is stack empty? %d\n", STACK_isEmpty(integerNumbers));
    
    // Check if stack is full
    printf("Is stack full? %d \n", STACK_isFull());
    
}


// =========== Node Operation Implementation ===========

// Allocate memory for a node and initialize it
node* create_node(int data){
    
    node *temp = (node *)malloc(sizeof(node));
    if(temp){
        // Memory allocation successfull, initialize it with data and return pointer
        temp->data = data;
        return temp;
    }
    
    // Memory allocation not successfull i.e. stack overflow
    return NULL;
}
// =========== Node Operation Implementation ===========

// =========== Stack Operation Implementation ===========

// Simple initialization of the stack's top pointer
void STACK_Init(stack *s){
    s->top=NULL;
}

// This function is used to push new elements on to the stack iff memory for a new node can be allocated - i.e. stack is not full
void STACK_push(stack *s, int data){
    
    // Request memory for a new node
    node *newNode = create_node(data);
    
    // Check if memory successfully allocated
    if(newNode){
        // Memory allocated successfully.
        
        // Add new node to the front of the Stack
        newNode->next = s->top;
        
        // update top of the stack
        s->top = newNode;
    }else{
        // Memory allocation for new node not successfull
        printf("Stack overflow.\n");
    }
}

// Diplay the content of the stack, the stack is passed by value, so its a copy
// The stack is passed by value so its a copy of the original stack created in main, HOWEVER, the "top" pointer inside stack copy
// is pointer to the original head of the stack, so don't move that - HENCE the need for *temp at start.
void STACK_display(stack s){
    
    while(s.top!=NULL){
        
        // Print current node data
        printf("%d ", s.top->data);
        
        // Move top pointer to the next element
        s.top = s.top->next;
        
    }
    printf("\n");
}

// Remove the top of the stack and update top pointer to the next node iff the stack is not empty -> i.e. top!=NULL
int STACK_pop(stack *s){
    // Place holder for value popped from the stack
    int x = INT_MIN;
    
    if(s->top){
        
        // Stack is not empty
        
        // Temporay pointer for updating deleting node that is popped
        node *temp =  s->top;
        
        // Get the data in top element of stack
        x = temp->data;
        
        // Update top to the next element of the stack
        s->top = s->top->next;
        
        // Return the allocated memory of the node removed from stack
        free(temp);
        temp = NULL;
    }
    
    // This will return top data from stack or will return INT_MIN if the stack was empty
    return x;
    
}

// This function will move the top pointer to the position given and return its data.
// The stack is passed by value so its a copy of the original stack created in main.
int STACK_peak(stack s, int position){
    
    // Move top pointer to the position given
    int i;
    for(i=1; i<position && s.top!=NULL; i++){
        // Move top pointer to the next node in the stack
        s.top = s.top->next;
    }
    
    // Check if the top is pointing to a valid node before you return the data of the node
    if(s.top){
        // Valid node, return its data
        return s.top->data;
    }
    
    // The stack is empty, return this
    return INT_MIN;
}
// Check if the top pointer of the stack is not NULL
int STACK_isEmpty(stack s){
    if(s.top){
        // top pointer is not NULL, i.e. stack is not empty
        return 0;
    }
    return 1;
}

// Try allocating memory for a node from heap, if not successfull, the stack is full
int STACK_isFull(void){
    
    // Allocate memory for a node with random data
    node *temp = create_node(1);
    
    // Check if memory allocation successful
    if(temp){
        // Memory allocated successfully
        // Return the allocated memory
        free(temp);
        
        // Return false because stack is not full i.e. was able to allocate memory from heap
        return 0;
    }
    
    // Unable to allocate memory from heap - return true to indicate stack is full
    return 1;
}
// =========== Stack Operation Implementation ===========
