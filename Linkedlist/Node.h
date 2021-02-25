#include <iostream>
using namespace std; 

/*  Node Class Definition.  */ 
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

