#include <iostream>
using namespace std;

#define MAX 5

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
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return ((rear + 1) % MAX == front);
    }

    int count() {
        if (isEmpty())
            return 0;
        return (rear >= front) ? (rear - front + 1) : (MAX - (front - rear) + 1);
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }

        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % MAX;
        } while (i != (rear + 1) % MAX);

        cout << endl;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is Full" << endl;
            return;
        }
        else if (isEmpty()) {
            rear = front = 0;
            arr[rear] = val;
        }
        else {
            rear = (rear + 1) % MAX;
            arr[rear] = val;
        }
    }

    int dequeue() {
        int x = 0;
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return x;
        }
        else if (rear == front) {
            x = arr[rear];
            rear = front = -1;
            return x;
        }
        else {
            x = arr[front];
            arr[front] = 0;
            front = (front + 1) % MAX;
            return x;
        }
    }
};

int main() {
    CircularQueue q1;

    cout << "Enqueueing elements: ";
    for (int i = 1; i <= 5; i++) {
        q1.enqueue(i * 10);
    }
    q1.display();

    cout << "Dequeuing elements: ";
    for (int i = 0; i < 3; i++) {
        cout << q1.dequeue() << " ";
    }
    cout << endl;

    cout << "Enqueueing more elements: ";
    for (int i = 6; i <= 8; i++) {
        q1.enqueue(i * 10);
    }
    q1.display();

    return 0;
}