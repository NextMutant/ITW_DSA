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


void addition(struct poly *head, int term2) {
    struct poly *temp = head;

    
    for (int i = 1; i <= term2; i++) {
        int coeff, pow;
        printf("Enter the coefficient of term %d: ", i);
        scanf("%d", &coeff);
        printf("Enter the power of term %d: ", i);
        scanf("%d", &pow);

        
        struct poly *prev = NULL;
        temp = head;
        while (temp != NULL && temp->power > pow) {
            prev = temp;
            temp = temp->next;
        }

        if (temp != NULL && temp->power == pow) {
            
            temp->data += coeff;
        } else {
            
            struct poly *new_term = (struct poly *)malloc(sizeof(struct poly));
            new_term->data = coeff;
            new_term->power = pow;
            new_term->next = temp;

            if (prev == NULL) {
                head = new_term;  
            } else {
                prev->next = new_term;  
            }
        }
    }

    
    printf("Resultant Polynomial after Addition: ");
    display(head);
}

int main() {
    int n1, n2;
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);

    struct poly *head1 = NULL;

    
    for (int i = 0; i < n1; i++) {
        head1 = create(head1, i + 1);
    }

    
    printf("First Polynomial: ");
    display(head1);

    
    addition(head1, n2);

    return 0;
}
