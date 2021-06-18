//
//  recursionPractice.c
//  Recursion
//
//  Created by jjkhan on 6/18/21.
//

#include <stdio.h>

#define SUM_OF_NATURAL_NUMBERS 0


#if SUM_OF_NATURAL_NUMBERS == 1
/*
    Sum of n-natural Numbers using:
            Recursion
            Loop
            Simple formula:  -> n(n+1)/2
    
    
    Notes:
            Natural Numbers start at 1.
            Each method gives the same answer, but their time and space complexity is different.
 
        For Recurison:
                Sum of n natural numbers means, the recursive call is made (n+1) times,
                so (n+1) activation records are created in stack -> Hence, O(n+1) = O(n) space complexity
                Time complexity is O(n) because for sum of n natural numbers, n+1 recursive calls are made to the function. The statements in the function body are executed n+1 times, therefore O(n+1) time complexity, which becomes O(n).
 
        Using a Loop:
                The time complexity of this setup is O(n+1)=O(n) because the loop statements are exectued n+1 times.
                The space complexity is constant because you create a finite number of variables to help you sum the natural numbers - i.e. one iterator, 'n' and a 'sum' variable.
 
        Using Simple Formula:
                Time complexity is o(1) because using the formula you're only executing 3 operations to get the sum.
                Space complexity is also o(2)=contant = o(1), because you only create a copy for the parameter 'n' and for the return value.
    
        Recursion is costly in both space and time. A simple formula is preferred over a loop and a loop is preferred over a recursive function, when you compare the time and space complexities among the 3.
    
 */
int recursion_sum_of_natural_num(int n){
    
    if(n==0){
        return 0;
    }else{
        return recursion_sum_of_natural_num(n-1) + n;
    }
}


int formula_sum_natural_num(int n){
    return (n*(n+1))/2;
}

int loop_sum_of_natural_num(int n){
    
    int i, sum=0;
    for(i=1; i<=n; i++){
        sum +=i;    
    }
    return sum;
}

#endif

int main(void){
    
#if SUM_OF_NATURAL_NUMBERS == 1
    // All print same result, but the time and space complexity is different for each.
    printf("Sum Of n natural numbers: %d \n", recursion_sum_of_natural_num(5));
    printf("Sum Of n natural numbers: %d \n", formula_sum_natural_num(5));
    printf("Sum Of n natural numbers: %d \n", loop_sum_of_natural_num(5));
#endif
    
    return 0;
}
