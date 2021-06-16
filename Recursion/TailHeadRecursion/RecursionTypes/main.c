//
//  main.c
//  TailHeadRecursion
//
//  Created by jjkhan on 6/15/21.
//

#include <stdio.h>

#define TESTALL 0
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

void treeRecursion(int n){
    
    if(n>0){
        printf("%d ", n);
        treeRecursion(n-1);
        treeRecursion(n-1);
    }
}


void funcA(int);  // To avoid "Implicit Definition" errors when calling funcA in funcB
void funcB(int n){
    
    if(n>1){
        printf("%d ", n);
        funcA(n/2);
    }
}
void funcA( int n){
    if( n >0){
        
        printf("%d ", n);
        funcB(n-1);
    }
    
}
void indirectRecursion(int n){

    funcA(n);

}

int func3(int n){
    if (n>100){
        return n-10;
    }else{
        return func3(func3(n+11));
    }
}
void nestedRecursion(int n){
    
    printf("%d ",func3(n));
    
}
int main(int argc, const char * argv[]) {
    
#if  TESTALL==1
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
    
    treeRecursion(3); // 3 2 1 1 2 1 1
    indirectRecursion(20); // 20 19 9 8 4 3 1
    
#endif
    
    nestedRecursion(95);
   
    
    return 0;
}
