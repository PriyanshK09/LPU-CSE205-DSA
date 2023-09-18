#include <iostream>
#define MAX 5
using namespace std;

class Queue
{
    public:
    int q[MAX];
    int front, rear;
    Queue()
    {
        front=rear=-1;
    }
    
    void insert(int x);
    int Delete();
    bool isEmpty();
    bool isFull();
    int getFront();
};

int Queue::Delete()
{
    if(front==rear)
    {
        cout<<"Queue is Underflow.";
        return -1;
    }
    else
    {
        front++;
        return q[front];
    }
}

bool Queue::isFull()
{
    if(rear==MAX-1)
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
}

bool Queue::isEmpty()
{
    if(front==rear)
        cout<<"True (Empty)"<<endl;
    else
        cout<<"False (Empty)"<<endl;
}

void Queue::insert(int x)
{
    if(rear==MAX-1)
        cout<<"Queue is Full"<<endl;
    else
    {
        rear++;
        q[rear]=x;
    }
}

int Queue::getFront()
{
    if(front==rear)
    {
        cout<<"Queue is Empty"<<endl;
        return -1;
    }
    else
    {
        return q[front+1];
    }
}


int main()
{
    Queue qq;
    int x;
    for (int i=0;i<7;i++){
        cin>>x;
        qq.insert(x);
    
    }
    cout<<qq.Delete()<<endl;
    cout<<qq.Delete()<<endl;
    // Pops 2 elements

    // New Function
    qq.isFull();
    qq.isEmpty();

    // New Function
    qq.getFront();

}