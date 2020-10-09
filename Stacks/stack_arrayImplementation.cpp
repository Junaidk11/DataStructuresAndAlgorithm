#include <iostream>
using namespace std;
class Stack{

    int top;  // Keep track of top of the Stack

    public:
    int a[10];   // Stack maximum size is 10
    Stack();     // Default constructor
    void push(int x);   // Pushing new element to the stack
    int pop();          // Removing top element of the stack
    void isEmpty();     // Checking if stack is empty

};

// Default Constructor
Stack::Stack(){
        top = -1;
    
}
void Stack::push(int x){
    if(top>=10){
        cout << "Stack overflow. \n";
    }else{
        a[++top] = x;
    }
}

int Stack::pop(){
    if(top<0){
        cout << "Stack Underflow. \n";
    }else{
        int top_element = a[top--];
        return top_element;
    }
}

void Stack::isEmpty(){
    if(top<0){
        cout<< "Stack is empty. \n";
    }else{
        cout<< "Stack not empty. \n";
    }
}

int main(){

    Stack s1; 
    s1.isEmpty(); 
    s1.push(100);
    s1.push(20);
    printf("Stack top element: %d \n", s1.pop());
    s1.isEmpty();
    printf("Stack top element: %d \n", s1.pop());
    s1.isEmpty();
    /*
      Application code for using Stack DS. 

    */
   return 0;
}