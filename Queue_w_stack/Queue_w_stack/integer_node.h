//
//  integer_node.h
//  Queue_w_stack
//
//  Created by jjkhan on 8/22/21.
//

#ifndef integer_node_h
#define integer_node_h

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
        Note: Data stored in node is integer but the program can easily be adapted for any data.
 */
// Building block of linkedlist
typedef struct NODE node;
struct NODE{
    
    int data;
    node *next;
};


// Node Methods
node* create_node(int data);

#endif /* integer_node_h */
