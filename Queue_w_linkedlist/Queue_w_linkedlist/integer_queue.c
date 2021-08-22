//
//  integer_queue.c
//  Queue_w_linkedlist
//
//  Created by jjkhan on 8/22/21.
//

#include "integer_queue.h"


// Node Operations

// Allocate memory from heap and initialize the node
node* create_node(int data){
    
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Queue Operations

// Initialize the front and rear pointers to null
void QUEUE_init(queue *que){
    que->front=que->rear = NULL;
}

/*
    Create a new node and add the new element to the end of the Queue and updating rear pointer to it.
    The node is only added to the queue iff it is not full, the queue is full if the heap cannot allocate memory for the new node.
 
    Special case: If this the first node in the queue, then both front and rear pointers should point here.
                  else you only update rear pointer as you add more nodes to the queue.
 */
void QUEUE_enqueue(queue *que, int data){
    
    // Allocate memory for new node
    node *newNode=create_node(data);
    
    // Update queue internal pointers iff the memory allocation was successful
    if(newNode){
        // Memory allocated successfully
        
        // Check if this the first node in the queue
        if(que->front==NULL){
            // This is first node
            
            // Both front and rear should point to same node
            que->front = que->rear = newNode;
            
        }else{
            // Not first node
            // Add new node to the end of the queue and update rear pointer of queue
            que->rear->next = newNode;
            que->rear = que->rear->next;
        }
    }else{
        
        // Memory allocation unsucessfull, Queue is full (i.e. heap is full
        printf("Queue Overflow. \n");
    }
    
}

/*
    Node is removed from the front of the queue and the front pointer is updated.
 
    Element from the front is removed only if the queue is not empty.
    
    Queue is empty when front pointer is NULL
 */
int QUEUE_dequeue(queue *que){
    
    int data_removed = INT_MAX;
    
   // Check if queue is not empty
    if(QUEUE_isEmpty(*que)){
        // Queue is empty
        printf("Queue underflow. \n");
        return data_removed;
    }else{
        
        // Queue is not empty
        
        // Temporary pointer to the front of the queue
        node *temp = que->front;
        
        // Get data from the front node first
        data_removed = temp->data;
        
        // Update front pointer to the next node
        que->front = que->front->next;
        
       
        // Return front node memory back to heap
        free(temp);
    }
    
    // return data removed from the queue
    return data_removed;
    
}

// Check if queue is empty
// Empty condition is front pointer of the queue is NULL
int QUEUE_isEmpty(queue que){
    
    if(que.front==NULL){
        return 1;
    }
    return 0;

}

// Queue is full if memory allocation from heap for new node fails
int QUEUE_isFull(queue que){
    
    // new node memory allocation request
    node *newNode = (node*)malloc(sizeof(node));
    
    // check if memory allocation was a success
    if(newNode){
        // Memory allocation was a success
        
        // Return memory allocated from heap before returning from function
        free(newNode);
        return 0;
        
    }else{
        
        // Memory allocation failed, heap is full, which means queue is full
        return 1;
    }
    
}

// The queue is passed by value here, its a copy so you directly use the front pointer to traverse the queue
void QUEUE_display(queue que){
    
    if(QUEUE_isEmpty(que)){
        printf("Queue is empty.\n");
    }else{
        printf("Queue contents are: ");
        while(que.front!=NULL){
            
            // print current node data
            printf(" %d", que.front->data);
            
            // move to next node
            que.front = que.front->next;
        }
        
        printf("\n");
    }
}
