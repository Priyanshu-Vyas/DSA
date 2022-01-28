//QUESTION
/* A team of experts formed under the supervision of the prime minister of India conducted a survey on some of the top colleges of India. They were sent to most of 
the institutions to check on the facilities, academics and infrastructure. The experts’ team then gave a report of 20 top universities in India to the prime minister. 
Prime minster then asks them to make two lists – One list containing the top10 universities and the second list containing the remaining universities. Write a C program 
to depict the above scenario and display the results. */
#include <stdio.h>
int main()
{
    int ranks[20],temp=0,top10[10],all[20],k=0;
    for(int i=0;i<20;i++)
    {
        scanf("%d",&ranks[i]);
    }
    for(int i=0;i<20;i++)
    {
        for(int j=i+1;j<20;j++)
        {
            if(ranks[i]>ranks[j])
            {
                temp=ranks[i];
                ranks[i]=ranks[j];
                ranks[j]=temp;
            }
        }
    }
    for(int i=0;i<20;i++)
    {
        if(i<10)
        {
            top10[i]=ranks[i];
        }
        else
        {
            all[k]=ranks[i];
            k++;
        }
    }
    printf("TOP 10\n");
    for(int i=0;i<10;i++)
    {
        printf("%d ",top10[i]);
    }
    printf("\nALL others\n");
    for(int i=0;i<k;i++)
    {
        printf("%d ",all[i]);
    }
    return 0;
}
