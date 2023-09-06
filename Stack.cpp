#include <iostream>
#define MAXSIZE 5
using namespace std;
class Stack
{
    int s[MAXSIZE];
    int top;
    public:
    Stack()
    {
        top=-1;
    }

    void push(int x)
    {
        if(top==MAXSIZE-1)
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        s[++top]=x;
    }

    int pop()
    {
        if(top==-1)
        {
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        return s[top--];
    }

    void display()
    {
        if(top==-1)
        {
            cout<<"Stack is empty"<<endl;
            return;
        }
        for(int i=top;i>=0;i--)
        {
            cout<<s[i]<<" ";
        }
        cout<<endl;
    }

    int StackInput()
    {
        int x;
        cout<<"Enter the element to be pushed: ";
        cin>>x;
        return x;
    }
};

int main()
{
    Stack s;
    int ch;
    do
    {
        // Menu
        cout<<"1. Input Stack"<<endl;
        cout<<"2. Push"<<endl;
        cout<<"3. Pop"<<endl;
        cout<<"4. Display"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                int n;
                cout<<"Enter the number of elements to be pushed: ";
                cin>>n;
                for(int i=0;i<n;i++)
                {
                    s.push(s.StackInput());
                }
                break;
            }
            case 2:
            {
                s.push(s.StackInput());
                break;
            }
            case 3:
            {
                cout<<"Popped element: "<<s.pop()<<endl;
                break;
            }
            case 4:
            {
                s.display();
                break;
            }
            case 5:
            {
                cout<<"Exiting..."<<endl;
                break;
            }
            default:
            {
                cout<<"Invalid choice"<<endl;
            }
        }
    }while(ch!=5);
    return 0;
}