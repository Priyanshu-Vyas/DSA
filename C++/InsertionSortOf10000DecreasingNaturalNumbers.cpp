#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
#define n 10000
int main() {
    int arr[n];
    //Decreasing order
    for (int i=n;i>0;i--) {
        arr[n-i]=i;
    }
    //Insertion Sort
    auto start = high_resolution_clock::now();
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
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<< duration.count() <<"ms"<<endl;
}