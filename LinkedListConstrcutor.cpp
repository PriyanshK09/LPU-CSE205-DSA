#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *link;
};
class Linkedlist
{
    node *head;
    public:
    Linkedlist() //constructor function
    {
      head=NULL;
    }
    void create();

};
void Linkedlist::create()
{
    node *temp,*ptr;
    int n;
    cout<<"Enter the data to insert into node";
    cin>>n;
    temp=new node;
    temp->data=n;
    temp->link=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        ptr=head;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=temp;
    }
}
int main()
{
    Linkedlist l;
    l.create();
    return 0;
}