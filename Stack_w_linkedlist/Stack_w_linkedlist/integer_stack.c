//
//  integer_stack.c
//  Stack_w_linkedlist
//
//  Created by jjkhan on 8/20/21.
//

#include <stdio.h>
#include "integer_stack.h"
#include <stdlib.h>
#include <limits.h>

// =========== Node Operation Implementation ===========

// Allocate memory for a node and initialize it
node_int* INT_create_node(int data){
    
    node_int *temp = (node_int *)malloc(sizeof(node_int));
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
void INT_STACK_Init(int_stack *s){
    s->top=NULL;
}

// This function is used to push new elements on to the stack iff memory for a new node can be allocated - i.e. stack is not full
void INT_STACK_push(int_stack *s, int data){
    
    // Request memory for a new node
    node_int *newNode = INT_create_node(data);
    
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
void INT_STACK_display(int_stack s){
    
    while(s.top!=NULL){
        
        // Print current node data
        printf("%d ", s.top->data);
        
        // Move top pointer to the next element
        s.top = s.top->next;
        
    }
    printf("\n");
}

// Remove the top of the stack and update top pointer to the next node iff the stack is not empty -> i.e. top!=NULL
int INT_STACK_pop(int_stack *s){
    // Place holder for value popped from the stack
    int x = INT_MIN;
    
    
    if(s->top){
        
        // Stack is not empty
        
        // Temporay pointer for updating deleting node that is popped
        node_int *temp =  s->top;
        
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
int INT_STACK_peak(int_stack s, int position){
    
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
// Returns top element of the stack
int INT_STACK_top(int_stack s){
    
    if(s.top){
        // top pointer is not NULL, i.e. stack not empty
        return s.top->data;
    }
    // Return space if nothing there
    return INT_MIN;
}

// Check if the top pointer of the stack is not NULL
int INT_STACK_isEmpty(int_stack s){
    if(s.top){
        // top pointer is not NULL, i.e. stack is not empty
        return 0;
    }
    return 1;
}

// Try allocating memory for a node from heap, if not successfull, the stack is full
int INT_STACK_isFull(void){
    
    // Allocate memory for a node with random data
    node_int *temp = INT_create_node(1);
    
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
