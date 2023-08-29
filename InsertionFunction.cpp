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
    // Insertion Function : Last
    void insertion();
    // Insertion Function : Beginning
    void insert_begin();
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

// Insertion Function : Last
void LinkedList::insertion()
{
    int n;
    node *temp = new node;
    cout << "\nEnter the data to insert into last: ";
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

// Insetion Function : Beginning
void LinkedList::insert_begin()
{
    int n;
    node *temp = new node;
    cout << "\nEnter the data to insert into beginning: ";
    cin >> n;
    temp->data = n;
    temp->link = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->link = head;
        head = temp;
    }
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
    l.insertion();
    l.display();
    l.insert_begin();
    l.display();
    return 0;
}