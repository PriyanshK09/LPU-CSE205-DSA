#include <iostream>
using namespace std;

class node {
public:
    node* left;
    int data;
    node* right;
};

node* root;

class BST {
public:
    BST() {
        root = NULL;
    }
    void insert(int);
    void inOrder(node*);
    void preOrder(node*);
    void postOrder(node*);
};

void BST::inOrder(node* t) {
    if (t != NULL) {
        inOrder(t->left);
        cout << t->data << " ";
        inOrder(t->right);
    }
}

void BST::preOrder(node* t) {
    if (t != NULL) {
        cout << t->data << " ";
        preOrder(t->left);
        preOrder(t->right);
    }
}

void BST::postOrder(node* t) {
    if (t != NULL) {
        postOrder(t->left);
        postOrder(t->right);
        cout << t->data << " ";
    }
}

void BST::insert(int d) {
    node* temp = new node;
    temp->left = NULL;
    temp->right = NULL;
    temp->data = d;

    if (root == NULL) {
        root = temp;
    } else {
        node* curr = root;
        node* prev = NULL; // Initializing prev to NULL

        while (curr != NULL) {
            prev = curr;
            if (d > curr->data) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }

        // Inserting at the appropriate position
        if (d > prev->data) {
            prev->right = temp;
        } else {
            prev->left = temp;
        }
    }
}

int main() {
    BST b;
    b.insert(30);
    b.insert(40);
    b.insert(60);
    b.insert(50);

    cout << "inOrder: " << endl;
    b.inOrder(root);
    cout << endl;

    cout << "preOrder: " << endl;
    b.preOrder(root);
    cout << endl;

    cout << "postOrder: " << endl;
    b.postOrder(root);
    cout << endl;

    return 0;
}