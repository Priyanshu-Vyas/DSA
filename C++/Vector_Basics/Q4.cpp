#include<iostream>
#include<list>
using namespace std;

int main()
{
    list<int> l;
    int n,input;
    cout<<"Enter n(how many numbers to be inserted) : ";
    cin>>n;
    cout<<"Enter n Elements : ";
    //a. Insert n numbers in the List
    for(int i=0;i<n;i++)
    {
        cin>>input;
        l.push_back(input);
    }
    cout<<endl;
    cout<<"Numbers inserted : ";
    //b. Print n numbers in the list 
    for(int i:l)
    {
        cout<<i<<' ';
    }
    cout<<endl;
    cout<<"Numbers after sorting : ";
    //c. Sort the n numbers in the list
    l.sort();
    for(int i:l)
    {
        cout<<i<<' ';
    }
    cout<<endl;
    cout<<"Numbers after reverse : ";
    //d. Reverse the previously sorted numbers 
    l.reverse();
    for(auto i:l)
    {
        cout<<i<<' ';
    }
}