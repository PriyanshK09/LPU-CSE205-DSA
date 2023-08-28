#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *link;
};

class linked_list
{
    public
    node *head;
    linkedList(){
        head = NULL;
    }
    void insert(int x){
        node *temp = new node;
        temp->data = x;
        temp->link = head;
        head = temp;
    }
};