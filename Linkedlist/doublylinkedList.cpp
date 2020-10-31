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
    numbers->backward_traverse();

    // Add Node to the front of the list
     printf("Enter an integer (Note: Adding to the front of the list):");
    scanf("%d",&x);
    numbers->AddNodeToFront(x);
    numbers->forward_traverse();
    numbers->backward_traverse();

    // Add Node to the end of the list
    printf("Enter an integer (Note: Adding to the end of the list):");
    scanf("%d",&x);
    numbers->AddNodeToEnd(x);
    numbers->forward_traverse();
    numbers->backward_traverse();

    // Add Node to the end of the list
    printf("Enter an integer (Note: Adding to the end of the list):");
    scanf("%d",&x);
    numbers->AddNodeToEnd(x);
    numbers->forward_traverse();
    numbers->backward_traverse();

    return 0;
}