#include <stdio.h>
#include <stdlib.h>

// Structure for polynomial node
struct poly {
    int data;  // Coefficient
    int power; // Exponent
    struct poly *prev;
    struct poly *next;
};

// Function to create a new term in the polynomial
struct poly *create(struct poly *head, int term) {
    struct poly *p = (struct poly *)malloc(sizeof(struct poly));
    printf("Enter the coefficient of term %d: ", term);
    scanf("%d", &p->data);
    printf("Enter the power of term %d: ", term);
    scanf("%d", &p->power);
    p->prev = NULL;
    p->next = NULL;

    if (head == NULL) {
        return p;
    } else {
        struct poly *q = head;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
        p->prev = q;
        return head;
    }
}

// Function to display the polynomial
void display(struct poly *head) {
    if (head == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }

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

// Function to subtract two polynomials
struct poly *subtraction(struct poly *head1, struct poly *head2) {
    struct poly *p = head1;
    struct poly *q = head2;
    struct poly *result = NULL;

    while (p != NULL && q != NULL) {
        if (p->power == q->power) {
            int coeff = p->data - q->data;
            if (coeff != 0) {
                result = create(result, 0);
                result->data = coeff;
                result->power = p->power;
            }
            p = p->next;
            q = q->next;
        } else if (p->power > q->power) {
            result = create(result, 0);
            result->data = p->data;
            result->power = p->power;
            p = p->next;
        } else {
            result = create(result, 0);
            result->data = -q->data;
            result->power = q->power;
            q = q->next;
        }
    }

    while (p != NULL) {
        result = create(result, 0);
        result->data = p->data;
        result->power = p->power;
        p = p->next;
    }

    while (q != NULL) {
        result = create(result, 0);
        result->data = -q->data;
        result->power = q->power;
        q = q->next;
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

    struct poly *result = subtraction(head1, head2);
    printf("Resultant Polynomial after Subtraction: ");
    display(result);

    return 0;
}
