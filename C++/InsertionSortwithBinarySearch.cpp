/*
Binary Search
While sorting the algorithm using insertion sort, if half of the elements are sorted and half is unsorted. 
The position of one element, say from unsorted list is determined and placed at the suitable position, say ‘i’. 
In order to determine the position of the element from the unsorted list use binary search.
*/
#include<iostream>
#include<vector>
#include<iterator>
#include <sstream>
#include<string>
using namespace std;

int BinarySearch(vector<int>& a,int s,int d,int t) {
    if(s<d) {
        int mid=s+(d-s)/2;
        if(a[mid]==t)
            return mid;
        else if(t<a[mid])
            return BinarySearch(a, s, mid-1, t);
        else
            return BinarySearch(a, mid+1, d, t);
    }
    else
        if(t>a[s])
            return s+1;
        else
            return s;
}

int main()
{
    string input;
    getline(cin,input);
    istringstream is(input);
    vector<int> a((istream_iterator<int>(is)),std::istream_iterator<int>());
    int n=a.size();
    for(int i=1;i<n;i++) {
        int key=a[i];
        int j=i-1;
        int index=BinarySearch(a, 0, j, key);
        while(j>=index) {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    for(auto i:a)
        cout<<i<<' ';
}