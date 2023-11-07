#include <iostream>

#define SIZE 10

int table[SIZE];
int size = SIZE;

void initialize() {
    for (int i = 0; i < size; i++) {
        table[i] = -1;
    }
}

int hash(int key) {
    return key % size;
}

void insert(int key) {
    int index = hash(key);
    while (table[index] != -1) {
        index = (index + 1) % size;
    }
    table[index] = key;
}

void display() {
    for (int i = 0; i < size; i++) {
        std::cout << i << ": " << table[i] << std::endl;
    }
}

int main() {
    initialize();
    insert(5);
    insert(15);
    insert(25);
    insert(35);
    insert(45);
    display();
    return 0;
}