#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to find the maximum value in the linked list
int maximum(struct Node* head) {
    int max = INT_MIN;
    struct Node* temp = head;
    while (temp != NULL) {
        if (max < temp->data) {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

// Function to perform counting sort based on a specific digit
void countSortForRadix(struct Node** headRef, int exp) {
    struct Node* output = NULL;
    struct Node* temp = *headRef;
    int count[10] = {0}; // Count array to store count of occurrences
    struct Node* nodes[10] = {NULL}; // Array of pointers to linked lists for each digit

    // Store count of occurrences of each digit and create a linked list for each digit
    while (temp != NULL) {
        int index = (temp->data / exp) % 10;
        count[index]++;
        
        // Create a new node for the current element
        struct Node* newNode = createNode(temp->data);
        newNode->next = nodes[index];
        nodes[index] = newNode;

        temp = temp->next;
    }

    // Build the output linked list from nodes array
    for (int i = 9; i >= 0; i--) {
        if (nodes[i] != NULL) {
            struct Node* tempNode = nodes[i];
            while (tempNode->next != NULL) {
                tempNode = tempNode->next;
            }
            tempNode->next = output;
            output = nodes[i];
        }
    }

    // Set the head reference to the sorted list
    *headRef = output;
}

// Function to perform Radix Sort on a linked list
void radixSort(struct Node** headRef) {
    int max = maximum(*headRef);

    // Do counting sort for every digit. Note that instead of passing the digit number, exp is passed. exp is 10^i where i is the current digit number
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSortForRadix(headRef, exp);
    }
}

// Function to append a node at the end of the linked list
void appendNode(struct Node** headRef, int newData) {
    struct Node* newNode = createNode(newData);
    struct Node* last = *headRef;
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

int main() {
    struct Node* head = NULL;
    int n, data;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    printf("Enter the elements of the list: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        appendNode(&head, data);
    }

    printf("Original List is: ");
    printList(head);

    radixSort(&head);

    printf("Sorted List is: ");
    printList(head);

    return 0;
}
