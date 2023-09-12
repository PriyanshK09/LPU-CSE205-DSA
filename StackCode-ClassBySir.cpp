#include<iostream>
#define MAXSIZE 5
using namespace std;
class Stack{
	
	int  top;
	int s[MAXSIZE];
	public:
	    Stack(){
	    	top=-1;
		}
		void push(int);
		int pop();
		bool isFull();
		bool isEmpty();
		int getTop();   // return topmost element in the stack
};
int Stack::getTop(){
	int t=-1;
	if(top==-1){
		cout<<"Stack is underflow!"<<endl;
	}
	else{
		t=s[top];
		
	}
	return t;
}

bool  Stack::isEmpty(){
	if(top==-1){
		return true;
	}
	else{
		return false;
	}
}
bool Stack::isFull(){
	if(top==MAXSIZE-1){
		return true;
	}
	else{
		return false;
	}
}
void Stack::push(int x){
	if(top==MAXSIZE-1){
		cout<<"stack is overflow!"<<endl;
	}
	else{
	top++;
	s[top]=x;
	}
}
int Stack::pop(){
	int t=-1;
	if(top==-1){
		cout<<"Stack is underflow!"<<endl;
	}
	else{
		t=s[top];
		top--;
		
	}
	return t;
}
int main(){
	Stack s;
	s.push(6);
	s.push(2);
	s.push(9);
	cout<<"Deleted element: "<<s.pop()<<endl;;
	s.push(7);
	cout<<"Deleted element: "<<s.pop()<<endl;
	cout<<"Deleted element: "<<s.pop()<<endl;
	cout<<"Top element: "<<s.getTop()<<endl;
    cout<<"Deleted element: "<<s.pop()<<endl;
	cout<<"Empty or not: "<<s.isEmpty()<<endl;
	cout<<"Ful or not: "<<s.isFull()<<endl;
	for(int i=0;i<7;i++){
		s.push(i*i);
	}
	return 0;
}