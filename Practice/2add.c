#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    int coeff;
    struct node *next;
} node;

node *insert(node *head, int expo, int num) {
    node *ptr = malloc(sizeof(node));
    ptr->coeff = expo;
    ptr->data = num;
    ptr->next = NULL;
    
    if (head == NULL || expo > head->coeff) {
        ptr->next = head;
        head = ptr;
    } else {
        node *prev = head;
        node *temp = head->next;

        while (temp != NULL && temp->coeff > expo) {
            prev = temp;
            temp = temp->next;
        }

        ptr->next = temp;
        prev->next = ptr;
    }
    return head;
}

node *create(node *head) {
    int n;
    int expo;
    int data1;
    printf("Enter number of terms:");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("Enter coeff of term %d:",i);
        scanf("%d", &data1);
        printf("Enter exponent of term %d:",i);
        scanf("%d", &expo);
        head = insert(head, expo, data1);
    }
    return head;
}

node *add(node *head1, node *head2) {
    node *temp1 = head1;
    node *temp2 = head2;
    node *head = NULL;

    while (temp1!= NULL && temp2!= NULL) {
        if (temp1->coeff == temp2->coeff) {
            int num = temp1->data + temp2->data;
            head = insert(head, temp1->coeff, num);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->coeff > temp2->coeff) {
            head = insert(head, temp1->coeff, temp1->data);
            temp1 = temp1->next;
        } else {
            head = insert(head, temp2->coeff, temp2->data);
            temp2 = temp2->next;
        }
    }

    while (temp1!= NULL) {
        head = insert(head, temp1->coeff, temp1->data);
        temp1 = temp1->next;
    }

    while (temp2!= NULL) {
        head = insert(head, temp2->coeff, temp2->data);
        temp2 = temp2->next;
    }

    return head;
}

int main() {
    node *head1 = NULL;
    node *head2 = NULL;
    
    head1 = create(head1);
    
head2 = create(head2);
    
    node *head3 = add(head1, head2);
    
    node *temp = head3;
    while (temp != NULL) {
        printf("%d x^%d", temp->data, temp->coeff);
        temp = temp->next;
        if (temp != NULL) {
            printf(" + ");
        }
    }

    return 0;
}