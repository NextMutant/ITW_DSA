#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int findMax(struct Node* head) {
    int max = head->data;
    struct Node* temp = head->next;
    while (temp != NULL) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}


int getTotalDigits(int max) {
    int digits = 0;
    while (max != 0) {
        digits++;
        max /= 10;
    }
    return digits;
}


void radixSort(struct Node** head, int totalDigits) {
    struct Node* output = NULL;
    struct Node* count[10];
    for (int i = 0; i < 10; i++) {
        count[i] = NULL;
    }
    
    int exp = 1;
    for (int i = 0; i < totalDigits; i++) {
        struct Node* temp = *head;

        
        while (temp != NULL) {
            int digit = (temp->data / exp) % 10;
            if (count[digit] == NULL) {
                count[digit] = createNode(temp->data);
            } else {
                struct Node* tempCount = count[digit];
                while (tempCount->next != NULL) {
                    tempCount = tempCount->next;
                }
                tempCount->next = createNode(temp->data);
            }
            temp = temp->next;
        }

        
        struct Node* prevOutput = output;
        output = NULL;
        for (int j = 0; j < 10; j++) {
            if (count[j] != NULL) {
                if (output == NULL) {
                    output = count[j];
                } else {
                    struct Node* tempOutput = output;
                    while (tempOutput->next != NULL) {
                        tempOutput = tempOutput->next;
                    }
                    tempOutput->next = count[j];
                }
                count[j] = NULL;
            }
        }

        
        *head = output;
        exp *= 10;
        display(*head);
    }
}


void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main() {
    printf("Enter the number of total digits: ");
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int num;
        printf("Enter the %d number: ", i + 1);
        scanf("%d", &num);
        append(&head, num);
    }

    int max = findMax(head);
    int totalDigits = getTotalDigits(max);
    
    radixSort(&head, totalDigits);

    return 0;
}