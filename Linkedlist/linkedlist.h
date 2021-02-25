/* Linkedlist Class definition. */
class linkedlist{

    /* data */
    Node* headptr; // 
public:
    // Methods
    /* The addition of the constructor and destructor of linkedlist class with Node class as an attribute throws: Segmentation error 11: Why?
    *   Segmentation error = Going out of bound. I believe this is because of the atrributes of the linkedlist class is another class which has its own 
    *   constructor and destructor. 
    * 
    */
    linkedlist();
    ~linkedlist();
    void addNodeToFront(Node* nodePtr);
    int addNodeToEnd(Node* nodePtr);
    int isEmpty();
    Node* searchList(int x);
    int deleteNode(int x);
    void printList();
};