#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() : head(nullptr) {}

    void createCLL();
    void display();
    void insertAtBeginning();
    void insertAtEnd();
    int getLength();
    void insertAtPosition();
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteFromPosition();
    void reverse();
};

void CircularLinkedList::createCLL() {
    int value;
    cout << "Enter Data: ";
    cin >> value;

    Node* newNode = new Node(value);

    if (!head) {
        head = newNode;
        head->next = head;
    } else {
        newNode->next = head->next;
        head->next = newNode;
        head = newNode;
    }
}

void CircularLinkedList::insertAtBeginning() {
    int value;
    cout << "Enter Data: ";
    cin >> value;

    Node* newNode = new Node(value);

    if (!head) {
        head = newNode;
        head->next = head;
    } else {
        newNode->next = head->next;
        head->next = newNode;
    }
}

void CircularLinkedList::insertAtEnd() {
    int value;
    cout << "Enter Data: ";
    cin >> value;

    Node* newNode = new Node(value);

    if (!head) {
        head = newNode;
        head->next = head;
    } else {
        newNode->next = head->next;
        head->next = newNode;
        head = newNode;
    }
}

int CircularLinkedList::getLength() {
    if (!head)
        return 0;

    int count = 1;
    Node* temp = head->next;
    while (temp != head) {
        count++;
        temp = temp->next;
    }
    return count;
}

void CircularLinkedList::insertAtPosition() {
    int position, value;
    cout << "Enter Position: ";
    cin >> position;
    int length = getLength();

    if (position < 1 || position > length + 1) {
        cout << "INVALID POSITION" << endl;
    } else if (position == 1) {
        insertAtBeginning();
    } else if (position == length + 1) {
        insertAtEnd();
    } else {
        cout << "Enter Data: ";
        cin >> value;
        Node* newNode = new Node(value);

        Node* temp = head->next;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void CircularLinkedList::deleteFromBeginning() {
    if (!head) {
        cout << "LIST IS EMPTY!!!" << endl;
        return;
    }

    if (head->next == head) {
        delete head;
        head = nullptr;
    } else {
        Node* temp = head->next;
        head->next = temp->next;
        delete temp;
    }
}

void CircularLinkedList::deleteFromEnd() {
    if (!head) {
        cout << "LIST IS EMPTY!!!" << endl;
        return;
    }

    if (head->next == head) {
        delete head;
        head = nullptr;
    } else {
        Node* temp = head->next;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        delete head;
        head = temp;
    }
}

void CircularLinkedList::deleteFromPosition() {
    int position;
    cout << "Enter Position: ";
    cin >> position;
    int length = getLength();

    if (position < 1 || position > length) {
        cout << "INVALID POSITION!!!" << endl;
    } else if (position == 1) {
        deleteFromBeginning();
    } else if (position == length) {
        deleteFromEnd();
    } else {
        Node* temp = head->next;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }
}

void CircularLinkedList::reverse() {
    if (!head) {
        cout << "LIST IS EMPTY!!!" << endl;
        return;
    }

    Node* current = head;
    Node* prev = nullptr;
    Node* nextNode = head->next;

    do {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    } while (current != head);

    head = prev;
}

void CircularLinkedList::display() {
    if (!head) {
        cout << "LIST IS EMPTY" << endl;
    } else {
        Node* temp = head->next;
        do {
            cout << temp->data << " ==> ";
            temp = temp->next;
        } while (temp != head);
        cout << temp->data << endl;
    }
}

int main() {
    CircularLinkedList c;
    int n;
    cout << "No of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
        c.createCLL();

    c.display();
    c.insertAtBeginning();
    c.insertAtEnd();
    cout << "Length: " << c.getLength() << endl;
    c.insertAtPosition();
    c.display();
    cout << endl;
    c.reverse();
    c.display();
    c.deleteFromBeginning();
    c.deleteFromEnd();
    c.deleteFromPosition();
    c.display();

    return 0;
}