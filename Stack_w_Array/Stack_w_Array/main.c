//
//  main.c
//  Stack_w_Array
//
//  Created by jjkhan on 8/19/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
    General Structure for a Stack. The size and top element are integers.
    The actual stack data type is dependent on application - using integer for simplicity, could
    easily be an array of pointers, or could be an array of another structure. Allocate memory dynamically depending on size given.
 */
typedef struct _STACK_{
    
    int size;
    int top;
    int *stack;
}stack;

// Stack Operations
void STACK_Init(stack *s);
void STACK_push(stack *s,int data);
int STACK_pop(stack *s);
int STACK_peak(stack s, int position);
int STACK_stackTop(stack s);
int STACK_isEmpty(stack s);
int STACK_isFull(stack s);


// Program functions
void stack_ADT_Test(void);


int main(int argc, const char * argv[]) {
    
    stack_ADT_Test();
    return 0;
}

// Testing all the Stack operations - test passed!
void stack_ADT_Test(void){
   
    stack integerStack;
    // initialize stack
    STACK_Init(&integerStack);
    
    // Check if stack is empty
    printf("Stack is empty? %d \n", STACK_isEmpty(integerStack));
    
    // Add elements to the stack
    STACK_push(&integerStack, 9);
    STACK_push(&integerStack, 8);
    STACK_push(&integerStack, 7);
    STACK_push(&integerStack, 5);
    STACK_push(&integerStack, 4);
    
    // Check if stack is full
    printf("Stack is full? %d \n", STACK_isFull(integerStack));
    
    // Get top of the stack
    printf("Top element of the stack is: %d \n", STACK_stackTop(integerStack));
    
    // Peak position of the stack
    printf("Stack element at position 1: %d \n", STACK_peak(integerStack, 1)); // top element of the stack
    printf("Stack element at position 2: %d \n", STACK_peak(integerStack, 2)); // Second element of the stack from the top
    printf("Stack element at position 3: %d \n", STACK_peak(integerStack, 3)); // third element of the stack from the top
    
    // Pop elements from the stack
    printf("Removed top element of the stack is: %d \n", STACK_pop(&integerStack));
    
}

// ==========  Stack Operation Implementation ===========

// Initialize stack by asking for size and allocating memory from heap for the stack array
void STACK_Init(stack *s){
    
    printf("Enter size of the stack.\n");
    scanf("%d",&(s->size));
    
    // Allocate memory for the stack array
    s->stack = (int *)malloc(sizeof(int)*(s->size));
    
    // Set top to outside stack array
    s->top = -1;
}

// Push given data to stack top iff the stack is not full
void STACK_push(stack *s,int data){
    if(STACK_isFull(*s)){
        printf("Stack Overflow.\n");
    }
    else{
        // Stack is not full, insert new element by first incrementing top pointer
        s->top++;
        s->stack[s->top] = data;
    }
}

// Pop top element from the stack iff the stack is not empty
int STACK_pop(stack *s){
    
    int x = INT_MIN;
    if(STACK_isEmpty(*s)){
        printf("Stack underflow.\n");
    }else{
        
        // retrieve top element of stack and decrement top pointer
        x = s->stack[s->top];
        s->top--;
        
    }
    return x;
    
}

/*
    The top pointer starts at -1 and moves up (think of vertical array with index incrementing from bottom),
    the element position starts from top as 1 and works down. Therefore, the stack indexing formula based on position given:
                        stack_index = (Top-position)+1
            Assume stack size is 5, and you have it full upto index 3. Now you want to peak the second element in the stack, which is
            index 2 of stack array, you get this: Top-position + 1 = (3-2)+1 = 1+1= 2
 
    Note: Only peak the stack iff the calculate Stack index is valid, i.e. not <0
 */
int STACK_peak(stack s, int position){
    
    int index = (s.top-position) + 1;
    int data = INT_MIN;
    if(index <0){
        printf("Invalid position.\n");
    }else{
        data = s.stack[index];
    }
    
    // If position was valid, you will get a value else you will get INT_MIN
    return data;
}

// Returns the top element of the stack iff the stack is not empty
int STACK_stackTop(stack s){
    int data = INT_MIN;
    if(STACK_isEmpty(s)){
        printf("Stack is empty.\n");
    }else{
        data = s.stack[s.top];
    }
    // Returns INT_MIN if stack is empty, else returns the top element of the stack
    return data;
}

// Checks if top pointer is a valid array index, if valid: stack is not empty, else it is empty.
int STACK_isEmpty(stack s){
    if(s.top<0){
        return 1;
    }
    return 0;
}

// Checks if top pointer is equal to size-1
int STACK_isFull(stack s){
    if(s.top == s.size-1){
        return 1;
    }
    return 0;
}
// ==========  Stack Operation Implementation ===========
