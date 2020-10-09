#include <iostream>
using namespace std;  

#define SIZE    10          // Set Desired Queue Size


class Queue{

    int tail;           //  Rear/back of the Queue
    int head;           //  Front of the Queue

    public:
        int a[SIZE];                    // Array of SIZE 
        Queue();                        // Constructor
        void enqueue(int x);            // For adding elements to the queue 
        int dequeue_approach1();        // Dequeue/Remove head element and update head to the next index -> Dequeuing approach 1
        int dequeue_approach2();        // Dequeue/Remove head element, push all elements one index up to fill out Index [0] -> Dequeuing approach 2             
        void display();                 // Display all elements of the Queue
        int peek();                     // Retrieve head element without dequeuing
};

// Queue Constructor Definition
Queue::Queue(){
    head = tail = -1; // Array indexing starts at 0, a negative indicates Queue is empty
}

void Queue::enqueue(int x){
    // Check if Queue is full

    if (head == -1 && tail==-1){
        head = tail = 0;  //Stat indexing Queue 
    }
    if(tail > SIZE-1){
        cout << "Queue overflow." << endl;
    }else{
        a[tail++] = x; // Add new element to the current index of the tail and then increment tail by 1
    }
}

/*
    Dequeuing and updating Head to the next index.
     Avoids overhead with shifting each element one index to fill gap of index 0
*/
int Queue::dequeue_approach1(){

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
int Queue::dequeue_approach2(){
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

void Queue::display(){
    if(head == -1 && tail == -1){
        cout<<"Queue is empty." << endl;
    }else{
        for (int i = head; i<=tail-1; i++){
            
            printf("Queue element at Index %d: %d \n", i, a[i]);

        }
    }
}

int Queue::peek(){
    return a[head]; // returning the head element of the queue
}

int main(){

    Queue q1; 
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