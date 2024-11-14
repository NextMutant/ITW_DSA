// Write a C program for the removing all the terms with odd coefficients from a single variable
// polynomial stored in a doubly linked list.
#include <stdio.h>
#include <stdlib.h>

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
    newNode->next = newNode->prev = NULL;
    return newNode;
}


void insertEnd(struct Node** poly, int coef, int exp) {
    struct Node* newNode = createNode(coef, exp);
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}


void displayPoly(struct Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    struct Node* temp = poly;
    while (temp != NULL) {
        printf("%dx^%d", temp->coef, temp->exp);
        temp = temp->next;
        if (temp != NULL)
            printf(" + ");
    }
    printf("\n");
}
void removeOddCoefficients(struct Node** poly) {
    struct Node* current = *poly;

    while (current != NULL) {
        struct Node* nextNode = current->next;

        
        if (current->coef % 2 != 0) {
            
            if (current->prev != NULL)
                current->prev->next = current->next;
            else
                *poly = current->next;  

            if (current->next != NULL)
                current->next->prev = current->prev;

            free(current); 
        }
        current = nextNode;
    }
}
int main() {
    struct Node* poly = NULL;

 
    insertEnd(&poly, 4, 3);
    insertEnd(&poly, 3, 2);
    insertEnd(&poly, 5, 1);
    insertEnd(&poly, 6, 0);

    printf("Original Polynomial: ");
    displayPoly(poly);

   
    removeOddCoefficients(&poly);

    printf("Polynomial after removing terms with odd coefficients: ");
    displayPoly(poly);

    return 0;
}


