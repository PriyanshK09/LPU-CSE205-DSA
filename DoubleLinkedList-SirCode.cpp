#include <iostream>
using namespace std;

class node {
public:
    node* prev;
    int data;
    node* next;
};

class dlinkedlist {
public:
    node* head, * tail;
    dlinkedlist() {
        head = NULL;
        tail = NULL;
    }

    void create();
    void display();
    void revdisplay();
    void insertlast();
    void insertfirst();
    void insertpos();
    void deletebegin();
    void deletelast();
    void deletepos();
    void search();
    void revsearch();
};

void dlinkedlist::create() {
    int n;
    node* temp = new node;
    cout << "Enter the data to insert into node: ";
    cin >> n;
    temp->data = n;
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL) {
        head = temp;
        tail = temp;
    }
    else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void dlinkedlist::display() {
    node* t = head;
    while (t != NULL) {
        if (t->next != NULL) {
            cout << t->data << " ==> ";
        }
        else {
            cout << t->data;
        }
        t = t->next;
    }
}

void dlinkedlist::revdisplay() {
    node* t = tail;
    while (t != NULL) {
        if (t->prev != NULL) {
            cout << t->data << " ==> ";
        }
        else {
            cout << t->data;
        }
        t = t->prev;
    }
}

void dlinkedlist::insertlast() {
    int n;
    node* temp = new node;
    cout << "Enter the data to insert into node: ";
    cin >> n;
    temp->data = n;
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL) {
        head = temp;
    }
    else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void dlinkedlist::insertfirst() {
    node* t = new node;
    cin >> t->data;
    t->next = head;
    t->prev = NULL;
    head->prev = t;
    head = t;
}

void dlinkedlist::insertpos() {
    node* temp = new node;
    int pos;
    cout << "Enter the position at which you want to add a node: ";
    cin >> pos;
    cout << "Enter the data: ";
    cin >> temp->data;
    node* cur = head, * pre = NULL;
    int count = 1;
    while (count < pos && cur->next != NULL) {
        pre = cur;
        cur = cur->next;
        count++;
    }
    if (count == pos) {
        temp->prev = cur->prev;
        temp->next = cur;
        cur->prev = temp;
        pre->next = temp;
    }
    else {
        cout << "Cannot insert data. End reached." << endl;
    }
}

void dlinkedlist::deletebegin() {
    node* temp = head;
    if (head == NULL) {
        cout << "DELETE NOT POSSIBLE." << endl;
    }
    else {
        head = head->next;
        head->prev = NULL;
        cout << "Deleted Data is : " << temp->data << endl;
        delete temp;
    }
}

void dlinkedlist::deletelast() {
    node* temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    cout << "Deleted Data is : " << temp->data << endl;
    delete temp;
}

void dlinkedlist::deletepos() {
    node* temp = head, * pre = NULL;
    int pos;
    cout << "Enter the position which you want to delete: ";
    cin >> pos;
    int count = 1;
    while (pos != count && temp->next != NULL) {
        pre = temp;
        temp = temp->next;
        count++;
    }
    if (count == pos) {
        pre->next = temp->next;
        pre = temp->next;
        pre->prev = temp->prev;
        cout << "Deleted Data is : " << temp->data << endl;
        delete temp;
    }
    else {
        cout << "Deletion not possible." << endl;
    }
}

void dlinkedlist::search() {
    node* temp = head;
    int x;
    cout << "Enter the element you want to search: ";
    cin >> x;
    int count = 1, flag = 0;
    while (temp != NULL) {
        if (temp->data == x) {
            cout << "Data found at position: " << count << " from the start of the list." << endl;
            flag = 1;
            break;
        }
        temp = temp->next;
        count++;
    }
    if (!flag) {
        cout << "Data not in the list." << endl;
    }
    else {
        node* temp = tail;
        int count = 1, flag1 = 0;
        while (temp != NULL) {
            if (temp->data == x) {
                cout << "Data found at position: " << count << " from the end of the DLL." << endl;
                flag1 = 1;
                break;
            }
            temp = temp->prev;
            count++;
        }
        if (!flag1) {
            cout << "Data not in the list." << endl;
        }
    }
}

void dlinkedlist::revsearch() {
    node* temp = tail;
    int x;
    cout << "Enter the element you want to search: ";
    cin >> x;
    int count = 1, flag = 0;
    while (temp != NULL) {
        if (temp->data == x) {
            cout << "Data found at position: " << count << " from the end of the DLL." << endl;
            flag = 1;
            break;
        }
        temp = temp->prev;
        count++;
    }
    if (!flag) {
        cout << "Data not in the list." << endl;
    }
}

int main() {
    dlinkedlist l1;
    int n;
    cout << "Enter the number of elements you want to enter: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        l1.create();
    }
    cout << "Your created list is : ";
    l1.display();
    cout << endl;
    cout << "Your created list in reverse order: ";
    l1.revdisplay();
    cout << endl;
    //l1.insertlast();
    //cout<<endl;
    //l1.insertfirst();
    //l1.insertpos();
    //l1.deletebegin();
    //l1.deletelast();
    //l1.deletepos();
    l1.search();
    cout << endl;
    //l1.revsearch();
    return 0;
}