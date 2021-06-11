#include "Node.h"

struct Node* createNode(int v){
    // Allocate memory from heap for new Node
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    // Initialize the new Node
    newNode->Vertex = v;
    newNode->nextNode = NULL;

    // Return new node
    return newNode;
}