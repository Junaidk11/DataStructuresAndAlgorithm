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

int linkedlist::addNodeToFront(Node* nodePtr){

    if(true){
        nodePtr->setNextNode(headptr); // The new head node points to where the current linkedlist headptr is pointing to
        headptr=nodePtr; //Linkedlist header pointer is now pointing to the new head node. 
        return 1; // Return 1 to indicate head node updated successfully
    }
    return 0; // Return 0 to indicate head node update failed. 
}

