#include <iostream>
using namespace std;

class Node{

    int data;
    Node* next; 
    
    public:
        
        Node();// Default Constructor
        Node(int x); // Parameterized constructor
        ~Node(); // Destructor

        // Getters and Setters
        int getData(){ return data;} 
        Node* getNextNode(){ return this->next;} 
        void setData(int x){ this->data = x;}
        Node* setNextNode(Node* node_ptr){ return this->next;}
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