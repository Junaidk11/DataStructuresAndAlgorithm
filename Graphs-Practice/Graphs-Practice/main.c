//
//  main.c
//  Graphs-Practice
//
//  Created by jjkhan on 8/16/21.
//

#include <stdio.h>
#include <stdbool.h>

// Adjacency Matrix
// An undirected graph with 7 nodes and 9 edges, you see 18 because edges are both ways
// Also nodes are numbered from 1-7. Therefore, row and column 0 are empty
#define NUMBER_OF_VERTICES 7
int graph_adj_matrix [NUMBER_OF_VERTICES+1][NUMBER_OF_VERTICES+1] = {
    {0},
    {0,0,1,1,1},
    {0,1,0,1},
    {0,1,1,0,1,1},
    {0,1,0,1,0,1},
    {0,0,0,1,1,0,1,1},
    {0,0,0,0,0,1},
    {0,0,0,0,0,1}
};

// An array to keep track of Vertices visited
int visited[8] = {0};

// A basic queue DS
struct QUEUE{
    int array[NUMBER_OF_VERTICES+1];
    int start;
    int end;
}queue;

void enqeue(struct QUEUE *pQueue, int node);
int dequeue(struct QUEUE *pQueue);
bool isEmpty(struct QUEUE *pQueue);

// Graph traversal Algorithms
void BFS(int startingNode);



int main(int argc, const char * argv[]) {
    
}


/*
    Breadth-First Search of Graph = Level Order traversal of Tree
        A graph can be re-written as a tree and you can visualize the level order traversal.
    
    The idea:
            Given a starting node, you mark the node as visited and add that node into a queue. Next, dequeue this node and explore
            its adjacent nodes (i.e. its edges), each adjacent node is marked as visited and added to queue for exploration later (after you've explored all the edges of the current node you're exploring). Once you have explored all the adjacent
            nodes (i.e. added them into the queue and marked them visited), you dequeue a node from the queue and explore its adjacent nodes, repeat this until you've explored all the nodes in the queue.
 
    There could be multiple solutions to BFS, depending on your starting node and the order in which you explore adjacent nodes.
 
    Things neeeded for a BFS:
                An Adjacency Matrix to represent a graph's vertices and edges
                An array of size corresponding to number of vertices in the graph - this is used to keep track of nodes visited
                A queue DS to push nodes into the queue when you're exploring a node's adjacent nodes.
               
 */
void BFS(int startingNode){
    
    // Print/Process the given starting node
    printf("%d ", startingNode);
    
    // Mark starting node as visited
    visited[startingNode]=1;
    
    // Push the starting node into a queue
    enqeue(&queue, startingNode);
    
    // Now, explore the adjacent nodes of the node in the queue (after dequeuing it)
    int dequeued_node;
    while(!isEmpty(&queue)){
        // First dequeue a node from the queue
        dequeued_node = dequeue(&queue);
        
        // For the dequeued node, you should EXPLORE all its edges, which are defined in the Adjacency matrix as the row
        // corresponding to the dequeued node.
        int i;
        for(i=0; i<(NUMBER_OF_VERTICES+1); i++){
            
            // Check if there is an edge (represented by '1' in the row) and the node connected to this edge has not been visited yet
            if(graph_adj_matrix[dequeued_node][i] == 1 && visited[i]==0){
                // Found an edge and the node connected to this edge has not been visited. Therefore,
                // print/process this edge's node, mark it as visited and add it to queue for exploration later
                printf("%d ", i);
                
                // Mark this adjacent node as visited
                visited[i] = 1;
                
                // Add this node to the queue for exploration later
                enqeue(&queue, i);
            }
            
        }
        
    }
    
}
