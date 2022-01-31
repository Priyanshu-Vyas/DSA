/*
Insertion Sort with class
Consider a class named student with student name, student registration number and student marks.
Sort the students using the student marks using insertion sort
Use vector

Input
John
7635
91
David
7654
95
Ron
8976
92
Expected output
David
Ron
John
*/
#include<iostream>
#include<string>
#include<vector>
#include<ctype.h>
using namespace std;

class student {
    public:
        string name;
        int regno;
        int marks;
};
int main()
{
    vector<student> ss;
    student s;
    for(int i=0;i<3;i++) {
        cin>>s.name>>s.regno>>s.marks;
        ss.push_back(s);
    }
    for (int i=1;i<3;i++) {
        int key=ss[i].marks;
        int regno=ss[i].regno;
        string name=ss[i].name;
        int j=i-1;
        while(key>ss[j].marks && j>=0) {
            ss[j+1].marks=ss[j].marks;
            ss[j+1].name=ss[j].name;
            ss[j+1].regno=ss[j].regno;
            j--;
        }
        ss[j+1].marks=key;
        ss[j+1].name=name;
        ss[j+1].regno=regno;
    }
    for (auto i:ss)
        cout<<i.name<<'\n';
}