/*Create a doubly linked list to store the XYZ Bank’s customer’s information
 

Account Number          Balance

A100                      1000

A101                      2000

A102                      1500

A103                      1200

A104                      2500

 

Write a C Program to 

(i) Create a list of customers (Account no, balance) whose balance is greater than 1500 and display the details. 

(ii) Delete the customer having account number A102.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
struct node *prev;
char data1[20];
int data2;
struct node *next;
}*head;

void insert()
{
    char accno[20];
    int bal;
    printf("\nEnter Account No. = ");
    scanf("%s",accno);
    printf("\nEnter Balance = ");
    scanf("%d",&bal);
    struct node *new=malloc(sizeof(struct node));
    strcpy(new->data1,accno);
    new->data2=bal;
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

void display()
{
    printf("\nTotal Customer's : \n");
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
    printf("\t%s\t%d\n",temp->data1,temp->data2);
    temp=temp->next;
    }
}

void excess1500()
{
    printf("\nCustomer's having balance greater than 1500 : \n");
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
    if(temp->data2>1500)
    {
        printf("\t%s\t%d\n",temp->data1,temp->data2);
    }
    temp=temp->next;
    }
}

void delete()
{
    char a[20];
    printf("Enter the account no of the Customer which data has to be deleted = ");
    scanf("%s",a);
    struct node *temp,*ptr;
    temp=head;
    while(temp!=NULL)
    {
    if(strcmp(temp->data1,a)==0)
    {
        ptr=temp;
    }
    temp=temp->next;
    }
    ptr->prev->next=ptr->next;
    ptr->next->prev=ptr->prev;
}

int main()
{
    int totalacc,i;
    printf("Enter Total No. of account to be added = ");
    scanf("%d",&totalacc);
    for(i=0;i<totalacc;i++)
    {
        insert();
    }
    display();    
    excess1500();//for display the details of customer whose balance is greater than 1500
    delete();
    display();
}
