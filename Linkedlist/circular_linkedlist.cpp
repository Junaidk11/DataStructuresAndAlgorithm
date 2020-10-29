#include <iostream>
using namespace std;

class Node{

    private: 
        int data;
        Node* nextNode;
    public:
        Node();  // Default constructor
        Node(int x); // Parametric Constructor
        ~Node();     // Destructor 
        // Getters and Setters
        int getData();
        Node* getNextNode();
        void setData(int x); 
        void setNextNode(Node* nextNodePtr);
};

class circularLinkedList{

    Node* headptr; // Points to the head of the circular linked list

    public:
    //circularLinkedList(); // Default constructor
    //~circularLinkedList(); // Destructor
    int AddNodeToFront(Node* nodePtr); 
    int AddNodeToEnd(Node* nodePtr);
    Node* searchList(int x);
    void deleteNode(int x);
    void printlist();
};
/* -> Read linkedlist.cpp commit # :  4767084ac243c9fcffa477ff15bbe5ae6246b269 for more details on why this is commented out. 
// CircularLinkedlist Constructor definition
circularLinkedList::circularLinkedList(){
    headptr = NULL;
}

// CircularLinkedlist destructor 
circularLinkedList::~circularLinkedList(){
    delete this; 
}*/

void circularLinkedList::printlist(){
    Node* listTraverser = headptr;
    int i =1;
    do{
        if(listTraverser->getNextNode()==NULL){  // This is for when the circular list only has 1 node, the current first node is pointing to NULL
            printf("Node %d's data is %d and Address %p. \n",i++,listTraverser->getData(), listTraverser);
            break;
        }else{
           printf("Node %d's data is %d and Address %p. \n",i++,listTraverser->getData(), listTraverser);
           listTraverser = listTraverser->getNextNode();
        }
        
    }while(listTraverser->getNextNode()!=headptr);
}
int circularLinkedList::AddNodeToFront(Node* nodePtr){
    if(headptr==NULL){ // Circular linked list is empty
        headptr=nodePtr; // headpointer points to the new node
        nodePtr->setNextNode(NULL); // The new node will point to NULL as it is the only node in the list.
        return 1;  // new node added successfully to the front of the list. 
    }else{
        // List is not empty. 
            // 1) New node points to the where the headpointer is pointing to. 
            // 2) Find the last node in the circularLinkedList, it will point to the new node
            // 3) The headpointer will point to the new node
        nodePtr->setNextNode(headptr);
        printf("New node's address: %p \n", nodePtr);
        Node* listTraverser = headptr;

        do{
            if(listTraverser->getNextNode()==NULL){ // This is for when the circular list only has 1 node, the current first node is pointing to NULL
                break; 
            }else{
                listTraverser = listTraverser->getNextNode(); // Find the node who's nextNode is pointing to the same node as the current headpointer
            }
        }while(listTraverser->getNextNode()!=headptr);

        // Now your listTraverser pointer and the headpointer are both pointing to the old first node
        listTraverser->setNextNode(nodePtr); // Last node now pointing to the newly added first node
        printf(" Old first node pointing to address: %p\n", listTraverser->getNextNode()); 
        headptr = nodePtr; // Update head pointer to point to the new head node. 

        
        return 1;  // New node added successfully to the front of the circular linkedlist. 
    }
    return 0;
}


Node::Node(){
    nextNode = NULL;
}
Node::Node(int x){
    data = x; 
    nextNode = NULL;
}

Node::~Node(){
    delete this; // Delete the calling object
}

int Node::getData(){
    return this->data;
}

Node* Node::getNextNode(){
    return this->nextNode;
}

void Node::setData(int x){
    this->data =x;
}

void Node::setNextNode(Node* nextNodePtr){
    this->nextNode = nextNodePtr;
}

int main(){
    
    

    int x;
    printf("Enter an integer:");
    scanf("%d",&x);
    Node* item1 = new Node(x);
    circularLinkedList numbers;
    numbers.AddNodeToFront(item1);
    numbers.printlist();

    printf("Enter an integer:");
    scanf("%d",&x);
    Node* item2 = new Node(x);
    numbers.AddNodeToFront(item2);
    numbers.printlist();

    printf("Enter an integer:");
    scanf("%d",&x);
    Node* item3 = new Node(x);
    numbers.AddNodeToFront(item3);
    numbers.printlist();

     printf("Enter an integer:");
    scanf("%d",&x);
    Node* item4 = new Node(x);
    numbers.AddNodeToFront(item4);
    numbers.printlist();

    return 0;

}