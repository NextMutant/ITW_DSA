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
    p->next = NULL;

    if (head == NULL) {
        return p;
    } else {
        struct poly *q = head;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
        return head;
    }
}

void display(struct poly *head) {
    struct poly *temp = head;
    while (temp != NULL) {
        if (temp->power == 0) {
            printf("%d", temp->data);
        } else {
            printf("%dx^%d", temp->data, temp->power);
        }
        temp = temp->next;
        if (temp != NULL && temp->data >= 0) {
            printf(" + ");
        }
    }
    printf("\n");
}

struct poly *add_term(struct poly *head, int coeff, int power) {
    struct poly *new_term = (struct poly *)malloc(sizeof(struct poly));
    new_term->data = coeff;
    new_term->power = power;
    new_term->next = NULL;

    if (head == NULL) {
        return new_term;
    }

    struct poly *temp = head;
    struct poly *prev = NULL;

    // Find the correct position to insert the new term (sorted by power)
    while (temp != NULL && temp->power > power) {
        prev = temp;
        temp = temp->next;
    }

    // If the power already exists, just add the coefficients
    if (temp != NULL && temp->power == power) {
        temp->data += coeff;
        free(new_term); // no need to create a new node, so free it
    } else {
        // Insert the new term in the list
        if (prev == NULL) { // Insert at the beginning
            new_term->next = head;
            head = new_term;
        } else { // Insert between prev and temp
            prev->next = new_term;
            new_term->next = temp;
        }
    }

    return head;
}

struct poly *multiplication(struct poly *head1, struct poly *head2) {
    struct poly *p = head1;
    struct poly *result = NULL;

    while (p != NULL) {
        struct poly *q = head2;
        while (q != NULL) {
            int coeff = p->data * q->data;
            int power = p->power + q->power;
            result = add_term(result, coeff, power);
            q = q->next;
        }
        p = p->next;
    }

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

    struct poly *result = multiplication(head1, head2);
    printf("Resultant Polynomial after Multiplication: ");
    display(result);

    return 0;
}
