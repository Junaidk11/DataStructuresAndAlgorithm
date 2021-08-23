//
//  integer_queue.c
//  Queue_w_stack
//
//  Created by jjkhan on 8/22/21.
//

#include "integer_queue.h"


// =================== Queue Methods ===================
// Initialize the two Stack's top pointers to NULL
// NOTE:  Heap Memory allocation for the stack pointers is important.
void QUEUE_Init(queue *q){
    
    // Allocate memory for the two stack pointers in the heap
    q->s1 = (stack *)malloc(sizeof(stack));
    q->s2 = (stack *)malloc(sizeof(stack));
    
    if(q->s1 && q->s2){
        printf("Memory allocated for both stacks.\n");
        return;
    }
    printf("Heap is full, memory for stack not allocated!");
}

// Add new elements ONLY to stack s1 iff the s1 is not full -> which is determined by heap being able
// to allocate memory for a new node
void QUEUE_enqueue(queue *q, int data){
    
    // Call stack push function and it will do the check for size
    STACK_push(q->s1, data);
}

/*
    For Dequeing, you first pop all the elements from s1 and push to s2 and then you pop top element of s2 -> this is
    front of the queue.
        You keep the elements in s2 after removing element and future calls to dequeue should remove elements from s2
        until s2 becomes empty. When s2 becomes, you pop the new elements from s1 and push to s2 and then pop top element
        of s2 -> this cycle repeats. This way you don't have to move elements from s1 to s2 for dequeuing and then move
        them back.
 */
int QUEUE_dequeue(queue *q){
    // Element dequeued
    int data_removed = INT_MIN;
    
    // Check stacks 1 and 2 are initialized

    // Check if s2 is empty
    if(STACK_isEmpty(*(q->s2))){
        
        // S2 is empty
        
        //check if s1 is not empty before you pop elements from s1 and push to s2
        if(!STACK_isEmpty(*(q->s1))){
            
            // s1 is not empty, pop s1 elements over to s2
            while(!STACK_isEmpty(*(q->s1))){
                STACK_push(q->s2, STACK_pop(q->s1));
            }
            
            // s2's top element is the front element of the queue
            data_removed = STACK_pop(q->s2);
        }else{
            
            // s1 is empty aswell
            printf("Queue underflow.\n");
        }
    }else{
        
        // s2 is not empty
        
        // Dequeue from s2 by just popping top elements
        data_removed = STACK_pop(q->s2);
    }

    
    return data_removed;
    
}

// Queue is empty when both stack pointers are pointing at NULL
int QUEUE_isEmpty(queue q){
    
    if(q.s1->top==NULL && q.s2->top==NULL){
        // Both stacks are empty
        return 1;
    }
    return 0;
}

// Queue is full when you can't allocate anymore memory for enqueue more elements
// New elements are only added to s1 and not s2.
int QUEUE_isFull(queue q){
    
    // To avoid "bad access" errors
    if(q.s1==NULL){
        return 0;
    }else{
        
        // Check if memory can be allocated from heap
        if(STACK_isFull(*(q.s1))){
            return 1;
        }
    }
    
    return 0;
}

/*
    Scenarios:              s1 is not empty and s2 is empty -> Print s1 contents
                            s2 is empty and s1 is empty -> Print s2
                            s1 and s2 both not empty -> s1 is used for enqueue (so its the back of queue), s2 is used for
                                                        dequeuing(so its the front of queue)
 */

int getSize(node *top){
    int count=0;
    // top->next!=NULL is used because if you have 2 nodes, there is 1 link between them, so if 3 nodes -> 2 links
    while(top->next!=NULL){
        count++;
        top = top->next;
    }
    return count;
}
void QUEUE_display(queue q){
    
    // Get stack pointers
    node *stack1_top = q.s1->top;
    node *stack2_top = q.s2->top;
    
    if(stack1_top==NULL && stack2_top == NULL){
        // Queue is empty
        printf("Queue is empty.\n");
    }else if(stack1_top!=NULL && stack2_top==NULL){
        
        // Stack 1 is not empty
        printf("Queue contents are: ");
        // Print queue from the bottom of stack1 to top because stack1 is used for enqueuing data
        
        int s1_size = getSize(stack1_top);
    
        int i;
        for(i=s1_size; i>=0; i--){
            printf(" %d ", STACK_peek(*(q.s1), i));
        }
        printf("\n");
    
    }else if(stack1_top==NULL && stack2_top!=NULL){
        // Stack 2 is not empty
        
        printf("Queue contents are: ");
        // Print queue from the top of stack2 to bottom because stack2 is used for dequeuing data
        
        while(stack2_top!=NULL){
            printf(" %d", stack2_top->data);
            stack2_top = stack2_top->next;
        }
        printf("\n");
    }else{
        
        // Both s1 and s2 are not empty
        
        // Print s2 first because its top is the front of the queue.
        // then count number of elements in s2, followed by using STACK peek to
        // get print data from bottom of stack to the top
        
        
        printf("Queue contents: ");
        
        // Print stack 2 first from top to bottom
        while(stack2_top!=NULL){
            printf(" %d ", stack2_top->data);
            stack2_top = stack2_top->next;
        }
        
        
        // Count number of elements in stack 1
        int s1_size = getSize(stack1_top);
        
        // Print stack 1 from bottom to top
        int i;
        for(i=s1_size; i>=0; i--){
            printf(" %d ", STACK_peek(*(q.s1), i));
        }
        printf("\n");
    
    }
    
}

// =================== Queue Methods ===================
