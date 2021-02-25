#include <iostream>
using namespace std;  
#include "Queue_A.cpp"

int main(){

    Queue_A q1; 
    q1.enqueue(100);
    q1.enqueue(1000);
    q1.enqueue(4);
    q1.enqueue(56);
    q1.enqueue(0);
    q1.enqueue(11);
    q1.display();
    //q1.dequeue_approach1();  
    //q1.display();
    q1.dequeue_approach2();
    q1.display();
    printf("Head element: %d\n",q1.peek());

    return 0;
}