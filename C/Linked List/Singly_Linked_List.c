//QUESTION
/*Devise a program to create a list of integers dynamically.
Write a Count ( )  function that counts the number of nodes in a Singly Linked List and display the contents of the list and the total count of nodes. */

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};
struct node *head;


void insert()
{
	int data;
	for(;;)
	{
		printf("Enter the data to be inserted:");
		scanf("%d",&data);
		if(data!=0)
		{
			struct node *ptr,*temp;    
    			ptr=malloc(sizeof(struct node));      
    			ptr->data=data; 
    			if(head==NULL)  
    			{  
        			ptr->link=NULL;  
        			head = ptr;  
        			printf("1st Node inserted\n");  
    			}  
    			else  
    			{
        			temp=head;  
        			while (temp->link!=NULL)  
        			{
        				temp=temp->link;  
        			}  
        			temp->link=ptr;  
        			ptr->link=NULL;
        			printf("Node inserted\n");  
    			}
    		}
    		else
		{
    			break;
    		}
	}
}

void count_of_nodes(struct node *head)
{
	int count=0;
	if(head==NULL)
		printf("Singly Linked list is empty\n");
	struct node *ptr=NULL;
	ptr=head;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->link;
	}
	printf("COUNT=%d\n",count);
}

void display()  
{  
    struct node *ptr;  
    ptr=head;   
    if(ptr==NULL)  
    {  
        printf("Singly Linked list is empty\n");  
    }  
    else  
    {     
        while(ptr!=NULL)  
        {  
            printf("%d\t",ptr->data);  
            ptr=ptr->link;  
        }
    }  
}

int main()
{
    printf("Note:  Insert 0 for Stop inserting in Singly linked list.\n");
	insert();
	count_of_nodes(head);
	printf("Data containing in the Singly linked list:\n");
	display();
	return 0;
}

