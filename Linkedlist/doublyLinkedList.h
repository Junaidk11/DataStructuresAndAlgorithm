// A Node Structure 
struct Node{
    int data; 
    Node* frontNode;  // Points to the front Node of the list
    Node* backNode;   // Points to the back Node of the list
};

// doublyLinkedList  Class
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