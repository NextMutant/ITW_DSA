#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

node* createReversedLinkedList(node* head) {
    node *temp = NULL;       
    node *temp1 = head;      
    node *temp2;             

    while (temp1 != NULL) {
        temp2 = temp1->next; 
        temp1->next = temp;  
        temp = temp1;        
        temp1 = temp2;       
    }

    return temp;             
}


node *insert(node *head,int num){
    node *temp;
    node *temp1;
    node *ptr = malloc(sizeof(node));
    ptr->data = num;
    ptr->next = NULL;
    if(head==NULL){
        ptr->next = head;
        head = ptr;
    }
    else{
        temp = head;
        while(temp->next!=NULL){
            temp1 = temp;
            temp = temp->next;
        }
        temp->next = ptr;
    }
    return head;
}

node *add(node *head1,node *head2){
    node *head = NULL;
    node *temp1 = createReversedLinkedList(head1);
    node *temp2 = createReversedLinkedList(head2);
    int carry = 0;
    while(temp1!=NULL && temp2!=NULL){
        int sum=temp1->data+temp2->data+carry;
        int num=sum%10;
        head=insert(head,num);
        carry=sum/10;
        temp1=temp1->next;
        temp2=temp2->next;

    }
    while(temp1!=NULL){
        int sum=temp1->data + carry;
        int num=sum%10;
        head=insert(head,num);
        carry=sum/10;
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        int sum=temp2->data + carry;
        int num=sum%10;
        head=insert(head,num);
        carry=sum/10;
        temp2=temp2->next;
    }
    
    
    if(carry>0) head = insert(head,carry);
    return head;
    
}

node *create(node *head){
    int data1;
    int n;
    printf("Enter no. of node you want to insert\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter data of given node\n");
        scanf("%d",&data1);
        head = insert(head,data1);
    }
    return head;
}

int main(){
    node *head1 = NULL;
    node *head2 = NULL;
    
    printf("Creating first polynomial:\n");
    head1 = create(head1);
    
    printf("Creating second polynomial:\n");
    head2 = create(head2);
    
    node *head3 = add(head1, head2);
    head3 = createReversedLinkedList(head3);
    node *temp = head3;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

}