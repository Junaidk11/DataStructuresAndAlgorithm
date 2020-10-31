#include <iostream>
using namespace std;

// A Node Structure 
struct Node{
    int data; 
    Node* frontNode;  // Points to the front Node of the list
    Node* backNode;   // Points to the back Node of the list
};

class doublyLinkedList{
    private:
        Node* firstNode; // a pointer to the first node in the list
        Node* lastNode;  // a pointer to the last node in the list
    public:
        doublyLinkedList(); // Default constructor
        ~doublyLinkedList(); // Destructor
        doublyLinkedList(Node* firstNode, Node* lastNode); // Parameterized constructor

        // Setters and Getters
        void setFirstNodeAddress(Node* nodePtr);
        void setLastNodeAddress(Node* nodePtr); 
        int getData(Node* nodePtr); 
        Node* getFirstNodeAddress();
        Node* getLastNodeAddress();

        friend Node* nodeInitialization(int value, Node* frontPtr, Node* backPtr);
        
        // Doubly linked list Operations
        void AddNodeToFront(int x);
        void AddNodeToEnd(int x);
        void AddNodeAfter(Node* nodePtr, int x);
        void AddNodeBefore(Node* nodePtr, int x);
        void deleteNode(Node *);
        void forward_traverse();
        void backward_traverse();
        Node* searchList(int x);
};

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

int main(){


    doublyLinkedList* numbers = new doublyLinkedList;     // Dynamically allocate memory for the doubly linked list
    int x;
    // Add Node to the front of list
    printf("Enter an integer (Note: Adding to the front of the list):");
    scanf("%d",&x);
    numbers->AddNodeToFront(x);
    numbers->forward_traverse();
    //numbers->backward_traverse();

    // Add Node to the front of the list
     printf("Enter an integer (Note: Adding to the front of the list):");
    scanf("%d",&x);
    numbers->AddNodeToFront(x);
    numbers->forward_traverse();
    //numbers->backward_traverse();

    // Add Node to the end of the list
    printf("Enter an integer (Note: Adding to the end of the list):");
    scanf("%d",&x);
    numbers->AddNodeToEnd(x);
    numbers->forward_traverse();
    //numbers->backward_traverse();

    // Add Node to the end of the list
    printf("Enter an integer (Note: Adding to the end of the list):");
    scanf("%d",&x);
    numbers->AddNodeToEnd(x);
    numbers->forward_traverse();
    //numbers->backward_traverse();

    // Add Node after a given node
    int y; // Adding node after this value
    printf("Enter node data you want to add, followed by the value of the node you want to add this node after:");
    scanf("%d %d",&x, &y);
    Node* afterNode = numbers->searchList(y); // Search for y in the list
    numbers->AddNodeAfter(afterNode, x);  // Add the new node with data=x to the list
    numbers->forward_traverse();
    //numbers->backward_traverse();


    // Add Node before a given node
      // Adding node before the value = y
    printf("Enter node data you want to add, followed by the value of the node you want to add this node before:");
    scanf("%d %d",&x, &y);
    Node* beforeNode = numbers->searchList(y); // Search for y in the list
    numbers->AddNodeBefore(beforeNode, x);  // Add the new node with data=x to the list
    numbers->forward_traverse();
    //numbers->backward_traverse();

    return 0;
}