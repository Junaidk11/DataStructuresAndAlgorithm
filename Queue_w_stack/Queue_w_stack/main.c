//
//  main.c
//  Queue_w_stack
//
//  Created by jjkhan on 8/22/21.
//

#include <stdio.h>
#include "integer_queue.h"

// Program
void TEST_queue_w_stacks(void);

int main(int argc, const char * argv[]) {
    TEST_queue_w_stacks();
    return 0;
}


void TEST_queue_w_stacks(void){
    // Declare and initialize a queue
    queue integer_queue;
    QUEUE_Init(&integer_queue);
    
    // Check if queue is empty
    printf("Is Queue empty? %d\n", QUEUE_isEmpty(integer_queue));
           
    // Add elements to the queue
    QUEUE_enqueue(&integer_queue, 5);
    QUEUE_enqueue(&integer_queue, 6);
    QUEUE_enqueue(&integer_queue, 7);
    QUEUE_enqueue(&integer_queue, 10);
        
    // Print Queue
    QUEUE_display(integer_queue);
    
    // Remove elements from the queue
    printf("Data removed from queue: %d \n",QUEUE_dequeue(&integer_queue));
    
    
    // Print Queue
    QUEUE_display(integer_queue);
    
    // Add elements to the queue
    QUEUE_enqueue(&integer_queue, 100);
    
    // printf Queue
    QUEUE_display(integer_queue);
    
    // Check if queue is full
    printf("Is Queue full? %d\n", QUEUE_isFull(integer_queue));

    
}
