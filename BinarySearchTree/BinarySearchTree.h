#include <iostream>
using namespace std;

// Tree Node Structure
struct tree_node{
    int data;  // For node data
    tree_node *left, *right; // Node pointers to hold left and right subtree
};

class BinarySearchTree{
    private: 
    tree_node *root; // Root node of the tree

    // Binary Search Tree Methods
    void insert(tree_node* node, int data); 
    bool searhTree(tree_node* node, int data);

    // Traversing tree
    void pre_order(tree_node *root);
    void post_order(tree_node *root);
    void in_order(tree_node *root); 

    public: 
    
    // The public methods will call the private methods AND handle the scenario when root == NULL (i.e. empty tree)
    BinarySearchTree(){
        root = NULL;
    }
    void insert(int data);
    bool searchTree(int data);
    void pre_order();
    void post_order();
    void in_order();
};