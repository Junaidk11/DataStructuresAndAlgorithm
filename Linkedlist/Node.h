#include <iostream>
using namespace std;

class Node{

    private:
        int data;
        Node* next; 
    
    public:
        
        Node();// Default Constructor
        Node(int x); // Parameterized constructor
        ~Node(); // Destructor

        // Getters and Setters
        int getData(){ return data;} 
        Node* getNextNode(); 
        void setData(int x);
        void setNextNode(Node* node_ptr);
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