#include <iostream>
using namespace std; 

#include "../Stacks/Stack.cpp"
#include "Queue.cpp"

int main(){
    Queue q1; 
    q1.enqueue(100);
    q1.enqueue(2);
    q1.enqueue(40);
    q1.enqueue(35);
    q1.display();
    q1.dequeue();   
    q1.display();
    return 0;
}

