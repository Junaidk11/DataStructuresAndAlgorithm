#include <iostream>
using namespace std;

class Node{

    int data;
    Node* next; 
    
    public:
        
        Node(){ this->next=NULL;} // Default Constructor
        Node(int x){ this ->data=x; this->next=NULL;} // Parameterized constructor

        // Getters and Setters
        int getData(){ return data;} 
        Node* getNextNode(){ return this->next;} 
        void setData(int x){ this->data = x;}
        Node* setNextNode(Node* node_ptr){ return this->next;}
};


