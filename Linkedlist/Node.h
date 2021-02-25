#include <iostream>
using namespace std; 

/*  Node Class Definition.  */ 
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

