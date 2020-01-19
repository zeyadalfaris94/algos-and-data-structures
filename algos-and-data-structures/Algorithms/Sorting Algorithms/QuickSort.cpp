#include <bits/stdc++.h>
using namespace std;

/*
    Quick Sort Algorithm
*/


/*
    Overall Time Complexity Worst Case: O(n^2)
    Best/Average Case: O(n lg(n))

    Space Complexity: Auxiliary Space complexity is O(n log(n)) => call stack
*/

int partition(int arr[], int start, int end){


    /*
    Getting the best pivot can be done by choosing the
    median of the array
    Here I chose the end of the interval as my pivot;
    */
    int pivot = arr[end];
    int pIndex = start;

    for(int i = start; i < end; i++){
        if(arr[i] <= pivot){
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }

    swap(arr[end],arr[pIndex]);

    return pIndex;

}

void quickSort(int arr[], int start, int end){
    if(start<end){

        int pIndex = partition( arr, start, end);

        quickSort(arr,start, pIndex-1);
        quickSort(arr, pIndex+1, end);
    }
}


void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{

    int arr[] = {4,3,1,2,0,-2};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int temp[arr_size];

    printf("Given array is \n");
    printArray(arr, arr_size);

    quickSort(arr, 0, arr_size-1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);

    return 0;
}
