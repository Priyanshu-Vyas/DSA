/*
Insertion Sort
In insertion sort we arrange the element in given order. Consider that you have one given list of elements as 
follows

12,31,56,45,78,68,15

Change the code to arrange the element in alternate elements in ascending order. For example after the sorting 
the list will be

15,12,45,31,68,56,78
*/
#include<iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
int main() {
    vector<int> a(istream_iterator<int>(cin),{}); //Enter anything except int to end inputting
    //copy(a.begin(), a.end(), ostream_iterator<int>{cout, " "});

    int n=a.size();
    for(int i=1;i<n;i++) {
        int key=a[i];
        int j=i-1;
        while(key<a[j] && j>=0) {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    for (int i=0;i<n && i+1<n;i+=2) {
        int swap=a[i];
        a[i]=a[i+1];
        a[i+1]=swap;
    }
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
    }
}