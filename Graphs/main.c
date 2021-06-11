#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

int main(void){

    // Allocate memory for a graph structure
    struct Graph* graph = createGraph(4); // 4 vertices

    // Add edges using indices from 0-3 for the 4 Vertices 
    addEdge(graph, 0,1);
    addEdge(graph, 2,1);
    addEdge(graph, 3,2);
    addEdge(graph, 3,0);

    // Print graph

    printGraph(graph);

    return 0;

}