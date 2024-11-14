// 2.	Write a C program for construction of min heap using heapify algorithm.
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

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[] = {10, 15, 30, 40, 50, 100, 40};  
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    
    buildMinHeap(arr, n);

    printf("Min-Heap array: ");
    printArray(arr, n);

    return 0;
}
