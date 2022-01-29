#include<iostream>
using namespace std;

int BinarySearch(int a,int s,int d,int )

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
    BinarySearch(arr,0,n-1,target);
}