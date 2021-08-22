//
//  circular_queue.h
//  Queue_w_array
//
//  Created by jjkhan on 8/22/21.
//

#ifndef integer_circular_queue_h
#define integer_circular_queue_h

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


/*
                Circular QUEUE structure
        Data stored in Queue is Integer in this implementation, but can easily adapt for other types.
 
    NOTES:
            Queue Front and Rear "pointers" - actually index place holders.
            The front pointer will point to the element before the current element at the front of the Queue
            Front and Rear are same at start of Queue and when Queue is emptied as elements are removed from the Queue.
            The rear pointer will always point to the last element in the Queue.
 
 
     IMPORTANT NOTE:
        When implementing a queue using arrays, best implementation (i.e. o(1) time for enqueue and dequeue) is a circular queue because in a linear queue, although
        the enqueue and dequeue can be acheived in o(1) time, the array space is only used once - you could reset the pointers, it still won't always guarantee the
        spaces will be used more than once. However, in circular queue implementation, the array spaces are used multiple times with o(1) time enqueuing and dequeing operations.
 
 */

struct CIRCULAR_QUEUE {
    
    // Array size
    int size;
    int front_pointer;
    int rear_pointer;
    
    // Pointer to memory allocated from Heap
    int *data;
};

// For Readability
typedef struct CIRCULAR_QUEUE Circular_Queue;


// Queue Operations
void CIRCULAR_QUEUE_init(Circular_Queue *queue, int size);
void CIRCULAR_QUEUE_display(Circular_Queue queue);
void CIRCULAR_QUEUE_enqueue(Circular_Queue *queue, int data);
int CIRCULAR_QUEUE_dequeue(Circular_Queue *queue);
int CIRCULAR_QUEUE_isFull(Circular_Queue queue);
int CIRCULAR_QUEUE_isEmpty(Circular_Queue queue);

#endif /* circular_queue_h */
