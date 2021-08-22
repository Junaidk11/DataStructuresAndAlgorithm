//
//  integer_queue.h
//  Queue_w_array
//
//  Created by jjkhan on 8/22/21.
//

#ifndef integer_queue_h
#define integer_queue_h

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


/*
                QUEUE structure
        Data stored in Queue is Integer in this implementation, but can easily adapt for other types.
 
    NOTES:
            Queue Front and Rear "pointers" - actually index place holders
            The front pointer will point to the element before the current element at the front of the Queue
                -> Because: starting both pointers at -1, rear moves down the array as elements get in Queue, Front moves down the array as elements are removed from the Queue
                    In this way both removing and adding an element from the queue takes a constant time  - o(1)
            Front and Rear are same at start of Queue and when Queue is emptied as elements are removed from the Queue.
            The rear pointer will always point to the last element in the Queue
 
 */
struct QUEUE {
    
    // Array size
    int size;
    int front_pointer;
    int rear_pointer;
    
    // Pointer to memory allocated from Heap
    int *data;
};

// For Readability
typedef struct QUEUE Queue;


// Queue Operations
void QUEUE_init(Queue *queue, int size);
void QUEUE_display(Queue queue);
void QUEUE_enqueue(Queue *queue, int data);
int QUEUE_dequeue(Queue *queue);
int QUEUE_isFull(Queue queue);
int QUEUE_isEmpty(Queue queue);


#endif /* integer_queue_h */
