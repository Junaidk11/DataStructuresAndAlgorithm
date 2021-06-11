#ifndef _NODE_H 

#include <stdlib.h>

struct Node{
    int Vertex; // Node data
    struct Node* nextNode;

};

struct Node* createNode(int);

#endif
