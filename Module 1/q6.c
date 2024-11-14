//  Write a C program for the addition of two 2-variable Polynomials. The polynomials are stored in the
// circular linked lists.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;            
    int exp_x;           
    int exp_y;           
    struct Node* next;   
};

struct Node* createNode(int coef, int exp_x, int exp_y) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coef = coef;
    newNode->exp_x = exp_x;
    newNode->exp_y = exp_y;
    newNode->next = newNode;  
    return newNode;
}


void insertEnd(struct Node** poly, int coef, int exp_x, int exp_y) {
    struct Node* newNode = createNode(coef, exp_x, exp_y);
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        while (temp->next != *poly)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = *poly;  
    }
}


void displayPoly(struct Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    struct Node* temp = poly;
    do {
        printf("%dx^%dy^%d", temp->coef, temp->exp_x, temp->exp_y);
        temp = temp->next;
        if (temp != poly)
            printf(" + ");
    } while (temp != poly);
    printf("\n");
}

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node *temp1 = poly1, *temp2 = poly2;


    do {
        insertEnd(&result, temp1->coef, temp1->exp_x, temp1->exp_y);
        temp1 = temp1->next;
    } while (temp1 != poly1);

   
    do {
        struct Node* current = result;
        int found = 0;

        
        do {
            if (current->exp_x == temp2->exp_x && current->exp_y == temp2->exp_y) {
                current->coef += temp2->coef;  
                found = 1;
                break;
            }
            current = current->next;
        } while (current != result);

        
        if (!found)
            insertEnd(&result, temp2->coef, temp2->exp_x, temp2->exp_y);

        temp2 = temp2->next;
    } while (temp2 != poly2);

    return result;
}
int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    
    insertEnd(&poly1, 3, 2, 1);
    insertEnd(&poly1, 2, 1, 2);
    insertEnd(&poly1, 5, 0, 0);

    
    insertEnd(&poly2, 4, 2, 1);
    insertEnd(&poly2, 3, 1, 2);
    insertEnd(&poly2, 1, 0, 0);

    printf("First Polynomial: ");
    displayPoly(poly1);

    printf("Second Polynomial: ");
    displayPoly(poly2);

    
    struct Node* result = addPolynomials(poly1, poly2);

    printf("Resulting Polynomial after addition: ");
    displayPoly(result);

    return 0;
}
