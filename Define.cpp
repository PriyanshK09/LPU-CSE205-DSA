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
void Delete_element();
void Insert_atlast();
void Insert_atfirst();
void Delete_atlast();
void Delete_atfirst();
void Delete_atpos();

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

void Delete_element()
{
    int pos;
    cout<<"\n Enter the position of the element to be deleted: ";
    cin>>pos;
    if (pos>size)
    {
        cout<<"Invalid position"<<endl;
        return;
    }
    else
    {
        for (int i=pos-1; i<size-1; i++)
        {
            a[i]=a[i+1];
        }
        size--;
        cout<<"Element deleted successfully"<<endl;
        cout<<"Array elements are: ";
        for (int i=0; i<size; i++)
        {
            cout<<a[i]<<" ";
        }
    }
}

void Insert_atlast()
{
    int ele;
    cout<<"\n Enter the element to be inserted: ";
    cin>>ele;
    a[size]=ele;
    size++;
    cout<<"Element inserted successfully"<<endl;
    cout<<"Array elements are: ";
    for (int i=0; i<size; i++)
    {
        cout<<a[i]<<" ";
    }
}

void Insert_atfirst()
{
    int ele;
    cout<<"\n Enter the element to be inserted: ";
    cin>>ele;
    for (int i=size-1; i>=0; i--)
    {
        a[i+1]=a[i];
    }
    a[0]=ele;
    size++;
    cout<<"Element inserted successfully"<<endl;
    cout<<"Array elements are: ";
    for (int i=0; i<size; i++)
    {
        cout<<a[i]<<" ";
    }
}

void Delete_atlast()
{
    size--;
    cout<<"Element deleted successfully"<<endl;
    cout<<"Array elements are: ";
    for (int i=0; i<size; i++)
    {
        cout<<a[i]<<" ";
    }
}

void Delete_atfirst()
{
    for (int i=0; i<size-1; i++)
    {
        a[i]=a[i+1];
    }
    size--;
    cout<<"Element deleted successfully"<<endl;
    cout<<"Array elements are: ";
    for (int i=0; i<size; i++)
    {
        cout<<a[i]<<" ";
    }
}

void Delete_atpos()
{
    int pos;
    cout<<"\n Enter the position of the element to be deleted: ";
    cin>>pos;
    if (pos>size)
    {
        cout<<"Invalid position"<<endl;
        return;
    }
    else
    {
        for (int i=pos-1; i<size-1; i++)
        {
            a[i]=a[i+1];
        }
        size--;
        cout<<"Element deleted successfully"<<endl;
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
    Delete_element();
    Insert_atlast();
    Insert_atfirst();
    Delete_atlast();
    Delete_atfirst();
    Delete_atpos();
    return 0;
}