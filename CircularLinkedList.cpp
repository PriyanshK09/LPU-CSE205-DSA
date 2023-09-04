* Circular Linked List*
#include<iostream>
#include<stdlib.h>
using namespace std;
class node
{
	public:
    int data;
    node *next;
};

class CLL
{
	public:
	node *head, *temp;
	CLL()
	{
		head=NULL;
		temp=NULL;
	}
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
void CLL::createCLL()
	{
    	node *newnode=new node;
    	cout<<"Enter Data :";
    	cin>>newnode->data;
    	newnode->next=NULL;

	    if(head==NULL){
    	    head=newnode;
        	head->next = newnode;
    	}
    	else{
        	newnode->next = head->next;
        	head->next = newnode;
        	head = newnode;
    	}
 }


void CLL::insertAtBeginning()
{
    node *newnode=new node;
    cout<<"Enter Data ";
    cin>>newnode->data;
    newnode->next=NULL;

    if(head==NULL){
        head = newnode;
        head->next = newnode;
    }
    else{
        newnode->next = head->next;
        head->next = newnode;
    }
}

void CLL::insertAtEnd()
{
    node *newnode=new node;
    
    cout<<"Enter Data ";
    cin>>newnode->data;

    newnode->next = head->next;
    head->next = newnode;
    head = newnode;
}

int CLL::getLength()
{
    int count=0;

    temp = head->next;
    while(temp->next != head->next)
    {
        count++;
        temp = temp->next;
    }
    return count+1;
}

void CLL::insertAtPosition()
{
    int i=1, position;
    node *newnode=new node;
    //newnode = (struct node *)malloc(sizeof(newnode));

    cout<<"Enter Position ";
    cin>>position;

    int l = getLength();

    if(position<1 || position> l+1){
        printf("INVALID POSITION");
    }
    else if(position == 1){
        insertAtBeginning();
    }
    else if(position == l+1){
        insertAtEnd();
    }
    else{
        newnode = new node;
        cout<<"Enter Data ";
        cin>>newnode->data;
        newnode->next=NULL;

        temp = head->next;
        while(i<position-1){
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void CLL::deleteFromBeginning()
{
    temp = head->next;
    if(head==0){
        cout<<"LIST IS EMPTY!!!\N";
    }
    else if(temp->next==temp){
        head=0;
        delete temp;
    }
    else{
        head->next = temp->next;
        delete temp;
    }
}

void CLL::deleteFromEnd()
{
    node *current, *previous;
    current = head->next;

    if(head==0){
        cout<<"LIST IS EMPTY\n";
    }
    else if(current->next == current){
        head = 0;
        delete current;
    }
    else{
        while(current->next != head->next){
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        head = previous;
        delete current;
    }
}

void CLL::deleteFromPosition()
{
    node *current, *previous;
    int position, i=1;

    cout<<"Enter Position ";
    cin>>position;

    int l = getLength();

    if(position<1 || position>l){
        cout<<"INVALID POSITION!!!\n";
    }
    else if(position==1){
        deleteFromBeginning();
    }
    else if(position==l){
        deleteFromEnd();
    }
    else{
        current = head->next;
        while(i<position){
            previous = current;
            current = current->next;
            i++;
        }
        previous->next = current->next;

        delete current;
    }
}

void CLL::reverse()
{
    node *current, *prev, *nextnode;

    current = head->next;
    nextnode = current->next;

    if(head == 0){
        cout<<"LIST IS EMPTY!!!\n";
    }
    while(current != head)
    {
        prev = current;
        current = nextnode;
        nextnode = current->next;
        current->next = prev;
    }
    nextnode->next = head;
    head = nextnode;
}


void CLL::display()
{
   if(head==0)
   {
       printf("LIST is EMPTY\n");
   }
   else{
    temp = head->next;
   }

   while(temp->next != head->next)
   {
       cout<<temp->data<<"==>";
       temp = temp->next;
   }
   cout<<temp->data;
}

int main()
{
 	CLL c;
    int n;
    cout<<"No of node: ";
    cin>>n;
    for(int i=0;i<n;i++)
	 	c.createCLL();

 	c.display();
 	c.insertAtBeginning();
 	c.insertAtEnd();
 	cout<<"length :"<<c.getLength();
 	c.insertAtPosition();
 	c.display();
 	cout<<endl;
 	c.reverse();
 	c.display();
	 c.deleteFromBeginning();
 	c.deleteFromEnd();
 	c.deleteFromPosition();
 	c.display();
 	return 0;

}