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

int main(int argc, const char * argv[]) {
    
    int a = 5;
    // Tail Recursion result:
    //      Print current value of n
    //      Call function again with n-1
    //      repeat until base case reached, then back track -> n=0
    //tailRecursion(a); // Pass by value, tail recursion -> 5 4 3 2 1
    headRecursion(a);   // Pass by value, 1 2 3 4 5
    
    
    return 0;
}
