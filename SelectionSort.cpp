#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    int a[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    //Selection Sort

    for(int i=0;i<n-1;i++){
        int loc = i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[loc]){
                loc = j;
            }
            if(loc!=i){
                int temp = a[i];
                a[i] = a[loc];
                a[loc] = temp;

            }
        }
    }

    cout<<"The sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}