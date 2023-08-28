#include<iostream>
using namespace std;
class node{
public:
int data;
node *link;
};
class linkedlist{
public:
node *head;
linkedlist(){
head=NULL;
}
void create();
void display();
};
void linkedlist::create(){
int n;
node *temp=new node;
cout<<"Enter the data insert into node: ";
cin>>n;
temp->data=n;
temp->link=NULL;
if(head==NULL){
head=temp;
}
else{
node *t=head;
while(t->link!=NULL){
t=t->link;
}
t->link=temp;
}
}
void linkedlist::display(){
node *t=head;
while(t!=NULL){
if(t->link!=NULL){
cout<<t->data<<" ==> ";
}
else{
cout<<t->data;
}
t=t->link;
}
}
int main(){
linkedlist l1;
int n;
cout<<"Enter the number of elements you want to enter: ";
cin>>n;
for(int i=0;i<n;i++){
l1.create();
}
cout<<"Your created list is : ";
l1.display();
return 0;
}