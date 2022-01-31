#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of an Array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of Array : ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Array before sorting :  ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<' ';
    //Insertion Sort
    // k : 2 to arr.length()
    for (int k=1;k<n;k++)
    {
        int key=arr[k]; //Right hand
        int l=k-1; //for traversing
        while(l>=0 && arr[l]>key) {
            arr[l+1]=arr[l];
            l--;
        }
        arr[l+1]=key;
    }
    cout<<"\nArray after Sorting : ";
    for (int i=0;i<n;i++) {
        cout<<arr[i]<<' ';
    }
}

// rand() : function to generate random values