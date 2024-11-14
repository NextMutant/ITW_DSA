// Write a C program for the removing all the terms with even exponents from a single variable
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
void removeEvenExponents(struct Node** poly) {
    if (*poly == NULL)
        return;

    struct Node *current = *poly, *prev = NULL;

    
    do {
        struct Node* nextNode = current->next;

      
        if (current->exp % 2 == 0) {
            
            if (current == *poly) {  
                struct Node* last = *poly;
                while (last->next != *poly)
                    last = last->next;
                
                
                last->next = current->next;
                *poly = current->next;
                free(current);
                current = *poly;

                
                if (current == last) {
                    free(current);
                    *poly = NULL;
                    return;
                }
            } else {
                
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else {
            prev = current;
            current = nextNode;
        }
    } while (current != *poly && *poly != NULL);
}

int main() {
    struct Node* poly = NULL;

    
    insertEnd(&poly, 4, 3);
    insertEnd(&poly, 3, 2);
    insertEnd(&poly, 5, 1);
    insertEnd(&poly, 6, 0);

    printf("Original Polynomial: ");
    displayPoly(poly);

    removeEvenExponents(&poly);

    printf("Polynomial after removing terms with even exponents: ");
    displayPoly(poly);

    return 0;
}
