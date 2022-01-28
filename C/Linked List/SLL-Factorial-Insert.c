/*
Given a singly linked list containing ‘N’ nodes, the task is to read each number from the list, find the 
factorial of it and then insert the factorial after the original number in the list. Write a ‘C’ program to 
implement the above scenario and display both the original list and the output list.
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
}*l1,*l2;

void insert(struct node **head,int data)
{
    struct node *temp,*ptr;
    ptr=malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=NULL;
    if(*head==NULL)
    {
        *head=ptr;
    }
    else
    {
        temp=*head;
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=ptr;
    }
}

int factorial(int n)
{
    if(n<=1)
        return 1;
    else
    {
        return n*factorial(n-1);
    }
}

void factorialinsert(struct node **head)
{
    struct node *temp=*head;
    while(temp!=NULL)
    {
        insert(&l2,temp->data);
        insert(&l2,factorial(temp->data));
        temp=temp->link;
    }
}

void display(struct node **head)
{
    struct node *temp;
    temp=*head;
    if(temp==NULL)
    {
        printf("Singly Linked List is Empty!");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->link;
        }
    }
}

int main()
{
    int data;
    printf("Note : Enter 404 for Ending inserting!\n");
    while(1)
    {
        printf("Enter data to be inserted=\t");
        scanf("%d",&data);
        if(data!=404)
        {
            insert(&l1,data);
        }
        else
        {
            break;
        }
    }
    printf("Original List = [");
    display(&l1);
    printf("]\n");
    factorialinsert(&l1);
    printf("Output List = [");
    display(&l2);
    printf("]\n");
}
