#include "Stack.h"

Stack::Stack(){
    top = -1; //-1 indicates stack is empty, because Array indexing starts at 0
    size = 10;
}

void Stack::push(int x){
    // Check if Stack is not full
    if(top>size-1){
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