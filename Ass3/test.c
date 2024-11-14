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
    if (*head==NULL ||(*head)->priority<priority){
        
    }
}
    















//     if (*head == NULL || (*head)->priority < priority) {
//         temp->next = *head;
//         *head = temp;
//     } else {
      
//         struct Node* start = *head;
//         while (start->next != NULL && start->next->priority >= priority) {
//             start = start->next;
//         }
//         temp->next = start->next;
//         start->next = temp;
//     }
// }