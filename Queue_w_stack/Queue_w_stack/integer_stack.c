//
//  integer_stack.c
//  Queue_w_stack
//
//  Created by jjkhan on 8/22/21.
//

#include "integer_stack.h"



// =================== Stack Methods ===================

// Initialize top pointer of stack to NULL
void STACK_Init(stack *s){
    
    // NOTE: In some compilers 's' already initialized to NULL - gives error here if you try to initialize NULL with NULL
    
    s->top = NULL;
    
    
}

// Pop top element of the stack iff the stack is not empty
int STACK_pop(stack *s){
    
    // Place holder for element remove
    int data_popped = INT_MIN;
    
    // Check if stack is not empty
    if(STACK_isEmpty(*s)){
        // Stack is empty
        printf("Stack underflow.\n");
    }else{
        
        // Stack is not empty, remove top element and update top pointer
        
        // Temp node pointer to free memory after retrieving its data
        node *temp = s->top;
        
        data_popped = temp->data;
        
        // Update top of the stack pointer to next element
        s->top = s->top->next;
        
        // return removed node memory back to heap
        free(temp);
    }
    // Will return INT_MIN is stack is empty else the data removed from top of stack
    return data_popped;
}

// Push element to the top of the stack -> i.e. add new node to the front of the list iff node memory allocation
// successfull -> i.e. heap is not full, which means Stack is not full

void STACK_push(stack *s, int data){
    
    // New node
    node *newNode = create_node(data);
    
    // Check if node memory allocated
    if(newNode){
        // Node created successfull
        
        // add the node to the front of the list
        newNode->next = s->top;
        
        // Update top pointer of the stack to the newNode
        s->top = newNode;
        
    }else{
        // Node creation unsuccessfull -> stack overflow
        printf("Stack overflow.\n");
    }

    
    
}

// Return top of stack data iff the stack is not empty
int STACK_top(stack s){
    int top_element = INT_MIN;
    if(STACK_isEmpty(s)){
        printf("Stack is empty.\n");
    }else{
        // Retrieve data of the top of Stack
        top_element = s.top->data;
    }
    
    return top_element;
}

// Display stack content starting from top
void STACK_display(stack s){
    
    printf("Stack contents are: ");
    
    // The stack is passed by value, so its a copy -> can use the top pointer to traverse the stack
    while(s.top!=NULL){
        
        printf(" %d", s.top->data);
        
        // Move top to the next node
        s.top = s.top->next;
    }
    printf("\n");
}
// Check if top of the stack is pointing to NULL
int STACK_isEmpty(stack s){
    if(s.top==NULL){
        return 1;
    }
    return 0;
}
// Since stack is implemented using a linkedlist, try allocating memory for a new node from heap,
// If successfull, stack is not FULL else it is FULL because heap is full
int STACK_isFull(stack s){
    
    // New node
    node *newNode=create_node(1);
    
    // Check if memory allocation successfull
    if(newNode){
        // Memory allocation successfull, heap not full, therefore the stack is not full
        
        // return allocated memory first
        free(newNode);
        
        // Return false to indicate stack not full
        return 0;
    }
    
    // Indicate stack is full because heap is full
    return 1;
}

// Position is the element of the stack from top to the bottom of stack: i.e. position 1 == top of stack and down you go.
int STACK_peek(stack s, int position){
    
    int retrived_data = INT_MIN;
    
    // Check if stack is empty
    if(STACK_isEmpty(s)){
        // Stack is empty
        printf("Stack is empty.\n");
    }else{
        // Stack is not empty
        
        int i;
        for(i=0; i<position; i++){
            // Move top pointer of the stack, down the stack
            s.top = s.top->next;
        }
        
        // Make sure the pointer is valid
        if(s.top){
            // Now top is pointing to the desired position
            retrived_data = s.top->data;
        }else{
            printf("Invalid position.\n");
        }
        
    }
    return retrived_data;
}

// =================== Stack Methods ===================
