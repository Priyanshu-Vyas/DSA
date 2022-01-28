//QUESTION
/*Data structure laboratory’ has got 60 systems connected to a server and a printer. After the coding gets over, the student wants to take print out. The printer can 
serve only one person per time with a buffer to hold 10 programs at a time including the one that is printing at that time. Write a C Program to automate the process 
of getting the files printed according to the time of arrival. Use appropriate data structure. The printer at any time should show the list of files waiting for service.*/

#include<stdio.h>
#define max 60
int queue[max];
int front=-1; 
int rear=-1;
void enqueue(int item)
{
	if(isfull()==0)
	{
		printf("Queue is Full\n");
	}
	else
	{
		front=0;
		rear++;
		queue[rear]=item;
	}
}
void dequeue()
{
	if(isempty()==0)
    {
    	printf("Queue is Empty\n");
    }
    else
    {
    	front++;
    	int item=queue[front];
    }
}
int isfull()
{
	if(rear==max-1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int isempty()
{
	if(front==-1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void display()
{
    int i;
    printf("Students in the Queue: ");
    for (i=front;i<rear+1;i++)
    {
        printf("%d\t",queue[i]);
    }
}
int main()
{
    int i;
    for (i=0;i<10;i++)
    {
        printf("Insert the element: ");
        int st;
        scanf("%d",&st);
        enqueue(st);
    }
    int k;
    printf("Enter  how many student have completed the copy: ");
    scanf("%d",&k);
    for (i=0;i<k;i++)
    {
        dequeue();
    }
    display();
}
