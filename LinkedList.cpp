#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *link;
};

class LinkedList
{
public:
    node *head;
    LinkedList()
    {
        head = NULL;
    }

    void create();
    void display();
};

void LinkedList::create()
{
    int n;
    node *temp = new node;
    cout << "Enter the data to insert into node: ";
    cin >> n;
    temp->data = n;
    temp->link = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        node *t = head;
        while (t->link != NULL)
        {
            t = t->link;
        }
        t->link = temp;
    }
}

void LinkedList::display()
{
    node *t = head;
    while (t != NULL)
    {
        cout << t->data << "==>";
        t = t->link;
    }
    cout << "NULL";
}

int main()
{
    LinkedList l;
    int n;
    cout << "Enter the number of nodes to insert: ";
    cin >> n;
    for (int i = 0; i < n; i++)
        l.create();
    l.display();
    return 0;
}