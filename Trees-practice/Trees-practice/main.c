//
//  main.c
//  Trees-practice
//
//  Created by jjkhan on 8/24/21.
//

#include <stdio.h>
#include "tree.h"


/*
    
    E.g. Tree
               Root
                8
          3            5
        4   9       7     2
 */

// Test Programs
void TEST_create_a_tree(void);
void TEST_tree_traversal(void);

int main(int argc, const char * argv[]) {
    
    TEST_tree_traversal();
    return 0;
}

// Recursive Pre-order passed.
// Recursive In-order passed.
// Recursive Post-order passed.
void TEST_tree_traversal(void){
    
    // Create root node of the tree
    tree_node *root = create_treenode(8);
    
    // Declare and initialize a queue to create the rest of the sample tree above
    queue tree_nodes;
    
    // add root node into queue
    QUEUE_enqueue(&tree_nodes, root);
    
    // Call helper function to create the rest of tree
    create_tree(&tree_nodes);
    
    // Pre order traversal of the tree
    printf("Pre-Order Traversal of tree: ");
    pre_order(root);
    printf("\n");
    
    // In-order traversal of the tree
    printf("In-Order Traversal of tree: ");
    in_order(root);
    printf("\n");
    
    // Post-order traversal of the tree
    printf("Post-Order Traversal of tree: ");
    post_order(root);
    printf("\n");
    
}
// Test passed. 
void TEST_create_a_tree(void){
    
    // Create a root node first
    tree_node *root = create_treenode(5);
    
    // Declare and initialize a queue to store tree nodes
    queue tree_nodes;
    
    // Push the root node of the tree in to the queue
    QUEUE_enqueue(&tree_nodes, root);
    
    // Now you add more nodes to the tree by simply typing in any positive or negative integer data except -1.
    // First integer is left-child data and second integer is right-child data
    // -1 indicates that the node's respective child is not there, i.e.  its NULL.
    create_tree(&tree_nodes);
    
    
    printf("Tree created.");
    
    
}
