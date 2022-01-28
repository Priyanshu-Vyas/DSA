// QUESTION :
/*
Given a word, form a Double linked list (DLL) by taking each letter from the word sequentially (from left to right). Now check if this word is palindrome or not using 
the DLL. If it is a palindrome, push the matching characters together one by one in to a stack. For example, for the word ‘liril’ being a palindrome, the stack will 
contain ‘lliir.’ Now pop all the elements from the stack and print those elements as a new word. In the given example, the new word from the stack is ‘riill’.

Input format: In the first line, enter the word.

Output format:

In the first line, print if the word is ‘Palindrome’ or ‘Not a Palindrome’

In the second line, If Palindrome then print the new word from the stack NB: In the output, it is not necessary to print the new word if it is not a palindrome.
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define max 20
char stack[max];
int top=-1,i,n;

struct node {
    char data;
    struct node *prev;
    struct node *next;
}*head;

void push(char ch) {
    if(top==max-1)
        printf("\nStack Full!\n");
    else {
        stack[++top]=ch;
    }
}

char pop() {
    if(top==-1){
        exit(0);
    }
    else{
        char item=stack[top--];
        return item;
    }
}

void DLLinsert(char c) {
    struct node *new=malloc(sizeof(struct node));
    new->data=c;
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

bool palindrome() {
    struct node *headr=head;
    while(headr->next!=NULL)
        headr=headr->next;
    while(head!=headr)
    {
        if(head->data!=headr->data)
            return false;
        push(head->data);
        push(headr->data);
        head=head->next;
        headr=headr->prev;
    }
    push(head->data);
    return true;
}

int main() {
    char word[max];
    scanf("%s",word);
    n=strlen(word);
    for(i=0;i<n;i++) {
        DLLinsert(word[i]);
    }
    if(palindrome()) {
        printf("Palindrome\n");
        while(1) {
            printf("%c",pop());
        }
    }
    else
        printf("Not a Palindrome");
    return 0;
}
