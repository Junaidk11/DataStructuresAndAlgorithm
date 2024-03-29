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
#include <string.h> // for memset
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


// Finding missing elements in an array
void find_single_missing_element_of_n_natural_numbers(int *arr, int len); // Sorted array
void find_single_missing_element_of_natural_numbers(int *arr, int len); // Sorted array
void find_multiple_missing_element_of_natural_numbers(int *arr, int len); // Sorted array
void find_all_missing_numbers(int *arr, int len, int lowestNumber, int highestNumber); // could be used with both sorted and unsorted list of numbers


// Finding duplicates in an array
void find_duplicates_sorted_array_not_using_hashtable(int *arr, int len);
void count_duplicates_sorted_array_not_using_hashtable(int *arr, int len);
void count_duplicates_sorted_array_using_hashtable(int *arr, int len);
void count_duplicates_unsorted_array_using_hashtable(int *arr, int len);


// Find a pair in given array that add to given sum
void find_pair_for_given_sum(int *arr,int len, int sum); // works for both sorted and unsorted list -> O(n)
void find_pair_give_sorted_array(int *arr, int len, int sum); // Only works for sorted array -> O(n)

// Find max and min in an array in single scan
void find_max_min_in_single_scan(int *arr, int len);


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
void missing_elements(void);
void find_duplicates(void);
void find_pairs_for_given_sum(void);
void find_min_max(void);


int main(int argc, const char * argv[]) {
    // insert code here...
    find_min_max();
    return 0;
}

void find_min_max(void){
    int arr1[]={1,3,4,5,6,7,8};
    int arr2[]={-10,11,45,100,22000,556,-1000};
    print_Array(arr1, 7);
    find_max_min_in_single_scan(arr1, 7);
    print_Array(arr2, 7);
    find_max_min_in_single_scan(arr2, 7);
}
// Test passed.
void find_pairs_for_given_sum(void){
    
    int arr1[]={1,3,4,5,6,7,8}; // sorted
    int arr2[]={3,5,2,7,6,10}; // unsorted
    print_Array(arr1, 7);
    find_pair_for_given_sum(arr1, 7, 10);
    print_Array(arr2, 6);
    find_pair_for_given_sum(arr2, 7, 10);
    print_Array(arr1, 7);
    find_pair_give_sorted_array(arr1, 7, 10);
    
}
// Test passed
void find_duplicates(void){
    
    int arr1[]={1,2,3,4,5,5,6,7,8,9,9,9};
    int arr2[]={2,5,1,1,7,9,8,4,4,8};
    print_Array(arr1, 12);
    count_duplicates_sorted_array_not_using_hashtable(arr1, 12);
    find_duplicates_sorted_array_not_using_hashtable(arr1, 12);
    count_duplicates_sorted_array_using_hashtable(arr1,12);
    print_Array(arr2, 10);
    count_duplicates_unsorted_array_using_hashtable(arr2,10);
}
// Tests passed;
void missing_elements(void){
    int arr1[] = {1,2,3,4,5,6,8,9,10};
    int arr2[] = {6,7,8,9,11,12,13};
    int arr3[] ={6,7,9,10,13,16,20};
    print_Array(arr1, 9);
    find_single_missing_element_of_n_natural_numbers(arr1, 9);
    print_Array(arr2, 7);
    find_single_missing_element_of_natural_numbers(arr2, 7);
    print_Array(arr3, 7);
    find_multiple_missing_element_of_natural_numbers(arr3, 7);
    print_Array(arr3, 7);
    find_all_missing_numbers(arr3, 7, 6, 20);
    
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
//        Set1 smaller than set2 - passed
//        Set1 bigger than set2 - Passed
void get_difference_of_sorted_sets(void){
    int arr1[]={3,5,7,9,11,20};
    int arr2[]={1,3,5,11,15};
    int arr3[]={1,7,11};
    print_Array(arr1, 6);
    print_Array(arr2, 5);
    struct dynamicArray *result = difference_of_sorted_sets(arr1, 6, arr2, 5);
    dynamicArray_Display(*result);
    
}


// Tests: Same size sets - passed
//        Set1 smaller than set2 - passed
//        Set1 bigger than set2 - Passed
void get_difference_of_unsorted_sets(void){
    int arr1[]={5,3,2,15,1,25,16};
    int arr2[]={1,5,3,11,15};
    int arr3[]={5,56,45};
    print_Array(arr1, 7);
    print_Array(arr2, 5);
    struct dynamicArray *result = difference_of_unsorted_sets(arr1, 7, arr2, 5);
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
    } // End of while-loop one of the sets reached its end, don't have to copy the elements of set2, only set1's remaining elements
    
    while(i<arr1_len){
        difference->A[k]=arr1[i];
        i++;
        k++;
        difference->length++;
    }
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


/*
        The array is assumed to have the first n natural numbers.
        The natural numbers start at 1.
        
        We can find the missing element of a sorted array of n natural numbers
        by getting the sum of all the elements and comparing it with the
        expected sum. The difference between the sums will give you the missing number.
        
        sum of n natural numbers = n(n+1)/2
 
        The time complexity is simply the work done in the function,
        the work done here is summing all the elements printing the missing element.
        For summing you're going through the entire array so O(n)
 */
void find_single_missing_element_of_n_natural_numbers(int *arr, int len){
    
    // n would be the last nummber of the natural numbers in arr
    int expectedSum = (arr[len-1]*(arr[len-1]+1))/2;
    int i, sum=0;
    for(i=0;i<len;i++){
        sum +=arr[i];
    }
    if(sum<expectedSum){
        printf("First Missing number is: %d\n", expectedSum-sum);
    }else{
        printf("No missing number.\n");
    }
    
}

/*
    In this function the natural numbers don't start at 1. Could start at any value;
    The key idea here is to use the index of the array to find the missing element.
 
    E.g.
        If the natural numbers start are: 6,7,8,10,11,12
            The difference between each element and index should be 6 because you
            start at natural numbers at 6.
                6-0 = 6
                7-1 = 6
                8-2 = 6
                9-3 = 6
                10-4= 6
                and so on.
 
        Therefore, if you find a element in the array where the difference is
        not 6, then you know an element is missing, the missing element is simpling
        the (Index + the difference).
 
        Note: You could count the number of missing elements,
                but you can only find the first missing element with this method. Because, as you scan through the arr after you've found the missing element, the differences can't be used to find the missing element with the index.
            The difference between the calculated difference between current array element and index and expected difference tells you how many elements are missing.
            
 */
void find_single_missing_element_of_natural_numbers(int *arr, int len){

    int difference = arr[0];
    int i;
    for(i=0;i<len;i++){
        if((arr[i]-i)!=difference){
            // Found the missing element
            // you could count the number of missing elements,
            // but you can only find the first missing element with this method.
            printf("First missing element is: %d\n", i+difference);
            return;
        }
    }
}

/*
    The difference between the calculated difference between current array element and index and expected difference tells you how many elements are missing.
 
    Therefore, the code is similar to finding a single missing element of the natural numbers, if there are multiple missing elements, you need to update your expected difference to the calculated current difference so that you only print the missing elements.
 
    E.g.
            6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19
    
    Starting expected difference -> 6 (because arr[0] - index0 = 6)
    This difference is maintained until index 3.
    At index 4, the calculated difference is 11-4 = 7, which means we're missing one element. Print this missing element using (currentIndex + expectedDifference) 4+6 = 10, now we increment our expectedDifference for
        the remaing elements until it matches the current calculated difference.
        Therefore, expected difference now is 7
    This difference is maintained until index 5.
    At index 6, the calculated difference is 9, which is two more than expected
    , therefore, we're missing two elements, print those elements using the currentIndex and increment expectedDifference: print 6+7=13, expectedDifference is now incremented to 8.
        print 6+8=14, expectedDifference is now incremented to 9, matches the currentDifference, move to next index now.
    The difference of 9 is now maintained till the end of the array. And We've printed
    all the missing elements in the natural numbers array
 
    Note:           The work done here is simply scanning the array, the while loop
                used to increment the expectedDifference to match currentDifference
                takes negligible time.
 */
void find_multiple_missing_element_of_natural_numbers(int *arr, int len){
  
    int expectedDifference = arr[0]; // first element minus index 0

    int i;
    for(i=0;i<len;i++){
        // scanning through array
        if((arr[i]-i)!=expectedDifference){
            // current Difference doesn't match expected,
            // missing elements
            while((arr[i]-i)!=expectedDifference){
                // print missing elements and update expectedDifference
                // until it matches the new difference
                printf("Missing elements is: %d\n",i+expectedDifference);
                expectedDifference++;
            }
        }
    }
}


/*
        In this method, we use a Hashtable which is the size of the highest possible
        number in the given array.
        The elements of arr are used to index into the Hashtable and increment that index of the hashtable.
        After scanning the arr and updating the hashtable, we scan hashtable and find all the elements that are 0 in the hashtable.
        
        This procedure is fast, it has two for loops, one for updating hashtable by scanning given array and the other is for scanning hashtable to print all missing elements. Total workdone with O(n) because each loop takes n time -> o(n+n) = o(n).
 
        NOTE:
            Whenever there is searching to do, you can always use a Hashtable. Its faster but it requires memory. If you're constricted by memory size, then hashtable may not be the best option for searching.
 */
void find_all_missing_numbers(int *arr, int len, int lowestNumber, int highestNumber){
    
    // allocate memory for hashtable
    int *hashtable = (int*)malloc(highestNumber*sizeof(int));
    
    // Scan given array and update hashtable
    int i;
    for(i=0;i<len;i++){
        
        // The element of arr is used to index into hashtable and increment it
        hashtable[arr[i]]++;
    }
    
    // Scan the hashtable and print all the missing elements
    for(i=lowestNumber;i<(highestNumber-1);i++){
        if(hashtable[i]==0){
            // Number missing in given array
            printf("Missing number is: %d\n",i);
        }
    }
    // Return allocated memory back to heap.
    free(hashtable);
    hashtable=NULL;
}

/*
    In this algorithm, you're using two iterators.
    The two iterators, are used to keep count number of duplicates.
 
    When you find a duplicate, you use the second iterator
    to move forward until you find a new element that is not the same duplicate.
        When you find new element using the second indexer, you print the count, Then you update your previous iterator to the element before second iterator you started, because the algorithm is based on checking if current element is same as next element.
 
    The work done here is O(n) because you're only scanning the given list once,
    and all the operations in the loop are of constant time.
 */
void count_duplicates_sorted_array_not_using_hashtable(int *arr, int len){
    
    int i,j;
    for(i=0;i<len;i++){
        if(arr[i]==arr[i+1]){
            // Found a duplicate
            // move j to the next element and check if its same as currentDuplicate
            j=i+1;
            // Check if next element is also the same duplicate as the one found at i
            while(arr[i]==arr[j])j++; // Incrementing j until you reach a different element
            // Found a new element, print the number of duplicates of the previous element
            printf("Number %d is repeated %d times.\n",arr[i], j-i);
            // Update i to the element before the new element at j
            i = j-1;
        }
    }
}

/*
    In this algorithm, you're using two iterators just like before,
    and using an additional variable to store the lastDuplicate found, to avoid printing the same duplicate multiple times as you scan through the given list.
 
    The work done in this function is just scanning through list, therefore time complexity is linear o(n)
 */
void find_duplicates_sorted_array_not_using_hashtable(int *arr, int len){
    
    int lastDuplicate =0; // Stores last duplicate found
    int i;
    for(i=0;i<len;i++){
        
        if(arr[i]==arr[i+1] && arr[i]!=lastDuplicate){
            // found a new duplicate
            // print it
            printf("%d is duplicated.\n", arr[i]);
            // update last duplicate
            lastDuplicate=arr[i];
        }
    }
}

/*
    In this method we create a Hashtable that is of size lastElement+1 (because array index starts at 0;
    
    Then we scan through the given array and use the elementValue to index into Hashtable and increment the value there.
    
    The work done here is scanning through given given, which is linear and then setting hashtable element value, which is constant time, finally
    you scan hashtable and print the duplicates and their count, which is also linear.
        Therefore, overall time taken is also linear.
 
 */
void count_duplicates_sorted_array_using_hashtable(int *arr, int len){
    
    // Allocate memory for the hashtable from heap
    // arr[len-1]+1 -> Size of Hashtable
    int *hashtable = (int*)calloc((arr[len-1]+1), sizeof(int)); // Calloc will allocate and initialize memory to 0

    
    // scan through given array and update hashtable
    int i;
    for(i=0;i<len;i++){
        // increment count
        hashtable[arr[i]]++;
    }
    
    // Scan through hashtable and find duplicates and their count
    for(i=0;i<arr[len-1]+1;i++){
        if(hashtable[i]>1){
            // Multiple occurence of the current number
            printf("Number \'%d\' is repeated %d times.\n",i, hashtable[i]);
        }
    }
    
    // Return memory allocated from heap
    free(hashtable);
    hashtable=NULL;
}

/*
    Assumption is that the arr is not sorted.
    Work done here is just scanning through the entire list and updating max -> linear time, O(n)
    Function returns largest element in the array
 */
int get_max(int *arr, int len){
    
    int currentMax=arr[0];
    int i;
    for(i=0;i<len;i++){
        if(arr[i]>currentMax){
            // Found a larger value
            currentMax = arr[i];
        }
    }
    return currentMax;

}

/*
    In this method, we find the largest number in the given arr.
    Then we create a hashtable of that size+1, because index starts at 0.
    
    Next, we scan through the given array, and using element to index into hashtable and increment its value.
    Finally, we scan through the hashtable and print all the numbers that were repeated.
    
    In this algorithm the work done is: Scanning through the given array to update hashtable, done in linear time.
                                        Scanning through the hashtable to print all the duplicates, done in linear time.
                            Therefore, linear + linear is still linear.
 
    There is another method to find duplicates in an array using two for loops, the time complexity of that is quadratic. So, I've skipped it.
 */
void count_duplicates_unsorted_array_using_hashtable(int *arr, int len){
    // Get max element in the given array
    int maxElement = get_max(arr, len);
    
    // Allocate memory for hashtable of size maxElement+1 because indexing starts at 0
    // Calloc will initialize the memory with 0
    int *hashtable = (int *)calloc(maxElement+1, sizeof(int));
    
    // Scan through the given array and index into hashtable to update
    int i;
    for(i=0;i<len;i++){
        hashtable[arr[i]]++;
    }
    
    // Scan through hashtable and print all duplicates
    for(i=0;i<maxElement+1;i++){
        if(hashtable[i]>1){
            // Found a duplicate
            printf("\'%d\' is repeated %d times.\n",i, hashtable[i]);
        }
    }
    
    // Return memory allocated from heap
    free(hashtable);
    hashtable=NULL;
}

/*
    There are multiple ways to achieve this.
        One is: Using two nested loops -> this will give you time complexity of O(n^2)
        Second is: Using hashtable -> which will give you linear time complexity -> the fastest method
 
    We're assuming the list has no duplicates, if the list has duplicates, you can remove the duplicates
    and perform the same procedure.
 
    So, the idea with Hashtable is: You find the largest number in the give index,
    then you create a hashtable of largestNumber+1, because indexing starts at 0.
 
    Then scan through the given list, and use the element of list to index into the hashtable
    and set that value. Now, for the current element, determine what number is needed to get the desired sum.
    The needed number can be used to index into hashtable and check if it was found in the given list, if it was
    then we have found a pair that can give you the desired sum. If the desired number needed at the current element
    of given list is not found in the hashtable, you move to the next index. This way you can print all the possible
    pair available to get the given sum.
 
    
 */
// We assume the list has no duplicates.
void find_pair_for_given_sum(int *arr, int len, int sum){
    
    
    // Find the largest number in the list
    int maxNumber = get_max(arr, len);
    
    // Allocate memory for hashtable of size maxNumber+1
    int *hashtable = (int *)calloc(maxNumber+1, sizeof(int));
    
    // Scan through given list, update hashtable, find pairs
    int i,number_needed;
    for(i=0;i<len;i++){
        
        // Don't update hashtable first, because we calculate the number needed based on current element
        // if the number needed is the same number found in list, then we're getting a result that assumes
        // the list has duplicates -> but we said list has not duplicates.
        
        // calculate number needed to reach desired sum
        number_needed = sum - arr[i];
        
        // check if the needed number was found in the hashtable
        // we're assuming there are no duplicates, so all hashtable values should be either 0 or 1
        // hashtable indices cannot be negative -> could check if the number_needed is sensible.
        if(number_needed>=0 && number_needed<maxNumber){
            if(hashtable[number_needed]){
                // number was found in the list
                printf("The pair of numbers to get \'%d\' are \'%d\' and \'%d\'.\n", sum, arr[i], number_needed);
            }
        }
        
        // Update hashtable with current element
        hashtable[arr[i]]++;
    }
    
    // Return memory allocated from heap for hash table
    free(hashtable);
    hashtable=NULL;
    
}

/*
    This algorithm is different compared to the Hashtable method, although same time complexity, this method
    saves space in comparison to Hashtable method.
 
    The idea stems from the fact that in a sorted array, the small values are on one side and the large values
    are on the other side (side depends on ascending or descending sort). Also, the sum of two numbers, usually
    involves one large number and one small number to give you the sum.
 
        Assuming list sorted in ascending order:
        Therefore, we can use two iterators, one starting at the front and one at the end of the list. At each iteration, you add the elements at front and end, if the sum is greater than desired sum, then you
            move only the iterator at the end, because you want to decrease the larger number to get the desired
            sum. If the sum of elements at the current positions of the two iterators is less than desired sum, then
            you move the iterator at the front to the next element (i.e. you want increase the smaller number). If you find two elements (one from front, the other from back) that add up to desired sum, then you move
            both iterators (one goes forward, the other goes backwards).
            This process repeated until the two iterators meet at in the middle, no more pairs.
 
    Note: The work done here is just scanning the list, partially from lower half to the middle, and partially from upper half to the midde -> therefore work done is linear.
 */
void find_pair_give_sorted_array(int *arr, int len, int sum){
    // One iterator starts at front, the other at the last element
    int i=0,j=len-1;
    while(i<j){
        // repeat until i==j, both at same element, no more pairs
        if((arr[i]+arr[j])>sum){
            // current sum greater than desired
            // move iterator at the end back, to get a smaller number
            j--;
        }else if( (arr[i]+arr[j])<sum){
            // current sum less than desired
            // move the iterator at the front ahead, to get a larger number
            i++;
        }else{
            // The current elements meet the desired sum
            printf("Numbers %d and %d = %d.\n", arr[i], arr[j], sum);
            // move i forward and j backward
            i++;
            j--;
        }
    }
}

/*
    The goal here is to show how you can find the max and min of a given list, while you scan the list.
    The idea is to use two variables to store max and min. For each iteration, you update min if the current element
    is smaller than existing min. If the current element is less than existing min it can't be greater than existing max. Therefore, you only update max, if the current element is not less than existing.
 
    Note:
        The work done is linear for all cases of arrays, i.e. not sorted, sorted in ascending order, sorted in descending order.
        But, the number of comparisons done is minimal when the list sorted in descending order, because
        in that case you only update the min each iteration.
        The most number of comparisons is done when the given list is sorted in ascending order, because
        you will check if the current element is less than current min before you check if its greater than you existing max, so two comparsions each iteration if the list is sorted in ascending order.
 
        You could put a counter to check number of comparisons for a given sorted array and unsorted array, and compare the number of comparisons done. 
 */
void find_max_min_in_single_scan(int *arr, int len){
    // Initialize min and max with first element
    int max = arr[0], min=arr[0];
    
    // scan the list and update min and max
    int i;
    for(i=0;i<len;i++){
        // check if min first
        if(arr[i]<min){
            // update min
            min = arr[i];
        }else if(arr[i]>max){
            // update max
            max = arr[i];
        }
    }
    printf("Max is: %d, Min is: %d.\n",max, min);
    
}
