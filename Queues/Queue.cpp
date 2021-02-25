#include "Queue.h"

void Queue::enqueue(int x){

    // Enqueing for this implementation of Queue for
    s1.push(x); // s1 checks if the stack is full or not before pushing queuing new element
}
int Queue::dequeue(){

    int x,y; // 'x' for place holder for pop and push operation; 'y' placeholder for the Queue's header element
    // Move all elements from Stack s1 to Stack s2
    while(!s1.isEmpty()){
        x = s1.pop();  // Pop top element from data stack s1
        s2.push(x);    // Push top element of s1 to the temporary storage stack s2
    }
    y = s2.pop();  // After moving s1 elements to s2, s2's top element is the head of the Queue -> need to return this

    // Move elements back from temporary storage s2 stack to the data stack s1
    while(!s2.isEmpty()){
        x = s2.pop();  
        s1.push(x);
    }
    return y;
}

void Queue::display(){
    s1.display();  // s1 is the data Stack 
}