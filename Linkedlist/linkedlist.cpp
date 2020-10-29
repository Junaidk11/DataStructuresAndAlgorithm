#include <iostream> 
using namespace std; 
#include "Node.h"

class linkedlist
{

    /* data */
    Node* headptr; // 
public:
    linkedlist(/* args */);
    ~linkedlist();

    // Methods
    int addNodeToFront(Node* nodePtr);
    int addNodeToEnd(Node* nodePtr);
    int isEmpty(Node *headptr);
    Node* searchList(int x);
    Node* deleteNode(int x);
};

linkedlist::linkedlist(/* args */)
{
    this->headptr=NULL;
}

linkedlist::~linkedlist()
{
    delete this;
}

// Adding a node to the front of the node
int linkedlist::addNodeToFront(Node* nodePtr){

    if(true){
        nodePtr->setNextNode(headptr); // The new head node points to where the current linkedlist headptr is pointing to
        headptr=nodePtr; //Linkedlist header pointer is now pointing to the new head node. 
        return 1; // Return 1 to indicate head node updated successfully
    }
    return 0; // Return 0 to indicate head node update failed. 
}

int linkedlist::addNodeToEnd(Node* nodePtr){

    if(headptr==NULL){ // if Linkedlist is empty, add node to
        headptr=nodePtr;
        nodePtr->setNextNode(NULL); 
        return 1; // 1 = true, indicates node successfully added
    }else{

        Node* listTraverser = headptr; // Create a node pointer to traverse through the linkedlist
        while(listTraverser!=NULL){ //Loop through the linkedlist until reach the end of the list
            listTraverser = listTraverser->getNextNode(); 
        }
        listTraverser->setNextNode(nodePtr); // The end node points to the new node
        nodePtr->setNextNode(NULL); // The new node points to NULL (end of list indicator)
        return 1; 

    }
    return 0;  // Node addition failed. 

}