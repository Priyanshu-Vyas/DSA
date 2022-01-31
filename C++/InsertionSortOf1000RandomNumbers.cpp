#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
#define n 10000
int main() {
    int arr[n];
    //Random values
    for (int i=0;i<n;i++) {
        arr[i]=rand();
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