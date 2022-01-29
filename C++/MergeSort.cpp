#include<iostream>
using namespace std;

void merge(int *a,int beg,int mid,int end) {
   int l=mid-beg+1,r=end-mid;
   int la[l],ra[r];
   for(int i=0;i<l;i++) {
       la[i]=a[beg+i];
   }
   for(int j=0;j<r;j++) {
       ra[j]=a[mid+1+j];
   }
   int i=0,j=0,k=beg;
   while(i<l && j<r) {
       if(la[i]<=ra[j]) {
           a[k]=la[i];
           i++;
       }
       else{
           a[k]=ra[j];
           j++;
       }
       k++;
   }
   while(i<l) {
       a[k]=la[i];
       i++;
       k++;
   }
   while(j<r) {
       a[k]=ra[j];
       j++;
       k++;
   }
}

void mergesort(int *arr,int beg,int end) {
    int mid;
    if(beg<end) {
        int mid=beg+(end-beg)/2;
        mergesort(arr,beg,mid);
        mergesort(arr,mid+1,end);
        merge(arr,beg,mid,end);
    }
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    cout<<arr[n-1]<<endl;
    cout<<arr[0]<<endl;
}