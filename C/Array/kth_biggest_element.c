//QUESTION
/* Write an algorithm to find kth biggest element in an array, whose elements are not sorted. For the identified kth biggest element (call it X) you have to find its 
sum of digits and cross-check if the sum of the digits and X’s corresponding index in the array are same. If so, your algorithm should print “Matching”. If not, print 
“Not matching”. Compute the time complexity of the algorithm. Example: If the given array is [1, 3, 12, 19, 13, 2, 15] and you are asked for the 3rd biggest element 
i.e., k = 3 then your algorithm should print 13 since 13 is the 3rd biggest element of the array. For 13, we find its sum of digits, viz. 1+3=4. Since the sum of the 
digits of 13  and its index position viz. 4 in the array are the same, we print “Matching” */

#include<stdio.h>
void sort(int a[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]<a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
int sum_of_digits(int k)
{
    int s=0;
    while(k!=0)
    {
        s+=k%10;
        k/=10;
    }
    return s;
}
int main()
{
    int i,n;
    printf("Enter the size of an array:");
    scanf("%d",&n);
    int a[n],b[n];
    printf("Enter n Elements to be inserted in array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    int k;
    printf("Enter the K value:");
    scanf("%d",&k);
    sort(a,n);
    int t=0;
    for(i=0;i<n;i++)
    {
        if(b[i]==a[k-1])
        {
            t=i;
        }
    }
    if(sum_of_digits(a[k-1])==t)
    {
        printf("Matching");
    }
    else
    {
        printf("Not Matching");
    }
}
