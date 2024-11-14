// Write a C program for the evaluation a polynomial for some real value of x stored in a doubly
// circular linked list.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int coef;           
    int exp;            
    struct Node* next;  
    struct Node* prev;  
};

struct Node* createNode(int coef, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = newNode->prev = newNode;  
    return newNode;
}


void insertEnd(struct Node** poly, int coef, int exp) {
    struct Node* newNode = createNode(coef, exp);
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node* last = (*poly)->prev;

        newNode->next = *poly;
        (*poly)->prev = newNode;
        newNode->prev = last;
        last->next = newNode;
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
double evaluatePolynomial(struct Node* poly, double x) {
    double result = 0.0;
    struct Node* temp = poly;

    if (poly == NULL) return result;

    do {
        result += temp->coef * pow(x, temp->exp);  // Calculate term value
        temp = temp->next;
    } while (temp != poly);

    return result;
}
int main() {
    struct Node* poly = NULL;
    double x, result;

    
    insertEnd(&poly, 3, 2);
    insertEnd(&poly, 5, 1);
    insertEnd(&poly, 6, 0);

    printf("Polynomial: ");
    displayPoly(poly);

    
    printf("Enter the value of x: ");
    scanf("%lf", &x);

    
    result = evaluatePolynomial(poly, x);
    printf("Result after evaluating polynomial at x = %.2lf: %.2lf\n", x, result);

    return 0;
}
