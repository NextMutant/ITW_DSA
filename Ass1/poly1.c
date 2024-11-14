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

struct poly *addition(struct poly *head1, struct poly *head2) {
    struct poly *p = head1;
    struct poly *q = head2;
    struct poly *head = NULL;
    struct poly *new = NULL;

    // Copy the first polynomial
    while (p != NULL) {
        struct poly *new1 = (struct poly *)malloc(sizeof(struct poly));
        new1->data = p->data;
        new1->power = p->power;
        new1->next = NULL;
        if (new == NULL) {
            head = new1;
            new = new1;
        } else {
            new->next = new1;
            new = new->next;
        }
        p = p->next;
    }

    // Add the second polynomial
    while (q != NULL) {
        struct poly *temp = head;
        int found = 0;
        while (temp != NULL) {
            if (temp->power == q->power) {
                temp->data += q->data;
                found = 1;
                break;
            }
            temp = temp->next;
        }
        if (!found) {
            struct poly *new1 = (struct poly *)malloc(sizeof(struct poly));
            new1->data = q->data;
            new1->power = q->power;
            new1->next = NULL;
            if (new == NULL) {
                head = new1;
                new = new1;
            } else {
                new->next = new1;
                new = new->next;
            }
        }
        q = q->next;
    }

    // Sort the polynomial in decreasing order of power
    struct poly *temp1 = head;
    struct poly *temp2;
    while (temp1 != NULL) {
        temp2 = temp1->next;
        while (temp2 != NULL) {
            if (temp1->power < temp2->power) {
                int tempData = temp1->data;
                int tempPower = temp1->power;
                temp1->data = temp2->data;
                temp1->power = temp2->power;
                temp2->data = tempData;
                temp2->power = tempPower;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    return head;
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
