#include <iostream>
#define MAXSIZE 20
using namespace std;
int a[MAXSIZE];
int size=0;

void create_array();
void Trav_forward();
void Trav_backward();

void create_array()
{
    int n;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;

    if (n>MAXSIZE)
    {
        cout<<"Array size is too large"<<endl;
        return;
    }
    else
    {
        cout<<"Array created successfully"<<endl;
        cout<<"Enter the elements of the array: ";
        for (int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        size=n;
    }
}

void Trav_forward()
{
    if (size==0)
    {
        cout<<"Array is empty"<<endl;
        return;
    }
    else
    {
        cout<<"Array elements are: ";
        for (int i=0; i<size; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}

void Trav_backward()
{
    if (size==0)
    {
        cout<<"Array is empty"<<endl;
        return;
    }
    else
    {
        cout<<"Array elements are: ";
        for (int i=size-1; i>=0; i--)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    create_array();
    Trav_forward();
    Trav_backward();
    return 0;
}