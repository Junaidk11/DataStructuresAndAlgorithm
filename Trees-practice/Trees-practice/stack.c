//
//  stack.c
//  Trees-practice
//
//  Created by jjkhan on 8/25/21.
//

#include "stack.h"
#include <limits.h>
// Basci stack operations

void STACK_Init(stack *st){
    st->top = NULL;
}
stack_node* STACK_create_node(tree_node *address){
    
    // Create stack node pointer
    stack_node *newNode = (stack_node*)malloc(sizeof(stack_node));
    
    if(newNode){
        // New node memory allocated successfully
        newNode->address = address;
        newNode->next = NULL;
    }else{
        printf("Heap is full. Unable to allocate memory for new node of stack.\n");
    }
    
    return newNode;
}
/*
    Add the given tree_node address to the stack iff the stack is not full. Stack nodes are allocated from heap, if heap can't
    allocate memory for new node, stack is full.
 */
void STACK_push(stack *st, tree_node *address){
    
    // Create a new stack
    stack_node *newNode = STACK_create_node(address);
    
    // First check if the new node memory allocated
    if(newNode){
        
        // Check if this is the first node in the stack
        if(st->top==NULL){
            
            // this is the first node in the stack
            
            // point the top of the stack to the new node
            st->top = newNode;
        }else{
            
            // Not the first node in the stack
            
            // Add the new node to the top of the stack
            newNode->next=st->top;
            
            // update top of the stack pointer
            st->top = newNode;
        }
        
    }else{
        printf("Heap is full. Unable to create new node for the stack.\n");
    }
}

/*
    Remove the top node of the stack iff the stack is not empty, return the tree_node address of the top element of the stack.
 */
tree_node* STACK_pop(stack *st){
    
    // Pointer to the address of the tree node removed from top of stack
    tree_node *popped_address = NULL;
    
    // temp pointer
    stack_node *temp = NULL;
    
    if(st->top!=NULL){
        // Stack is not empty.
        
        // use a temp pointer to point to the top of the stack
        temp = st->top;
        
        // Get the address stored in the top node of stack
        popped_address = temp->address;
        
        // update top pointer of the stack to the next node
        
        st->top = st->top->next;
        
        // free node
        free(temp);
        
    }else{
        printf("Stack underflow.\n");
    }
    
    // return address popped from the stack
    return popped_address;
}


int STACK_isEmpty(stack st){
    if(st.top){
        //  Not emtpy
        return 0;
    }
    
    // stack is empty
    return 1;
}

/*
    Return data of top node of the stack
 */
int STACK_top(stack st){
    if(st.top){
        return st.top->address->data;
    }else{
        // Stack is empty
        return INT_MIN;
    }
}
