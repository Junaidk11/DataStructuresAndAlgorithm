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
        if(listTraverser->getNextNode()==NULL){  // This is for when the circular list has 1 node only: the current first node is pointing to NULL
            printf("Node %d Address: %p, Node %d: Data = %d, Next Node Address: %p. \n",i,listTraverser, i,listTraverser->getData(), listTraverser->getNextNode());
            break;
        }else{
           printf("Node %d Address: %p, Node %d: Data = %d, Next Node Address: %p. \n",i,listTraverser, i,listTraverser->getData(), listTraverser->getNextNode());
           listTraverser = listTraverser->getNextNode();
        }
        i++;
    }while(listTraverser!=headptr);
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
            // 3) The headpointer will point to the newly added node at the front 
        nodePtr->setNextNode(headptr); // New node points to the first node in the linkedlist. 
        //printf("New node's address: %p \n", nodePtr); // Uncomment for debugging node addresses

        Node* listTraverser = headptr; 

        do{
            if(listTraverser->getNextNode()==NULL){ // This is for when the circular list only has 1 node, the current first node is pointing to NULL
                break; 
            }else{
                listTraverser = listTraverser->getNextNode(); // Find the node who's nextNode is pointing to the same node as the current headpointer
            }
        }while(listTraverser->getNextNode()!=headptr && listTraverser->getNextNode()!=NULL);


        listTraverser->setNextNode(nodePtr); // Last node now pointing to the newly added first node
        // printf("Old first node pointing to address: %p\n\n", listTraverser->getNextNode());  // Uncomment for node addresses for debugging
        headptr = nodePtr; // Update head pointer to point to the new head node. 

        
        return 1;  // New node added successfully to the front of the circular linkedlist. 
    }
    return 0;
}

/*
        Three possible setups you can have when adding a new node to the circular linkedlist:
            1) The linkedlist is empty. 
            2) The linkedlist only has one node, i.e. the first node is pointing to NULL, i.e. your linkedlist is actually a linear linkedlist. 
            3) The linked list has more than 1 node, i.e. you have a circular linked list

*/
int circularLinkedList::AddNodeToEnd(Node* nodePtr){
    if(headptr==NULL){  // Check if list is empty. if true, then add node by pointing to the headptr to the nodeptr
            headptr = nodePtr;
            nodePtr->setNextNode(NULL); // The new node is the first node in the list, it should not be pointing to anything -> i.e. you have a linear linkedlist.
            return 1; // new node added to the list
    }else if(headptr->getNextNode()==NULL){ // Check if the list has 1 node only, if true, then add new node after the first node and point the new node to the first node, headptr not changed
        Node* listTraverser = headptr; // Create a temporary pointer to traverse through the list.
        listTraverser->setNextNode(nodePtr); // The first node (which is the only node in the list will point to the next node)
        listTraverser=listTraverser->getNextNode(); //Move the temporary node pointer to the newly added node in the list
        listTraverser->setNextNode(headptr); // The newly added node is now pointing to the first node, which is pointed to by the headptr (head pointer)
        return 1; // New node added to the list
    }else{  // The third case is: the list already has 2 or more nodes
        
        Node* listTraverser = headptr; // Create a temporary pointer to traverse through the list.
        while(listTraverser->getNextNode()!=headptr){  // Updated indexing node-pointer until you reach the node that is pointing back to the node that is pointing to the head node.
                listTraverser = listTraverser->getNextNode();
        }
        // After loop, the indexing node-pointer is pointing to a node that is pointing to the headnode, 
        listTraverser->setNextNode(nodePtr); // Now the last node of the circular linkedlist will point to the new node
        nodePtr->setNextNode(headptr); // The newly added node to the end of the circular linkedlist will point to the head node.
        return 1; // Addition to the list was succesfull
    }
    return 0;
}

Node* circularLinkedList::searchList(int x){
    Node* listTraverser = headptr; 
    if(listTraverser==NULL){
        //List is empty
        return NULL; 
    }else{
        do{
            if(listTraverser->getData()==x){
                return listTraverser; 
            }else{
                listTraverser=listTraverser->getNextNode();
            }
        }while(listTraverser!=NULL && listTraverser!=headptr); // The first condition is added to handle the scenario where your circularlist has a single node.
    }
    return NULL;
}


void circularLinkedList::deleteNode(int x){
    Node* listTraverser1 = headptr;  
    if(listTraverser1==NULL){ // List is empty
        return;  // Adding this return in a void function will increase readability of the code
    }else{
        Node* listTraverser2 = listTraverser1->getNextNode();
        do{
            if(listTraverser2->getData()==x){
                listTraverser1->setNextNode(listTraverser2->getNextNode()); // The previous node's node-pointer will point to the node after the one that contains x
                break;
            }else{
                listTraverser1 = listTraverser1->getNextNode(); // Update the back-pointer
                listTraverser2=listTraverser1->getNextNode();   // Update the front-pointer (this will point to the node that should be deleted, if x is found in it)
            }
        }while(listTraverser1!=NULL && listTraverser1!=headptr);
    }
}


Node::Node(){
    this->nextNode= NULL;
}
Node::Node(int x){
    this->data = x; 
    this->nextNode = NULL;
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

    /* Uncomment this block to test AddNodeToEnd method of the circularlinkedlist class
    // Testing the 3 possible setups of linkedlist for Node addition to the end:
        // An empty list
            int x;
            printf("Enter an integer: (Note: Adding to the end of the list):");
            scanf("%d",&x);
            Node* item1 = new Node(x);
            circularLinkedList numbers;
            numbers->AddNodeToEnd(item1);
            numbers->printlist();

        // Adding a node to the end of a list with a single node
            printf("Enter an integer (Note: Adding to the end of the list):");
            scanf("%d",&x);
            Node* item2 = new Node(x);
            numbers->AddNodeToEnd(item2);
            numbers->printlist();

        // Adding a node to the end of a list with 2 or more nodes
            printf("Enter an integer (Note: Adding to the end of the list):");
            scanf("%d",&x);
            Node* item3 = new Node(x);
            numbers->AddNodeToEnd(item3);
            numbers->printlist();

    */
     // Uncomment this block to test adding nodes to the front and the back. 
    // Adding a node to the front of the list 
    int x;
    printf("Enter an integer: (Adding to the front of the list)");
    scanf("%d",&x);
    Node* item1 = new Node(x);
    circularLinkedList* numbers = new circularLinkedList;
    numbers->AddNodeToFront(item1);
    numbers->printlist();

    // Adding a node to the front of the list 
    printf("Enter an integer (Note: Adding to the front of the list):");
    scanf("%d",&x);
    Node* item2 = new Node(x);
    numbers->AddNodeToFront(item2);
    numbers->printlist();

    // Adding a node to the front of the list 
    printf("Enter an integer (Note: Adding to the front of the list):");
    scanf("%d",&x);
    Node* item3 = new Node(x);
    numbers->AddNodeToFront(item3);
    numbers->printlist();

    // Adding a node to the front of the list 
    printf("Enter an integer (Note: Adding to the front of the list):");
    scanf("%d",&x);
    Node* item4 = new Node(x);
    numbers->AddNodeToFront(item4);
    numbers->printlist();

    // Adding a node to the back of the list 
    printf("Enter an integer (Note: Adding to the end of the list):");
    scanf("%d",&x);
    Node* item5 = new Node(x);
    numbers->AddNodeToEnd(item5);
    numbers->printlist();

    // Adding a node to the back of the list 
    printf("Enter an integer (Note: Adding to the end of the list):");
    scanf("%d",&x);
    Node* item6 = new Node(x);
    numbers->AddNodeToEnd(item6);
    numbers->printlist();
    
    
    // Testing searchList Method of the circularlinkedlist class
    printf("Enter an integer to search for in the list: ");
    scanf("%d",&x);
    Node* searchResult = numbers->searchList(x);
    if(searchResult==NULL){
        printf("Integer not found in the list. \n\n");
    }else{
        printf("Integer found in the list. First node in the list that contains this integer: %p \n", searchResult);
    }

    // Testing the deleteNode Method of the circularlinkedlist class
    printf("Enter an integer to delete from the list: ");
    scanf("%d",&x);
    numbers->deleteNode(x);
    numbers->printlist();

    delete numbers;

    numbers->printlist();
    return 0;

}