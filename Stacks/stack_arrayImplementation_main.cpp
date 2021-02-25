#include <iostream>
using namespace std;
#include "Stack.cpp"
 

int main(){

    // Simple Test of Stack DS
    Stack s1; 
    s1.isEmpty(); 
    s1.push(100);
    s1.push(20);
    printf("Stack top element: %d \n", s1.pop());
    s1.isEmpty();
    printf("Stack top element: %d \n", s1.pop());
    s1.isEmpty();
    
   return 0;

}