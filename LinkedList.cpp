// Local Variables are created in stack and are destroyed when the function is over
// Dynamic Variables are created in heap and are destroyed when the program is over


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
    void display();

};
void Linkedlist::create()
{
    int n;
    node *temp=new node;
    cout<<"Enter the data to insert into node: ";
    cin>>n;
    temp->data=n;
    temp->link=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        node *t=head;
        while(t->link!=NULL)
        {
            t=t->link;
        }
        t->link=temp;
    }

};
void Linkedlist::display()
{
    node *t=head;
    while(t!=NULL)
    {
        cout<<t->data<<"=>";
        t=t->link;
    }
    cout<<"NULL";
};
int main()
{
    Linkedlist l;
    l.create();
    l.create();
    l.display(); // 1=>2=>3=>NULL : Expected Output
    return 0;
}
