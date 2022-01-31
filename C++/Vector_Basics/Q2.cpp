#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int main()
{
    stack<int> s;
    int choice,input;
    while(1)
    {
        cout<<"---------------------------------------------------"<<endl;
        cout<<"1. Insert the element in the stack."<<endl;
        cout<<"2. Delete the element from the stack."<<endl;
        cout<<"3. Display size of the stack."<<endl;
        cout<<"4. Fetch top most element from the stack."<<endl;
        cout<<"5. Quit."<<endl;
        cout<<"---------------------------------------------------"<<endl;
        cout<<"Enter Your Choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter an element : ";
                cin>>input;
                s.push(input);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout<<"Size of the stack is : "<<s.size()<<endl;
                break;
            case 4:
                if(s.empty())
                    cout<<"Stack is Empty!"<<endl;
                else
                    cout<<"Top Most element of the stack is : "<<s.top()<<endl;
                break;
            case 5:
                cout<<"Program Terminated Sucessfully!";
                exit(0);
            default:
                cout<<"Enter A Valid Choice!"<<endl;
        }
        
    }
}
