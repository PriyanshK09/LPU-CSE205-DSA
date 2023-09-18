#include <iostream>
#define MAX 5
using namespace std;

class CircularQueue {
private:
    int front;
    int rear;
    int arr[MAX];
public:
    CircularQueue() {
        front = -1;
        rear = -1;
        for (int i = 0; i < MAX; i++) {
            arr[i] = 0;
        }
    }

    bool isEmpty() {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }

    bool isFull() {
        if ((rear + 1) % MAX == front)
            return true;
        else
            return false;
    }

    int count() {
        return (rear + MAX - front) % MAX + 1;
    }

    void display() {
        cout << "All values in the Queue are: " << endl;
        for (int i = 0; i < MAX; i++) {
            cout << arr[i] << "  ";
        }
    }

    // enqueue = insert
    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is Full" << endl;
            return;
        }
        else if (isEmpty()) {
            rear = 0;
            front = 0;
            arr[rear] = val;
        }
        else {
            rear = (rear + 1) % MAX;
            arr[rear] = val;
        }
    }

    // dequeue = delete
    int dequeue() {
        int x = 0;
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return x;
        }
        else if (rear == front) {
            x = arr[rear];
            rear = -1;
            front = -1;
            return x;
        }
        else {
            cout << "Front Value : " << front << endl;
            x = arr[front];
            arr[front] = 0;
            front = (front + 1) % MAX;
            return x;
        }
    }
};

int main()
{
    CircularQueue cq;
    int option, value;

    do {
        cout << "\n\nWhat operation do you want to perform? Select Option number." << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cout << "7. Exit" << endl;

        cin >> option;

        switch (option) {
        case 0:
            break;
        case 1:
            cout << "Enqueue Operation \nEnter an item to Enqueue in the Queue" << endl;
            cin >> value;
            cq.enqueue(value);
            break;
        case 2:
            cout << "Dequeue Operation \nDequeued Value : " << cq.dequeue() << endl;
            break;
        case 3:
            if (cq.isEmpty())
                cout << "Queue is Empty" << endl;
            else
                cout << "Queue is not Empty" << endl;
            break;
        case 4:
            if (cq.isFull())
                cout << "Queue is Full" << endl;
            else
                cout << "Queue is not Full" << endl;
            break;
        case 5:
            cout << "Count Operation \nCount of items in Queue : " << cq.count() << endl;
            break;
        case 6:
            cout << "Display Function Called - " << endl;
            cq.display();
            break;
        case 7:
        // exit
            break;
            return 0;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 7);
}