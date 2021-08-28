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
    
    E.g. 1  Tree
 
               Root
                8
          3            5
        4   9       7     2
 */

/*
    
    E.g. 2  Tree
 
                    Root
                    10
          20                30
    40          50
                    60
 
 */

// Create a tree function - Use this to create tree for testing a function - root_data is the root node data
tree_node* createTree(int root_data);
void disply_tree(tree_node *root);

// General Binary Tree Functions
int count_total_number_of_nodes(tree_node *node);
int count_nodes_with_degree_two(tree_node *node);
int count_only_leaf_nodes(tree_node *node);
int count_nodes_with_degree_1_or_2(tree_node *node);
int count_nodes_with_only_degree_1(tree_node *node);
int sum_of_all_nodes_data(tree_node *node);
int calculate_height_of_tree(tree_node *node);

// Binary Search Tree Functions
tree_node* Recurisve_BinarySearch(tree_node* headptr, int key);
tree_node* Iterative_BinarySearch(tree_node* headptr, int key);
void Insert_BST(tree_node *headptr, int key);
tree_node* Recursive_InsertBST(tree_node *nodeptr, int key);

// Test Programs
void TEST_create_a_tree(void);
void TEST_tree_traversal(void);
void TEST_operations_on_tree(void);
void TEST_searchBST(void);
void TEST_insertBST(void);
void TEST_RecursiveCreationOfBST(void);


int main(int argc, const char * argv[]) {
    
    TEST_RecursiveCreationOfBST();
    return 0;
}

/*

        Binary Search Tree

                    Root
                    10
            8                30
        4       9        20       50
          

*/

// Test passed.
void TEST_RecursiveCreationOfBST(void){
    
    // Declare a root pointer of the BST
    tree_node *root = NULL;
    root = Recursive_InsertBST(root, 10);
    
    // Add new Nodes
    Recursive_InsertBST(root, 8);
    Recursive_InsertBST(root, 4);
    Recursive_InsertBST(root, 9);
    Recursive_InsertBST(root, 30);
    Recursive_InsertBST(root, 20);
    Recursive_InsertBST(root, 50);
    
   // In order traversal of BST - should print the tree in ascending order
    Iterative_in_order(root);
    printf("\n");
    
}
void TEST_insertBST(void){
    // Create a Binary Tree
    
    // Use -1 for nodes with no right/left child
    tree_node *root = createTree(10);
    
    
    // Search for key in tree before adding
    tree_node *searchResult = Recurisve_BinarySearch(root, 60);
    
    if(searchResult){
        printf("Key found = %d. Pointer to the node is %p. \n", searchResult->data, &searchResult);
    }else{
        printf("Key not found. \n");
    }
    
    // We're assuming the tree is already populated - so don't have to worry about adding new key to the root
    // so we pass the tree root pointer by value and not by reference
    Insert_BST(root, 60);
    
    
    // Search for key in tree again
    searchResult = Recurisve_BinarySearch(root, 60);
    
    if(searchResult){
        printf("Key found = %d. Pointer to the node is %p. \n", searchResult->data, &searchResult);
    }else{
        printf("Key not found. \n");
    }
    
    
    
}
// Recursive Binary Search on BST - test passed.
// Iterative Binary Search on BST - test passed.
void TEST_searchBST(void){
    // Create a Binary Tree
    
    // Use -1 for nodes with no right/left child
    tree_node *root = createTree(10);
     
    
    // ===== Recursive Implementation ======
    // Search for key in tree
    tree_node *searchResult = Recurisve_BinarySearch(root, 4);
    
    if(searchResult){
        printf("Key found = %d. Pointer to the node is %p. \n", searchResult->data, &searchResult);
    }else{
        printf("Key not found. \n");
    }
    
    // Search for key not in tree
    searchResult = Recurisve_BinarySearch(root, 1);
    
    if(searchResult){
        printf("Key found = %d. Pointer to the node is %p. \n", searchResult->data, &searchResult);
    }else{
        printf("Key not found. \n");
    }

    // ===== Iterative Implementation ======
    
    // Search for key in tree
    searchResult = Iterative_BinarySearch(root, 4);
    
    if(searchResult){
        printf("Key found = %d. Pointer to the node is %p. \n", searchResult->data, &searchResult);
    }else{
        printf("Key not found. \n");
    }
    
    // Search for key not in tree
    searchResult = Iterative_BinarySearch(root, 1);
    
    if(searchResult){
        printf("Key found = %d. Pointer to the node is %p. \n", searchResult->data, &searchResult);
    }else{
        printf("Key not found. \n");
    }
    
}
// Counting total number of nodes in the tree: psssed.
// Counting number of nodes with degree two: passed.
// Counting number of nodes with degree two/one: passed.
// Counting number of nodes with degree zero: passed.
// Sum of all node data in the tree: passed.
// Height of tree : passed but still needs to be worked on - will work but the logic is iffy.
void TEST_operations_on_tree(void){
    
    // Create a root node for your tree first
    tree_node *root = create_treenode(10);
    
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
    printf("Number of nodes in the tree with degree one: %d \n", count_nodes_with_only_degree_1(root));
    

    // Count the number of nodes in the tree
    printf("Number of nodes in the tree with degree 0 (i.e. leaf nodes): %d \n", count_only_leaf_nodes(root));
    
    // Count the number of nodes in the tree
    printf("Number of nodes in the tree with degree one/two: %d \n", count_nodes_with_degree_1_or_2(root));
    
    
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

//  ========== Creating a tree function =======
// Tested and it works.
tree_node* createTree(int root_data){
    // Create root node of the tree
    tree_node *root = create_treenode(root_data);
    
    // Declare and initialize a queue to create the rest of the sample tree above
    queue tree_nodes;
    
    // add root node into queue
    QUEUE_enqueue(&tree_nodes, root);
    
    // Call helper function to create the rest of tree
    create_tree(&tree_nodes);

    return root;
}

//  ========== Creating a tree function =======

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
    The recursive function is same as previous. The only difference is the counting condition.
 
    For a node to be a leaf node, the left and right child pointers should be NULL.
 */
int count_only_leaf_nodes(tree_node *node){
    int left_subtree_degree_0_nodes, right_subtree_degree_0_nodes;
    if(node!=NULL){
        // Count the number of nodes with degree two in the left subtree of current node first
        left_subtree_degree_0_nodes = count_only_leaf_nodes(node->left_child);
        
        // next, Count the number of nodes with degree two in the right subtree of current node
        right_subtree_degree_0_nodes = count_only_leaf_nodes(node->right_child);
        
        // Count current node only if the current node has a degree of 0
        if(node->left_child==NULL && node->right_child==NULL){
            // Current node has degree of 0
            // Both left and right child don't exist - count this node
            // The '1' accounts for the current node
            return left_subtree_degree_0_nodes+right_subtree_degree_0_nodes+1;
        }else{
            // Current node has either left/right child or both - i.e. is not a leaf node
            // Don't count current node
            return left_subtree_degree_0_nodes+right_subtree_degree_0_nodes;
        }
    }
    // This is the base case of the recursive function. I.e. when you reach the leaf nodes's children (which are NULL),
    // return 0 to go back to the leaf node level.
    return 0;
    
}

/*
    The recursive function is same as previous. The only difference is the counting condition.
 
    For a node to be of degree 1 or 2, the left/right or both child pointers should not be NULL.
 */
int count_nodes_with_degree_1_or_2(tree_node *node){
    int left_subtree_internal_nodes, right_subtree_internal_nodes;
    if(node!=NULL){
        // Count the number of nodes with degree two in the left subtree of current node first
        left_subtree_internal_nodes = count_nodes_with_degree_1_or_2(node->left_child);
        
        // next, Count the number of nodes with degree two in the right subtree of current node
        right_subtree_internal_nodes = count_nodes_with_degree_1_or_2(node->right_child);
        
        // Count current node only if the current node has a degree of two or 1
        if(node->left_child!=NULL || node->right_child!=NULL){
            // Current node has degree of 0
            // Both left right child exist or one of them exist - count this node as its an internal node
            // The '1' accounts for the current node
            return left_subtree_internal_nodes+right_subtree_internal_nodes+1;
        }else{
            // Current node has neither left/right child - i.e. is a leaf node
            // Don't count current node
            return left_subtree_internal_nodes+right_subtree_internal_nodes;
        }
    }
    // This is the base case of the recursive function. I.e. when you reach the leaf nodes's children (which are NULL),
    // return 0 to go back to the leaf node level.
    return 0;
    
}

/*
    The recursive function is same as previous. The only difference is the counting condition.
 
    For a node to be of degree 1, either left/right child pointers should not be NULL i.e. both can't exist or both can't be NULL.
 */
int count_nodes_with_only_degree_1(tree_node *node){
    int left_subtree_degree_1_nodes, right_subtree_degree_1_nodes;
    if(node!=NULL){
        // Count the number of nodes with degree two in the left subtree of current node first
        left_subtree_degree_1_nodes = count_nodes_with_only_degree_1(node->left_child);
        
        // next, Count the number of nodes with degree two in the right subtree of current node
        right_subtree_degree_1_nodes = count_nodes_with_only_degree_1(node->right_child);
        
        // Count current node only if the current node has a degree of 1
        if( (node->left_child!=NULL && node->right_child==NULL) ||  (node->left_child==NULL && node->right_child!=NULL)){
            // Current node has degree of 1
            // Only left/right child exist - count this node as its an internal node with degree 1
            // The '1' accounts for the current node
            return left_subtree_degree_1_nodes+right_subtree_degree_1_nodes+1;
        }else{
            // Current node has either both left/right children or neither - i.e. it has a degree of 2 or it is a leaf node
            // Don't count current node
            return left_subtree_degree_1_nodes+right_subtree_degree_1_nodes;
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

/*
    Recursively searching a Binary Search Tree for the given key.
    Time complexity -> Search depends on height of binary tree, which is logn < h < n, we take minimum so -> logn is search time
    
    Since there is no operation performed after the recursive call returns, this a tail recursion - can easily be converte to an iterative
    solution using a while loop
 */
tree_node* Recurisve_BinarySearch(tree_node* headptr, int key){
    
    // base case of recursion
    if(headptr==NULL){
        // key not found in the tree
        return NULL;
    }
    
    // Recursive Calls
    if(headptr->data == key){
        // Key found, return node address
        return headptr;
    }else if(headptr->data > key){
        // the key is in right subtree, if it exists
        return Recurisve_BinarySearch(headptr->left_child, key);
    }else{
        // the key is in left subtree, if it exists
        return Recurisve_BinarySearch(headptr->right_child, key);
    }
}

/*
    The recursive implementation of the binary search on a Binary tree.
    Time complexity: Search time depends on tree height and minimum height of Binary tree is logn, this is the time complexity.
 
    Important note: When converting a recursive function to iterative, sometimes we may need to use a stack. However, for a tail recursion we don't need a stack!
 */
tree_node* Iterative_BinarySearch(tree_node* headptr, int key){
    
    while(headptr!=NULL){
        
        if(key==headptr->data){
            return headptr;
        }else if(key < headptr->data){
            // Key has to be in left subtree, if it exist
            headptr = headptr->left_child;
        }else{
            // Key has to be in right subtree, if it exist
            headptr = headptr->right_child;
        }
    }
    
    // key not found or tree empty
    return NULL;
}

/*
        Inserting a new node into a BST.
        
        The new node is only added if it doesn't exist in the tree. New nodes in a BST are always added as leaf nodes.
        
        First you have to find the parent node of this key node (assuming key is not in the BST) -> if the parent node data is
        greater than key, then insert new node as left child, else as right child.
            First you find the parent node, then you link the new node to it (as left/right child depending on parent node data).
                To be able to do this, you need two tailing pointers, one pointer will search until it reaches the leaf node (i.e. NULL),
                and the other will tail this pointer so that it can be used to link the new node to the parent's respective child pointer.
        
        Time complexity of this is logn because we're searching the tree to find the correct place for the new key and search of
        binary tree depends on the height of the tree - we know binary tree height range is logn - n, we take the min, which is logn.
 */
void Insert_BST(tree_node *headptr, int key){
    
    // The tailing pointer - using headptr to move forward because its a copy of the original headptr
    tree_node *follower = NULL, *newNode = NULL;
    
    // Find the node where the key will go in the BST
    while(headptr!=NULL){
        
        // Move follower where headptr is
        follower = headptr;
        
        // Update forward aka headptr
        if(key==headptr->data){
            // Key already exist - return
            return;
        }else if(key < headptr->data){
            // Key will go in left subtree
            headptr = headptr->left_child;
        }else{
            // Key will go in right subtree
            headptr = headptr->right_child;
        }
    }
    
    // At this point, headptr reached end of tree, follower is pointing to the leaf node where the new key goes
    // Create new node
    newNode = create_treenode(key);
    
    // Link the new node to the existing leaf node
    if(key < follower->data){
        // New node goes to the left child
        follower->left_child = newNode;
    }else{
        follower->right_child = newNode;
    }
    
}


/*
    This is a recursive implementation of creating BST.
 */
tree_node* Recursive_InsertBST(tree_node *nodeptr, int key){
    
    // Pointer for new node
    tree_node *newNode;
    
    if(nodeptr==NULL){
        
        // Reached the end of a tree, create a new node here
        newNode = (tree_node*)malloc(sizeof(tree_node));
        
        if(newNode){
            // memory allocated successfully
            newNode->data = key;
            newNode->right_child = NULL;
            newNode->left_child = NULL;
            return newNode;
        }else{
            printf("Memory allocation for node failed.\n");
        }
        
    }else if(nodeptr->data > key){
        // The new key should go to left subtree
        // Call recursive function on left subtree by passing the left child as root node,
        // At return, the new node will be assigned to the current node's left child
        nodeptr->left_child = Recursive_InsertBST(nodeptr->left_child, key);
    }else{
        // The new key should go to right subtree
        // Call recursive function on right subtree by passing the right child as root node,
        // At return, the new node will be assigned to the current node's right child
        nodeptr->right_child = Recursive_InsertBST(nodeptr->right_child, key);
    }
    
    // Returning the current node pointer to the previous function call
    return nodeptr;
}
