/*Reverse a Doubly Linked List*/

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

void reverse()
{
    struct node *temp=NULL,*ptr=head;
    while(ptr!=NULL)
    {
        temp=ptr->prev;
        ptr->prev=ptr->next;
        ptr->next=temp;
        ptr=ptr->prev;
    }
    if(temp!=NULL)
        head=temp->prev;
}

void display()
{
    printf("\nData Present in the DoublyLinkedList : \n");
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
    display();
    reverse();
    display();
}