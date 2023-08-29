#include <iostream>
using namespace std;

//  NODE CLASS: This represents each element in the linked list. It has two important things inside it:
//  DATA: This holds the actual information you want to store, like a number or a word.
//  LINK: This is like a pointer that points to the next element in the list.

//  LinkedList Class: This is like the manager of the linked list. It has functions that allow you to interact with the list.

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
    // Insertion Function : After a given position
    void insert_after();
    // Insertion Function : on a given position
    void insert_at();

    // Deletion Function
    void delete_last();
    void delete_begin();
    void delete_at();

    // Searching Function
    void search();
};

void LinkedList::create()
{
    int n;
    node *temp = new node;
    cout << "Enter the data to insert into node: ";
    cin >> n;
    temp->data = n;
    temp->link = NULL; // Null means Zero Valued Pointer
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

// Insertion Function : At a given position
void LinkedList::insert_at()
// using count :
{
    int n, pos, count = 0;
    node *temp = new node;
    cout << "\nEnter the data to insert into given position: ";
    cin >> n;
    cout << "\nEnter the position to insert into given position: ";
    cin >> pos;
    temp->data = n;
    temp->link = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        node *t = head;
        while (t != NULL)
        {
            count++;
            t = t->link;
        }
        if (pos == count)
        {
            t = head;
            for (int i = 1; i < pos; i++)
            {
                t = t->link;
            }
            temp->link = t->link;
            t->link = temp;
        }
        else
        {
            if (pos > count)
            {
                cout << "\nGiven position is greater than the number of nodes!!";
            }
            else
            {
                cout << "\nInvalid Position";
            }
        }
    }
}

// Deletion Function
void LinkedList::delete_last()
{
    node *t = head;
    node *temp = head;
    while (t->link != NULL)
    {
        temp = t;
        t = t->link;
    }
    temp->link = NULL;
    delete t;
}

void LinkedList::delete_begin()
{
    node *t = head;
    head = head->link;
    delete t;
}

void LinkedList::delete_at()
{
    int pos, count = 0;
    cout << "\nEnter the position to delete: ";
    cin >> pos;
    node *t = head;
    node *temp = head;
    while (t != NULL)
    {
        count++;
        t = t->link;
    }
    if (pos == count)
    {
        t = head;
        for (int i = 1; i < pos; i++)
        {
            temp = t;
            t = t->link;
        }
        temp->link = t->link;
        delete t;
    }
    else
    {
        if (pos > count)
        {
            cout << "\nGiven position is greater than the number of nodes!!";
        }
        else
        {
            cout << "\nInvalid Position";
        }
    }
}

// Searching Function
void LinkedList::search()
{
    int n, count = 0;
    cout << "\nEnter the data to search: ";
    cin >> n;
    node *t = head;
    while (t != NULL)
    {
        count++;
        if (t->data == n)
        {
            cout << "\nData found at position " << count;
            break;
        }
        t = t->link;
    }
    if (t == NULL)
    {
        cout << "\nData not found!!";
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
    cout << "What do you want to perform?\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\n5. Search\n";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "\nWhat do you want to perform?\n1. Insertion at the end\n2. Insertion at the beginning\n3. Insertion at a given position\n";
        int choice1;
        cin >> choice1;
        switch (choice1)
        {
        case 1:
            l.insertion();
            l.display();
            break;
        case 2:
            l.insert_begin();
            l.display();
            break;
        case 3:
            l.insert_at();
            l.display();
            break;
        default:
            cout << "Invalid Choice";
        }
        break;
    case 2:
        cout << "\nWhat do you want to perform?\n1. Deletion at the end\n2. Deletion at the beginning\n3. Deletion at a given position\n";
        int choice2;
        cin >> choice2;
        switch (choice2)
        {
        case 1:
            l.delete_last();
            l.display();
            break;
        case 2:
            l.delete_begin();
            l.display();
            break;
        case 3:
            l.delete_at();
            l.display();
            break;
        }
        break;
    case 3:
        l.display();
        break;
    case 4:
        exit(0);
        break;
    case 5:
        l.search();
        break;
    default:
        cout << "Invalid Choice";
    }
    return 0;
}