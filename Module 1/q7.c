// Write a C program for the multiplication of two polynomials represented using circular linked list.
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


void insertSorted(struct Node** poly, int coef, int exp) {
    if (coef == 0) return; 

    struct Node* newNode = createNode(coef, exp);
    if (*poly == NULL) {
        *poly = newNode;
        newNode->next = newNode;  
    } else {
        struct Node* temp = *poly;
        struct Node* prev = NULL;

        
        do {
            if (temp->exp == exp) { 
                temp->coef += coef; 
                free(newNode);  
                return;
            } else if (temp->exp < exp) {
                prev = temp;
                temp = temp->next;
                if (temp == *poly) break;  
            } else break;
        } while (temp != *poly);

        newNode->next = temp;
        if (prev == NULL) {
            
            struct Node* last = *poly;
            while (last->next != *poly)
                last = last->next;
            last->next = newNode;
            newNode->next = *poly;
            *poly = newNode;  
        } else {
            prev->next = newNode;
        }
    }
}


void displayPoly(struct Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    struct Node* temp = poly;
    do {
        printf("%dx^%d", temp->coef, temp->exp);
        temp = temp->next;
        if (temp != poly)
            printf(" + ");
    } while (temp != poly);
    printf("\n");
}

struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    if (poly1 == NULL || poly2 == NULL)
        return NULL;

    struct Node* temp1 = poly1;

    
    do {
        struct Node* temp2 = poly2;
        
        do {
            int newCoef = temp1->coef * temp2->coef;
            int newExp = temp1->exp + temp2->exp;

            
            insertSorted(&result, newCoef, newExp);

            temp2 = temp2->next;
        } while (temp2 != poly2);

        temp1 = temp1->next;
    } while (temp1 != poly1);

    return result;
}
int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    
    insertSorted(&poly1, 3, 2);
    insertSorted(&poly1, 5, 1);
    insertSorted(&poly1, 6, 0);

    
    insertSorted(&poly2, 4, 1);
    insertSorted(&poly2, 2, 0);

    printf("First Polynomial: ");
    displayPoly(poly1);

    printf("Second Polynomial: ");
    displayPoly(poly2);

    
    struct Node* result = multiplyPolynomials(poly1, poly2);

    printf("Resulting Polynomial after multiplication: ");
    displayPoly(result);

    return 0;
}
