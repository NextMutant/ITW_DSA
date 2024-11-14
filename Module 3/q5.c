// 5.	Write a C program for sorting an array in descending order using heap sort. 
#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int smallest = i;           
    int left = 2 * i + 1;      
    int right = 2 * i + 2;      

    
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    
    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;

        
        heapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}


void heapSort(int arr[], int n) {
    
    buildMinHeap(arr, n);

    
    for (int i = n - 1; i > 0; i--) {
       
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        
        heapify(arr, i, 0);
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};  
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    
    heapSort(arr, n);

    printf("Sorted array in descending order: ");
    printArray(arr, n);

    return 0;
}
