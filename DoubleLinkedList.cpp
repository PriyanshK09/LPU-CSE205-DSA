#include <iostream>
using namespace std;

class node
{
public:
    node *prev;
    int data;
    node *next;

    void create();
    void display();
};

void node::create()
{
    cout << "Enter data: ";
    cin >> data;
    prev = next = NULL;
}

void node::display()
{
    cout << data << " ";
}

class DoubleLinkedList
{
public:
    node *first, *last;

    DoubleLinkedList()
    {
        first = last = NULL;
    }

    void create();
    void display();
    void reverse();
    void traverse();
    void traversalbackward();
    void insertAtBeginning();
    void insertatEnd();
    void deleteNode();
    void deleteEnd();
};

void DoubleLinkedList::create()
{
    int numNodes;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    for (int i = 0; i < numNodes; i++)
    {
        node *temp = new node;
        temp->create();
        if (first == NULL)
        {
            first = last = temp;
        }
        else
        {
            last->next = temp;
            temp->prev = last;
            last = temp;
        }
    }
}

void DoubleLinkedList::display()
{
    node *current = first;
    if (current == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    while (current != NULL)
    {
        current->display();
        current = current->next;
    }
    cout << endl;
}

void DoubleLinkedList::reverse()
{
    node *current = first;
    node *temp = NULL;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
    {
        first = temp->prev;
    }
}

void DoubleLinkedList::traverse()
{
    display();
}

void DoubleLinkedList::traversalbackward()
{
    node *current = last;
    if (current == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    while (current != NULL)
    {
        current->display();
        current = current->prev;
    }
    cout << endl;
}

void DoubleLinkedList::insertAtBeginning()
{
    node *temp = new node;
    temp->create();
    if (first == NULL)
    {
        first = last = temp;
    }
    else
    {
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
}

void DoubleLinkedList::insertatEnd()
{
    node *temp = new node;
    temp->create();
    if (first == NULL)
    {
        first = last = temp;
    }
    else
    {
        last->next = temp;
        temp->prev = last;
        last = temp;
    }
}

void DoubleLinkedList::deleteNode()
{
    int targetData;
    cout << "Enter the data to delete: ";
    cin >> targetData;

    node *current = first;

    while (current != NULL)
    {
        if (current->data == targetData)
        {
            if (current->prev != NULL)
            {
                current->prev->next = current->next;
            }
            else
            {
                first = current->next;
            }

            if (current->next != NULL)
            {
                current->next->prev = current->prev;
            }
            else
            {
                last = current->prev;
            }

            delete current;
            cout << "Node with data " << targetData << " deleted successfully." << endl;
            return;
        }
        current = current->next;
    }

    cout << "Node with data " << targetData << " not found in the list." << endl;
}

void DoubleLinkedList::deleteEnd()
{
    if (first == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    if (first->next == NULL)
    {
        delete first;
        first = last = NULL;
        return;
    }

    node *current = first;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->prev->next = NULL;
    delete current;
}



int main()
{
    DoubleLinkedList list;
    int choice;

    while (true)
    {
        cout << "Menu:\n";
        cout << "1. Create nodes\n";
        cout << "2. Display the list\n";
        cout << "3. Reverse the list\n";
        cout << "4. Traverse the list backward\n";
        cout << "5. Insert at the beginning\n";
        cout << "6. Insert at the end\n";
        cout << "7. Delete a node\n";
        cout << "8. Exit\n";
        cout << "9. Delete from end\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 8)
        {
            break; // Exit the loop when the user chooses to exit
        }

        switch (choice)
        {
        case 1:
            list.create();
            break;
        case 2:
            list.display();
            break;
        case 3:
            list.reverse();
            break;
        case 4:
            list.traversalbackward();
            break;
        case 5:
            list.insertAtBeginning();
            break;
        case 6:
            list.insertatEnd();
            break;
        case 7:
            list.deleteNode();
            break;
        case 9:
            list.deleteEnd();
            break;
        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}