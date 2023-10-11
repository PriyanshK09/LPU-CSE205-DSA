// You are using GCC
#include <iostream>
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
    node *deleteNode(node *, int);
    // node *search(int k); // non recursive
    // node *search(node *r, int k);
};
node *BST::deleteNode(node *rt, int key)
{
    if (rt == NULL)
    {
        cout << "\nElement not found :" << key << endl;
        return rt; // NULL
    }
    else
    {
        if key
            < rt->data
                    rt->left = deleteNode(rt->left, key);
        else if key
            > rt->data
                    rt->right = deleteNode(rt->right, key);
        else
        {
            // case 1: no child
            if (rt->left == NULL)
            {
                node *temp = rt->right;
                delete (rt);
                return temp;
            }
            // case 2: one child
            else if (rt->right == NULL)
            {
                node *temp = rt->left;
                delete (rt);
                return temp;
            }
            // case 3: two child
            else
            {
                node *temp = rt->right;
                while (temp->left != NULL)
                {
                    temp = temp->left;
                }
                rt->data = temp->data;
                rt->right = deleteNode(rt->right, temp->data);
            }
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
void BST ::insert_Node(int d)
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
int main()
{
    BST b;
    node *p;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        b.insert_Node(d);
    }
    b.inorder(root);
    b.deleteNode(20);
    cout << "\n After delete the node " << endl;
    b.inorder(root);

    return 0;
}