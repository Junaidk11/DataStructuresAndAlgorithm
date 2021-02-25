#include "doublyLinkedList.h"

// Constructors and Destructor definitions 

doublyLinkedList::doublyLinkedList(){
    setFirstNodeAddress(NULL);
    setLastNodeAddress(NULL);
}

doublyLinkedList::doublyLinkedList(Node* firstNodePtr, Node* lastNodePtr){
    setFirstNodeAddress(firstNodePtr);
    setLastNodeAddress(lastNodePtr);
}

doublyLinkedList::~doublyLinkedList(){
    delete this;
}

// Setters and Getter Definitions

void doublyLinkedList::setFirstNodeAddress(Node* nodePtr){
    firstNode = nodePtr;
}
void doublyLinkedList::setLastNodeAddress(Node* nodePtr){
    lastNode = nodePtr;
} 
int doublyLinkedList::getData(Node* nodePtr){
    return nodePtr->data;
}
Node* doublyLinkedList::getFirstNodeAddress(){
    return this->firstNode;
}
Node* doublyLinkedList::getLastNodeAddress(){
    return this->lastNode;

}

// Initialize a node with data
Node* nodeInitialization(int value){
    Node* node = new Node;
    node->data = value; 
    node->backNode = NULL; 
    node->frontNode = NULL; 
    return node;
}

void doublyLinkedList::AddNodeToFront(int x){

    Node* nodePTr = nodeInitialization(x); // Dynamically allocate memory for the new node and initialize it. 
   if(firstNode==NULL && lastNode==NULL){
       firstNode = nodePTr; 
       lastNode = nodePTr; 
   }else{
       firstNode->backNode = nodePTr;  // The current first node will point to the new node which was just initialized.
       nodePTr->frontNode = firstNode; // The new node's front will point to the old head node (aka first node)
       firstNode = nodePTr; // Update headnode pointer
   }
}


void doublyLinkedList::AddNodeToEnd(int x){

    Node* nodePtr = nodeInitialization(x); // Dynamically allocate memory for the new node and initialize it. 

    if(firstNode==NULL && lastNode==NULL){ // List is empty
        firstNode = nodePtr; 
        lastNode = nodePtr;
    }else{
        lastNode->frontNode = nodePtr;  // The last node's front pointer will point to the new node
        nodePtr->backNode = lastNode; // The new node's back pointer will point to the current last node
        lastNode = nodePtr; // Update the lastNode pointer of the list to point to the newly added node
    }
}

void doublyLinkedList::AddNodeAfter(Node* nodePtr, int x){

    Node* nodeToAdd=nodeInitialization(x); // Dynamically allocate memory for the new node and initialize it. 
    if(firstNode==NULL && lastNode==NULL){ // check if list is empty, if empty, just add new node to the list
        firstNode = nodeToAdd;
        lastNode = nodeToAdd; 
    }else if(nodePtr!=NULL){// Making sure nodePtr is not NULL, can't add after a NULL PTR
        if(nodePtr==lastNode){ //Adding after the last node = AddToEnd
            AddNodeToEnd(x);
        }else{ // Adding somewhere between the firstNode and lastNode
            Node* temporaryNodePtr = nodePtr->frontNode; // This temp node pointer is pointing to the node ahead of nodePtr
            nodeToAdd->frontNode = temporaryNodePtr; // The new node should point to the node ahead of nodePtr
            temporaryNodePtr->backNode = nodeToAdd;  // The node ahead of nodePtr should point back to new node
            nodeToAdd->backNode = nodePtr; // The new node's back pointer should point to the nodePtr
            nodePtr->frontNode = nodeToAdd; // nodePtr is the node after which the new node is added, so it should point to the new node.
        }
    }
}

void doublyLinkedList::AddNodeBefore(Node* nodePtr, int x){

    Node* nodeToAdd=nodeInitialization(x); // Dynamically allocate memory for the new node and initialize it. 
    if(firstNode==NULL && lastNode==NULL){ // check if list is empty, if empty, just add new node to the list
        firstNode = nodeToAdd;
        lastNode = nodeToAdd; 
    }else if(nodePtr!=NULL){// Making sure nodePtr is not NULL, can't add before a NULL PTR
        if(nodePtr==firstNode){ //Adding before the first node = AddToFront
            AddNodeToFront(x);
        }else{ // Adding somewhere between the firstNode and lastNode
            Node* temporaryNodePtr = nodePtr->backNode; // This temp node pointer is pointing to the node before of nodePtr
            nodeToAdd->backNode = temporaryNodePtr; // The new node should point to the node behind of nodePtr
            temporaryNodePtr->frontNode = nodeToAdd;  // The node behind of nodePtr should point back to new node
            nodeToAdd->frontNode = nodePtr; // The new node's front pointer should point to nodePtr
            nodePtr->backNode = nodeToAdd; // nodePtr is the node after which the new node is added, so it should point to the new node.
        }
    }

}
Node* doublyLinkedList:: searchList(int x){
    
    if(firstNode==NULL && lastNode==NULL){
        return NULL; //List is empty
    }else{
        Node* listTraverser = firstNode; // Can search from the front or from the back 
        while(listTraverser!=NULL){
            if(listTraverser->data==x){
                return listTraverser;
            }else{
                listTraverser=listTraverser->frontNode;
            }
        }
    }
    return NULL; // Data not found in the list
}
void doublyLinkedList::forward_traverse(){

    printf("Forward traversing. \n");
    Node* listTraverser = firstNode; // Use this pointer to traverse through the list
    int i = 1;
    do{
        if(listTraverser==NULL){
            break; // List is empty
        }else{
            printf("Node %d Address: %p, Node %d: Data = %d, Next Node Address: %p. \n",i,listTraverser, i,listTraverser->data, listTraverser->frontNode);
            listTraverser = listTraverser->frontNode;
        }
        i++;
    }while(listTraverser!=NULL);
}

void doublyLinkedList::backward_traverse(){

    printf("Backward traversing. \n");
    Node* listTraverser = lastNode; // Use this pointer to traverse through the list
    int i = 1;
    do{
        if(listTraverser==NULL){
            break; // List is empty
        }else{
            printf("Node %d Address: %p, Node %d: Data = %d, Next Node Address: %p. \n",i,listTraverser, i,listTraverser->data, listTraverser->backNode);
            listTraverser = listTraverser->backNode;
        }
        i++;
    }while(listTraverser!=NULL);
}