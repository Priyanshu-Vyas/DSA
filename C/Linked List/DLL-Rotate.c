/*Rotate (clockwise) a Doubly Linked List by N nodes*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
}*head;

void insert()
{
    int d;
    printf("\nEnter the Data to be inserted = ");
    scanf("%d",&d);
    struct node *new=malloc(sizeof(struct node));
    new->data=d;
    new->prev=NULL;
    new->next=NULL;
    if(head==NULL)
    {
        head=new;
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new;
        new->prev=temp;
    }
}

void rotate()
{
    int N;
    printf("\nEnter the no. of Nodes rotated = ");
    scanf("%d",&N);
    if(N==0)
        return;
    struct node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head;
    head->prev=temp;
    int count=1;
    while(count<=N)
    {
        head=head->next;
        temp=temp->next;
        count++;
    }
    temp->next=NULL;
    head->prev=NULL;
}

void display()
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
    printf("\t%d",temp->data);
    temp=temp->next;
    }
}

int main()
{
    insert();
    insert();
    insert();
    insert();
    insert();
    insert();
    printf("\nData Present Before N rotation's in the DoublyLinkedList : \n");
    display();
    rotate();
    printf("\nData Present After N rotation's in the DoublyLinkedList : \n");
    display();
}