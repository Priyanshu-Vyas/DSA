/*Read a set of integers with duplicates and Create a binary search tree with no duplicates.*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root;

void insert()
{
    int d;
    printf("Enter The Data to be inserted : ");
    scanf("%d",&d);
    struct node *new,*temp,*ptr;
    new=malloc(sizeof(struct node));
    new->data = d;
    new->left = NULL;
    new->right = NULL;
    if(root==NULL)
    {
        root=new;
    }
    else
    {
        ptr=NULL;
        temp=root;
        while(temp!=NULL)
        {
            ptr=temp;
            if(d==temp->data)
                return;
            else if(d<temp->data)
                temp=temp->left;
            else
                temp = temp->right;
        }
        if(d<ptr->data)
            ptr->left = new;
        else
            ptr->right = new;
    }
}

void inorder(struct node *root)
{ 
    if (root!=NULL) { 
        inorder(root->left); 
        printf("\t%d",root->data);
        inorder(root->right); 
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
    printf("\nElements in the tree :\n");
    inorder(root);
}