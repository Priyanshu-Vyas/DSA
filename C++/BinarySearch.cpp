#include<iostream>
#include<vector>
using namespace std;

int BinarySearch(int* a,int s,int d,int t) {
    if(s<=d) {
        int mid=s+(d-s)/2;
        if(a[mid]==t)
            return mid;
        if(t<a[mid])
            return BinarySearch(a, s, mid-1, t);
        else
            return BinarySearch(a, mid+1, d, t);
    }
    return -1;
}

int main() {
    int n;
    cout<<"Size=";
    cin>>n;
    int arr[n];
    cout<<"Array=";
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int target;
    cout<<"Target=";
    cin>>target;
    cout<<BinarySearch(arr,0,n-1,target);
}