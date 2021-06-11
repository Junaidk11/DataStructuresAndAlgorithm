#ifndef _GRAPH_H

#include "Node.h"

struct Graph{

    int numVertices;
    struct Node** adjList; // Edge list pointer
};

struct Graph* createGraph(int);
void addEdge(struct Graph*, int, int);
void printGraph(struct Graph*);



#endif