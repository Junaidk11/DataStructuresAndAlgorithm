//
//  integer_stack.h
//  Queue_w_stack
//
//  Created by jjkhan on 8/22/21.
//

#ifndef integer_stack_h
#define integer_stack_h

#include <stdio.h>
#include "integer_node.h"

// Stack implementation using Linkedlist
struct STACK{
    node *top;
};
typedef struct STACK stack;


// Stack Methods
void STACK_Init(stack *s);
int STACK_pop(stack *s);
void STACK_push(stack *s, int data);
int STACK_top(stack s);
void STACK_display(stack s);
int STACK_isEmpty(stack s);
int STACK_isFull(stack s);
int STACK_peek(stack s, int position);

#endif /* integer_stack_h */
