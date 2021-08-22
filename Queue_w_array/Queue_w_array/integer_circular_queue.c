//
//  circular_queue.c
//  Queue_w_array
//
//  Created by jjkhan on 8/22/21.
//

#include "integer_circular_queue.h"

// ============= Circular Queue Operations Implementation ================

// Allocate memory from heap for the Queue
// NOTE: Rear and front pointers of the queue array start at 0, NOT at -1 (the linear queue initialized this way to have o(1) time for
// insertion and deletion from queue

void CIRCULAR_QUEUE_init(Circular_Queue *queue, int size){
    
    // Initialize size, front and rear pointers of the given queue
    queue->size = size;
    queue->front_pointer = queue->rear_pointer = 0;
    
    // Allocate memory from the heap for array
    queue->data = (int *)malloc(size*sizeof(int));
    
}

// Add new elements to the end of the Queue iff the queue is not full
/*
    Formuala for Rear wrap around after rear-pointer==size-1 -> (rear_pointer+1)%size
        Mod operator -> will give you the remainder
 
            Assume size = 4 for this example:
    rear_pointer    | (rear_pointer+1)%size     |     index
        0               (0+1)%size = 1%size             1
        1               (1+1)%size = 2%size             2
        2               (2+1)%size = 3%size             3
        3               (3+1)%size = 4%size             0
        0               (0+1)%size = 1%size             1
        1               (1+1)%size = 2%size             2
        2               (2+1)%size = 3%size             3
        3               (3+1)%size = 4%size             0
 
    Although, we can acheive wrap around with mod-operator, it is important to remember that a circular queue can only hold size-1 elements, because
    the front pointer always pointing to an empty slot (Front pointer also starts at 0 and whenever you call dequeue, it will move to the next slot
    (which is front of the queue) and remove element).
        Therefore, before you enqueue new element, you need to check if moving the rear_pointer to the next slot results in meeting the front_pointer - if it does then
        it will cause queue overflow. Hence, can't add new element to the queue.
 
 */
void CIRCULAR_QUEUE_enqueue(Circular_Queue *queue, int data){
    
   // printf("Before: Front and Rear pointer values are: %d %d \n", queue->front_pointer, queue->rear_pointer);
    
    if(CIRCULAR_QUEUE_isFull(*queue)){
        // Queue is full, can't add new element
        printf("Queue overflow.\n");
    }else{
        // Move rear pointer to the next slot in the array and add the new element to it
            // Calculate new index position using the mod-function  - used for wrap around when you reach end of array
        queue->rear_pointer = (queue->rear_pointer + 1) % queue->size;
        queue->data[queue->rear_pointer] = data;
    }
    //printf("After: Front and Rear pointer values are: %d %d \n", queue->front_pointer, queue->rear_pointer);
}

/*
    Remove the element at the front of the Queue iff the queue is not empty.
 */
int CIRCULAR_QUEUE_dequeue(Circular_Queue *queue){
    
    //printf("Before: Front and Rear pointer values are: %d %d \n", queue->front_pointer, queue->rear_pointer);
    if(CIRCULAR_QUEUE_isEmpty(*queue)){
        // Queue is empty
        printf("Queue underflow.\n");
        return INT_MAX;
    }
    
    // Queue not empty
    // Recall, front pointer is always one index behind the front of the queue because front_pointer initialized with 0 and using mod-operator for wrapping around to 0
    // when value reaches size-1
    queue->front_pointer = (queue->front_pointer+1) % queue->size;
    //printf("After: Front and Rear pointer values are: %d %d \n", queue->front_pointer, queue->rear_pointer);
    return queue->data[queue->front_pointer];
    
}

/* Circular Queue is full when you have size-1 elements in your queue
    because the front pointer always points to an empty spot (when dequeuing, you move one spot ahead and remove the element).
 
    Therefore, Circular queue full condition is to check if moving rear pointer to the next slot will result in meeeting the front_pointer, if so, then queue is full. This
    is because the front pointer always points to a slot before the front of the queue -> i.e. it removed that slot's content in the previous dequeue call.

 */
int CIRCULAR_QUEUE_isFull(Circular_Queue queue){
    
    if(( (queue.rear_pointer+1)%queue.size ) == (queue.front_pointer)){
        // Queue is full
        return 1;
    }
    return 0;
}

/*
    Circular queue is empty when the rear and front pointers are equal: This only happens at initialization and when all the elements in the Queue are removed
 
    Therefore, Circular queue empty condition is the same as linear queue empty condition, if the rear and front pointers are pointing at the same index, the queue is empty.
 */
int CIRCULAR_QUEUE_isEmpty(Circular_Queue queue){
    
    if(queue.front_pointer==queue.rear_pointer){
        // Queue is emptty
        return 1;
    }
    return 0;
}

// Display queue contents
// Formula for wrapping around index to 0 when you reach end of array: index = (currentIndex+1)%arraySize
void CIRCULAR_QUEUE_display(Circular_Queue queue){
    
    if(CIRCULAR_QUEUE_isEmpty(queue)){
        printf("Queue is empty.\n");
    }else{
        printf("Queue contents are: ");
        int i;
        // i initialized with front pointer + 1 because front pointer always points to one index before the front element of the queue - b/c front_pointer starts at 0
        // and using mod-operator for wrap around so can only store size-1 elements in a circular queue
        i=queue.front_pointer+1;
        while(i!=queue.rear_pointer){
            printf("%d ", queue.data[i]);
            
            // Increment using the indexing formula for wrapping around in array when you reach end of array
            i = (i+1)%queue.size;
        } // i is at last element of the circular queue now
        
        // Print last element of the queue
        printf("%d \n", queue.data[i]);
    }
}

// ============= Circular Queue Operations Implementation ================
