// 1.	Write a C program for addition of two polynomials represented using circular linked list.
#include <stdio.h>
#include <stdlib.h>

struct poly {
    int data;
    int power;
    struct poly *next;
};

struct poly *create(struct poly *head, int term) {
    struct poly *p = (struct poly *)malloc(sizeof(struct poly));
    printf("Enter the coefficient of term %d: ", term);
    scanf("%d", &p->data);
    printf("Enter the power of term %d: ", term);
    scanf("%d", &p->power);
    p->next = p;  // Initially points to itself

    if (head == NULL) {
        return p;
    } else {
        struct poly *q = head;
        while (q->next != head) {
            q = q->next;
        }
        q->next = p;
        p->next = head;
        return head;
    }
}

void display(struct poly *head) {
    if (head == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }

    struct poly *temp = head;
    do {
        if (temp->power == 0) {
            printf("%d", temp->data);
        } else {
            printf("%dx^%d", temp->data, temp->power);
        }
        temp = temp->next;
        if (temp != head && temp->data >= 0) {
            printf(" + ");
        }
    } while (temp != head);
    printf("\n");
}

struct poly *add_term(struct poly *head, int coeff, int power) {
    struct poly *new_term = (struct poly *)malloc(sizeof(struct poly));
    new_term->data = coeff;
    new_term->power = power;

    if (head == NULL) {
        new_term->next = new_term;  // Circular link
        return new_term;
    }

    struct poly *temp = head;
    struct poly *prev = NULL;

    do {
        if (temp->power == power) {
            temp->data += coeff;
            free(new_term);
            return head;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    // Insert at the end
    prev->next = new_term;
    new_term->next = head;

    // Ensure the list is sorted by power in descending order
    if (head->power < new_term->power) {
        struct poly *new_head = new_term;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = new_head;
        return new_head;
    }

    return head;
}

struct poly *addition(struct poly *head1, struct poly *head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct poly *result = NULL;
    struct poly *p = head1;

    // Add terms from the first polynomial to the result
    do {
        result = add_term(result, p->data, p->power);
        p = p->next;
    } while (p != head1);

    p = head2;
    // Add terms from the second polynomial to the result
    do {
        result = add_term(result, p->data, p->power);
        p = p->next;
    } while (p != head2);

    return result;
}

int main() {
    int n1, n2;
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);

    struct poly *head1 = NULL;
    struct poly *head2 = NULL;

    for (int i = 0; i < n1; i++) {
        head1 = create(head1, i + 1);
    }

    for (int i = 0; i < n2; i++) {
        head2 = create(head2, i + 1);
    }

    printf("First Polynomial: ");
    display(head1);
    printf("Second Polynomial: ");
    display(head2);

    struct poly *result = addition(head1, head2);
    printf("Resultant Polynomial after Addition: ");
    display(result);

    return 0;
}
