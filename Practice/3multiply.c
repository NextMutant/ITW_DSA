#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int expo;
    int coeff;
    struct node *next;
} node;

node *insert(node *head, int coeff, int expo) {
    node *ptr = malloc(sizeof(node));
    ptr->coeff = coeff;
    ptr->expo = expo;
    ptr->next = NULL;
    
    if (head == NULL || expo > head->expo) {
        ptr->next = head;
        head = ptr;
    } else {
        node *prev = head;
        node *temp = head->next;

        while (temp != NULL && temp->expo > expo) {
            prev = temp;
            temp = temp->next;
        }

        if (temp != NULL && temp->expo == expo) {
            temp->coeff += coeff;  
            free(ptr);
        } else {
            ptr->next = temp;
            prev->next = ptr;
        }
    }
    return head;
}

node *create(node *head) {
    int n;
    int expo;
    int coeff;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("Enter coeff of term %d: ", i);
        scanf("%d", &coeff);
        printf("Enter exponent of term %d: ", i);
        scanf("%d", &expo);
        head = insert(head, coeff, expo);
    }
    return head;
}

node *multiply(node *head1, node *head2) {
    node *temp1 = head1;
    node *head = NULL;
    
    while (temp1 != NULL) {
        node *temp2 = head2;
        while (temp2 != NULL) {
            int coeff = temp1->coeff * temp2->coeff;
            int expo = temp1->expo + temp2->expo;
            head = insert(head, coeff, expo);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return head;
}



int main() {
    node *head1 = NULL;
    node *head2 = NULL;
    
    printf("First polynomial:");
    head1 = create(head1);
    
    printf("Second polynomial:");
    head2 = create(head2);
    
    node *head3 = multiply(head1, head2);
    
    printf("Resultant polynomial after multiplication:\n");
    node *temp = head3;
    while (temp != NULL) {
        printf("%d x^%d", temp->coeff, temp->expo);
        temp = temp->next;
        if (temp != NULL) {
            printf(" + ");
        }
    }

    return 0;
}
