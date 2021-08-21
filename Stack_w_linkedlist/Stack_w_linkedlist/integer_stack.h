//
//  integer_stack.h
//  Stack_w_linkedlist
//
//  Created by jjkhan on 8/20/21.
//

#ifndef integer_stack_h
#define integer_stack_h

// =================  Integer  STACK  =================

typedef struct NODE_INT node_int;
struct NODE_INT {
    int data;
    node_int *next;
};


// Node Operations
node_int* INT_create_node(int data);

/*
    The stack holds pointer to the top element of the Stack.
    Since the nodes are allocated memory from the Heap, the size of the stack is limited by heap allocating memory when requested.
        This can be used to determine if the stack is full by looking at the output of malloc call for new node creation.
 */
typedef struct INT_STACK{
    node_int *top;
}int_stack;


// integer Stack Operation
void INT_STACK_Init(int_stack *s);
void INT_STACK_display(int_stack s);
void INT_STACK_push(int_stack *s, int data);
int INT_STACK_pop(int_stack *s);
int INT_STACK_peak(int_stack s, int position);
int INT_STACK_top(int_stack s);
int INT_STACK_isEmpty(int_stack s);
int INT_STACK_isFull(void);
// =================  Integer STACK  =================

#endif /* integer_stack_h */
