#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int h,int m,int e)
{
    int i,j,k;
    int n1=m-h+1;
    int n2=e-m;
  
    int L[n1],R[n2];
  
    for(i=0;i<n1;i++)
        L[i]=arr[h+i];
    for(j=0;j<n2;j++)
        R[j]=arr[m+1+j];
  
    i=0;
    j=0;
    k=h;
    while (i<n1 && j<n2) {
        if (L[i]<=R[j]) {
            arr[k]=L[i];
            i++;
        }
        else {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
  
    while (i<n1) {
        arr[k]=L[i];
        i++;
        k++;
    }

    while (j<n2) {
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[],int home,int end) {
    int mid;
    if(home<end) {
        mid=home+(end-home)/2;
        mergesort(arr,home,mid);
        mergesort(arr,mid+1,end);
        merge(arr,home,mid,end);
    }
}

int main() {
    int i,n;
    printf("Enter the size of an array= ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the Array Elements= \n");
    for(i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    printf("OK");
    mergesort(arr,0,n-1);

    printf("\n Array After Sorting : \n ");
    for(i=0;i<n;i++) {
        printf("%d\t",arr[i]);
    }

    return 0;
}