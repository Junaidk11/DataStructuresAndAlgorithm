//
//  recursionPractice.c
//  Recursion
//
//  Created by jjkhan on 6/18/21.
//

#include <stdio.h>

#define SUM_OF_NATURAL_NUMBERS      0
#define PROD_OF_NATURAL_NUMBERS     0
#define POWER_FUNCTION              1

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


#if PROD_OF_NATURAL_NUMBERS == 1

/*
        The time and space complexity is same as recursive implementation of sum of N natural numbers, for an input of 'n', the function is called n+1 times, so n+1 activation records are created in the stack, so space complexity of O(n+1) = O(n). Similarly, for an input of n, the function is called n+1 times to give you the result, therefore the time complexity is also O(n+1) = O(n).
        You can implement this recursive call using a loop and reduce the space complexity, but the time complexity will still be O(n+1).
        
 */
int factorial(int n){
    
    if(n==0){
        // Base case
        return 1;
    }else{
        // Recursive case to break down the input to base case
        return factorial(n-1)*n;
    }
}

#endif

#if POWER_FUNCTION == 1
#include <math.h>
// Time complexity -> o(n+1)  == o(n) because n+1 function calls to give you the result
// Space Complexity -> o(n+1) == o(n) because n+1 activation records created in stack to give a solution
int recursive_Pow(int m, int n){
    if(n==0){
        // base case pow(m, 0) = 1
        return 1;
    }else{
        return recursive_Pow(m, n-1)*m;
    }
}

// Time complexity is o(n) because the loop is repeated n times
// Space complexity is constant because only 4 variables used in the function + 1 return variable.
int iterative_pow(int m, int n){
    
    int i, sum = 1;
    if(n==0){
        return 1;
    }
    
    for(i=0;i<n;i++){
        sum*=m;  // Adding m to the sum, n-1 times, because n=0 already added
    }
    return sum;
}

// Time complexity is dependent on how pow(double, double) is implemented in the math library
// Space complexity on formula_pow is constant because you're using 2 variables input + 1 return value from pow(double, double);
int formula_pow(int m, int n){
    
    return pow(m,n); // From math.h library
}

// Time and Space complexity is halved, because you reduced the number of recursive calls.
// You will have to trace the function for exact number of function calls made.
//  General Idea is that if n==even, you don't need multiplication at return time
//   which reduces the number of multiplication operations done, incomparison to the previous
//    recursive power function.
int fast_recursive_Pow(int m, int n){
    // Base case
    if (n==0){
        return 1; // Because (m)^0 = 1
    }else{
        // If n == even, you only need to (m)^n = (m^2)^(n/2)
        if(n%2==0){
            return fast_recursive_Pow(m*m, n/2);
        }else{
            // n == odd, you need to do: (m)^n =(m^1)*(m^2)^((n-1)/2)
            return fast_recursive_Pow(m*m, (n-1)/2)*m;
        }
    }
}

// Time complexity -> O(logn) -> Instead of n iterations of loop, the loop is executed n/2 times
// Space complexity -> constant, 4 variables used in the function body
int iterative_logn_power(int m, int n){
    
    int i, sum=1;
    if(n%2!=0){
        // Power is odd
        // m^n = m * (m^2)^(n-1)/2
        sum *= m; // sum = m
        n = (n-1)/2;
    }else{
        // Power is even
        // m^n = (m^2)*(n/2)
        // So reduce power by half
        n = n/2;
    }
    
    // Now loop
    for(i=0; i<n; i++){
        sum*=(m*m); // (m*m) is added to the sum n/2 times.
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
    
#if PROD_OF_NATURAL_NUMBERS == 1
    printf("Sum of Product of n natural numbers: %d \n", factorial(5));
#endif
    
#if POWER_FUNCTION == 1
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);
    printf("%d to the power of %d = %d \n", m, n, recursive_Pow(m,n));
    printf("%d to the power of %d = %d \n", m, n, fast_recursive_Pow(m,n));
    printf("%d to the power of %d = %d \n", m, n, iterative_pow(m,n));
    printf("%d to the power of %d = %d \n", m, n, formula_pow(m,n));
    printf("%d to the power of %d = %d \n", m, n, iterative_logn_power(m, n));
    
#endif
    
    return 0;
}
