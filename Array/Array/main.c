//
//  main.c
//  Array
//
//  Created by jjkhan on 7/6/21.
//

#include <stdio.h>
#include <stdlib.h> // For malloc function
#include <math.h> // For floor operations in BinarySearch
#include <stdbool.h> // for bool type
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
void staticArray_insert_sortedArray(struct staticArray *arr, int value);
void dynamicArray_insert_sortedArray(struct dynamicArray *arr, int value);
bool isSorted(int arr[], int length);
void move_negative_to_left(int *arr, int length);
int * mergeArrays(int *arr1, int arr1_length, int *arr2, int arr2_length);

// Set Operations on array - an Array can hold a set of elements
//      Union: All the elements of arr1 and arr2, without duplicates
//      Intersection: Common elements of arr1 and arr2.
//      Difference: Arr1-Arr2, the elements that are in arr2 but not in arr1?
//      Set membership: Searching if an element is part of the set
//
//  The two sets could be sorted or unsorted. If the two sets are sorted,
//  all the set operations below can be implemented using the idea behind merge of
//  two arrays. For unsorted sets, there are different ways to do it. Regardless of
//  if the two sets are sorted or unsorted, the result of a set operation would
//  require another array to return results.
struct dynamicArray* union_of_unsorted_sets(int *arr1, int arr1_len, int *arr2, int arr2_len);
struct dynamicArray* union_of_sorted_sets(int *arr1, int arr1_len, int *arr2, int arr2_len);
struct dynamicArray* intersection_of_unsorted_sets(int *arr1, int arr1_len, int *arr2, int arr2_len);
struct dynamicArray* intersection_of_sorted_sets(int *arr1, int arr1_len, int *arr2, int arr2_len);
struct dynamicArray* difference_of_unsorted_sets(int *arr1, int arr1_len, int *arr2, int arr2_len);
struct dynamicArray* difference_of_sorted_sets(int *arr1, int arr1_len, int *arr2, int arr2_len);
bool is_memeber_of_unsorted_set(int *arr, int len, int value);
bool is_memeber_of_sorted_set(int *arr, int len, int value);


// Programs
void print_Array(int* arr, int length);
void append_to_array(void);
void insert_at_index(void);
void delete_at_index(void);
void linear_Search(void);
void binary_Search(void);
void shift_array(void);
void rotate_array(void);
void reverse(void);
void sorted_Array_insert(void);
void check_if_sorted(void);
void separate_pos_neg_values(void);
void merge_two_arrays(void);
void get_union_of_unsorted_sets(void);
void get_union_of_sorted_sets(void);
void get_intersection_of_unsorted_sets(void);
void get_intersection_of_sorted_sets(void);
void get_difference_of_unsorted_sets(void);
void get_difference_of_sorted_sets(void);
void search_unsorted_list(void);
void search_sorted_list(void);


int main(int argc, const char * argv[]) {
    // insert code here...
    search_sorted_list();
    return 0;
}

// Tests: Passed
void search_sorted_list(void){
    int arr1[]={3,5,7,9,11};
    print_Array(arr1, 5);
    printf("Search for %d, result: %d\n",1, is_memeber_of_unsorted_set(arr1, 5, 1));
    printf("Search for %d, result: %d\n",9, is_memeber_of_unsorted_set(arr1, 5, 9));
    
}

// Tests: Passed
void search_unsorted_list(void){
    int arr1[]={1,5,3,11,15};
    print_Array(arr1, 5);
    printf("Search for %d, result: %d\n",11, is_memeber_of_unsorted_set(arr1, 5, 11));
    printf("Search for %d, result: %d\n",2, is_memeber_of_unsorted_set(arr1, 5, 2));
    
}
// Tests: Same size sets - passed
//        Different size sets - passed
void get_difference_of_sorted_sets(void){
    int arr1[]={3,5,7,9,11};
    int arr2[]={1,3,5,11,15};
    int arr3[]={1,7,11};
    print_Array(arr3, 3);
    print_Array(arr2, 5);
    struct dynamicArray *result = difference_of_sorted_sets(arr3, 3, arr2, 5);
    dynamicArray_Display(*result);
    
}


// Tests: Same size sets - passed
//        Different size sets - passed
void get_difference_of_unsorted_sets(void){
    int arr1[]={5,3,2,15,1};
    int arr2[]={1,5,3,11,15};
    int arr3[]={5,56,45};
    print_Array(arr3, 3);
    print_Array(arr2, 5);
    struct dynamicArray *result = difference_of_unsorted_sets(arr3, 3, arr2, 5);
    dynamicArray_Display(*result);
    
}

// Tests:  Same size sets - passed
//        Different size sets - passed
void get_intersection_of_sorted_sets(void){
    int arr1[]={3,5,7,9,11};
    int arr2[]={1,3,5,11,15};
    int arr3[]={1,5,15};
    print_Array(arr3, 3);
    print_Array(arr2, 5);
    struct dynamicArray *result = intersection_of_unsorted_sets(arr3, 3, arr2, 5);
    dynamicArray_Display(*result);
}

// Tests: Same size sets - passed
//        Different size sets - passed
void get_intersection_of_unsorted_sets(void){
    int arr1[]={5,3,2,15,1};
    int arr2[]={1,5,3,11,15};
    int arr3[]={5,56,15};
    print_Array(arr3, 3);
    print_Array(arr1, 5);
    struct dynamicArray *result = intersection_of_unsorted_sets(arr3, 3, arr1, 5);
    dynamicArray_Display(*result);
    
}

// Test case:  Same size sorted sets: Passed
//             Different size sorted sets: Passed
void get_union_of_sorted_sets(void){
    int arr1[]={3,5,7,9,11};
    int arr2[]={1,3,5,11,15};
    int arr3[]={0,9,10};
    print_Array(arr1, 5);
    print_Array(arr3, 3);
    struct dynamicArray *union_result = union_of_sorted_sets(arr1, 5, arr3, 3);
    dynamicArray_Display(*union_result);
    
}
// Test passed with both: Same size unsorted arrays & different sizes
void get_union_of_unsorted_sets(void){
    
    // Create two unsorted arrays

    int arr1[]={3,5,10,4,6};
    int arr2[]={12,4,7,2,5};
    int arr3[]={12,4,6};
    print_Array(arr3, 3);
    print_Array(arr2, 5);
    struct dynamicArray *union_result = union_of_unsorted_sets(arr3, 3, arr2, 5);
    dynamicArray_Display(*union_result);
    
    
}


void merge_two_arrays(void){
    
    // the two arrays you want to merge have to be sorted.
    int arr1[] ={ 1,3,5,7,9,11};
    int arr2[] ={ 1,4,6,10};
    int *mergeArray = mergeArrays(arr1, 6, arr2, 4);
    print_Array(mergeArray, 10);
}

void separate_pos_neg_values(void){
    // Statically allocated memory
    struct staticArray arr ={{1,6,-8,9,-5, -2,4}, 20, 7};
    staticArray_Display(arr);
    move_negative_to_left(arr.A, 7);
    staticArray_Display(arr);
    
    // Dynamic array
    struct dynamicArray arr2 = createDynamicStruct();
    dynamicArray_Display(arr2);
    move_negative_to_left(arr2.A, 7);
    dynamicArray_Display(arr2);
    
}

void check_if_sorted(void){
    
    // Statically allocated memory
    struct staticArray arr ={{1,1,9,10}, 20, 4};
    printf("Is the array sorted? %d\n", isSorted(arr.A, 4));
    // Dynamic array
    struct dynamicArray arr2 = createDynamicStruct();
    printf("Is the array sorted? %d\n", isSorted(arr2.A, 4));
}
void sorted_Array_insert(void){
    // Statically allocated memory
    struct staticArray arr ={{1,6,8,9}, 20, 4};
    staticArray_Display(arr);
    staticArray_insert_sortedArray(&arr, 0);
    staticArray_Display(arr);
    staticArray_insert_sortedArray(&arr, -1);
    staticArray_Display(arr);
    staticArray_insert_sortedArray(&arr, 7);
    staticArray_Display(arr);
    
    // Dynamic array
    struct dynamicArray arr2 = createDynamicStruct();
    dynamicArray_Display(arr2);
    dynamicArray_insert_sortedArray(&arr2, 0);
    dynamicArray_Display(arr2);
    dynamicArray_insert_sortedArray(&arr2, -1);
    dynamicArray_Display(arr2);
    dynamicArray_insert_sortedArray(&arr2, 7);
    dynamicArray_Display(arr2);
    
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

/*
        Insert a value in a sorted array.
        The idea is to start at the end of the array and if the given value is
        less than current index value, shift the value to the right. You repeat this
        until you reach an element in the array whose value is less than given value.
        
        The typical way done is you look for position in the sorted array and then shift all the elements after that to the right to make room. But, its better to start at the end of the sorted array and shift while you look for its correct position of insertion.
        
        
 */

void staticArray_insert_sortedArray(struct staticArray *arr, int value){
    if(arr->length==arr->size){
        // No room for insertion
        printf("Array is full.\n");
        return;
    }else if(arr->length<arr->size){
        // There is room for insertion
        int i = (arr->length)-1; // Start at the end of the sorted array
        // Keep shifting elements to the right if the current element is > value
        // I'm assuming the list is sorted in ascending order
        
        // The (i!=-1) is added for case when given value has to be inserted at the
        // front -> worse case scenario of this algorithm
        while(arr->A[i]>value && (i!=-1)){
            arr->A[i+1] = arr->A[i]; // shifting element to the right
            i--;
        }
        // arr[i] < value, therefore, 'value' is inserted right after
        arr->A[i+1] = value;
        (arr->length)++; // Increase length, new element added.
    }
    
}

void dynamicArray_insert_sortedArray(struct dynamicArray *arr, int value){
    
    if(arr->length==arr->size){
        // No room for insertion
        printf("Array is full.\n");
        return;
    }else if(arr->length<arr->size){
        // There is room for insertion
        int i = (arr->length)-1; // Start at the end of the sorted array
        // Keep shifting elements to the right if the current element is > value
        // I'm assuming the list is sorted in ascending order
        
        // The (i!=-1) is added for case when given value has to be inserted at the
        // front -> worse case scenario of this algorithm
        while(arr->A[i]>value && (i!=-1)){
            arr->A[i+1] = arr->A[i]; // shifting element to the right
            i--;
        }
        // arr[i] < value, therefore, 'value' is inserted right after
        arr->A[i+1] = value;
        (arr->length)++; // Increase length, new element added.
    }
    
}

/*
      You compare pair of indices starting at front and you look for first pair that
        is not sorted. i.e. if checking for sorted in ascending order,
      then element at i should be less than element at i+1, find first pair that negates this and return false
        
        Key note: You don't traverse the array till length-1, because you can't
                  compare element at length-1 with non-exisiting element at length,
                  so, you stop at length-1 for last pair comparison.
 */
bool isSorted(int arr[], int length){
    
    int i;
    for(i=0;i<length-1;i++){
        if(arr[i]>arr[i+1]){
            // found a pair not in ascending order
            return false;
        }
    }
    // You reached here, that means the list is sorted in ascending order
    return true;
}

/*
    This function moves all the negative numbers in an array to the left
    and all the positive numbers to the right.
 
    The idea is to use two iterators, one starting at the front and one at the back.
    The front iterator will look for positive numbers and the back iterator will
    look for negative numbers. When they've found their numbers, the two will swap to push positive to the front and the negative to the end. This is repeated until the front iterator cross the back iterator, which means you've pushed all the negative to the front and all the positive numbers to the right.
    
    This algorithm does n+2 comparisons -> time complexity is o(n)
 */
void move_negative_to_left(int *arr, int length){
    int i = 0, j=length-1;
    
    while(i<j){
        // The two iterators keep moving until i crosses j,
        // then you scanned full array
        while(arr[i]<0){
            // Its negative number, move to next index
            i++;
        } // end of this while -> you've found a positive number
        
        while(arr[j]>0){
            // Its a positive number, move to previous index
            j--;
        }// end of this while -> you've found a negative number
        
        if(i<j){
            // Swap the two numbers iff i hasn't crossed j
            swap(&arr[i], &arr[j]);
        }
    }
    
}

/*
        Note: Merge only makes sense for sorted arrays.
        This function will two arrays and return pointer to the merged array.
        The idea is to use three iterators: 1 for traversing arr1, 1 for traversing arr2 and 1 for traversing the merge array.
        
        You compare current index of each array and the smaller among them is copied to the merged array, increment the iterator of arr from which you copied and increment iterator of the merged Array.
        
        One of the arrays will reach the end first, then copy the elements of the array not traversed completely to the merge array.
        
        The time complexity of a merge algorithm is always denoted as
        theta(arr1_length + arr2_length), i.e. whenever you see two degrees in time
        complexity notation, it means there is some sort of merge in there.
 
 */
int* mergeArrays(int *arr1, int arr1_length, int *arr2, int arr2_length){
    
    int i=0,j=0,k=0;
    
    // Allocate memory from heap for merged Array
    int * mergedArray = (int*)malloc((arr1_length+arr2_length)*sizeof(int));
    
    while(i<arr1_length && j<arr2_length){
        // Compare and copy the lowest of the two array elements
        // over to the mergeArray, increment iterator
        if(arr1[i]<arr2[j]){
            mergedArray[k]=arr1[i];
            i++;
            k++;
        }else{
            mergedArray[k]=arr2[j];
            j++;
            k++;
        }
    }// End of while-loop, one of the array copied over completely
    
    // Copy over all the remaining elements of arr1
    while(i<arr1_length){
        mergedArray[k]=arr1[i];
        i++;
        k++;
    }
    
    // Copy over all the remaining elements of arr2
    while(j<arr2_length){
        mergedArray[k]=arr2[j];
        j++;
        k++;
    }
    // return merged array
    return mergedArray;
}

void print_Array(int* arr, int length){
    printf("The elements of the array are.\n");
    int i;
    for(i=0;i<length;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}



void copy(struct dynamicArray **destination, int* source, int source_len){
    
    int i;
    for(i=0; i<source_len; i++){
        // copy contents of source array into array of destination
        (*(*destination)).A[i] = source[i];
        // Increment length
        (*(*destination)).length++;
    } // source is copied over to destination struct's array A
    
}

// Allocate memory from the heap for dynamicArray
// The 'size' member of argument must be initialized before using this
void allocateArray(struct dynamicArray **arr){
    
    (*(*arr)).A = (int *)malloc(((*(*arr)).size)*sizeof(int));

}

bool linearSearch(int arr[] , int arr_len, int value){
    
    int i;
    for(i=0;i<arr_len;i++){
        if(arr[i]==value){
            return true;
        }
    }
    return false;
}

/*
        The idea is to copy one of the sets into the new array. Then traversing
        through each index of the second set, you search for that element in the
        new array, if its not there already, then you copy it over, else move to the next.
        
        Therefore, the total time complexity of this setup is:
            'arr1_len' time to copy one of the sets over to the union array,
        then search for 'arr2_len' elements in arr1 array.
        Therefore, total time is O(n^2) because the dominant time taken in searching
            arr1 for each arr2 element, before deciding to copy it over to union array.
 */
struct dynamicArray* union_of_unsorted_sets(int *arr1, int arr1_len, int *arr2, int arr2_len){
    
    struct dynamicArray *union_result = (struct dynamicArray *)malloc(sizeof(struct dynamicArray));
    
    // At most union array size would set1+set2
    union_result->size = arr1_len + arr2_len;
    union_result->length =0; // Initialize the value correctly.
    
    // Allocate memory for dynamic array of max possible size of union of sets
    allocateArray(&union_result);
    
    // Copy set arr1 over to union_result struct
    copy(&union_result, arr1, arr1_len); // Copy the elements of arr1 into union_Result array
    
    // Now we loop through arr2, search for its elements in arr1 before placing it in union_array
    
    int i;
    for(i=0;i<arr2_len;i++){
        // Search for current element of set arr2 in arr1
        if(!linearSearch(arr1,arr1_len, arr2[i])){
            // Element not found in set arr1, therefore copy the element over to union
            union_result->A[union_result->length] = arr2[i];
            
            // increment length of union_result
            (union_result->length)++;
        }
    }// Moved all the elements of arr2 that were not already present in arr1

    // Check if all of union array occupied, if not, reduce the size.
    if(union_result->length < union_result->size){
        // resize the array for the right size.
        
        //struct dynamicArray *final_result = (struct dynamicArray*)realloc(union_result, (union_result->length)*sizeof(int));
        
        union_result->A = (int *)realloc(union_result->A, union_result->length*sizeof(int));
        union_result->size = union_result->length;
    }
    
    return union_result;

}

/*
 
    The two sets are sorted and we determine the union of the two sets.
    The idea here is similar to merging two arrays (which has a prereq of being sorted). So, we use three iterators, one for each set and the third for the union array.
    We traverse through the two sets, updating the union set. If the two elements of the sets are the same, you copy a single copy of the element to the union set and increment the iterators of both sets at the same.
 
    Once you reach the end of one of the sets, you just copy over the elements of the set that hasn't reached its end.
 
    Since this code is using the idea behind merge of two arrays, its time complexity is dependent on two variables O(arr1_len + arr2_len);
    But if you were write the two as a function of a single variable, you get O(n),
    i.e. highest degree is 1.
 */
struct dynamicArray* union_of_sorted_sets(int *arr1, int arr1_len, int *arr2, int arr2_len){
    
    // Allocate memory for Result
    struct dynamicArray *union_result = (struct dynamicArray*)malloc(sizeof(struct dynamicArray));
    
    // Set size of the dynamic array
    union_result->size=arr1_len+arr2_len;
    union_result->length = 0;
    
    // allocate memory from heap for array
    union_result->A = (int *)malloc(union_result->size*sizeof(int));
    
    // three iterators, 1 for each set, 1 for union set
    int i =0, j=0, k=0;
    
    while(i<arr1_len && j<arr2_len){
        
        // if set element same, copy one to the union set, increment all iterator
        if(arr1[i]==arr2[j]){
            union_result->A[k]=arr1[i];
            i++;
            j++;
            k++;
            union_result->length++;
        }else if(arr1[i]<arr2[j]){
            // Copy arr1 element and increment its iterator
            union_result->A[k]=arr1[i];
            i++;
            k++;
            union_result->length++;
        }else{
            // Copy arr2 element and increment its iterator
            union_result->A[k] = arr2[j];
            j++;
            k++;
            union_result->length++;
        }
    }// End of while loop, one of the sets reached its end
    
    //Copy the remaining elements
    while(i<arr1_len){
        union_result->A[k] = arr1[i];
        i++;
        k++;
        union_result->length++;
    }
    
    while(j<arr2_len){
        union_result->A[k] = arr2[j];
        j++;
        k++;
        union_result->length++;
    }
    
    // Resize array if union set not using all the allocated memory
    if(union_result->length<union_result->size){
        union_result->A = (int *)realloc(union_result->A, union_result->length*sizeof(int));
        union_result->size = union_result->length; // Update size
    }
    
    return union_result;
}


/*
    Intersection of two sets should return a set with only values common in the two sets.
    
    In this you iterate through one of the sets and each iteration,you look for element in the other set, if it exist, then you copy it over to the result set.
 
    So, time complexity is, for each element in set1 you search set2 for that element, so time complexity it arr1_len*arr2_len, i.e. O(n^2)
            Because each element of arr1 (arr1_len elements) is searched in arr2 (arr2_len), so you iterate through arr2_len elements arr1_len times. Hence the time complexity of O(arr1_len*arr2_len) -> in single variable O(n^2)
    
 */
struct dynamicArray* intersection_of_unsorted_sets(int *arr1, int arr1_len, int *arr2, int arr2_len){
    
    struct dynamicArray* intersection = (struct dynamicArray*)malloc(sizeof(struct dynamicArray));
    
    // The intersection can at most have all the elements of set1 (i.e. arr1).
    // i.e. all the element of arr1 are in arr2
    intersection->size = arr1_len;
    intersection->A=(int*)malloc(intersection->size*sizeof(int));
    intersection->length=0;
    
    int i,k=0; // to iterate through set1 and for the intersection set.
    for(i=0; i<arr1_len;i++){
        
        if(linearSearch(arr2, arr2_len, arr1[i])){
            // Element found in both sets
            intersection->A[k] = arr1[i];
            k++;
            intersection->length++;
        }
    } // End all of for-loop, all of arr1 elements looked for in arr2.
    
    // resize the dynamic array if needed
    if(intersection->length<intersection->size){
        intersection->A=(int*)realloc(intersection->A, intersection->length*sizeof(int));
        // Update size
        intersection->size=intersection->length;
    }
                        
    return intersection;
}

/*
            The sets are sorted. Use the idea of merging two sorted arrays.
            Have three iterators, 1 for each given set, and 1 for the result set.
            You copy element to the result iff the two sets have the same element,
            else you move forward.
            (assuming sorted in ascending order)
            If set1 current element is < set2 current element, then we shouldn't increment move iterators, only set1's because its possible the next
            element of set1 is equal to set2's current element. Same idea if current
            element of set2 is < set1's element, you move iterator of set2 to the next element.
            
            The time complexity of this is dependent on the elements of both sets
            O(arr1_len1 + arr2_len) -> in a single variable it will be O(n)
            
 */
struct dynamicArray* intersection_of_sorted_sets(int *arr1, int arr1_len, int *arr2, int arr2_len){
    
    int i=0, j=0, k=0;
    
    struct dynamicArray *result = (struct dynamicArray*)malloc(sizeof(struct dynamicArray));
    
    // Get size of the smallest of the two sets
    result->size = (arr1_len>=arr2_len)? (arr2_len): (arr1_len);
    result->A = (int *)malloc(sizeof(result->size));
    result->length = 0;
    
    while(i<arr1_len && j<arr2_len){
        if(arr1[i]<arr2[j]){
            // increment arr1 iterator
            i++;
        }else if(arr1[i]>arr2[j]){
            j++;
        }else{
            // Both are equal, copy the element to result
            result->A[k]=arr1[i];
            i++;
            j++;
            k++;
        }
    }// One of the sets reached the end.
    
    // check if all of result->A allocated memory is occupied,
    // if not, resize the allocated memory.
    
    if((result->length+1)<result->size){
        
        result->A = (int *)realloc(result->A, sizeof(result->length+1));
        result->size = result->length+1;
    }
    return result;
    
}

/*
        The difference of two sets is set1-set2, the goal is two only return elements of set1 that are not present in set2, i.e. subtract all the common elements of set1 and set2, leaving only the elements of set1 that are not present in set2.
 
        So, for every element of set1, you search for that element in set2, if it is
        not present in set2, then move it to result set, else move iterator of set1 to next position.
        Therefore, for each set1 element, you search set2 -> therefore: set1_Size*set2_Size -> in one variable = O(n^2)
 */
struct dynamicArray* difference_of_unsorted_sets(int *arr1, int arr1_len, int *arr2, int arr2_len){
    
    // At most all of arr1 elements not found in arr2.
    struct dynamicArray *difference = (struct dynamicArray*)malloc(sizeof(struct dynamicArray));
    difference->size = arr1_len;
    difference->length=0;
    
    // allocate size for difference->A, assuming all elements of arr1 not found in arr2
    difference->A = (int *)malloc(difference->size*sizeof(int));
    
    int i,k=0;
    for(i=0; i<arr1_len; i++){
        if(!linearSearch(arr2, arr2_len, arr1[i])){
            // arr1 element not found in arr2
            difference->A[k] = arr1[i];
            k++;
            difference->length++;
        }
    } // end of for loop: all the elements of arr1 that are not present in arr2 copied over to differenc->A
    
    // Resize result->A if not using all the allocated space
    if((difference->length+1)<difference->size){
        difference->size = difference->length+1;
        difference->A = (int *)realloc(difference->A, difference->size*sizeof(int));
    }
    return difference;
}

/*
    The two sets are sorted here. The idea of merging two arrays is applied here again.
        
    The difference of set1 and set2 is the elements of set1 that are not present in set2. So, if the current set1 element is > set2 element, its possible the next set2 element is same as current set1 element. Therefore, you increment iterator of set2 to the next element, leaving set1 iterator at its current position. When you find a set2 element that is > than current set1 element, then it confirms that current set1 element is not in set2 so you copy it over to the result set. This is repeated until you reach the end of either set1 or set2. Note, you only copy elements of set1 to result if they're not present in set2.
 
        Since you're iterating through two sets, the time complexity is dependent on both set lengths, therefore its O(set1_len + set2_len) -> in 1 variable its O(n)
 
 */
struct dynamicArray* difference_of_sorted_sets(int *arr1, int arr1_len, int *arr2, int arr2_len){
    
    // At most all the elements of set1 are not found in set2
    struct dynamicArray* difference = (struct dynamicArray*)malloc(sizeof(struct dynamicArray));
    difference->size = arr1_len;
    difference->length=0;
    
    // allocate memory for difference->A
    difference->A=(int *)malloc(difference->size*sizeof(int));
    
    // Iterators for the two given sets and result set
    int i=0,j=0,k=0;
    
    while(i<arr1_len && j<arr2_len){
        
        if(arr1[i]<arr2[j]){
            // set1 element is not in set2 because its smaller
            // copy it into result set
            difference->A[k] = arr1[i];
            k++;
            i++;
            difference->length++;
        }else if(arr1[i]>arr2[j]){
            // set1 element is greater than set2 element
            // next element of set2 could be == to set1
            // so you only move set2 iterator
            j++;
        }else{
            // the two set elements are the same
            // move both iterators forward
            i++;
            j++;
        }
    } // End of while-loop one of the sets reached its end, don't have to copy the rest
    
    // Check if all the memory allocated for result set used
    // if not, resize it
    if((difference->length+1)<difference->size){
        // not all the allocated memory used
        // resize the result set
        difference->size = difference->length+1;
        difference->A =(int *)realloc(difference->A, difference->size*sizeof(int));
    }
    return difference;
}


/*
        For unsorted set, you can only perform a Linear search and go through
        the entire set to find the element.
        
        Time complexity is O(set_len) = O(n)
 */
bool is_memeber_of_unsorted_set(int *arr, int len, int value){
    
    if(linearSearch(arr, len, value)){
        return true;
    }
       return false;
}
/*
       For sorted set, you can only perform a Binary search and find the value in
       O(log set1_len) = O(log n)
 */
bool is_memeber_of_sorted_set(int *arr, int len, int value){
        
    if(Iterative_BinarySearch(arr, len, value)){
        return true;
    }
    return false;
}
