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

int Recursive_BinarySearch(int arr[], int low, int high, int key);
int Iterative_BinarySearch(int arr[], int length, int key);
void left_shift(int *arr, int length);
void right_shift(int *arr, int length);
void rotate_left(int *arr, int length);
void rotate_right(int *arr, int length);
void reverse_array(int *arr, int length);

// Programs
void append_to_array(void);
void insert_at_index(void);
void delete_at_index(void);
void linear_Search(void);
void binary_Search(void);
void shift_array(void);
void rotate_array(void);
void reverse(void);

int main(int argc, const char * argv[]) {
    // insert code here...
    reverse();
    return 0;
}

void reverse(void){
#if METHOD2
    // Statically allocated memory
    struct staticArray arr ={{1,2,3,4,5}, 20, 5};
    staticArray_Display(arr);
    reverse_array(arr.A, arr.length);
    staticArray_Display(arr);
    
    // Dynamic array
    struct dynamicArray arr2 = createDynamicStruct();
    dynamicArray_Display(arr2);
    reverse_array(arr2.A, arr2.length);
    dynamicArray_Display(arr2);
#else
    // METHOD1
    // Statically allocated memory
    struct staticArray arr ={{1,2,3,4,5}, 20, 5};
    staticArray_Display(arr);
    reverse_array(arr.A, arr.length);
    staticArray_Display(arr);
    
    // Dynamic array
    struct dynamicArray arr2 = createDynamicStruct();
    dynamicArray_Display(arr2);
    reverse_array(arr2.A, arr2.length);
    dynamicArray_Display(arr2);
#endif
}

void rotate_array(void){
    
#ifdef LEFT_ROTATE
    // Statically allocated array
    struct staticArray arr ={{1,2,4,5,6},20, 5};
    staticArray_Display(arr);
    rotate_left(arr.A, arr.length);
    staticArray_Display(arr);
    rotate_left(arr.A, arr.length);
    staticArray_Display(arr);
    
    // Dynamically allocated array
    struct dynamicArray arr2 = createDynamicStruct();
    dynamicArray_Display(arr2);
    rotate_left(arr2.A, arr2.length);
    dynamicArray_Display(arr2);
    rotate_left(arr2.A, arr2.length);
    dynamicArray_Display(arr2);
#else
    // Statically allocated array
    struct staticArray arr ={{1,2,4,5,6},20, 5};
    staticArray_Display(arr);
    rotate_right(arr.A, arr.length);
    staticArray_Display(arr);
    rotate_right(arr.A, arr.length);
    staticArray_Display(arr);
    
    // Dynamically allocated array
    struct dynamicArray arr2 = createDynamicStruct();
    dynamicArray_Display(arr2);
    rotate_right(arr2.A, arr2.length);
    dynamicArray_Display(arr2);
    rotate_right(arr2.A, arr2.length);
    dynamicArray_Display(arr2);
#endif
}
void shift_array(void){
    
#ifdef LEFT_SHIFT
    struct staticArray arr ={{1,2,4,5,6}, 20, 5};
    staticArray_Display(arr);
    left_shift(arr.A, arr.length);
    staticArray_Display(arr);
    
    struct dynamicArray arr2 = createDynamicStruct();
    dynamicArray_Display(arr2);
    left_shift(arr2.A, arr2.length);
    dynamicArray_Display(arr2);
#else
    struct staticArray arr ={{1,2,4,5,6}, 20, 5};
    staticArray_Display(arr);
    right_shift(arr.A, arr.length);
    staticArray_Display(arr);
    
    struct dynamicArray arr2 = createDynamicStruct();
    dynamicArray_Display(arr2);
    right_shift(arr2.A, arr2.length);
    dynamicArray_Display(arr2);
#endif
    
}
void binary_Search(void){
    
    
    struct staticArray C ={{1,3,4,5,6,8},20, 6};
    struct dynamicArray D = createDynamicStruct();
    printf("Index of key in array: %d\n", Recursive_BinarySearch(C.A, 1, 3, 0));
    printf("Index of key in array: %d\n", Iterative_BinarySearch(C.A, C.length, 0));
    printf("Index of key in array: %d\n", Recursive_BinarySearch(D.A, 0, 5, 0));
    printf("Index of key in array: %d\n", Iterative_BinarySearch(D.A, D.length, 0));
    
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


// Tail Recursion
// Can easily be converted to a while loop and it is preferred over tail recurison
/*
        The binary search can also be performed using recursion.
        The recursive binary search is a tail recursion (i.e. function does nothing
        after returning from recursive call). A tail recursion can be converted to a
        while loop implementation, which is preferred as space complexity is reduced,
        (recursive calls use stack memory).
 
 */
int Recursive_BinarySearch(int arr[], int low, int high, int key){
    
    // Binary search performed as long as low<=high
    int mid;
    if(low<=high){
        mid = floor((low+high)/2);
        if(arr[mid]==key){
            return mid;
        }else if(key<arr[mid]){
            // key has to be on left side
            return Recursive_BinarySearch(arr, low, mid-1, key);
        }else{
            // key has to be on right side
            return Recursive_BinarySearch(arr, mid+1, high, key);
        }
    }
    
    // At point low>high, key not found
    return -1;
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

int Iterative_BinarySearch(int arr[], int length, int key){
    
    int low = 0, high=length-1, midpoint=0;
    while(low<=high){
        midpoint = floor((low+high)/2);
        if(arr[midpoint]==key){
            return midpoint;
        }else if(key<arr[midpoint]){
            //update high because key if exists, has to be on left
            high = midpoint-1;
        }else{
            // update low becaue key if exists, has to be on right
            low = midpoint+1;
        }
    }
    
    // At this point, there are no elements to check
    return -1; // key not found
}

/*
        You start at index 0, copy value at index 1 to index 0
            Process repeated until you reach the end of array.
        Element at index 0 is lost
 */
void left_shift(int *arr, int length){
    
    int i;
    for(i=0;i<length; i++){
        arr[i] = arr[i+1];
    }
    arr[length-1] = 0;
}
/*
        You start at the end of the array, copy second last to last,
            process repeats until you reach the first index
        Element at the end is lost
 */
void right_shift(int *arr, int length){
    int i;
    for(i=length-1;i>0;i--){
        arr[i]=arr[i-1];
    }
    arr[0] = 0; // The first element is set to 0
}
/*
        Rotate is similar to shift, except that the element lost is wrapped around.
            For Left rotate, the element at index 0 is brought to end index
            For right rotate, the element at end index is brought to index 0
 */
void rotate_left(int *arr, int length){
    int i, firstElement = arr[0];
    
    // Start at the front of the array
    for(i=0;i<length;i++){
        arr[i]=arr[i+1];
    }
    arr[length-1] = firstElement; // Bring first element to end of array
}
/*
    In rotating right, the last index value is brought to the front of the array
 */
void rotate_right(int *arr, int length){
    int i, lastElement = arr[length-1];
    for(i=length-1;i>0;i--){
        arr[i]=arr[i-1]; // Copy left index to the current index
    }
    arr[0] = lastElement;
}

/*
        Reversing can be done in two ways:
            1) Create another array of same size and use two iterators,
                one pointing to end of original and the other pointing to start
                of new array. Copy elements over.
                After copy elements in reverse to the new array, copy the new array to old array and return new array memory to program
            2) Use two iterators, one pointing to front and the other to the end
                Swap the values at these indices, increment front iterator and decrement end iterator. This is repeated until the two iterators are equal or if front iterator is > end iterator
 */
void reverse_array(int *arr, int length){

#ifdef METHOD2
// Method 2 is simpler, because its a single for loop
    int i, j,temp;
    for(i=0, j=length-1;i<j;i++, j--){
        // swap the two values
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }
#else
    // Method 1
    int *tempArr = (int *)malloc(length*sizeof(int));
    
    // Copy elements from arr into tempArr in reverse
    int i, j;
    for(i=length-1,j=0;i>=0;i--,j++){
        tempArr[j]=arr[i];
    }
    
    // Copy values in tempArr over to original arr
    for(i=0;i<length;i++){
        arr[i] = tempArr[i];
    }
    
    // release dynamically allocated memory for tempArr
    free(tempArr);
#endif
}
