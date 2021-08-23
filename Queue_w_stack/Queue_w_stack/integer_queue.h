//
//  integer_queue.h
//  Queue_w_stack
//
//  Created by jjkhan on 8/22/21.
//

#ifndef integer_queue_h
#define integer_queue_h

#include <stdio.h>
#include "integer_stack.h"

/*
 
    Note: Building Queue for integer data type, but code can easily be used for any data type
 
 */

// Queue implementation using two stacks
struct QUEUE {
    stack *s1;
    stack *s2;
};
typedef struct QUEUE queue;


// Queue Methods
void QUEUE_Init(queue *q);
void QUEUE_enqueue(queue *q, int data);
int QUEUE_dequeue(queue *q);
void QUEUE_display(queue q);
int QUEUE_isEmpty(queue q);
int QUEUE_isFull(queue q);


#endif /* integer_queue_h */
