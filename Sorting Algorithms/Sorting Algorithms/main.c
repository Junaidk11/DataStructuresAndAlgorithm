//
//  main.c
//  Sorting Algorithms
//
//  Created by jjkhan on 7/12/21.
//

#include <stdio.h>

// Algorithm
void mergeSort(int *arr, int leftIndex, int rightIndex);

// Test function
void print_array(int arr[], int len);
void merge_Sort(void);

int main(int argc, const char * argv[]) {
    // insert code here...
   merge_Sort();
    return 0;
}


void print_array(int arr[], int len){
    int i;
    printf("Array elements are: ");
    for(i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}

void merge_Sort(void){
    
    int arr[]={1,5,4,6,3,34,24};
    int arr2[]={0,-1,45,-10,-10,100};
    int arr3[] = {1};
    // test 1
    print_array(arr, 7);
    mergeSort(arr, 0, 6);
    print_array(arr, 7);
    
    //test 2
    print_array(arr2, 6);
    mergeSort(arr2, 0, 5);
    print_array(arr2, 6);
    
    // test 3
    print_array(arr3, 1);
    mergeSort(arr3, 0, 0);
    print_array(arr3, 1);
}


/*
    In this function, you break the given arr into two halves, sort them first,
    then merge their results.
        First subarray is arr[l..m]
        Second subarray is arr[m+1..r]
 
    The work done in this algorithm is: Breaking the arr into two halves and working
    on each half recursively so the worse case time complexity is O(logn).
 
    The space complexity of this algorithm is high because you make recursive
    calls to the same function, however, you break the workspace into two on each call,
    so the time complexity is O(logn)
 */

void merge(int *arr, int leftIndex, int midPoint, int rightIndex)
{
    // Calculate length of left and right sorted subarrays
    int i, j, k;
    int left_len = midPoint - leftIndex + 1;
    int right_len = rightIndex - midPoint;

    // Temp left and right subarrays
    int Left[left_len], Right[right_len];

    // Copy data over to the temp arrays
    for (i = 0; i < left_len; i++)
        Left[i] = arr[leftIndex + i];
    for (j = 0; j < right_len; j++)
        Right[j] = arr[midPoint + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = leftIndex; // Initial index of merged subarray
    while (i < left_len && j < right_len) {
        if (Left[i] <= Right[j]) {
            arr[k] = Left[i];
            i++;
        }
        else {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }
    
   // One of the arrays reached end
   // Copy remaing elements over
    while (i < left_len) {
        arr[k] = Left[i];
        i++;
        k++;
    }

    while (j < right_len) {
        arr[k] = Right[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int *arr, int leftIndex, int rightIndex)
{
    if (leftIndex < rightIndex) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int midpoint = leftIndex + (rightIndex - leftIndex) / 2;

        // Sort first and second halves
        mergeSort(arr, leftIndex, midpoint);
        mergeSort(arr, midpoint + 1, rightIndex);
        // Merge the two sorted subarrays
        merge(arr, leftIndex, midpoint, rightIndex);
    }
}
