#include <iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter a Number you want to check: ";
    cin>>a;

    b=a%2;
    if (b==0)
    {
        cout<<"The given number is Even";
    }
    else
        cout<<"The given number is Odd";
    
}