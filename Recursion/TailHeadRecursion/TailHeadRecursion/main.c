//
//  main.c
//  TailHeadRecursion
//
//  Created by jjkhan on 6/15/21.
//

#include <stdio.h>

void tailRecursion(int n){
    
    if(n>0){
        
        printf("%d ", n);
        // Calling function recursively after printing
        tailRecursion(n-1);
    }
}

void headRecursion(int n){
    if(n>0){
        
        // Calling function recursively before printing
        headRecursion(n-1);
        printf("%d ", n);
    }
    
}

int nonStaticRecursion(int n){
    
    if(n>0){
        return nonStaticRecursion(n-1)+n; // '+n' only executed when func(n-1) returns
    }
    return 0; // Base case
}

int staticRecursion(int n){
    // This variable is created in the code section of the memory.
    // A single copy shared by all the function calls -> i.e. 'x' is not created in Stack
    // for each activation record of 'staticRecursion(n)'
    static int x =0; // A single copy created at compile time, only accessible by staticRecursion function
    if(n>0){
        x++;
        return staticRecursion(n-1)+x;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    
    int a = 5;
    // Tail Recursion result:
    //      Print current value of n
    //      Call function again with n-1
    //      repeat until base case reached, then back track -> n=0
    tailRecursion(a); // Pass by value, tail recursion -> 5 4 3 2 1
    headRecursion(a);   // Pass by value, 1 2 3 4 5
    
    printf("Non-static Variable Recursive Function: ");
    // Result: Forward  "[func(4) + 5] -> [func(3) + 4] -> [func(2) + 3] -> [func(1) + 2] -> [func(0) + 1] -> [func(0) = 0]"
    //         Backward "[func(0) = 0] -> [0 + 1 = 1 ] -> [1 + 2 = 3] -> [3 + 3 = 6] -> [6 + 4 =10 ] -> [10 + 5 = 15]"  -> 15 is result
    printf("%d \n", nonStaticRecursion(a));
    
    printf("Static Variable Recursive Function: ");
    printf("%d \n", staticRecursion(a)); // Result is 25
    
    return 0;
}
