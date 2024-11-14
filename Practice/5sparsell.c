#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int row, col, data;
    struct node *next;
} node;

node* insert(node *head, int row, int col, int data) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->row = row;
    newNode->col = col;
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

node* create(int row, int col, int arr[row][col]) {
    node *head = NULL;

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(arr[i][j] != 0) {
                head = insert(head, i, j, arr[i][j]);
            }
        }
    }

    return head;
}

void printSparseMatrix(node *head) {
    node *temp = head;
    printf("Row\tCol\tValue\n");
    while(temp != NULL) {
        printf("%d\t%d\t%d\n", temp->row, temp->col, temp->data);
        temp = temp->next;
    }
}

int main() {
    int rows = 4, cols = 5;
    int arr[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    node *sparseMatrix = create(rows, cols, arr);
    printSparseMatrix(sparseMatrix);

    return 0;
}