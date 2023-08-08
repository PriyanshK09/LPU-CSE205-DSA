#include <iostream>
#define MAXSIZE 20
using namespace std;
int a[MAXSIZE];
int size=0;

void create_array();
void Trav_forward();
void Trav_backward();
void Search_element();
void Insert_element();

void create_array()
{
    int n;
    cout<<"Enter the size of the array: ";
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

void Search_element()
{
    int ele;
    cout<<"Enter the element to be searched: ";
    cin>>ele;
    for (int i=0; i<size; i++)
    {
        if (a[i]==ele)
        {
            cout<<"Element found at position: "<<i+1<<endl;
            return;
        }
    }
    cout<<"Element not found"<<endl;
}

void Insert_element()
{
    int ele, pos;
    cout<<"Enter the element to be inserted: ";
    cin>>ele;
    cout<<"Enter the position of the element: ";
    cin>>pos;
    if (pos>size+1)
    {
        cout<<"Invalid position"<<endl;
        return;
    }
    else
    {
        for (int i=size-1; i>=pos-1; i--)
        {
            a[i+1]=a[i];
        }
        a[pos-1]=ele;
        size++;
        cout<<"Element inserted successfully"<<endl;
        cout<<"Array elements are: ";
        for (int i=0; i<size; i++)
        {
            cout<<a[i]<<" ";
        }
    }
}

int main()
{
    create_array();
    Trav_forward();
    Trav_backward();
    Search_element();
    Insert_element();
    return 0;
}