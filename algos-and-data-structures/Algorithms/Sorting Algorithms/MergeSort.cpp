#include <bits/stdc++.h>
using namespace std;

void merge(int arr[],int temp[], int leftStart, int rightEnd)
{

    int leftEnd = (rightEnd+leftStart)/2;
    int rightStart = leftEnd+1;

    int left = leftStart;
    int right = rightStart;
    int index = leftStart;

    while(left<=leftEnd && right<=rightEnd){
        if(arr[left] <= arr[right]){
            temp[index] = arr[left];
            left++;
        }
        else{
            temp[index] = arr[right];
            right++;
        }
        index++;
    }

    while(left<=leftEnd){
        temp[index] = arr[left];
        left++;
        index++;
    }

    while(right<=rightEnd){
        temp[index] = arr[right];
        right++;
        index++;
    }

    for(int i=leftStart; i<=rightEnd;i++){
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int temp[], int leftStart, int rightEnd)
{
    if(leftStart>=rightEnd)
        return;

    int middle = (leftStart+rightEnd)/2;

    mergeSort(arr,temp,leftStart,middle);
    mergeSort(arr,temp,middle+1,rightEnd);

    merge(arr,temp,leftStart,rightEnd);
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

    int arr[] = {15, 12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int temp[arr_size];

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, temp, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(temp, arr_size);

    return 0;
}
