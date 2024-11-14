#include <stdio.h>
#include <limits.h>

#define MAX 100  // Maximum size of the priority queue

// Structure to store elements with their priorities
struct item {
    int value;
    int priority;
};

// Array to store the priority queue elements
struct item arr[MAX];
int size = -1;  // Initialize size to -1 to indicate the queue is empty

// Function to insert an element into the priority queue
void enqueue(int value, int priority) {
    if (size == MAX - 1) {
        printf("Priority Queue is full!\n");
        return;
    }

    // Increase size and insert the element
    size++;
    arr[size].value = value;
    arr[size].priority = priority;
}

// Function to find the index of the element with the highest priority
int peek() {
    int highestPriority = INT_MIN;
    int ind = -1;

    // Loop through the queue to find the highest priority element
    for (int i = 0; i <= size; i++) {
        if (arr[i].priority > highestPriority) {
            highestPriority = arr[i].priority;
            ind = i;
        } else if (arr[i].priority == highestPriority) {
            if (arr[i].value > arr[ind].value) {
                ind = i;
            }
        }
    }

    return ind;
}

// Function to remove the element with the highest priority
void dequeue() {
    if (size == -1) {
        printf("Priority Queue is empty!\n");
        return;
    }

    int ind = peek();

    // Shift elements to the left after removing the highest priority element
    for (int i = ind; i < size; i++) {
        arr[i] = arr[i + 1];
    }

    size--;  // Decrease size of the queue
}

// Function to display the priority queue
void display() {
    if (size == -1) {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("Priority Queue:\n");
    for (int i = 0; i <= size; i++) {
        printf("Value: %d, Priority: %d\n", arr[i].value, arr[i].priority);
    }
}

// Main function to demonstrate the priority queue operations
int main() {
    enqueue(10, 1);
    enqueue(14, 2);
    enqueue(16, 3);
    enqueue(12, 4);

    display();

    int ind = peek();
    printf("\nElement with highest priority: %d\n", arr[ind].value);

    dequeue();
    
    display();
    int ind2 = peek();
    printf("\nElement with highest priority: %d\n", arr[ind2].value);

    return 0;
}
