#include <iostream>
using namespace std;
int main(){
    int n,n2;
    cin>>n;
    int arr1[n];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    cin>>n2;
    int arr2[n2];
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    
    int temp=n+n2;
    int arr3[temp];
    int i=0,j=0,k=0;
    while(i<n)
    arr3[k++]=arr1[i++];
    while(j<n2)
    arr3[k++]=arr2[j++];
    for(int i=0;i<temp;i++){
        cout<<arr3[i]<<" ";
    }

}