//
//  integer_queue.h
//  Queue_w_linkedlist
//
//  Created by jjkhan on 8/22/21.
//

#ifndef integer_queue_h
#define integer_queue_h

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Node Struct
typedef struct NODE node;
struct NODE{
    int data;
    node *next;
};


// Queue struct with front and rear pointers
struct QUEUE {
    node *front;
    node *rear;
};
typedef struct QUEUE queue;



// Node Operations
node* create_node(int data);

// Queue Operations
void QUEUE_init(queue *que);
void QUEUE_enqueue(queue *que, int data);
int QUEUE_dequeue(queue *que);
int QUEUE_isEmpty(queue que);
int QUEUE_isFull(queue que);
void QUEUE_display(queue que);


#endif /* integer_queue_h */
