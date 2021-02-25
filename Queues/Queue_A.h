class Queue_A{     // Array Implementation of a Queue

    int tail;           //  Rear/back of the Queue
    int head;           //  Front of the Queue
    int size = 10;  // SIZE = hard Code for now. 

    public:
        int a[10];                    // Array of SIZE 
        Queue_A();                        // Constructor
        void enqueue(int x);            // For adding elements to the queue 
        int dequeue_approach1();        // Dequeue/Remove head element and update head to the next index -> Dequeuing approach 1
        int dequeue_approach2();        // Dequeue/Remove head element, push all elements one index up to fill out Index [0] -> Dequeuing approach 2             
        void display();                 // Display all elements of the Queue
        int peek();                     // Retrieve head element without dequeuing
};