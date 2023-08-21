#include <iostream>
using namespace std;
int s;
int a[100];

int main(){
    cout<<"Enter the size of array: ";
    cin>>s;
    cout<<"Enter the elements of array: ";
    for(int i=0;i<s;i++){
        cin>>a[i];
    }
    for(int i=0;i<s;i++){
        for(int j=0;j<s-i-1;j++){
            if(a[j]>a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    cout<<"Sorted array is: ";
    for(int i=0;i<s;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}

// Bubble Sort is a method to sort an array in which we compare the adjacent elements and swap them if they are not in the correct order.