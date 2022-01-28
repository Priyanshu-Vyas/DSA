/*Write C Programs to Implement Basic Sorting ( Bubble, Insertion and selection) 
and searching (Linear and Binary Search) Techniques. Choose a data set of your choice.*/

#include<stdio.h>
#include<stdlib.h>

void LinearSearch(int array[],int size,int value)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(array[i]==value)
        {
            printf("Value Present in array at position %d \n",i+1);
            return;
        }
    }
    printf("Value is not present in the array.\n");
}

void BinarySearch(int array[],int size,int value)
{
    int beg=0,end=size-1;
    while(beg<=end)
    {
        int mid=(beg+end)/2;
        if(array[mid]==value)
        {
            printf("Value present in the array at position %d\n",mid+1);
            return;
        }
        else if(array[mid]>value)
            end=mid-1;
        else
            beg=mid+1;
    }
    printf("Value is not present in the array.\n");
}

void BubbleSort(int array[],int size)
{
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(array[i]>array[j])
            {
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void InsertionSort(int array[],int size)
{
    int i;
    for (i=1;i<size-1;i++)
    {
        int temp=array[i];
        int j=i-1;
        while(temp<=array[j])
        {
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=temp;
    }
}

void SelectionSort(int array[],int size)
{
    int i;
    for (i=0;i<size;i++)
    {
        int small=array[i];
        int j,k=i;
        for (j=i+1;j<size;j++)
        {
            if(small>array[j])
            {
                small=array[j];
                k=j;
            }
        }
        int temp=array[i];
        array[i]=array[k];
        array[k]=temp;
    }
}

int main()
{
    int Size,Value;
    int Array[Size],i,n;
    printf("Enter Size of An Array : ");
    scanf("%d",&Size);
    printf("Enter Elements To Be Inserted In the Array : ");
    for(i=0;i<Size;i++)
    {
        scanf("%d",&Array[i]);
    }
    while(1)
    {
        printf("\n1. LinearSearch()\n");
        printf("2. BinarySearch()\n");
        printf("3. BubbleSort()\n");
        printf("4. InsertionSort()\n");
        printf("5. SelectionSort()\n");
        printf("0. Exit()\n");
        printf("Enter Your Choice : ");
        scanf("%d",&n);
        switch(n)
        {
            case 0:
                printf("\nProgram Terminated!");
                exit(0);
            case 1:
                printf("\nEnter Value To Be Searched In An Array : ");
                scanf("%d",&Value);
                LinearSearch(Array,Size,Value);
                break;
            case 2:
                printf("\nEnter Value To Be Searched In An Array : ");
                scanf("%d",&Value);
                BinarySearch(Array,Size,Value);
                break;
            case 3:
                BubbleSort(Array,Size);
                break;
            case 4:
                InsertionSort(Array,Size);
                break;
            case 5:
                SelectionSort(Array,Size);
                break;
            default : printf("\nEnter A Valid Choice!\n");
        }
        printf("\nArray After Operation : [");
        for(i=0;i<Size-1;i++)
            printf("%d,",Array[i]);
        printf("%d]\n",Array[i]);
    }
}
