#include "BinarySearchTree.h"

void BinarySearchTree::insert( tree_node* node, int data ){

    /* Check which subtree to put the new value to */
    if(data < node->data){ 
        /* value belongs to the left subtree */
        if(node->left != NULL){ // Check if left subtree exists 

            /* left subtree exist. */

            insert(node->left,data); // Recursive call
        } /* end if */
        else{
             /* Left subtree doesn't exist, create a subtree */
             //node->left = malloc(sizeof(tree_node)); // Create a new node in C
              node->left = new tree_node;  // Same as functionality as malloc,
             (node->left)->data = data;  // Add the data to the new node added 
             (node->left)->left = NULL;
             (node->left)->right = NULL; 
        
        } /* end else */
        
    } /* end if */
    else if(data > node->data){ 
        /* value belongs to the right subtree */

        if(node->right != NULL){ // Check if right subtree exist. 
            /* right subtree exist */
            insert(node->right, data); // Recursive call 
        } /* end if */
        else {
            /* right subtree doesn't exist, create a node */
            node->right = new tree_node; 
            (node->right)->data = data; // New data assigned to the new node
            (node->right)->left = NULL; 
            (node->left)->right = NULL; 
        } /* end else */ 

    } /* end else-if */
    else{
        /* Value already exist in the tree, duplication not allowed in Tree. */
        cout << "Duplicate Value." << endl; 
    }

}
void BinarySearchTree::insert(int data){
    if(root==NULL){
        /* Tree is empty, create a new node  */
        root = new tree_node; 
        root->data = data; 
        root->left = NULL; 
        root->right = NULL;

    } /* end if */
    else{
        /* Tree is not empty. */ 
        insert(root,data); // call private member function to insert the new value (if it doesn't exist).
    } 
}

/* Private member function, called my the public in_order() method */ 

void BinarySearchTree::in_order(tree_node* root){

    if(root!=NULL){
        in_order(root->left); // Process left subtree in order, recursive call
        printf("%d ",root->data);  // Print current Node's data
        in_order(root->right); // Process right subtree in order, recursive call
    }
    
    
}
/*   In order traversing the tree.
        The output will be an ascending list. 
*/
void BinarySearchTree::in_order(){
    if(root == NULL){
        cout << "Tree is empty." << endl;
    } /* end if */
    else {
        in_order(root);  // Call the private member function
    }

}

void BinarySearchTree::pre_order(tree_node *root){
    if(root!=NULL){
        printf("%d ",root->data); 
        pre_order(root->left); // Process left subtree, recursive call
        pre_order(root->right); // Process right subtree, recursive call 
    }/* end if */
}
/* 
    Preorder traversal of a tree. You process each node as you visit it. 
    This traversal is used for copying a tree. 
*/
void BinarySearchTree::pre_order(){

    if(root==NULL){
        cout << " Tree is empty." <<endl;
    } /* end if */
    else{
        pre_order(root); // Call private member function 
    } /* end else */
}

/* 
    In this traversal, each node is processed after its subtrees (both left and right) have been processed. 
    This type of traversal is used for deleting a tree. 

*/ 
void BinarySearchTree::post_order(tree_node* root){
    if(root!=NULL){
        post_order(root->left);  // process left subtree first -> its a recursive call
        post_order(root->right);   // Process right subtree next -> its a recursive call
        printf("%d ",root->data);   //  print current node value.
    }
}
void BinarySearchTree::post_order(){

    if(root==NULL){
        cout<<"Tree is empty."<<endl;
    } /* end if */
    else{
        post_order(root); // Call the private member function 
    }/* end else */
}