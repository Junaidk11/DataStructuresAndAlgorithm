//
//  main.c
//  Array
//
//  Created by jjkhan on 7/6/21.
//

#include <stdio.h>
#include <stdlib.h> // For malloc function
// creating a struct for an array

struct dynamicArray{
  
    int *A;
    int size;
    int length;
};

struct staticArray{
    int A[20];
    int size;
    int length;
};

// Member functions
void staticArray_Display(struct staticArray arr);
void dynamicArray_Display(struct dynamicArray arr);
void dynamicArray_append(struct dynamicArray arr, int value);
void staticArray_append(struct staticArray arr, int value);
void staticArray_insertAtIndex(struct staticArray arr, int index, int value);
void dynamicArray_insertAtIndex(struct dynamicArray arr, int index, int value);

// Programs
void append_to_array(void);
void insert_at_index(void);


int main(int argc, const char * argv[]) {
    // insert code here...
    
    insert_at_index();
    return 0;
}

void insert_at_index(void){
    
    // Create a staticArray
    struct staticArray A = {{1,4,5,6}, 20, 4};
    staticArray_insertAtIndex(A,0,9);
}

void dynamicArray_Display(struct dynamicArray arr){
    int i;
    printf("\nElements are \n");
    for(i=0;i<arr.length;i++){
        printf("%d ",arr.A[i]);
    }
    printf("\n");
}

void dynamicallyAllocatedArray(void){
    struct dynamicArray arr;
    printf("Enter size of an Array \n");
    scanf("%d", &arr.size); // Get size of array from keyboard
    arr.A = (int *) malloc(arr.size*sizeof(int)); // Allocate memory for array in heap
    arr.length =0;
    
    int n,i;
    printf("Enter number of numbers. \n");
    scanf("%d", &n);
    
    // To read values from keyboard
    
    printf("Enter all elements.\n");
    for(i=0;i<n;i++){
        scanf("%d", &arr.A[i]);
    }
    arr.length =n;
    dynamicArray_Display(arr);
}

void staticArray_Display(struct staticArray arr){
    int i;
    printf("\nElements are \n");
    for(i=0;i<arr.length;i++){
        printf("%d ",arr.A[i]);
    }
    printf("\n");
}

void staticallyAllocatedArray(void){
    struct staticArray A = { {1,2,3,5}, 10, 5}; // Declaration and initialization
    staticArray_Display(A);
}

// Append value to the end of an Array
void dynamicArray_append(struct dynamicArray arr, int value){
    
    // Check if array full
    if(arr.length == arr.size){
        printf("Array is full.\n");
        return;
    }else{
        // Append new value to the end of array
        arr.A[arr.length]=value;
        // Increment length
        arr.length++;
    }
}

// Append value to the end of an Array
void staticArray_append(struct staticArray arr, int value){
    
    // Check if array full
    if(arr.length == arr.size){
        printf("Array is full.\n");
        return;
    }else{
        // Append new value to the end of array
        arr.A[arr.length]=value;
        // Increment length
        arr.length++;
    }
    staticArray_Display(arr);
}


void append_to_array(void){
    
    // Create an array struct
    
    struct staticArray A ={{1,2,4,5}, 20, 4}; // declared and initialized an array struct
    // Display current array elements
    staticArray_Display(A);
    staticArray_append(A, 64);
    
}

void staticArray_insertAtIndex(struct staticArray arr, int index, int value){
    
    staticArray_Display(arr); // Display before insertion
    // First check if index in within bounds of the array
   
    if(index>arr.size || index<0){
        printf("Index out of array bounds.\n");
        return;
    }else{
        // Starting at length, shift all the elements on left to the right,
        // decrement the iterator, until iterator = index, then insert new element there
        
        int i;
        for(i=arr.length; i>index; i--){
            arr.A[i]=arr.A[i-1]; // Element on left of 'i' is moved to current 'i'
        }
        // i == index
        arr.A[i] = value;
        // increase length by 1
        arr.length++;
    }
    
    staticArray_Display(arr); // Display after insertion
}
