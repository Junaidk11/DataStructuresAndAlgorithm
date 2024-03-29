#include "Graph.h"
#include <stdio.h>

struct Graph* createGraph(int vertices){

    // Allocate memory from heap for the graph
    struct Graph *newGraph = (struct Graph*)malloc(sizeof(struct Graph));

    // Initialize adjacency list
    newGraph->numVertices = vertices;

    // Allocate memory for visited list
    newGraph->visited = (int*)calloc(vertices, sizeof(int));  

    // Allocate memory for the adjancy list
    newGraph->adjList = (struct Node**)malloc(vertices*sizeof(struct Node*));

    
    int i;
    for(i=0;i<newGraph->numVertices;i++){

        // Set to NULL
        newGraph->adjList[i] = NULL;
    }

    // return graph
    return newGraph;
}

void addEdge(struct Graph* graph, int sourceVertex, int destinationVertex){

    // Allocate memory for source vertex
    struct Node* newNode = createNode(sourceVertex);

    /* assuming graph is undirected */
    // Create an edge between source and destination
    newNode->nextNode = graph->adjList[destinationVertex];
    graph->adjList[destinationVertex] = newNode;    

    // Allocate memory for destination vertex
    newNode = createNode(destinationVertex);

    // Create an edge between source and destination
    newNode->nextNode = graph->adjList[sourceVertex];
    graph->adjList[sourceVertex] = newNode;    
    
}

void printGraph(struct Graph* graph){

    // Create a temp Node pointer for traversing adjacency list
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    // Loop through the adjacency list
    int v; 
    for(v=0; v<graph->numVertices;v++){

        // Going vertically for each vertex
        temp = graph->adjList[v];

        // Print all edges of current vertex
        while(temp){
            printf(" %d -> %d ",v, temp->Vertex);
            // Update temp to next edge
            temp = temp->nextNode;
        }
        printf("\n");
    }
}

void printVisitedList(struct Graph* graph){
    int i;
    printf("Visited List: ");
    for(i =0; i< graph->numVertices; i++){
        printf(" %d ", graph->visited[i]);
    }
    printf("\n");
}
void DFS( struct Graph* graph, int startIndex){

    
    // Mark given start vertex as visited
    graph->visited[startIndex] = 1;

    // Print Visited List
    printVisitedList(graph); 

    // Create a temp Node ptr for iterating adjacent nodes of given vertex
    struct Node* temp = graph->adjList[startIndex];

    // Explore all UNVISITED vertices connected to current Vertex
    while( temp!=NULL){

        int connectedIndex = temp->Vertex; 
        if(graph->visited[connectedIndex]==0){
            // Not visited this connectedNode
            DFS(graph, connectedIndex);
        }
        // Move to next connected vertex to current Vertex
        temp = temp->nextNode;
    }

}