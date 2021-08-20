//
//  main.c
//  Stack_w_linkedlist
//
//  Created by jjkhan on 8/19/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/*
   Node structure for creating stack contents. Here we're assuming the node data is of type int, could be changed as desired.
    
    // Changed data to char
 */
typedef struct NODE node;
struct NODE {
    char data;
    node *next;
};

// Node Operations
node* create_node(char data);

/*
    The stack holds pointer to the top element of the Stack.
    Since the nodes are allocated memory from the Heap, the size of the stack is limited by heap allocating memory when requested.
        This can be used to determine if the stack is full by looking at the output of malloc call for new node creation.
 */
typedef struct STACK{
    node *top;
}stack;


// Stack Operation
void STACK_Init(stack *s);
void STACK_display(stack s);
void STACK_push(stack *s, char data);
char STACK_pop(stack *s);
char STACK_peak(stack s, char position);
char STACK_top(stack s);
int STACK_isEmpty(stack s);
int STACK_isFull(void);

// Program functions
void STACK_ADT_test(void);
void TEST_parenthesis_matching(void);
void TEST_infix_to_postfix(void);

// Stack Applications
int parenthesis_matching(char* str);
char* infix_to_postfix(char *infix, int size);

int main(int argc, const char * argv[]) {
    
    TEST_infix_to_postfix();
    return 0;
}

// All tests passed
void TEST_infix_to_postfix(void){
    
    // Test inputs
    char *input1 ="a+b";  // postix = ab+  -> passed
    
    /*
     NOTES:
     
        char *input2 ="a+b*c-d/e";
     
     Postfix = a+[bc*]-d/e -> a+[bc*]-[de/] -> [abc*+]-[de/] -> [abc*+de/-] = result -> NOT passed because compiler doesn't read '\' as \, gives warning if in isOperand you put '\' without escape sequence.
     Therefore, using '/' to indicate '\'
    */
    char *input2 ="a+b*c-d/e"; // Postfix = a+[bc*]-d\e -> a+[bc*]-[de\] -> [abc*+]-[de\] -> [abc*+de\-] = result -> Passed
    char *input3 ="a+b+c*d"; // postix = a+b+[cd*] -> [ba+]+[cd*] -> [ab+cd*+] -> passed
    char *input4 ="a+b*c"; // postfix = abc*+ -> passed
    
    // Function tests
    printf("Postfix of infix %s is: %s \n", input1, infix_to_postfix(input1, 3));
    printf("Postfix of infix %s is: %s \n", input2, infix_to_postfix(input2, 9));
    printf("Postfix of infix %s is: %s \n", input3, infix_to_postfix(input3, 7));
    printf("Postfix of infix %s is: %s \n", input4, infix_to_postfix(input4, 5));
    
}
// Function testing different inputs to parenthesis matching function - passed for all inputs
void TEST_parenthesis_matching(void){
    
    // Test inputs
    char *input1 ="((a+b)*(c+d))";
    char *input2 ="(((a+b)*(c+d))";
    char *input3 ="((a+b)*(c+d)))";
    char *input4 ="{([a+b]*[c-d])/5}";
    char *input5 ="{([a+b)*[c-d})/5}";
   
    // Function call
    printf("Parenthesis in %s match? %d\n", input1, parenthesis_matching(input1));
    printf("Parenthesis in %s match? %d\n", input2, parenthesis_matching(input2));
    printf("Parenthesis in %s match? %d\n", input3, parenthesis_matching(input3));
    printf("Parenthesis in %s match? %d\n", input4, parenthesis_matching(input4));
    printf("Parenthesis in %s match? %d\n", input5, parenthesis_matching(input5));
    
}

// Function testing all the operations of the stack implemented using a linkedlist - Passed, tested with integer 'data'
void STACK_ADT_test(void){
    
    stack integerNumbers;
    STACK_Init(&integerNumbers);
        
    // Check if stack is empty
    printf("Is stack empty? %d\n", STACK_isEmpty(integerNumbers));
    
    // Check if stack is full
    printf("Is stack full? %d \n", STACK_isFull());
    
    // Just call push function to add to the stack
    STACK_push(&integerNumbers, 5);
    STACK_push(&integerNumbers, 11);
    STACK_push(&integerNumbers, 45);
    STACK_push(&integerNumbers, 98);
    STACK_push(&integerNumbers, 123);
    
    // Display stack
    STACK_display(integerNumbers);
    
    
    
    // Peak stack
    printf("Stack element at position 1: %d\n", STACK_peak(integerNumbers, 1));
    printf("Stack element at position 2: %d\n", STACK_peak(integerNumbers, 2));
    printf("Stack element at position 4: %d\n", STACK_peak(integerNumbers, 4));
    printf("Stack element at position 6: %d\n", STACK_peak(integerNumbers, 6));
    
    
    // Pop from stack
    printf("Element popped from the stack: %d\n", STACK_pop(&integerNumbers));
    STACK_display(integerNumbers);
    printf("Element popped from the stack: %d\n", STACK_pop(&integerNumbers));
    STACK_display(integerNumbers);
    printf("Element popped from the stack: %d\n", STACK_pop(&integerNumbers));
    STACK_display(integerNumbers);
    
    // Check if stack is empty
    printf("Is stack empty? %d\n", STACK_isEmpty(integerNumbers));
    
    // Check if stack is full
    printf("Is stack full? %d \n", STACK_isFull());
    
}


// =========== Node Operation Implementation ===========

// Allocate memory for a node and initialize it
node* create_node(char data){
    
    node *temp = (node *)malloc(sizeof(node));
    if(temp){
        // Memory allocation successfull, initialize it with data and return pointer
        temp->data = data;
        return temp;
    }
    
    // Memory allocation not successfull i.e. stack overflow
    return NULL;
}
// =========== Node Operation Implementation ===========

// =========== Stack Operation Implementation ===========

// Simple initialization of the stack's top pointer
void STACK_Init(stack *s){
    s->top=NULL;
}

// This function is used to push new elements on to the stack iff memory for a new node can be allocated - i.e. stack is not full
void STACK_push(stack *s, char data){
    
    // Request memory for a new node
    node *newNode = create_node(data);
    
    // Check if memory successfully allocated
    if(newNode){
        // Memory allocated successfully.
        
        // Add new node to the front of the Stack
        newNode->next = s->top;
        
        // update top of the stack
        s->top = newNode;
    }else{
        // Memory allocation for new node not successfull
        printf("Stack overflow.\n");
    }
}

// Diplay the content of the stack, the stack is passed by value, so its a copy
// The stack is passed by value so its a copy of the original stack created in main, HOWEVER, the "top" pointer inside stack copy
// is pointer to the original head of the stack, so don't move that - HENCE the need for *temp at start.
void STACK_display(stack s){
    
    while(s.top!=NULL){
        
        // Print current node data
        printf("%d ", s.top->data);
        
        // Move top pointer to the next element
        s.top = s.top->next;
        
    }
    printf("\n");
}

// Remove the top of the stack and update top pointer to the next node iff the stack is not empty -> i.e. top!=NULL
char STACK_pop(stack *s){
    // Place holder for value popped from the stack
    //int x = INT_MIN;
    char x=' ';
    
    if(s->top){
        
        // Stack is not empty
        
        // Temporay pointer for updating deleting node that is popped
        node *temp =  s->top;
        
        // Get the data in top element of stack
        x = temp->data;
        
        // Update top to the next element of the stack
        s->top = s->top->next;
        
        // Return the allocated memory of the node removed from stack
        free(temp);
        temp = NULL;
    }
    
    // This will return top data from stack or will return INT_MIN if the stack was empty
    return x;
    
    
}

// This function will move the top pointer to the position given and return its data.
// The stack is passed by value so its a copy of the original stack created in main.
char STACK_peak(stack s, char position){
    
    // Move top pointer to the position given
    int i;
    for(i=1; i<position && s.top!=NULL; i++){
        // Move top pointer to the next node in the stack
        s.top = s.top->next;
    }
    
    // Check if the top is pointing to a valid node before you return the data of the node
    if(s.top){
        // Valid node, return its data
        return s.top->data;
    }
    
    // The stack is empty, return this
    return ' ';
}
// Returns top element of the stack
char STACK_top(stack s){
    
    if(s.top){
        // top pointer is not NULL, i.e. stack not empty
        return s.top->data;
    }
    // Return space if nothing there
    return ' ';
}

// Check if the top pointer of the stack is not NULL
int STACK_isEmpty(stack s){
    if(s.top){
        // top pointer is not NULL, i.e. stack is not empty
        return 0;
    }
    return 1;
}

// Try allocating memory for a node from heap, if not successfull, the stack is full
int STACK_isFull(void){
    
    // Allocate memory for a node with random data
    node *temp = create_node(1);
    
    // Check if memory allocation successful
    if(temp){
        // Memory allocated successfully
        // Return the allocated memory
        free(temp);
        
        // Return false because stack is not full i.e. was able to allocate memory from heap
        return 0;
    }
    
    // Unable to allocate memory from heap - return true to indicate stack is full
    return 1;
}
// =========== Stack Operation Implementation ===========



/*
    This is a helper function to check if the closing bracket is same type as its opening bracket
    i.e.        [ ] = true, { } = true, ( ) = true, everything else is false
 */
int bracket_matched(char closing_bracket, char opening_bracket){
    
    if((opening_bracket == '[' && closing_bracket == ']')
       || (opening_bracket == '{' && closing_bracket == '}')
       || (opening_bracket == '(' && closing_bracket == ')')){
        
        // Its one of the correct matches of closing and opening
        return 1;
    }
       // Opening and closing brackets are not of same type
       return 0;
    
}
// =========== Stack Applications  ===========
/*
    
    input = ((a+b) * (c-d))
    output = true, i.e. each opening bracket has a closing bracket
  
    input = (((a+b) * (c-d))
    output = false, one opening bracket has no closing bracket
 
    The idea is to scan the given string and push every opening bracket into the stack. For every closing bracket,
    you pop the top most element of the stack. At the end of the string if the stack is empty, then the parenthesis are
    matched, i.e. every opening bracket has a closing bracket.
 
    You only push and pop when you encounter brackets in the given string, every other character is skipped.
    
    Possible situations:
        1) all parenthesis match - i.e. reached end of string and stack is empty
        2) One opening bracket in stack but reached the end of the string - i.e. stack is not empty
        3) One closing bracket encountered in string but the stack is empty.
 
    NOTE: This method doesn't check if the given string is parenthesize correctly, it only checks if the parenthesis
            match. i.e. ((a+)b * (c-d))  -> parenthesis match but the string is not correctly parenthesized.
 
    Update:
            Code changed for input with different kinds of brackets : i.e. '(', '{', '['

 */
int parenthesis_matching(char* str){
    
    // Declare a stack
    stack opening_brackets;
    STACK_Init(&opening_brackets);
    
    // Place holder for the opening bracket popped from the stack
    char popped;
    
    // Scan through the given string
    int i;
    for(i=0;str[i]!='\0'; i++){
        
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            // The character is an opening bracket, push it to stack
            STACK_push(&opening_brackets, str[i]);
            
        }else if(str[i]==')' || str[i]=='}' || str[i]==']'){
            // The character is a closing bracket, pop a bracket from the stack
            
            // pop from stack iff stack not empty
            if(!STACK_isEmpty(opening_brackets)){
                
                // get popped bracked from stack
                popped = STACK_pop(&opening_brackets);
                
                if(!bracket_matched(str[i], popped)){
                    // the opening bracket doesn't match the closing bracket found
                    return 0;
                }
                
            }else{
                // Stack has no opening brackets, so mismatch found
                return 0;
            }
        }
    }
    
    // At this point the string completely scanned, if the stack is not empty, parenthesis not match
    if(STACK_isEmpty(opening_brackets)){
        return 1;
    }
    // Stack not empty, there is an opening bracket not matched in the given string
    return 0;
}
/*
    In Mathematics infix expressions are easily to evaluate - using BODMAS for precedance.
 
    In Programming, if you follow BODMAS, you will have to scan the expression each time and find the highest precedence
    operator and evaluate it - this time consuming. Therefore, you convert the infix expression to postfix expression.
    In postfix form, the expression is evaluated in a single scan.
 
    infix = left_operand operator right_operand
    postfix = left_operand right_operand operator
    prefix  = operator left_operand right_operand
 
    Examples:   infix = a+b*c, before converting to its post or prefix, parenthesize it based on precedence (if you don't,
                compiler will do based on table below). Therefore, infix = (a+(b*c))
                    
                    Postfix = 1) first inner bracket:  (a+[bc*]) -> square brackets used to indicate which is converted first
                              2) now outter operator: [abc*+] -> this postfix result
 
                    Infix = 1) first inner bracket:  (a+[*bc])
                            2) now outter operator:  [+a*bc] -> prefix results
 
 
    In a computer, the operator precedence is the following order of increasing precedence:
    
        operator            | precedence  |  Associativity
        - +                 |      1      |     Left-to-Right
        * /                 |      2      |     Left-to-Right
        Unary operators     |      3      |     Right-to-Left
        ()                  |      5      |     Left-to-Right
        Operands            |      6      |     Left-to-Right
 
    Notes:  All Unary operators have higher precedence than binary operators.
            If expression has same operators of same precedence only then you go for the associativity property to group
                determine which one is evaluated first.
 
    The idea for converting an infix expression to postfix:
        
        Use a stack to push and pop operators found when scanning the infix expression.
        You push an operator to stack iff the current top element's precedence is lower, else you pop the top of the
            stack and add it to postfix expression until stack top element is  lower in precedence to
            operator of the infix expression - this is when you push the current operator of the infix expression
            to the stack. Therefore, you only move to the next char of infix after you've pushed
            the current operator of the infix to the stack.
        Operands of the infix expression are always added to the postfix expression and only operators are
        pushed and popped from stack.
 
    You create a function to return precedence (i.e. creating the table above) - use this to determine if you push to
    stack or pop from stack.
        
 */

// Assuming the infix expression will have lower case operands and only the following operators
// Compiler giving erros with '\' for division, so using '/' instead
int isOperand(char ch){
    if( ch=='+' || ch=='-' || ch=='/' || ch=='*' )
    {
       return 0;
    }
    return 1;
}

// Returns precedence of the operator - based on table above
// Compiler giving erros with '\' for division, so using '/' instead
int precedance(char ch){
    if(ch=='+' || ch=='-'){
        return 1;
    }else if (ch=='*' || ch=='/' )
    {
        return 2;
    }
    // unknown precedence
    return -1;
}
char* infix_to_postfix(char *infix, int size){
    
    // Declare a stack
    // Using a linkedlist stack, don't need to declare size
    stack operator_stack;
    STACK_Init(&operator_stack);
    
    // Create a char string to store postfix result - +1 for null char
    char *postfix = (char *)malloc(size*sizeof(char)+1);
        
    // variables to scan the infix and postfix expressions
    int i=0, j=0;
    
    while(infix[i]!='\0'){
        
        
       
        if(isOperand(infix[i])){
            // Current infix character is an operand - add it to postfix expression
            postfix[j] = infix[i];
            j++;
            i++;
        }else{
            
            // Current infix character is an operator
            
            // Push operator to the stack if it has higher precedance than current top operator of stack,
            // else pop top and add to postfix expression until stack is either empty or until top of stack
            // has lower precedence operator than current infix operator
            
            // Top of stack
            //printf("Top operator in stack %c.\n", STACK_top(operator_stack));
            if( precedance(infix[i]) > precedance(STACK_top(operator_stack)) ){
                
                // operator has higher precedance
                // push to the top of stack
                STACK_push(&operator_stack, infix[i]);
                i++;
            }else{
                // operator has same or lower precedence, pop stack until top of stack precedence is lower or
                // stack is empty - add the popped data to postfix, don't move to next char in infix
                postfix[j] = STACK_pop(&operator_stack);
                j++;
            }
        }
    }
    
    // Add this point, the entire infix expression has been scanned. Pop whatever is in stack and add it to postfix expre
    while(!STACK_isEmpty(operator_stack)){
        postfix[j] = STACK_pop(&operator_stack);
        j++;
    }
    
    // Add Null character as last element of postfix
    postfix[j] = '\0';
    
    // return postfix expression
    return postfix;
}
// =========== Stack Applications  ===========
