#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> v;
    int n,input;
    cout<<"Enter n(how many numbers to be inserted) : ";
    cin>>n;
    cout<<"Enter n Elements : ";
    //a. Insert n numbers in the vector
    for(int i=0;i<n;i++)
    {
        cin>>input;
        v.push_back(input);
    }
    cout<<endl;
    cout<<"Numbers inserted : ";
    //b. Print n numbers in the vector 
    for(int i:v)
    {
        cout<<i<<' ';
    }
    cout<<endl;
    cout<<"Numbers after swapping two numbers : ";
    //c. Swap two numbers
    swap(v.at(0),v.at(v.size()-1));
    for(int i:v)
    {
        cout<<i<<' ';
    }
    cout<<endl;
    cout<<"Numbers after sorting : ";
    //d. Sort the n numbers in the vector
    sort(v.begin(),v.end());
    for(int i:v)
    {
        cout<<i<<' ';
    }
    cout<<endl;
    cout<<"Numbers after reverse : ";
    //e. Reverse the previously sorted numbers 
    reverse(v.begin(),v.end());
    for(auto i:v)
    {
        cout<<i<<' ';
    }
    cout<<endl;
    cout<<"Numbers after deletion of first and last elements : ";
    //f. Delete 2 numbers from the vector  
    //i. One number from the beginning  
    //ii. Another from the last 
    //iii. Display the remaining numbers in the vector
    v.erase(v.begin(),v.begin()+1);
    v.erase(v.end()-1,v.end());
    for(auto i:v)
    {
        cout<<i<<' ';
    }
}