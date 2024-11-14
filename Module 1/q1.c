#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;           
    int exp;            
    struct Node* next;  
};

struct Node* createNode(int coef, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = newNode;  
    return newNode;
}


void insertEnd(struct Node** poly, int coef, int exp) {
    struct Node* newNode = createNode(coef, exp);
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
    struct Node* temp = poly;
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    do {
        printf("%dx^%d", temp->coef, temp->exp);
        temp = temp->next;
        if (temp != poly)
            printf(" + ");
    } while (temp != poly);
    printf("\n");
}
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node *result = NULL, *p1 = poly1, *p2 = poly2;

    
    do {
        if (p1->exp == p2->exp) {
            
            insertEnd(&result, p1->coef + p2->coef, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            
            insertEnd(&result, p1->coef, p1->exp);
            p1 = p1->next;
        } else {
            
            insertEnd(&result, p2->coef, p2->exp);
            p2 = p2->next;
        }
    } while (p1 != poly1 && p2 != poly2);

    
    while (p1 != poly1) {
        insertEnd(&result, p1->coef, p1->exp);
        p1 = p1->next;
    }
    while (p2 != poly2) {
        insertEnd(&result, p2->coef, p2->exp);
        p2 = p2->next;
    }
    return result;
}
int main() {
    struct Node *poly1 = NULL, *poly2 = NULL;

    
    insertEnd(&poly1, 3, 2);
    insertEnd(&poly1, 5, 1);
    insertEnd(&poly1, 6, 0);

    
    insertEnd(&poly2, 4, 2);
    insertEnd(&poly2, 2, 1);
    insertEnd(&poly2, 1, 0);

    printf("Polynomial 1: ");
    displayPoly(poly1);

    printf("Polynomial 2: ");
    displayPoly(poly2);

    struct Node* result = addPolynomials(poly1, poly2);
    printf("Resultant Polynomial: ");
    displayPoly(result);

    return 0;
}
