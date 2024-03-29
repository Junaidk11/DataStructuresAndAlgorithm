//
//  char_stack.c
//  Stack_w_linkedlist
//
//  Created by jjkhan on 8/20/21.
//

#include "char_stack.h"

// =========== Node Operation Implementation ===========

// Allocate memory for a node and initialize it
node* create_node(char data){
    
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
void STACK_push(stack *s, char data){
    
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
char STACK_pop(stack *s){
    // Place holder for value popped from the stack
    //int x = INT_MIN;
    char x=' ';
    
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
char STACK_peak(stack s, int position){
    
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
    return ' ';
}
// Returns top element of the stack
char STACK_top(stack s){
    
    if(s.top){
        // top pointer is not NULL, i.e. stack not empty
        return s.top->data;
    }
    // Return space if nothing there
    return ' ';
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
