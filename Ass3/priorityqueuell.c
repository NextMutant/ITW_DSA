#include <stdio.h>
#include <stdlib.h>


struct Node {
    int value;
    int priority;
    struct Node* next;
};


struct Node* newNode(int value, int priority) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->value = value;
    temp->priority = priority;
    temp->next = NULL;
    return temp;
}


void enqueue(struct Node** head, int value, int priority) {
    struct Node* temp = newNode(value, priority);

    
    if (*head == NULL || (*head)->priority < priority) {
        temp->next = *head;
        *head = temp;
    } else {
        
        struct Node* start = *head;
        while (start->next != NULL && start->next->priority >= priority) {
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }
}


int peek(struct Node* head) {
    if (head == NULL) {
        printf("Priority Queue is empty!\n");
        return -1;  
    }
    return head->value;
}


void dequeue(struct Node** head) {
    if (*head == NULL) {
        printf("Priority Queue is empty!\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("Priority Queue:\n");
    while (head != NULL) {
        printf("Value: %d, Priority: %d\n", head->value, head->priority);
        head = head->next;
    }
}


int main() {
    struct Node* pq = NULL;

    
    enqueue(&pq, 10, 1);
    enqueue(&pq, 14, 2);
    enqueue(&pq, 16, 3);
    enqueue(&pq, 12, 4);

    
    display(pq);

    
    int highest = peek(pq);
    if (highest != -1) {
        printf("\nElement with highest priority: %d\n", highest);
    }

    
    dequeue(&pq);

    
    display(pq);

    
    highest = peek(pq);
    if (highest != -1) {
        printf("\nElement with highest priority: %d\n", highest);
    }

    return 0;
}
