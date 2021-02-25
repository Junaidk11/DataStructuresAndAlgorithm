#include <stdio.h>
#include "linkedlist.h"

linkedlist::linkedlist(){
    headptr = NULL;
}

linkedlist::~linkedlist(){
    delete this;
}


// Adding a node to the front of the node
void linkedlist::addNodeToFront(Node* nodePtr){

        nodePtr->setNextNode(headptr); // The new head node points to where the current linkedlist headptr is pointing to
        headptr=nodePtr; //Linkedlist header pointer is now pointing to the new head node. 
        
}


int linkedlist::addNodeToEnd(Node* nodePtr){

    if(headptr==NULL){ // if Linkedlist is empty, add node to
        headptr=nodePtr;
        nodePtr->setNextNode(NULL); 
        return 1; // 1 = true, indicates node successfully added
    }else{

        Node* listTraverser = headptr; // Create a node pointer to traverse through the linkedlist
        while(listTraverser->getNextNode()!=NULL){ //Loop through the linkedlist until reach the end of the list
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
    if(listTraverser->getData()!=x){

        return NULL;
    }
    return listTraverser; // You will either get the address of the first node that has data == x or you will get NULL (indicating reached end of list and 'x' not found in the list)
}

int linkedlist::deleteNode(int x){

    Node* nodeToDelete = NULL;
    if(headptr==NULL){
        return 0; // LinkedList is empty
    }else{

        nodeToDelete = searchList(x); // This will either return NULL or the pointer to where the first Node with data == x is located
        if(nodeToDelete == NULL){
            return 0; // "x" not in the list
        }else{
            Node* findNodeBefore = headptr;

            while((findNodeBefore->getNextNode()!=NULL) && (findNodeBefore->getNextNode()!=nodeToDelete) ){
                
                findNodeBefore=findNodeBefore->getNextNode();
            }
            // After this you have a pointer to the node before the node to delete or NULL (which would mean nodeToDelete doesn't exist -> which is not possible based previous if statement)
            findNodeBefore->setNextNode(nodeToDelete->getNextNode());         
        }
        
    }
    return 1; // 1 indicates delete successfull
}

void linkedlist::printList(){
    Node* listTraverser = headptr; // Create a node pointer to travel down the list
    int i =1;
    while(listTraverser!=NULL){ //If the current node is not NULL, continue printing the node's data

        printf("Node %d Address: %p, Node %d: Data = %d, Next Node Address: %p. \n",i,listTraverser, i,listTraverser->getData(), listTraverser->getNextNode());
        i++;
        listTraverser = listTraverser->getNextNode();
    }
}