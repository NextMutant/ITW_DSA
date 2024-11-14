
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

// Function to print the array
void printArray(int *A, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Function to get the maximum value in an array
int maximum(int A[], int n) {
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (max < A[i]) {
            max = A[i];
        }
    }
    return max;
}

// Function to perform counting sort based on a specific digit
void countSortForRadix(int *A, int n, int exp) {
    int *output = (int *)malloc(n * sizeof(int)); // Output array
    int count[10] = {0}; // Count array to store count of occurrences

    // Store count of occurrences of each digit
    for (int i = 0; i < n; i++) {
        count[(A[i] / exp) % 10]++;
    }

    // Change count[i] so that it now contains actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(A[i] / exp) % 10] - 1] = A[i];
        count[(A[i] / exp) % 10]--;
    }

    // Copy the output array to A[], so that A[] now contains sorted numbers according to the current digit
    for (int i = 0; i < n; i++) {
        A[i] = output[i];
    }

    free(output);
}

// Function to perform Radix Sort
void radixSort(int *A, int n) {
    int max = maximum(A, n);

    // Do counting sort for every digit. Note that instead of passing the digit number, exp is passed. exp is 10^i where i is the current digit number
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSortForRadix(A, n, exp);
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int A[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    printf("Original Array is: ");
    printArray(A, n);

    radixSort(A, n);

    printf("Sorted Array is: ");
    printArray(A, n);
    return 0;
}
