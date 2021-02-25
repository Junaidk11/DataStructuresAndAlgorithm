#include "Queue_A.h"

// Queue Constructor Definition
Queue_A::Queue_A(){
    head = tail = -1; // Array indexing starts at 0, a negative indicates Queue is empty
}

void Queue_A::enqueue(int x){
    // Check if Queue is full

    if (head == -1 && tail==-1){
        head = tail = 0;  //Stat indexing Queue 
    }
    if(tail > size-1){
        cout << "Queue overflow." << endl;
    }else{
        a[tail++] = x; // Add new element to the current index of the tail and then increment tail by 1
    }
}

/*
    Dequeuing and updating Head to the next index.
     Avoids overhead with shifting each element one index to fill gap of index 0
*/
int Queue_A::dequeue_approach1(){

    // Check if Queue is empty
    if(tail == -1 && head == -1){
        cout << "Queue underflow. " << endl;
    }else{
        return a[head++]; // Return the current head element and update head to next index. 
    }

}
/*
    Dequeuing and shifting all elements of the queue one index up/right to fill up gap created by head index.
*/
int Queue_A::dequeue_approach2(){
    int dequeue_element; 
    // Check if Queue is empty
    if(tail == -1 && head == -1){
        cout << "Queue underflow. " << endl;
    }else{
        dequeue_element = a[head]; // Return the current head element and update head to next index. 

        for(int i = head; i<tail-1;i++){           
            a[i] = a[i+1];      // Shift each element to the top/right by 1 index  
        } 
        tail--;             // Reduce tail by 1 element after shifting of elements
        return dequeue_element;
    }

}

void Queue_A::display(){
    if(head == -1 && tail == -1){
        cout<<"Queue is empty." << endl;
    }else{
        for (int i = head; i<=tail-1; i++){
            
            printf("Queue element at Index %d: %d \n", i, a[i]);

        }
    }
}

int Queue_A::peek(){
    return a[head]; // returning the head element of the queue
}