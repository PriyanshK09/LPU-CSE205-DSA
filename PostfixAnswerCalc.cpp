// You are using GCC
#include<iostream>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAXSIZE 50

using namespace std;
class Stack{
	
	int  top;
	int s[MAXSIZE];
	int n,n1,n2,n3;
	
	public:
	    Stack(){
	    	top=-1;
		}
		void push(int);
		int pop();
		bool isFull();
		bool isEmpty();
		int getTop();   // return topmost element in the stack
		void calculate(char *str);
};

void Stack::calculate(char *str)
{
    
    while (*str)
    {
        if (*str == ' ' || *str == '\t')
        {
            str++;
            continue;
        }
        if (isdigit(*str))
        {
            n = *str- '0';
            push(n);
        }
        else
        {
            n2 = pop();
            n1 = pop();
            switch(*str)
            {
                case '+':
                    n3=n1+n2;
                    break;
                case '-':
                    n3=n1-n2;
                    break;
                case '*':
                    n3=n1*n2;
                    break;
                case '/':
                    n3=n1/n2;
                    break;
                case '^':
                    n3=pow(n1,n2);
                    break;
                default:
                    cout<<"Invalid operator";
                    exit(1);
                
            }
            push(n3);
        }
        *str++;
    }
    
    cout << pop() << endl;

}

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
	char expr[50];
    cin.getline(expr,MAXSIZE);
	s.calculate(expr);
	
	return 0;
}