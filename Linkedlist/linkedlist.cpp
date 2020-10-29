#include <iostream>
using namespace std; 
#include <stdio.h>



class Node{

    private:
        int data;
        Node* next; 
    
    public:
        
        Node();// Default Constructor
        Node(int x); // Parameterized constructor
        ~Node(); // Destructor

        // Getters and Setters
        int getData(); 
        Node* getNextNode(); 
        void setData(int x);
        void setNextNode(Node* node_ptr);
};



class linkedlist{

    /* data */
    Node* headptr; // 
public:
    // Methods
    linkedlist();
    void addNodeToFront(Node* nodePtr);
    int addNodeToEnd(Node* nodePtr);
    int isEmpty();
    Node* searchList(int x);
    int deleteNode(int x);
    void printList();
};

Node::Node(){
    this->next=NULL;
}

Node::Node(int x){
    this->data=x;
    this->next=NULL;
}

Node::~Node(){
    delete this;
}

int Node::getData(){
    return data;
}
Node* Node::getNextNode(){
    return next;
}

void Node::setData(int x){ 
    this->data = x;
}

void Node::setNextNode(Node* node_ptr){
    this->next=node_ptr;
}

linkedlist::linkedlist(){
    headptr = NULL;
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

    Node* nodeToDelete;
    if(headptr==NULL){
        return 0; // LinkedList is empty
    }else{

        nodeToDelete = searchList(x); // This will either return NULL or the pointer to where the first Node with data == x is located
        if(nodeToDelete == NULL){
            return 0; // "x" not in the list
        }else{
            Node* findNodeBefore = headptr;

            while(findNodeBefore->getNextNode()!=NULL && findNodeBefore->getNextNode()!=nodeToDelete){
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

        printf("Node %d's data %d and Address %p. \n",i++,listTraverser->getData(), listTraverser);
        
        listTraverser = listTraverser->getNextNode();
    }
}

int main(){

    int x;

    // Add First node to the list
    cout << "Enter an integer:" << endl; 
    scanf("%d",&x);
    Node* item = new Node(x);
    linkedlist l; 
    l.addNodeToFront(item);
    l.printList();

    // Add a new node to the front of the list
    cout << "Enter an integer:" << endl; 
    scanf("%d",&x);
    Node* item2 = new Node(x);
    l.addNodeToFront(item2);
    l.printList();

    // Add a new node to the end of the list
    cout << "Enter an integer:" << endl; 
    scanf("%d",&x);
    Node* item3 = new Node(x);
    l.addNodeToEnd(item3);
    l.printList();

    // Add a new node to the end of the list
    cout << "Enter an integer:" << endl; 
    scanf("%d",&x);
    Node* item4 = new Node(x);
    l.addNodeToEnd(item4);
    l.printList();
    
    // Add a new node to the end of the list
    cout << "Enter an integer:" << endl; 
    scanf("%d",&x);
    Node* item5 = new Node(x);
    l.addNodeToFront(item5);
    l.printList();

    // Add a new node to the end of the list
    cout << "Enter an integer:" << endl; 
    scanf("%d",&x);
    Node* item6 = new Node(x);
    l.addNodeToFront(item6);
    l.printList();

    // Search for a node in the list with data == x
    cout << "Enter an integer to look for in your linkedlist:" << endl; 
    scanf("%d",&x);
    if(l.searchList(x)==NULL){
        printf("Integer not found in the list. \n");
    }else{
        printf("The address of the first node that contains your requested integer: %p.\n", l.searchList(x));
    }

    // Delete a node from the  list
    cout << "Enter an integer to delete from your linkedlist:" << endl; 
    scanf("%d",&x);
    if(l.deleteNode(x)){
        printf("Delete successful.\n");
    }else{
        printf("Delete failed - Integer not found or delete operation failed. \n");
    }
    l.printList();

    return 0;
}