#include <iostream>
using namespace std;
#include "doublyLinkedList.cpp"

int main(){

    doublyLinkedList* numbers = new doublyLinkedList;     // Dynamically allocate memory for the doubly linked list
    int x;
    // Add Node to the front of list
    printf("Enter an integer (Note: Adding to the front of the list):");
    scanf("%d",&x);
    numbers->AddNodeToFront(x);
    numbers->forward_traverse();
    //numbers->backward_traverse();

    // Add Node to the front of the list
     printf("Enter an integer (Note: Adding to the front of the list):");
    scanf("%d",&x);
    numbers->AddNodeToFront(x);
    numbers->forward_traverse();
    //numbers->backward_traverse();

    // Add Node to the end of the list
    printf("Enter an integer (Note: Adding to the end of the list):");
    scanf("%d",&x);
    numbers->AddNodeToEnd(x);
    numbers->forward_traverse();
    //numbers->backward_traverse();

    // Add Node to the end of the list
    printf("Enter an integer (Note: Adding to the end of the list):");
    scanf("%d",&x);
    numbers->AddNodeToEnd(x);
    numbers->forward_traverse();
    //numbers->backward_traverse();

    // Add Node after a given node
    int y; // Adding node after this value
    printf("Enter node data you want to add, followed by the value of the node you want to add this node after:");
    scanf("%d %d",&x, &y);
    Node* afterNode = numbers->searchList(y); // Search for y in the list
    numbers->AddNodeAfter(afterNode, x);  // Add the new node with data=x to the list
    numbers->forward_traverse();
    //numbers->backward_traverse();


    // Add Node before a given node
      // Adding node before the value = y
    printf("Enter node data you want to add, followed by the value of the node you want to add this node before:");
    scanf("%d %d",&x, &y);
    Node* beforeNode = numbers->searchList(y); // Search for y in the list
    numbers->AddNodeBefore(beforeNode, x);  // Add the new node with data=x to the list
    numbers->forward_traverse();
    //numbers->backward_traverse();
    return 0;
}