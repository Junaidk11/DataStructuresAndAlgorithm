#include "BinarySearchTree.cpp"

int main(){
    BinarySearchTree myTree = BinarySearchTree(); // Instantiate an object of type BinarySearchTree

    // ++Insert a bunch of nodes
    myTree.insert(6);  
    myTree.insert(5);
    myTree.insert(23);
    myTree.insert(20);
     // --Insert a bunch of nodes
    
    myTree.in_order();  // in_order traversal, should print all the nodes in ascending order. 
    cout << endl;
    myTree.pre_order(); // pre_order traversal 
    cout << endl;
    myTree.post_order(); // post_order traversal, the root node is processed at the end. 
    cout << endl;
    cout << "Item Search Result: " << myTree.searchTree(1) << endl;  // should return 0 
    cout << "Item Search Result: " << myTree.searchTree(23) << endl;  // should return 1 -> this is the right most leaf node of the tree


    return 0;
}