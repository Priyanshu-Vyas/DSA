#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
    queue<int> q;
    int choice,input;
    while(1)
    {
        cout<<"---------------------------------------------------"<<endl;
        cout<<"1. Insert the element in the queue."<<endl;
        cout<<"2. Delete the element from the queue."<<endl;
        cout<<"3. Display size of the queue."<<endl;
        cout<<"4. Fetch front element from the queue."<<endl;
        cout<<"5. Fetch last element from the queue."<<endl;
        cout<<"6. Quit."<<endl;
        cout<<"---------------------------------------------------"<<endl;
        cout<<"Enter Your Choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter an element : ";
                cin>>input;
                q.push(input);
                break;
            case 2:
                q.pop();
                break;
            case 3:
                cout<<"Size of the queue is : "<<q.size()<<endl;
                break;
            case 4:
                if(q.empty())
                    cout<<"Queue is Empty!"<<endl;
                else
                    cout<<"Element at the front position of the queue is : "<<q.front()<<endl;
                break;
            case 5:
                if(q.empty())
                    cout<<"Queue is Empty!"<<endl;
                else
                    cout<<"Element at the last position of the queue is : "<<q.back()<<endl;
                break;    
            case 6:
                cout<<"Program Terminated Sucessfully!";
                exit(0);
            default:
                cout<<"Enter A Valid Choice!"<<endl;
        }
    }
}
