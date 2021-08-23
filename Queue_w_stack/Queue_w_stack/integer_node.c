//
//  integer_node.c
//  Queue_w_stack
//
//  Created by jjkhan on 8/22/21.
//

#include "integer_node.h"

// =================== Node Methods ===================
node* create_node(int data){
    
    // Allocate memory from heap for node and initialize it
    node *newNode = (node *)malloc(sizeof(node));
    
    // Check if memory allocation successfull
    if(newNode){
        // memory allocation successfull, initialize the node
        newNode->data = data;
        
        // return newNode address
        return newNode;
    }
    
    // Memory allocation unsuccessful -> heap is full, which means Stack is full
    return NULL;
}
// =================== Node Methods ===================
