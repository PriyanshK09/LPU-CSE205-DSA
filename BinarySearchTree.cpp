//TREE
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
         root=NULL;
     }
     void insert_Node(int );
     void inorder(node *);
     node *search(int k); //non recursive
     node *search(node *r, int k);  //recursive
};
node *BST::search(node *t, int k){
	if(t==NULL || t->data==k){ 
		return t;
	}
	else{
		
		if(k>t->data)
		t=search(t->right, k);
		
		else 
		t=search(t->left, k);
	}
}

node *BST::search(int k){
	node *t=root;
	while(t){
		if(t->data==k)
		return t;
		else if(k<t->data)
		t=t->left;
		else
		t=t->right;
	}
	return NULL;
}

void BST::inorder(node *p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        cout<<p->data<<" ";
        inorder(p->right);
    }
}
void BST ::insert_Node(int d)
{
    node *temp=new node;
    
    temp->left=NULL;
    temp->right=NULL;
    temp->data=d;
    
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        node *cur=root;
        node *pre=NULL;
        while(cur!=NULL)
        {
            pre=cur;
            if( d < cur->data)
                cur=cur->left;
             else
                cur=cur->right;
        }
       if( d < pre->data)
          {
              pre->left=temp;
          }
          else
          {
              pre->right=temp;
          }
        
    }
}
int main()
{
   BST b;
   node *p;
   int n;
   cin>>n;
   
   for(int i=0;i<n;i++)
   {  int d;
        cin>>d;
        b.insert_Node(d);
   }
   b.inorder(root);
   /*p=b.search(35);
   cout<<endl;
   if(p!=NULL)
   cout<<"data found"<<p->data<<endl;
   else
   cout<<"data not found"<<p->data<<endl;  
    */
    p=b.search(root, 15);
   cout<<endl;
   if(p!=NULL)
   cout<<"data found"<<p->data<<endl;
   else
   cout<<"data not found"<<p->data<<endl;
}