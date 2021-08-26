//
//  queue.h
//  Trees-practice
//
//  Created by jjkhan on 8/24/21.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <stdlib.h>

// Tree building block
typedef struct TREE_NODE tree_node;
struct TREE_NODE{
    tree_node *left_child;
    tree_node *right_child;
    int data;
};

// Queue building Block
typedef struct QUEUE_NODE queue_node;
struct QUEUE_NODE{
    // Data = address of a tree node
    tree_node *data;
    
    // Pointer to next tree node
    queue_node *next;
};


// Queue Structure
typedef struct QUEUE queue;
struct QUEUE{
    // pointers to the front and rear of the queue
    // For dequeuing
    queue_node *front_ptr;
    // For enqueing
    queue_node *rear_ptr;
};


// Tree Node Operations
tree_node* create_treenode(int data);

// Queue Node Functions
queue_node* QUEUE_createNode(tree_node *address);

// Queue Operations
void QUEUE_initialize(queue *q);
tree_node* QUEUE_dequeue(queue *q);
void QUEUE_enqueue(queue *q, tree_node *address);
int QUEUE_isFull(queue q);
int QUEUE_isEmpty(queue q);


// Additional Functions
void create_tree(queue* nodes);

// Tree Traversals
void Recursive_pre_order(tree_node* node);
void Recursive_in_order(tree_node* node);
void Recursive_post_order(tree_node* node);
void Iterative_pre_order(tree_node* node);
void Iterative_in_order(tree_node* node);
void Iterative_post_order(tree_node* node);
void level_order(tree_node* node);


#endif /* queue_h */
