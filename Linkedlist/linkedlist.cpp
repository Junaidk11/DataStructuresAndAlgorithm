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
    int isEmpty();
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

int linkedlist::isEmpty(){
    if(headptr==NULL){
        return 1; // return True if headptr is pointing to NULL, linkedlist is empty
    }else{
        return 0; // return false if headptr is not pointing to NULL, this means linkedlist not empty.
    }
}

Node* linkedlist::searchList(int x){
    Node* listTraverser = headptr;  // Create a pointer to the head pointer of the list, will use it to traverse through the list

    while(listTraverser->getNextNode()!=NULL && listTraverser->getData()!=x){
        listTraverser = listTraverser->getNextNode();
    }
    return listTraverser; // You will either get the address of the first node that has data == x or you will get NULL (indicating reached end of list and 'x' not found in the list)
}