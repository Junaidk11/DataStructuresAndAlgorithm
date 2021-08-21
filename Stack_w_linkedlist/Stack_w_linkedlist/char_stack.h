//
//  char_stack.h
//  Stack_w_linkedlist
//
//  Created by jjkhan on 8/20/21.
//

#ifndef char_stack_h
#define char_stack_h

#include <stdio.h>
#include "char_stack.h"
#include <stdlib.h>

// =================  CHARACTER STACK  =================
/*
   Node structure for creating stack contents. Here we're assuming the node data is of type int, could be changed as desired.
    
    // Changed data to char
 */
typedef struct NODE node;
struct NODE {
    char data;
    node *next;
};

// Node Operations
node* create_node(char data);

/*
    The stack holds pointer to the top element of the Stack.
    Since the nodes are allocated memory from the Heap, the size of the stack is limited by heap allocating memory when requested.
        This can be used to determine if the stack is full by looking at the output of malloc call for new node creation.
 */
typedef struct STACK{
    node *top;
}stack;

// Character Stack Operation
void STACK_Init(stack *s);
void STACK_display(stack s);
void STACK_push(stack *s, char data);
char STACK_pop(stack *s);
char STACK_peak(stack s, int position);
char STACK_top(stack s);
int STACK_isEmpty(stack s);
int STACK_isFull(void);

// =================  CHARACTER STACK  =================


#endif /* char_stack_h */
