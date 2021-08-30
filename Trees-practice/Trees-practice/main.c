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
tree_node* Delete_BST(tree_node *nodeptr, int key);
tree_node* GenerateBST_usingPreOrder(int pre_order[], int arr_size);
tree_node* GenerateBST_usingPostOrder(int post_order[], int arr_size); // @TODO:


// Test Programs
void TEST_create_a_tree(void);
void TEST_tree_traversal(void);
void TEST_operations_on_tree(void);
void TEST_searchBST(void);
void TEST_insertBST(void);
void TEST_RecursiveCreationOfBST(void);
void TEST_deleteFromBST(void);
void TEST_generateBSTFromPre_order(void);
void TEST_generateBSTFromPost_order(void);


int main(int argc, const char * argv[]) {
    
    TEST_generateBSTFromPre_order();
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
void TEST_generateBSTFromPre_order(void){
    
    // Pre order traversal of the BST I want to create
    int pre_order[]={10, 8, 4, 9, 30, 20,50};
    
    tree_node *root = GenerateBST_usingPreOrder(pre_order, 7);
    
    // Print in-order traversal to confirm
    Iterative_in_order(root);
    
    
}
// Deleting a node from a BST - Passed - still need to review this.
void TEST_deleteFromBST(void){
    
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
    
    // Delete a node
    Delete_BST(root, 50);
    Iterative_in_order(root);
    printf("\n");
    
    // Delete a node
    Delete_BST( root, 30);
    Iterative_in_order(root);
    printf("\n");
    
    // Delete a node
    Delete_BST( root, 10);
    Iterative_in_order(root);
    printf("\n");
    
    
    // Delete a node
    Delete_BST(root, 4);
    Iterative_in_order(root);
    printf("\n");
    
}
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
 
    Time complexity:
            For a given key, first you search the tree to find its position - this takes logn time because search depends on height
            of Binary tree and the minimum height of a Binary tree is logn. For given n keys, we search the BST n times, so the complexity
            because n*logn. Finally, the creation of the new node takes constant time so the time complexity of creating a
            BST for n given nodes is o(nlogn)
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

/*
    In this function, we delete a given key from a BST.
        There are 3 possible cases:
                The key to delete is a leaf node.
                The key to delete has a single child.
                The key to delete has two children.
    In all three cases we don't want to adjust every single link to ensure that the BST properties are held. Therefore, the best method for deleting a key
    from a BST is to replace its data with EITHER this Node's in-order traversal pre-decessor OR the in-order successor - i.e. when you perform
    in-order traversal on the give BST, the node that comes before the key to be delete is = in-order predecessor and the node that comes
    after the key to be deleted is = in-order nsuccessor.
        You can either randomly choose which of these two will replace the data of the node to be deleted or you can calculate the height
        of left and right subtree of the key to be deleted and select the node from the tree with the greater height.
    
        The in-order predecessor of a node is the right most child of this (node to be deleted) node's left child - i.e. go left child of the node to be deleted and then go right-child until you reach the end of the tree - i.e. NULL.
        Similarly,The in-order successor of a node is the left most child of this(node to be deleted) node's right child - i.e. go right child of the node to be deleted and then go left-child until you reach the end of the tree - i.e. NULL.
 
    
    Note: If the node to be deleted has children, then delete function is called on the node's children to shift the decendants of the node deleted up.
 
    The Time complexity of this deletion of key from a BST is dependent on the height of the tree because you have to find the key first - the height of a
    binary tree ranges between logn and n, but we usually assume the height is minimum so the time complexity is logn.

    So the KEY IDEA here is, first you find the key to be deleted from the BST and then replace this node's data with the in-order predecessor or
    in-order successor node's data.
        This process is repeated until all the node's of the node to be deleted are shifted up the BST to maintain the BST properties. Therefore, the node
        corresponding to the key to be deleted is not physically deleted, it's data and links are updated with the pre/successor in-order node. The empty
        leaf node after all decendants of the key to be deleted are shifted up is the only physical node that is deleted from the tree.
 
    Algorithm:
            First search for the key.
                if key found:
                    Find this key's left and right subtree height
                        If left subtree height is greater:
                            Find the in-order predecessor of the key to be deleted
                            Replace the data of the key to be deleted with in-order predecessor node's data
                            Call delete function on the in-order predecessor's data - this will repeat the steps above from start to shift up the nodes below
                        If right subtree height is greater:
                            Find the in-order successor of the key to be deleted
                            Replace the data of the key to be deleted with in-order successor node's data
                            Call delete function on the in-order successor's data - this will repeat the steps above from start to shift up the nodes below
                
   
 
 */

/*
    In-order predeceessor of node is the right most child of the given node's left child
        I.e. go to left child of the given node, then keep going right until you reach the end of tree
 */
tree_node* get_in_order_predecessor(tree_node *nodeptr){
    
    // go left child first
    nodeptr = nodeptr->left_child;
    while(nodeptr && nodeptr->right_child!=NULL){
        nodeptr = nodeptr->right_child;
    }
    
    return nodeptr;
}

/*
    In-order successor of node is the left most child of the given node's right child
        I.e. go to right child of the given node, then keep going left until you reach the end of tree
 */
tree_node* get_in_order_succceessor(tree_node *nodeptr){
    
    // go right child first
    nodeptr = nodeptr->right_child;
    while(nodeptr && nodeptr->left_child!=NULL){
        nodeptr = nodeptr->left_child;
    }
    return nodeptr;
}


/*
E.g. Tracing the Delete a key from BST:
 
        Binary Search Tree

                    Root
                    10
            8                30
        4       9        20       50
    
        
        In this example, suppose you want to delete key 50 ->
                    The root node will be passed first, and then you will go to right subtree of 10, then right subtree of 30 to reach 50.
                    At key 50, this the node to be deleted, the height of its left and right subtree is 0, because its a leaf node, so
                    you will simply delete this node - the number recursive function calls made to delete 50 is 4 because at 50 you will call delete
                    on its right child (because of code default case). You return with NULL, and then you return to previous call where nodeptr is pointing
                    at 50, which has no children, so it is deleted and you return NULL to the previous call - where nodeptr is pointing to key 30, and its
                    its right child is now NULL because 50 was deleted. Next, we return 30's address to previous call (which is the first call) where
                    nodeptr is pointing to root node 10, so we returned 30's address to the right_child pointer of 10. And finally we return to main
                    the root node address.
    
        In this example, suppose you want to delete 8 ->
                    The root node will be passed first, and then you will go to the left subtree to reach 8. At key 8, this the node to be deleted,
                     the height of its left and right subtree is 1, since its same, you will replace this node with 9 and 9's node will be deleted from the
                    tree.
                    The number of recursive function calls made to delete 8 is 3 because at 8 you will replace its data with its in-order sucessor which
                    is 9 and then you will call delete on key = 9 and start search at 8's right child(which is key = 9's node) because BST
                    cannot have duplicates. So, at key = 9's node you will delete this node because it is a leaf node (degree = 0). You return with NULL,
                    and then you return to previous call where nodeptr is pointing at key=8's node, which HAD two children before and HAD data 8, but now its
                    data is 9 and its right child is NULL (so now only 1 child), so we shifted key=9 to key=8's location and deleted the physical
                    node of key=9. Now you return address of key=9 (was previous key=8's address) to the previous call - where nodeptr is pointing to key 10
                    (the root node), and its left child is still pointing to the same address as of key=8 BUT now that node's data is 9 because we deleted
                    physical node of key=9 and moved its data to key=8. Next, we return 10's address to main, which is the root node address.
                    
 
*/
tree_node* Delete_BST(tree_node *nodeptr, int key){
    
    // ============ 3. This part is where the node is actually deleted  ============
    
    if(nodeptr==NULL){
        
        //reached left/right child of node or tree was empty
        return NULL;
    }
    
    
    if(nodeptr->left_child==NULL && nodeptr->right_child==NULL){
        
        // Reached a leaf node - i.e. degree of node is 0
        // In deleting a node from a BST, you physically delete only the leaf node because nodes of the key to be deleted get shifted up
        free(nodeptr);
        return NULL;
    }
    
    // ============ This part is where the node is actually deleted  ============
    
    
    // Temp node ptr to find the in-order predecessor or in-order successsor node of a given node in BST
    tree_node *temp;
    
    // ===================    1. This part is searching for the key to delete  =========================
    // Find the key to be deleted
    if(nodeptr->data < key){
        // key is in right subtree
        nodeptr->right_child = Delete_BST(nodeptr->right_child, key);
    }else if(nodeptr->data > key){
        // key is in left subtree
        nodeptr->left_child = Delete_BST(nodeptr->left_child, key);
        
    // ===================     This part is searching for the key to delete  =========================
    }else{
        
    // ============  2. This part is replacing the key found with the in-order predecessor node or successor node's data  by replacing   ============
        // The current node has the key - i.e. node to be deleted
        
        // To select whether pre-decessor node of in-order or successor of in-order will replace this node: Calculate height of left and right subtrees
        if(calculate_height_of_tree(nodeptr->left_child)>calculate_height_of_tree(nodeptr->right_child)){
            
            // Left subtree is longer, take the pre-decessor node of in-order traversal to replace the node to be deleted
            temp = get_in_order_predecessor(nodeptr);
            
            // Update the key node with temp's data
            nodeptr->data = temp->data;
            
            // Now delete the pre-decessor node from the BST, because BST cannot have duplicates
            // We return the node
            nodeptr->left_child = Delete_BST(nodeptr->left_child, temp->data);
        }else{
            
            // Right subtree is longer, take the successor node of in-order traversal to replace the node to be deleted
            temp = get_in_order_succceessor(nodeptr);
            
            // Update the key node with temp's data
            nodeptr->data = temp->data;
            
            // Now delete the successor node from the BST, because BST cannot have duplicates
            // We return the node
            nodeptr->right_child = Delete_BST(nodeptr->right_child, temp->data);
        }
        
    // ============ This part is replacing the key found with the in-order predecessor node or successor node's data  by replacing   ============
    }
    
    return nodeptr;
}

/*
 
    For generating a unique Binary tree, we need either pre-order + in-order traversal OR post-order + in-order traversal.
    However, for generating a unique BST, we ONLY need either pre-order OR post-order traversal because we know that in-order traversal of the
    BST will give the sorted BST in ascending order.
 
    The idea is to scan through the given pre-order traversal array and add the nodes using a Stack.
    Whenever you add a node as a left child, you suspend the current node by pushing it to a stack and move to the left child.
    Whenever you want to add a node as right child, you first check if the data is in between the current node's data and the data of the node
    at the top of the stack:
            If it is, then you add the node to the right child and you DON'T suspend the current node, you simply move to the next data in the pre-order
            traveral array.
            If it is not, then you pop the top of the stack and check if the node to be added is going to the left child or the right child - repeating the
            steps above. i.e. if new node goes to left child, you add the node and suspend the current node else you check if the new node is in range of
            current node's data and the top of the stack node's data before addding the new node to the right child.
 
        NOTE: If stack is empty, assume top of stack node's data is infinity.
 
    The time complexity of this method is o(n) because we scan through the pre-order array once and create the BST.
 */
tree_node* GenerateBST_usingPreOrder(int pre_order[], int arr_size){
    
    // Create root node first
    tree_node *root = create_treenode(pre_order[0]);
    
    // Create a temp pointer to create the rest of the BST tree, and newNode for creating new nodes
    tree_node *temp = root, *newNode =NULL;
    
    // For scanning the pre-order array
    int i=1;
    
    // Declare and initialize a stack
    stack BST_nodes;
    STACK_Init(&BST_nodes);
    
    // Repeating steps for adding nodes to the BST
    while(i<arr_size){
        if(pre_order[i] < temp->data){
            // Add node to the left child of current node
            
            // Create new node
            newNode = create_treenode(pre_order[i]);
            temp->left_child = newNode;
            
            // Suspend the current node
            STACK_push(&BST_nodes, temp);
            
            // Move temp to the new node created
            temp = temp->left_child;
            
            // Move to next element
            i++;
                                                
        }else{
            
            // Check if the new node is in range of current node's data and top of stack node
            if( (pre_order[i]> temp->data && pre_order[i] < STACK_top(BST_nodes) ) ||
                (pre_order[i] > temp->data && STACK_isEmpty(BST_nodes)) ){
                
                // Create new node
                newNode = create_treenode(pre_order[i]);
                
                // New node is in range
                temp->right_child = newNode;
                
                // move temp to the new node
                temp = temp->right_child;
                
                i++;
            }else{
                
                // Pop node from the top of the stack
                temp  = STACK_pop(&BST_nodes);
            }
            
        }
    }
    
    return root;
}

