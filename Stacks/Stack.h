// Stack Class 
class Stack{

    int top;  // Keep track of top of the Stack

    public:
    int a[10];   // Stack maximum size is 10
    Stack();     // Default constructor
    void push(int x);   // Pushing new element to the stack
    int pop();          // Removing top element of the stack
    void isEmpty();     // Checking if stack is empty

};