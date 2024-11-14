#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtBeginning(struct Node *head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

struct Node* addLinkedLists(struct Node* l1, struct Node* l2) {
    struct Node* result = NULL;
    int carry = 0;

    
     while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        
        if (l1 != NULL) {
            sum += l1->data;
            l1 = l1->next;
        }
        
        if (l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }
        
        carry = sum / 10;
        sum = sum % 10;

        
        result = insertAtBeginning(result, sum);
    }

    return result;
}

void printLinkedList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* stringToLinkedList(char *num) {
    struct Node* head = NULL;
    int len = strlen(num);

    
    for (int i = 0; i < len; i++) {
        head = insertAtBeginning(head, num[i] - '0');
    }

    return head;
}


int main(){


    char n1[2048],n2[2048];
    printf("Enter the first num:");
    scanf("%s",&n1);
    printf("Enter the sec num:");
    scanf("%s",&n2);

    struct Node* head1 = stringToLinkedList(n1);
    struct Node* head2 = stringToLinkedList(n2);

    
    struct Node* result = addLinkedLists(head1, head2);

    
    printf("Sum: ");
    printLinkedList(result);

    return 0;
}