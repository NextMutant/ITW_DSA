#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    float coeff;
    int expo;
    struct node *next;
}node;

node *insert(node *head,int co,int ex){
    node *temp;
    node *ptr = malloc(sizeof(node));
    ptr->coeff = co;
    ptr->expo = ex;
    ptr->next = NULL;
    if(head==NULL || ex>head->expo){
        ptr->next = head;
        head = ptr;
    }
    else{
        node *temp1;
        temp = head;
        while(temp!=NULL && temp->expo > ex){
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = ptr;
        ptr->next = temp;
    }
    return head;
}

node *create(node *head){
    int ex;
    float co;
    int n;
    printf("Enter no. of node you want to insert\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter coefficient of given node\n");
        scanf("%f",&co);
        printf("Enter exponential of given node\n");
        scanf("%d",&ex);
        head = insert(head,co,ex);
    }
    return head;
}

int main(){
    node *head = NULL;
    head = create(head);
     node *temp = head;
    while (temp != NULL) {
        printf("%f x^%d", temp->coeff, temp->expo);
        temp = temp->next;
        if (temp != NULL) {
            printf(" + ");
        }
    }

}