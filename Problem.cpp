#include <iostream>
#include <list>

using namespace std;

int main() {
    int N;
    cin >> N;

    list<int> doublyLinkedList;

    // Insert elements at the end of the doubly linked list
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        doublyLinkedList.push_back(num);
    }

    int M;
    cin >> M;

    // Perform deletion operations
    for (int i = 0; i < M; i++) {
        int position;
        cin >> position;

        // Ensure the position is within valid bounds
        if (position > 0 && position <= doublyLinkedList.size()) {
            list<int>::iterator deletePos = doublyLinkedList.begin();
            advance(deletePos, position - 1);
            doublyLinkedList.erase(deletePos);
        }
    }

    // Print the elements of the doubly linked list
    for (const int& value : doublyLinkedList) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
