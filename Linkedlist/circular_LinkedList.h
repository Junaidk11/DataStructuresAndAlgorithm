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