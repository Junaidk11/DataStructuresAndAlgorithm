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
    {0,0,0,0,0,0,0,0},
    {0,0,1,1,1,0,0,0},
    {0,1,0,1,0,0,0,0},
    {0,1,1,0,1,1,0,0},
    {0,1,0,1,0,1,0,0},
    {0,0,0,1,1,0,1,1},
    {0,0,0,0,0,1,0,0},
    {0,0,0,0,0,1,0,0}
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
void DFS(int startingNode);



int main(int argc, const char * argv[]) {
    
    // @todo: Implement Queue DS and test BFS
    
    // DFS with starting node as 1
   
    printf("\nDFS Starting vertex: 1\n");
    DFS(1);
    /*printf("\nDFS Starting vertex: 4\n");
    DFS(4);
    printf("\nDFS Starting vertex: 5\n");
    DFS(5);*/
    
    return 0;
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
/*
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
*/
/*
    Depth-First search is like pre-order traversal of a tree.
    In this graph traversing method, you visit a vertex and start exploring its adjacent nodes. When you visit an adjacent node, you
    suspend the previous vertex and start exploring this adjacent node. So, the idea is to visit and explore the adjacent
    nodes of a vertex at the same time (unlike BFS, where you visit an adjacent node of a vertex and then add it to Queue
    for exploration later).
    
    For exploring an adjacent node of a vertex at visiting time, you suspend the previous vertex by pushing it on to a Stack, so that you
    can come back to it when you're done visiting and exploring all the adjacent nodes of the current node you're at - you can implement
    a stack DS for this or just implement DFS recursively which automatically uses a stack.
 
    Analytically, this graph traversal method takes o(n) because the work done is simply visiting all the nodes of the graph once. However,
    when you implement the algorithm in code, the time taken depends on the DS use for representing the graph - if Adjacency matrix used,
    the time will be o(n^2) and if adjacency list used the time will be o(vertices + edges) = o(n) - same conclusion applies to BFS.
 */
void DFS(int startingNode){
    
    // static declaration of visited array - to make its content available between function calls
    static int dfs_visited[NUMBER_OF_VERTICES+1]={0};
    int i;
    // First check if the given startingNode is not already visited
    if(dfs_visited[startingNode]==0){
        
        // Starting node not visited, so we mark it as visited first
        dfs_visited[startingNode]=1;
        
        // Process/print the data of the current Vertex
        printf("%d ", startingNode);
        
        // Now we start exploring the adjacent nodes of this node, which is the row corresponding to this starting node in the
        // adjacency matrix above
        
        // exploring the row
        for(i=1; i<NUMBER_OF_VERTICES+1; i++){
            // check if there is an edge with the current Vertex and the node hasn't been visited
            if(graph_adj_matrix[startingNode][i]==1 && visited[i]==0){
                
                // We found an edge and the node connected to this edge hasn't been visited yet
                // therefore, call DFS on this node - this will suspend the current vertex (i.e. push it to a stack, and start exploring
                // this node)
                DFS(i);
            }
            
        }
    }
    
    
}
