//
//  stack.h
//  Trees-practice
//
//  Created by jjkhan on 8/25/21.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


typedef struct STACK_NODE stack_node;
struct STACK_NODE{
    
    tree_node *address;
    stack_node *next;
    
};

typedef struct STACK stack;
struct STACK{
    stack_node *top;
};


// Basci stack operations
void STACK_Init(stack *st);
stack_node* STACK_create_node(tree_node *address);
void STACK_push(stack *st, tree_node *address);
tree_node* STACK_pop(stack *st);
int STACK_isEmpty(stack st);



#endif /* stack_h */
