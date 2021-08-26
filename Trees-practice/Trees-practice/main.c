//
//  main.c
//  Trees-practice
//
//  Created by jjkhan on 8/24/21.
//

#include <stdio.h>
#include "tree.h"
#include "stack.h"


/*
    
    E.g. Tree
               Root
                8
          3            5
        4   9       7     2
 */



// Functions
int count_total_number_of_nodes(tree_node *node);
int count_nodes_with_degree_two(tree_node *node);
int sum_of_all_nodes_data(tree_node *node);
int calculate_height_of_tree(tree_node *node);


// Test Programs
void TEST_create_a_tree(void);
void TEST_tree_traversal(void);
void TEST_operations_on_tree(void);


int main(int argc, const char * argv[]) {
    
    TEST_operations_on_tree();
    return 0;
}

// Counting total number of nodes in the tree: psssed.
// Counting number of nodes with degree two: passed.
// Sum of all node data in the tree: passed.
// Height of tree : passed but still needs to be worked on - will work but the logic is iffy.
void TEST_operations_on_tree(void){
    
    // Create a root node for your tree first
    tree_node *root = create_treenode(8);
    
    // Declare and initialize a queue to create the rest of the sample tree
    queue tree_nodes;
    QUEUE_initialize(&tree_nodes);
    
    // Add the root node to the queue
    QUEUE_enqueue(&tree_nodes, root);
    
    // Call helper function to create the rest of the tree
    create_tree(&tree_nodes);
    
    //leve;-order traversal of the tree
    printf("Level-Order Traversal of tree: ");
    level_order(root);
    printf("\n");
    
    // Count the number of nodes in the tree
    printf("Number of nodes in the tree are: %d \n", count_total_number_of_nodes(root));
    
    // Count the number of nodes in the tree
    printf("Number of nodes in the tree with degree two: %d \n", count_nodes_with_degree_two(root));
    
    // Count the number of nodes in the tree
    printf("Sum of all data in the tree %d \n", sum_of_all_nodes_data(root));
    
    // Count the number of nodes in the tree
    printf("Height of tree is %d \n", calculate_height_of_tree(root));
    
    
}
// Recursive & Iterative Pre-order passed.
// Recursive & Iterative In-order passed.
// Recursive & Iterative Post-order passed.
// Iterative Level order Passed.
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
    printf("Recursive Pre-Order Traversal of tree: ");
    Recursive_pre_order(root);
    printf("\n");
    
    printf("Iterative Pre-Order Traversal of tree: ");
    Iterative_pre_order(root);
    printf("\n");
    
    // In-order traversal of the tree
    printf("In-Order Traversal of tree: ");
    Recursive_in_order(root);
    printf("\n");
    
    printf("Iterative In-Order Traversal of tree: ");
    Iterative_in_order(root);
    printf("\n");
    
    // Post-order traversal of the tree
    printf("Post-Order Traversal of tree: ");
    Recursive_post_order(root);
    printf("\n");
    
    printf("Iterative Post-Order Traversal of tree: ");
    Iterative_post_order(root);
    printf("\n");
    
    //level-order traversal of the tree
    printf("Level-Order Traversal of tree: ");
    level_order(root);
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


/*
    In this function you're counting the number of nodes in a given tree.
    The function is recursive and is similar to post-order traversal
    of a tree.
    
    Note: Most of the operations you perform on a tree are done in post-order. This simple function can be adapted to
          many different things on the tree.
 
 */
int count_total_number_of_nodes(tree_node *node){
    
    int left_subtree_nodes, right_subtree_nodes;
    if(node!=NULL){
        // Count the number of nodes in the left subtree of current node first
        left_subtree_nodes = count_total_number_of_nodes(node->left_child);
        
        // Count the number of nodes in the right subtree of current node next
        right_subtree_nodes = count_total_number_of_nodes(node->right_child);
        
        // Counting every node in the tree
        // The '1' accounts for the current node
        return left_subtree_nodes+right_subtree_nodes+1;
    }
    // This is the base case of the recursive function. I.e. when you reach the leaf nodes's children (which are NULL),
    // return 0 to go back to the leaf node level.
    return 0;
}


/*
   Same as previous function with a minor change to only count if the current node has a degree of 2
 
    Note: Most of the operations you perform on a tree are done in post-order. This simple function can be adapted to
          many different things on the tree.
 
    In  this setup, the counter only counts the current node if it has a degree of 2, i.e. a left child and right child, else for nodes
    with degrees 0 or 1, the x and y only returns 0.
 
 */
int count_nodes_with_degree_two(tree_node *node){
    int left_subtree_degree_2_nodes, right_subtree_degree_2_nodes;
    if(node!=NULL){
        // Count the number of nodes with degree two in the left subtree of current node first
        left_subtree_degree_2_nodes = count_nodes_with_degree_two(node->left_child);
        
        // next, Count the number of nodes with degree two in the right subtree of current node
        right_subtree_degree_2_nodes = count_nodes_with_degree_two(node->right_child);
        
        // Count current node only if the current node has a degree of two
        if(node->left_child && node->right_child){
            // Current node has degree of 2
            // Both left and right child exist
            // The '1' accounts for the current node
            return left_subtree_degree_2_nodes+right_subtree_degree_2_nodes+1;
        }else{
            // Don't count current node if the current node doesn't have both left and right child - i.e. degree of 2
            return left_subtree_degree_2_nodes+right_subtree_degree_2_nodes;
        }
    }
    // This is the base case of the recursive function. I.e. when you reach the leaf nodes's children (which are NULL),
    // return 0 to go back to the leaf node level.
    return 0;
}

/*
    This function returns the sum of all the nodes data.
 
    Similar to previous functions, just a minor change.
 */
int sum_of_all_nodes_data(tree_node *node){
    
    int left_subtree_sum, right_subtree_sum;
    
    if(node!=NULL){
        
        // get sum of left subtree nodes
        left_subtree_sum = sum_of_all_nodes_data(node->left_child);
        
        // getn sum of right subtree nodes
        right_subtree_sum = sum_of_all_nodes_data(node->right_child);
        
        // add current nodes sum to the left and right subtree sum
        return left_subtree_sum+right_subtree_sum+node->data;
    }
    
    // This is the base case of the recursive function. I.e. when you reach the leaf nodes's children (which are NULL),
    // return 0 to go back to the leaf node level.
    return 0;
}

/*
    Calculating height of a tree : this function returns the height as actual height + 1 -> i.e. takes root node to be at height 1 if you
    return 0 at base case.
 */
int calculate_height_of_tree(tree_node *node){
    
    int left_subtree_height=0, right_subtree_height=0;
    
    // Base case
    if(node==NULL){
        return -1; // If we return = 0 we get the height as actualHeight+1 b/c root node considered as height 1
    }
    
    // Recursive calls
    left_subtree_height = calculate_height_of_tree(node->left_child);
    right_subtree_height = calculate_height_of_tree(node->right_child);
    
    
    if(left_subtree_height>right_subtree_height){
        return left_subtree_height+1;
    }else{
        return right_subtree_height+1;
    }

}
