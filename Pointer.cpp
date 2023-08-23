#include <iostream>
using namespace std;
int main(){
    int x=7;
    int *p;
    p=&x;

    cout<<x<<endl;
    cout<<&x<<endl;
    cout<<p<<endl;
    cout<<*p<<endl;

    cout<<sizeof(x)<<endl; 
    // Why 4 bytes? Because x is an integer and it takes 4 bytes of memory

    cout<<sizeof(p)<<endl;
    // Why 8 bytes? Because p is a pointer and it takes 8 bytes of memory

    int *pp;
    cout<<pp<<endl;

    return 0;
}