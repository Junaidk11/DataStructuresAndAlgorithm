//
//  integer_queue.c
//  Queue_w_array
//
//  Created by jjkhan on 8/22/21.
//

#include "integer_queue.h"

// ============= Queue Operations Implementation ================

// Allocate memory from heap for the Queue
void QUEUE_init(Queue *queue, int size){
    
    // Initialize size, front and rear pointers of the given queue
    queue->size = size;
    queue->front_pointer = queue->rear_pointer = -1;
    
    // Allocate memory from the heap for array
    queue->data = (int *)malloc(size*sizeof(int));
    
}

// Add new elements to the end of the Queue iff the queue is not full
void QUEUE_enqueue(Queue *queue, int data){
    
    if(QUEUE_isFull(*queue)){
        // Queue is full, can't add new element
        printf("Queue overflow.\n");
    }else{
        // Move rear pointer to the next slot in the array and add the new element to it
        queue->rear_pointer++;
        queue->data[queue->rear_pointer] = data;
    }
}

// Remove the element at the front of the Queue iff the queue is not empty
int QUEUE_dequeue(Queue *queue){
    
    if(QUEUE_isEmpty(*queue)){
        // Queue is empty
        printf("Queue underflow.\n");
        return INT_MAX;
    }
    
    // Queue not empty
    // Recall, front pointer is always one index behind the front of the queue because front_pointer starts at -1
    queue->front_pointer++;
    return queue->data[queue->front_pointer];
}

// Queue is full when your rear pointer has reached index "size-1"
int QUEUE_isFull(Queue queue){
    
    if(queue.rear_pointer==(queue.size-1)){
        // Queue is full
        return 1;
    }
    return 0;
}

// Queue is empty when the rear and front pointers are equal: This only happens at initialization and when all the elements in the Queue are removed
int QUEUE_isEmpty(Queue queue){
    
    if(queue.front_pointer==queue.rear_pointer){
        // Queue is emptty
        return 1;
    }
    return 0;
}

// Display queue contents
void QUEUE_display(Queue queue){
    
    if(QUEUE_isEmpty(queue)){
        printf("Queue is empty.\n");
    }else{
        printf("Queue contents are: ");
        int i;
        // i initialized with front pointer + 1 because front pointer always points to one index before the front element of the queue - b/c front_pointer starts at -1
        for(i=queue.front_pointer+1; i<=queue.rear_pointer; i++){
            printf("%d ", queue.data[i]);
        }
        printf("\n");
    }
}


// ============= Queue Operations Implementation ================

