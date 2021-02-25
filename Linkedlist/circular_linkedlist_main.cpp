#include "Node.cpp"
#include "circular_LinkedList.cpp"

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