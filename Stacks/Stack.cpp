#include "Stack.h"

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
    int top_element; 
    if(top<0){
        cout << "Stack Underflow. \n";
        top_element = -1;
    }else{
        top_element = a[top--];
    }
    return top_element;
}

void Stack::isEmpty(){
    if(top<0){
        cout<< "Stack is empty. \n";
    }else{
        cout<< "Stack not empty. \n";
    }
}
