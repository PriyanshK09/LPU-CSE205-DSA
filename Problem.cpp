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
    void insert(int);
    void inOrder(node *);
    void preOrder(node *);
    void postOrder(node *);
    node *deletenode(node *, int);
    node *minnode(node *);
};
node *BST::minnode(node *t)
{
    node *cur = new node;
    cur = t;
    while (cur && cur->left != NULL)
    {
        cur = cur->left;
    }
    return cur;
}

node *BST::deletenode(node *rt, int key)
{
    if (rt == NULL)
    {
        cout << "Element is not fund:" << endl;
        return NULL;
    }
    else
    {
        if (key > rt->data)
            rt->right = deletenode(rt->right, key);
        else if (key < rt->data)
            rt->left = deletenode(rt->left, key);
        else
        {
            // one child node
            if (rt->left == NULL)
            {
                node *temp = rt->right;
                delete rt;
                return temp;
            }
            else if (rt->right == NULL)
            {
                node *temp = rt->left;
                delete rt;
                return temp;
            }
            // no child
            else if (rt->left == NULL && rt->right == NULL)
            {
                delete rt;
                return NULL;
            }
            // two child
            node *temp = minnode(rt->right);
            rt->data = temp->data;
            rt->right = deletenode(rt->right, temp->data);
        }
        return rt;
    }
}

void BST::inOrder(node *t)
{
    if (t != NULL)
    {
        inOrder(t->left);
        cout << t->data << " ";
        ;
        inOrder(t->right);
    }
}

void BST::preOrder(node *t)
{
    if (t != NULL)
    {
        cout << t->data << " ";
        ;
        preOrder(t->left);
        preOrder(t->right);
    }
}

void BST::postOrder(node *t)
{
    if (t != NULL)
    {
        postOrder(t->left);
        postOrder(t->right);
        cout << t->data << " ";
    }
}
void BST::insert(int d)
{
    node *temp = new node;
    temp->left = NULL;
    temp->right = NULL;
    temp->data = d;

    if (root == NULL)
        root = temp;
    else
    {
        node *cur = root;
        node *parent;
        while (cur != NULL)
        {
            parent = cur;
            if (d > cur->data)
                cur = cur->right;
            else
                cur = cur->left;
        }
        if (d > parent->data)
            parent->right = temp;
        else
            parent->left = temp;
    }
}

int main()
{
    BST b;
    b.insert(50);
    b.insert(40);
    b.insert(60);
    b.insert(30);
    b.insert(45);
    b.insert(42);
    b.insert(52);
    b.insert(80);
    b.insert(75);
    b.insert(78);
    b.insert(90);
    b.insert(51);
    b.insert(48);
    b.insert(95);
    b.insert(20);

    //  cout<<"inOrder :"<<endl;
    // b.inOrder(root);
    // cout<<"\n preOrder :"<<endl;
    // b.preOrder(root);

    //    cout<<"\n PostOrder :"<<endl;
    //  b.postOrder(root);
    cout << "\n Before deletion preOrder :" << endl;
    b.preOrder(root);
    node *p;
    p = b.deletenode(root, 50);

    cout << "\n Before deletion preOrder :" << endl;
    b.preOrder(root);

    return 0;
}