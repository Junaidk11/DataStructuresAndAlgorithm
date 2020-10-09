#include <iostream>
using namespace std; 

#define SIZE 10

class Stack{

    int top;  // Top of the stack 
    public:
        int a[SIZE];        // Stack Size
        Stack();            // Stack class constructor
        int pop();          // Method to remove element at top of the stack
        void push(int x);   // Push new element to the top of the stack
        bool isEmpty();     // Checking if the stack is empty
        void display();     // Display Stack contents
};

Stack::Stack(){
    top = -1; //-1 indicates stack is empty, because Array indexing starts at 0
}

void Stack::push(int x){
    // Check if Stack is not full
    if(top>SIZE-1){
        cout << "Stack overflow. \n" << endl;
    }else{
        a[++top] = x; // Increment top counter and then Push element to the top of the stack 
    }
}

int Stack::pop(){
    //Check if stack is empty
    if(top == -1){
        cout << " Stack underflow." << endl;
    }else{
        return a[top--]; //Return the top of the stack followed by decrementing top 
    }
}

bool Stack::isEmpty(){
    if(top==-1){
        return true;
    }
    return false;
}

void Stack::display(){
    // Check if stack is empty
    if(top==-1){
        cout << "Stack underflow. " << endl;
    }else{
        int stack_size = top;
        while(stack_size>-1){
            printf("Stack element at index %d: %d \n", stack_size, a[stack_size]);
            stack_size--;
        }
    }
}
/* Note: The following implementation of Queue with Stacks is with Dequeuing the costly operation - 
        i.e. dequeuing takes longer than enqueuing because new element pushed into Stack will be at the bottom of the 
            stack - simple push() to enqueue new elements. 
            However, to dequeue first element: 
                1. Need to empty stack one by one to a new stack(temporary storage)
                2. pop the top of new stack -> your first element
                3. Move the temporary stack elements back to original stack 
*/
class  Queue{
    Stack s1, s2;    // Need two stacks of equal size to implement Queue with Stacks; s1 for holding the data and s2 as temporary storage for data operations
    public:
    void enqueue(int x);
    int dequeue();
    void display();

};

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

