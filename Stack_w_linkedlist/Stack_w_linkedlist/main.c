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
#include "integer_stack.h"
#include "char_stack.h"


// Program functions
void STACK_ADT_test(void);
void TEST_parenthesis_matching(void);
void TEST_infix_to_postfix_ONLY_L2R_ASSOCIATIVITY(void);
void TEST_infix_to_postfix_BOTH_L2R_R2L_ASSOCIATIVITY(void);
void TEST_evaluate_expression(void);


// Stack Applications
int parenthesis_matching(char* str);
char* infix_to_postfix(char *infix, int size);  // No brackets, only Left-to-right associativity operators
char* infix_to_postfix_2(char *infix, int size); // Brackets and both left-to-right, and right-to left associativity operators
int evaluate_expression(char *infix, int size);

int main(int argc, const char * argv[]) {
    
    TEST_evaluate_expression();
    return 0;
}

// Test passed for both
void TEST_evaluate_expression(void){
    
    // Test Inputs
    char *input1 = "5+2";
    char *input2 = "3*5+6/2-4";
    
    // Function results
    
    // Function tests
    printf("Evaluation of expression %s is: %d \n", input1, evaluate_expression(input1,3));
    printf("Evaluation of expression %s is: %d \n", input2, evaluate_expression(input2,9));


}

// All tests passed
void TEST_infix_to_postfix_BOTH_L2R_R2L_ASSOCIATIVITY(void){
    
    // Test inputs with only L-to-R associativity operators
    char *input1 = "a+b"; // Postfix = ab+ = result -> passed
    char *input2 ="a+b*c-d/e"; // Postfix = a+[bc*]-d/e -> a+[bc*]-[de/] -> [abc*+]-[de/] -> [abc*+de/-] = result -> Passed
    char *input3 ="a+b+c*d"; // postix = a+b+[cd*] -> [ba+]+[cd*] -> [ab+cd*+] -> Passed
    char *input4 ="a+b*c"; // postfix = abc*+ -> passed
    char *input5 ="a+b!"; // Postfix = a+[b!] -> [ab!+] -> passed
    
    // Test input with brackets, L-to-R and R-to-L associativity operators
    char *input6 = "((a+b)*c)-d^e^f"; // Postix = ([ab+]*c)-d^e^f -> [ab+c*]-d^e^f -> [ab+c*]-d^[ef^] -> [ab+c*]-[def^^] -> [ab+c*def^^-] = Result -> Passed
    
    
    // Function tests
    printf("Postfix of infix %s is: %s \n", input1, infix_to_postfix_2(input1, 3));
    printf("Postfix of infix %s is: %s \n", input2, infix_to_postfix_2(input2, 9));
    printf("Postfix of infix %s is: %s \n", input3, infix_to_postfix_2(input3, 7));
    printf("Postfix of infix %s is: %s \n", input4, infix_to_postfix_2(input4, 5));
    printf("Postfix of infix %s is: %s \n", input5, infix_to_postfix_2(input5, 4));
    printf("Postfix of infix %s is: %s \n", input6, infix_to_postfix_2(input6, 15));
    
}


// All tests passed
void TEST_infix_to_postfix_ONLY_L2R_ASSOCIATIVITY(void){
    
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
int isOperand(char ch){
    if( ch=='+' || ch=='-' || ch=='/' || ch=='*' )
    {
       return 0;
    }
    return 1;
}

// Returns precedence of the operator - based on table above
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

/*
    This function is similar to the previous infix to postfix, the only difference is that:
        Previous function only works for operators that have right-to-left associativity and it doesn't work with brackets
    
    This function works for all operators, including brackets and left-to-right and right-to-left associativity.
    
    The idea is similar to the previous function: Using a stack and a precedence table to pop/push operators to/from stack and send
    operands directly to the postfix expression. The precedence table for this function is setup such that operators with Left-to-right
    associativity have a lower precedence outside the stack (i.e. in infix expression) and greater precedence when they're inside the
    stack. Similarly, operators withh right-to-left associativity have a higher precedence outside the stack and greater precedence
    when inside the stack.
 
    The limited operators and their "out and in" stack precedence are shown below: (you can add more as needed based on the associativtity
    of the desired operator)
 
    In a computer, the operator precedence is the following order of increasing precedence:
 
     operator            | Outside Stack precedence | Inside Stack precedence    |  Associativity
     - +                 |      1                   |        2                   |     Left-to-Right
     * /                 |      3                   |        4                   |     Left-to-Right
     ^                   |      6                   |        5                   |     Right-to-Left
     (                   |      7                   |        0                   |     Left-to-Right
     )                   |      0                   |        ?                   |     Left-to-Right
     
 
    Notes:  The operators with l-to-r associativity have increasing precedence from outside to inside stack
            The operators with r-to-l associativity have decreasing precendce from inside to outside stack
            Closing brackets are never pushed to the stack. In and out precedence are only equal when you have opening bracket at top of stack and found a closing in infix,
                you pop the bracket and move on to next character in the infix, i.e. don't add brackets to the postfix expression.
            You can add more operators to the table above by determining if its associativity and assigning precedence correctly.
 
    The general code idea:
                Scan through the given infix expression, if the current character is an operand, add it to postfix string, else if the outside precedence of
                    the current operator (i.e. from infix) is higher than the in-stack precedence of the top element of the stack - you push the current operator
                    to the stack and move to the next character.
                When you come across an operator in the infix expression who's outside stack precedence is lower than
                    the precedence of the top element of stack, you pop the top element of the stack and add it to the postfix expression - you repeat this until the top
                    of stack has lower in-stack precendence operator than the current operator of infix expression. At this point, you push the current operator to the stack at this point and move to the next character of the infix expression.
                When you come across an operator in the infix expression who'se outside stack precedence is equal to the top of the stack operator precedence (which is only
                    possible if you come across a closing bracket and the stack has an opening bracket at the top of the element) -> in this case you pop top of the stack only (i.e.
                    don't add this operator to the postfix expression, and you only move to the next character of the infix expression, leaving the postfix string where it is.
 
        Scan the infix -> push operators with higher outside stack precedence than in-stack top element precedence -> pop and add to postfix expression if outside precedence
        lower than top of stack operator's inside precedence -> add operands to the postfix expression directly -> for brackets the outside and inside precedence will be equal,
        in this case only pop the opening bracket from the stack, don't have to add it to the postfix expression.
 
            
 
 */

int isOperand_2(char ch){
    if( ch=='+' || ch=='-' || ch=='/' || ch=='*' || ch=='^' || ch=='(' || ch==')')
    {
       return 0;
    }
    return 1;
}
/*
    Inside stack precedence of operators -> add more operators as needed - make sure to assign precendence based on associativity - read notes above
    
 */
int in_stack_precedence(char ch){
    
    if(ch == '+' || ch=='-'){
        return 2;
    }else if(ch == '*' || ch=='/'){
        return 4;
    }else if(ch == '^'){
        return 5;
    }else if(ch == '('){
        return 0;
    }
    
    // Precedence not defined
    return -1;
}

/*
    Outside stack precedence of operators -> add more operators as needed - make sure to assign precendence based on associativity - read notes above
 */
int out_stack_precedence(char ch){
    
    if(ch == '+' || ch=='-'){
        return 1;
    }else if(ch == '*' || ch=='/'){
        return 3;
    }else if(ch == '^'){
        return 6;
    }else if(ch == '('){
        return 7;
    }else if(ch == ')'){
        return 0;
    }
    
    // Precedence not defined
    return -1;
}
char* infix_to_postfix_2(char *infix, int size){
    
    
    // Declare and initiliaze a stack
    stack operator_stack;
    STACK_Init(&operator_stack);
    
    // Allocate memory for postfix expression
    char *postfix = (char *)malloc(size*sizeof(char)+1);
    
    // Variables to scan infix and postfix
    int i=0, j=0;
    
    // Scan till the end of the infix expression
    while(infix[i]!='\0'){
        
        // Check if current infix expression char is operand or operator
        if(isOperand_2(infix[i])){
            
            // Is an operand
            
            // Add operands to the stack
            postfix[j]=infix[i];
            
            // Move to next spot of both expressions
            i++;
            j++;
            
        }else{
            
            // Is an operator
            
            // Check for outside-stack precedence with in-stack precedence
            if(out_stack_precedence(infix[i]) > in_stack_precedence(STACK_top(operator_stack))){
                
                // Outside stack operator precedence higher
                //  Push the operator to the stack
                STACK_push(&operator_stack, infix[i]);
                
                // Move to next char of infix
                i++;
            }else if(out_stack_precedence(infix[i]) < in_stack_precedence(STACK_top(operator_stack))){
                
                // Outside stack operator precedence is lower
                // Pop from stack and add to postfix expression
                
                postfix[j]=STACK_pop(&operator_stack);
        
                // Move to next spot on postfix expression ONLY
                j++;
            }else{
                
                // Outside stack operator and top of stack operator precendences are equal -> i.e. closing bracket found in infix, and opening bracket at top of stack
                
                // Pop the stack ONLY, don't add to the postfix expression
                STACK_pop(&operator_stack);
        
                // Move to next spot on infix expression ONLY
                i++;
            }
        }
    } // End of infix expression scan
    
    // If stack not empty, pop all the elements and add it to the postfix
    while(!STACK_isEmpty(operator_stack)){
        
        postfix[j] = STACK_pop(&operator_stack);
        j++;
    }
    
    // Add null character to string and return postfix string
    postfix[j]='\0';
    
    return postfix;
    
}

/*
    In computers, infix expressions are first converted to postfix expression and then evaluated - this way the expression is evaluated in a single scan.
    
    Assuming we have the postfix expresion, you evaluate this as follows:
            As you scan the postfix expression, Operands are pushed into stack and whenever you get an operator, you pop two operands and perform operation, followed
                by pushing the result on to the stack again.
        
    Note:
            The first operand popped from the stack is the right operand and the second operand is the left operand.
 */
int convert_to_integer(char ch){
    
    if(ch=='1'){
        return 1;
    }else if(ch=='2'){
        return 2;
    }else if(ch=='3'){
        return 3;
    }else if(ch=='4'){
        return 4;
    }else if(ch=='5'){
        return 5;
    }else if(ch=='6'){
        return 7;
    }else if(ch=='8'){
        return 8;
    }else if(ch=='9'){
        return 9;
    }
    
    // Number not defined
    return -1;
}
int evaluate(int left_operand,int right_operand, char operator){
    
    if(operator=='+'){
        return (left_operand+right_operand);
    }else if(operator=='-'){
        return (left_operand-right_operand);
    }else if(operator=='*'){
        return (left_operand*right_operand);
    }else if(operator=='/'){
         return (left_operand/right_operand);
    }
    
    // For Operator not defined
    return 0;
    
}
int evaluate_expression(char *infix, int size){
    
    
    // Declare and initialize stack
    int_stack operand_stack;
    INT_STACK_Init(&operand_stack);
    
    // Postfix expression
    char *postfix = NULL;
    
    // Place holders for operands and result
    int right_operand, left_operand;
    int operation_result;
    
    // convert infix expression to postfix
    postfix = infix_to_postfix_2(infix, size);
    
    // variable to scan through postfix
    int i =0;
    
    // Scan postfix until you reach end
    while(postfix[i]!='\0'){
        
        // check if current char is operand
        
        if(isOperand(postfix[i])){
            
            // is operand
            // Push the operand to the stack
            INT_STACK_push(&operand_stack, convert_to_integer(postfix[i]));
            
            // Move to next char in the postfix expression
            i++;
        }else{
            
            // is operator, pop two operands from the stack
            // Get right and left operands from stack
            right_operand = INT_STACK_pop(&operand_stack);
            left_operand =  INT_STACK_pop(&operand_stack);
            
            // Evaluate the operation
            operation_result = evaluate(left_operand,right_operand, postfix[i]);
            
            // Push result of the operation to the stack
            INT_STACK_push(&operand_stack, operation_result);
            
            // Move to next char in postfix expression
            i++;
        }
    } // End of postfix expression scan
    
    // Expression result is in the stack
    return INT_STACK_pop(&operand_stack);
    
}
// =========== Stack Applications  ===========
