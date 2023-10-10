#include<iostream>
using namespace std;

class node
{
public:
    node *left;
    int data;
    node *right;
};

node *root;

class BST
{
public:

    BST()
    {
        root = NULL;
    }

    void insert_Node(int);
    void inorder(node *);
    node* delete_Node(node*, int);
};

void BST::insert_Node(int d)
{
    node *temp = new node;

    temp->left = NULL;
    temp->right = NULL;
    temp->data = d;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        node *cur = root;
        node *pre = NULL;
        while (cur != NULL)
        {
            pre = cur;
            if (d < cur->data)
                cur = cur->left;
            else
                cur = cur->right;
        }
        if (d < pre->data)
        {
            pre->left = temp;
        }
        else
        {
            pre->right = temp;
        }
    }
}

void BST::inorder(node *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }
}

node* BST::delete_Node(node* root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = delete_Node(root->left, key);
    else if (key > root->data)
        root->right = delete_Node(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }

        node* temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        root->data = temp->data;
        root->right = delete_Node(root->right, temp->data);
    }
    return root;
}

int main()
{
    BST b;
    int elements[] = {30, 20, 5, 15, 50, 45, 35, 60, 25, 22, 47, 80, 2};
    int n = sizeof(elements) / sizeof(elements[0]);

    for (int i = 0; i < n; i++)
    {
        b.insert_Node(elements[i]);
    }

    cout << "Inorder Traversal of BST: ";
    b.inorder(root);
    cout << endl;

    int key_to_delete;
    cout << "Enter the element to delete: ";
    cin >> key_to_delete;

    root = b.delete_Node(root, key_to_delete);

    cout << "Inorder Traversal after deletion: ";
    b.inorder(root);
    cout << endl;

    return 0;
}