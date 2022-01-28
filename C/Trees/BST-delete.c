/*Create a binary search root and delete a node  with (i) No children and (ii) One Child*/

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
            if(d<temp->data)
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

struct node *deleteleafnodes(struct node *root)
{
    if(root==NULL)
        return NULL;
    else if(root->left==NULL && root->right==NULL)
    {
        free(root);
        return NULL;
    }
    root->left=deleteleafnodes(root->left);
    root->right=deleteleafnodes(root->right);
    return root;
}

struct node *DeleteOneChildNodes(struct node *root)
{
    if(root==NULL)
        return NULL;
    else
    {
        if(root->left==NULL || root->right==NULL)
        {
            free(root);
            return NULL;
        }
    }
    root->left=DeleteOneChildNodes(root->left);
    root->right=DeleteOneChildNodes(root->right);
    return root;
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
    printf("\nElements before deletion's\n");
    inorder(root);
    deleteleafnodes(root);
    printf("\nElements After deletion of leaf nodes\n");
    inorder(root);
    DeleteOneChildNodes(root);
    printf("\nElements After deletion of nodes having one child\n");
    inorder(root);
}