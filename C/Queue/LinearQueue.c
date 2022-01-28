#include<stdio.h>
#include<stdlib.h>
#define max 5
int queue[max],front=-1,rear=-1;

void insert()
{
    int data;
    printf("Enter data to insert = ");
    scanf("%d",&data);
    if(rear==max-1)
        printf("Queue is full\n");
    else{
        if(front==-1 && rear==-1){
            front=0;
            rear=0;
        }
        else{
            rear++;
        }
        queue[rear]=data;
    }
}

void delete(){
    if(front==-1 || front>rear){
        printf("Queue is Empty\n");
    }
    else{
        printf("%d\n",queue[front++]);
    }
}

void display(){
    int i;
    for(i=front;i<=rear;i++)
    {
        printf("\t%d",queue[i]);
    }
}
void main()
{
    int n;
    while(1){
        printf("\n1. Insert() \n");
        printf("2. Delete() \n");
        printf("3. Display() \n");
        printf("4. Exit() \n");
        printf("Enter Your Choice : ");
        scanf("%d",&n);
        switch(n){
            case 1:insert();break;
            case 2:delete();break;
            case 3:display();break;
            case 4:printf("Program Terminated!");exit(0);
            default:printf("Enter a Valid Choice!\n");
        }
    }
}
