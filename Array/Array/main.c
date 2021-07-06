//
//  main.c
//  Array
//
//  Created by jjkhan on 7/6/21.
//

#include <stdio.h>
#include <stdlib.h> // For malloc function
#include <math.h> // For floor operations in BinarySearch

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
struct dynamicArray createDynamicStruct(void);
void staticArray_Display(struct staticArray arr);
void dynamicArray_Display(struct dynamicArray arr);
void dynamicArray_append(struct dynamicArray *arr, int value);
void staticArray_append(struct staticArray *arr, int value);
void staticArray_insertAtIndex(struct staticArray *arr, int index, int value);
void dynamicArray_insertAtIndex(struct dynamicArray *arr, int index, int value);
int staticArray_deleteAtIndex(struct staticArray *arr, int index);
int dynamicArray_deleteAtIndex(struct dynamicArray *arr, int index);
int staticArray_linearSearch(struct staticArray *arr, int value);
int dynamicArray_linearSearch(struct dynamicArray *arr, int value);
int staticArray_binarySearch_iterative(struct staticArray arr, int low, int high, int key);
int staticArray_binarySearch_tailRecursion(struct staticArray arr, int low, int high, int key);
int dynamicArray_binarySearch_iterative(struct dynamicArray arr, int low, int high, int key);
int dynamicArray_binarySearch_tailRecursion(struct dynamicArray arr, int low, int high, int key);


// Programs
void append_to_array(void);
void insert_at_index(void);
void delete_at_index(void);
void linear_Search(void);
void binary_Search(void);
int main(int argc, const char * argv[]) {
    // insert code here...
    binary_Search();
    return 0;
}

void binary_Search(void){
    
    // Create a static sorted array
    /*
    struct staticArray A ={ {2,4,5,7,9,12,16}, 20, 7};
    printf("Index of key in array: %d\n", staticArray_binarySearch_iterative(A, 0, 6, 7));
    printf("Index of key in array: %d\n", staticArray_binarySearch_iterative(A, 0, 6, 3));
    printf("Index of key in array: %d\n", staticArray_binarySearch_tailRecursion(A, 6, 4, 7));
    printf("Index of key in array: %d\n", staticArray_binarySearch_tailRecursion(A, 0, 6, 11));
    */
    
    // Create a dynamic sorted array
    struct dynamicArray B = createDynamicStruct();
    printf("Index of key in array: %d\n", dynamicArray_binarySearch_iterative(B, 0, 6, 7));
    printf("Index of key in array: %d\n", dynamicArray_binarySearch_tailRecursion(B, 6, 2, 7));
    
}
void linear_Search(void){
    
    // Create a static Array struct
    
    struct staticArray A = {{1,2,3,4},20, 4};
    staticArray_Display(A);
    printf("Index of value found: %d\n",staticArray_linearSearch(&A, 3));
    staticArray_Display(A);
    printf("Index of value found: %d\n",staticArray_linearSearch(&A, 3)); // Index will be different because we moved the value to left by 1 index
    staticArray_Display(A);
    printf("Index of value found: %d\n",staticArray_linearSearch(&A, 3)); // Index will be different because we moved the value to left by 1 index
    staticArray_Display(A);
    
    
    // Create a dynamic array struct
    struct dynamicArray B = createDynamicStruct();
    dynamicArray_Display(B);
    printf("Index of value found: %d\n", dynamicArray_linearSearch(&B, 3));
    dynamicArray_Display(B);
    
}
void delete_at_index(void){
    
    // Create a static Array struct
    
    struct staticArray A = {{1,2,3,4},20, 4};
    staticArray_Display(A);
    printf("Deleted value is: %d\n",staticArray_deleteAtIndex(&A, -1));
    staticArray_Display(A);
    
    
    // Create a dynamic array struct
    struct dynamicArray B = createDynamicStruct();
    dynamicArray_Display(B);
    printf("Deleted value is: %d\n", dynamicArray_deleteAtIndex(&B, 0));
    dynamicArray_Display(B);
    
}

struct dynamicArray createDynamicStruct(void){
    struct dynamicArray B;
    printf("Size of the array?\n");
    scanf("\n %d \n", &B.size);
    B.A = (int *)malloc(B.size*sizeof(int)); // Allocate memory for Array
    printf("\n");
    printf("How many elements in the array?\n");
    scanf("%d\n",&B.length);
    printf("Enter values of the elements.\n");
    int i;
    for(i=0; i<B.length; i++){
        scanf("%d", &B.A[i]);
    }
    return B;
}
void insert_at_index(void){
    
    // Create a staticArray
    /*struct staticArray A = {{1,4,5,6}, 20, 4};
    staticArray_Display(A);
    staticArray_insertAtIndex(&A,0,9);
    staticArray_Display(A);
    */
    // Create a dynamic struct
    struct dynamicArray B = createDynamicStruct();
    dynamicArray_Display(B);
    dynamicArray_insertAtIndex(&B,0, 12);
    dynamicArray_Display(B);
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
void dynamicArray_append(struct dynamicArray *arr, int value){
    
    // Check if array full
    if(arr->length == arr->size){
        printf("Array is full.\n");
        return;
    }else{
        // Append new value to the end of array
        arr->A[arr->length]=value;
        // Increment length
        arr->length++;
    }
}

// Append value to the end of an Array
void staticArray_append(struct staticArray *arr, int value){
    
    // Check if array full
    if(arr->length == arr->size){
        printf("Array is full.\n");
        return;
    }else{
        // Append new value to the end of array
        arr->A[arr->length]=value;
        // Increment length
        arr->length++;
    }
    
}


void append_to_array(void){
    
    // Create an array struct
    
    struct staticArray A ={{1,2,4,5}, 20, 4}; // declared and initialized an array struct
    // Display current array elements
    staticArray_Display(A);
    staticArray_append(&A, 64);
    staticArray_Display(A);
}

//  This function has min and max time complexity
// If the new value is added to the end of the array -> no shifting required, O(1)
// If the new value is added to the front of the array -> shifting "length" elements -> loop executed O(length), or O(n) where n is size of array.
// Typical only care about worse case time of a function -> so, O(n)
void staticArray_insertAtIndex(struct staticArray *arr, int index, int value){

    // First check if index in within bounds of the array
    if(index>arr->size || index<0){
        printf("Index out of array bounds.\n");
        return;
    }else{
        // Starting at length, shift all the elements on left to the right,
        // decrement the iterator, until iterator = index, then insert new element there
        
        int i;
        for(i=arr->length; i>index; i--){
            arr->A[i]=arr->A[i-1]; // Element on left of 'i' is moved to current 'i'
        }
        // i == index
        arr->A[i] = value;
        // increase length by 1
        arr->length++;
    }
}


void dynamicArray_insertAtIndex(struct dynamicArray *arr, int index, int value){

    // First check if index in within bounds of the array
    if(index>arr->size || index<0){
        printf("Index out of array bounds.\n");
        return;
    }else{
        // Starting at length, shift all the elements on left to the right,
        // decrement the iterator, until iterator = index, then insert new element there
        
        int i;
        for(i=arr->length; i>index; i--){
            arr->A[i]=arr->A[i-1]; // Element on left of 'i' is moved to current 'i'
        }
        // i == index
        arr->A[i] = value;
        // increase length by 1
        arr->length++;
    }
}

/*
    The delete function has a min and max time complexity.
        If the delete element is at the end of array, then no shifting required -> O(1)
        If the delet element is at the start, then shifting by "length" elements, so O(n) complexity.
*/
int staticArray_deleteAtIndex(struct staticArray *arr, int index){
    
    // First check if index is within length of the array
    if(index<0 || index>arr->length){
        printf("Index is out of bound.\n");
        return 0;
    }else
    {
        // Start at delete index and shift elements from right to left until you reach lenght-1
        int x = arr->A[index], i;
        
        for(i=index; i<arr->length-1; i++){
            arr->A[i] = arr->A[i+1];
        }
        // Update length of Array
        arr->length--;
        return x;
    }
}

int dynamicArray_deleteAtIndex(struct dynamicArray *arr, int index){
    // First check if index is within length of the array
    if(index<0 || index>arr->length){
        printf("Index is out of bound.\n");
        return 0;
    }else
    {
        // Start at delete index and shift elements from right to left until you reach lenght-1
        int x = arr->A[index],i;
        for(i=index; i<arr->length-1; i++){
            arr->A[i] = arr->A[i+1];
        }
        // Update length of Array
        arr->length--;
        return x;
    }
}
// Used in Improved linear search to swap a successfull search index with value at index-1 to speed up next search of the same value
void swap( int *x, int *y){
    *(x)^=*(y);
    *(y)^=*(x);
    *(x)^=*(y);
}
/*
        Linear Search requires no duplication.
        An improvment to typical linear search is: if you're repeatedly searching
        for the same element, you can swap that element with the element before it,
        this way the element slowly moves to the front of the array, thus reducing the
        number of comparisons done to find it each time -> this improvement is called "Transposition".
        
        Another improvement to is moving the element found to the front of the array,
        so that if you search it again (right after first search), you will find the element at the start so your algorithm runs at best case O(1). The drawback here is that if you search for some other element, the current element at index 0 can be pushed anywhere depending on the value you're looking for right now.
 
        Therefore, transposition improvement is slow improvement but move to front improvement is not always improving your search time.
 */
int staticArray_linearSearch(struct staticArray *arr, int value){
    
    int i;
    for(i=0; i< arr->length; i++){
        if(arr->A[i] == value){
            // Value found
            if(i!=0){
                // move the element to the previous index
                swap(&arr->A[i], &arr->A[i-1]);
            }
            return i; // Return current index of value found
        }
    }
    return -1; // Element not found
}

int dynamicArray_linearSearch(struct dynamicArray *arr, int value){
    int i;
    for(i=0; i< arr->length; i++){
        if(arr->A[i] == value){
            // Value found
            // move the element to the previous index
            if(i!=0){
                // Don't want to shift element out of bound.
                swap(&arr->A[i], &arr->A[i-1]);
            }
            return i; // Return current index of value found
        }
    }
    return -1; // Element not found
}

/*
        Pre-requisite for Binary search: The Array has to be sorted.
        Procedure:
                Check if key is present at midpoint of array.
                If key<midpointValue
                        update High index to midIndex-1
                If key>midpointValue
                        update Low index to midIndex+1
                
                The procedure above repeats until low>high
                    which means there are no more elements to check, the key is not found in the array.
 */

int staticArray_binarySearch_iterative(struct staticArray arr, int low, int high, int key){
    
    int l=low, h=high,midpoint=0;
    while(l<=h){
        midpoint = floor((l+h)/2);
        if(arr.A[midpoint]==key){
            return midpoint;
        }else if(key<arr.A[midpoint]){
            // key is in left side of the array, update high
            h = midpoint-1;
        }else{
            // key is in right side of the array, update low
            l = midpoint+1;
        }
    }
    
    // if you reached here then key not found in the array
    return -1;
}

/*
        The binary search can also be performed using recursion.
        The recursive binary search is a tail recursion (i.e. function does nothing
        after returning from recursive call). A tail recursion can be converted to a
        while loop implementation, which is preferred as space complexity is reduced,
        (recursive calls use stack memory).
 
 */
int staticArray_binarySearch_tailRecursion(struct staticArray arr, int low, int high, int key)
{
    
    // If low>high -> no elements left, key not found
    if(low<=high){
        int midpoint = floor((low+high)/2);
        if(arr.A[midpoint]==key){
            return midpoint;
        }else if(key<arr.A[midpoint]){
            // key is on left side of midpoint
            // recursive call with high updated
            return staticArray_binarySearch_tailRecursion(arr,low, midpoint-1,key);
        }else{
            // key is on right side of midpoint
            // recursive call with low updated
            return staticArray_binarySearch_tailRecursion(arr, midpoint+1, high, key);
        }
    }
    // key not in array because low>high, no elements to check
    return -1;
}

int dynamicArray_binarySearch_iterative(struct dynamicArray arr, int low, int high, int key){
    
    int l=low, h=high, midpoint=0;
    
    while(l<=h){
        // There are elements to check
        
        // calculate midpoint
        midpoint=floor((l+h)/2);
    
        if(arr.A[midpoint]==key){
            // key found in array
            return midpoint;
        }else if(key<arr.A[midpoint]){
            // key is on left of current midpoint
            // update high
            h = midpoint-1;
        }else{
            // key is on right of current midpoitn
            // update low
            l = midpoint+1;
        }
    }
    // key not found in the array
    return -1;
}
// Tail Recursion
int dynamicArray_binarySearch_tailRecursion(struct dynamicArray arr, int low, int high, int key){
    
    // Recursive calls are only made if low<=high -> i.e. there are elements to look at
    if(low<=high){
        
        int midpoint = floor((low+high)/2);
        if(arr.A[midpoint]==key){
            // Key found
            return midpoint;
        }else if(key<arr.A[midpoint]){
            // Key could be on the left side of midpoint
            // update high
            return dynamicArray_binarySearch_tailRecursion(arr, low, midpoint-1, key);
        }else{
            // Key could be on the right side of midpoint
            // update low
            return dynamicArray_binarySearch_tailRecursion(arr, midpoint+1, high, key);
        }
    }
    
    // At this point low>high, i.e. all elements checked, key not found
    return -1;
}
