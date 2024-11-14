#include <stdio.h>
#include <stdlib.h>
struct poly
{
    int data;
    int power;
    struct poly *next;
};
struct poly *create(struct poly *head, int term)
{
    if (head == NULL)
    {
        struct poly *p = (struct poly *)malloc(sizeof(struct poly));
        printf("Enter the coefficient of %d term: ", term);
        scanf("%d", &p->data);
        printf("Enter the power of the %d term: ", term);
        scanf("%d", &p->power);
        p->next = NULL;
        return p;
    }
    else
    {
        struct poly *p = (struct poly *)malloc(sizeof(struct poly));
        printf("Enter the coefficient of %d term: ", term);
        scanf("%d", &p->data);
        printf("Enter the power of the %d term: ", term);
        scanf("%d", &p->power);
        p->next = NULL;
        struct poly *q = head;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
        return head;
    }
}
void display(struct poly *head)
{
    struct poly *temp = head;
    while (temp != NULL)
    {
        if (temp->power == 0)
        {
            printf("%d", temp->data);
        }
        else
        {
            printf("%dx^%d + ", temp->data, temp->power);
        }
        temp = temp->next;
    }
    printf("\n");
}
struct poly *addition(struct poly *head1, int term1, int term2)
{
    struct poly *head = NULL;
    struct poly *p = head1;
    struct poly *new = NULL;
    for (int i = 0; i < term1; i++)
    {
        struct poly *new1 = (struct poly *)malloc(sizeof(struct poly));
        new1->data = p->data;
        new1->power = p->power;
        p = p->next;
        new1->next = NULL;
        if (new == NULL)
        {
            head = new1;
            new = new1;
        }
        else
        {
            new->next = new1;
            new = new->next;
        }
    }
    struct poly *temp = head;
    int flag = 0;
    for (int i = 0; i < term2; i++)
    {
        struct poly *q = (struct poly *)malloc(sizeof(struct poly));
        printf("Enter the coefficient of %d term: ", i);
        scanf("%d", &q->data);
        printf("Enter the power of the %d term: ", i);
        scanf("%d", &q->power);
        
        flag = 0;
        temp = head;
        while (temp->next != NULL)
        {
            if (temp->power == q->power)
            {
                temp->data = temp->data + q->data;
                flag = 1;
            }
            temp = temp->next;
        }
        if (flag != 1)
        {
            struct poly *new1 = (struct poly *)malloc(sizeof(struct poly));
            new1->data = q->data;
            new1->power = q->power;
            new1->next = NULL;
            if (new == NULL)
            {
                head = new1;
                new = new1;
            }
            else
            {
                new->next = new1;
                new = new->next;
            }
        }
        // q = q->next;
    }
    temp = head;
    struct poly *temp2 = head;



    while (temp!= NULL)
    {
        temp2 = head; 
        while (temp2 != NULL)
        {
            if (temp->power > temp2->power)
            {
                
                int tempData = temp->data;
                int tempPower = temp->power;
                temp->data = temp2->data;
                temp->power = temp2->power;
                temp2->data = tempData;
                temp2->power = tempPower;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }

    display(head);
}

int main()
{
    int n1, n2;
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);
    struct poly *head1 = NULL;
    // struct poly *head2 = NULL;
    for (int i = 0; i < n1; i++)
    {
        head1 = create(head1, i + 1);
    }
    display(head1);
    // display(head2);
    addition(head1, n1, n2);
}