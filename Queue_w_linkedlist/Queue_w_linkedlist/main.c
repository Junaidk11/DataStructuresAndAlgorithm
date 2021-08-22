//
//  main.c
//  Queue_w_linkedlist
//
//  Created by jjkhan on 8/22/21.
//

#include <stdio.h>
#include "integer_queue.h"



// Test Programs
void TEST_Queue_using_linkedlist(void);

int main(int argc, const char * argv[]) {
    
    TEST_Queue_using_linkedlist();
    return 0;
}

void TEST_Queue_using_linkedlist(void){
    
    // Declare and initialize queue
    queue integer_queue;
    QUEUE_init(&integer_queue);
    
    // Display Queue
    QUEUE_display(integer_queue);
    
    // Add elements to the queue
    
    // Add elements to the Queue
    QUEUE_enqueue(&integer_queue, 4);
    // Display Queue content
    QUEUE_display(integer_queue);

    QUEUE_enqueue(&integer_queue, 45);
    // Display Queue content
    QUEUE_display(integer_queue);

    QUEUE_enqueue(&integer_queue, 100);
    // Display Queue content
    QUEUE_display(integer_queue);

    QUEUE_enqueue(&integer_queue, 150);
    // Display Queue content
    QUEUE_display(integer_queue);

    QUEUE_enqueue(&integer_queue, 200);
    // Display Queue content
    QUEUE_display(integer_queue);

    QUEUE_enqueue(&integer_queue, 1234);
    // Display Queue content
    QUEUE_display(integer_queue);
    
    // Check if Queue is full
    printf("Is the queue full? %d \n", QUEUE_isFull(integer_queue));
    
    // Remove Queue contents
    printf("Element removed from the queue: %d\n", QUEUE_dequeue(&integer_queue));
    
    // Display Queue
    QUEUE_display(integer_queue);
    
    // Remove Queue contents
    printf("Element removed from the queue: %d\n", QUEUE_dequeue(&integer_queue));
    printf("Element removed from the queue: %d\n", QUEUE_dequeue(&integer_queue));
    
    // Display Queue
    QUEUE_display(integer_queue);
    
    printf("Element removed from the queue: %d\n", QUEUE_dequeue(&integer_queue));
    printf("Element removed from the queue: %d\n", QUEUE_dequeue(&integer_queue));
    printf("Element removed from the queue: %d\n", QUEUE_dequeue(&integer_queue));
    
}
