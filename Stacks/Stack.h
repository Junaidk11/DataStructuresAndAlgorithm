
class Stack{

    int top;  // Top of the stack 
    int size; 
    public:
        int a[10];        // Stack Size
        Stack();            // Stack class constructor
        int pop();          // Method to remove element at top of the stack
        void push(int x);   // Push new element to the top of the stack
        bool isEmpty();     // Checking if the stack is empty
        void display();     // Display Stack contents
};