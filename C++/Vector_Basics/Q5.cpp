#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,input;
    cout<<"Enter n(how many numbers to be inserted) : ";
    cin>>n;
    vector<int> v;
    cout<<"Enter n Elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>input;
        v.push_back(input);
    }
    for(auto i:v)
        cout<<i<<' ';
    cout<<endl;
    cout<<"Maximum Element Among n numbers : "<<*max_element(v.begin(),v.end())<<endl;
    cout<<"Minimum Element Among n numbers : "<<*min_element(v.begin(),v.end())<<endl;
    cout<<"Sum of n numbers : "<<accumulate(v.begin(),v.end(),0)<<endl;
    if(n%2==0)
        for(int i=0;i<n;i+=2)
            swap(v.at(i),v.at(i+1));
    else
        for(int i=0;i<n-1;i+=2)
            swap(v.at(i),v.at(i+1));
    cout<<"Numbers after alternate swapping : ";
    for(auto i:v)
        cout<<i<<' ';
    cout<<endl;
}