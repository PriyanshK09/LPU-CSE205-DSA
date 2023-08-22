#include <iostream>
using namespace std;
int main(){
    // Addition of 2 arrays of Different Sizes
    int n, n2;
    cout << "Enter the size of the first array: ";
    cin >> n;
    cout << "Enter the size of the second array: ";
    cin >> n2;
    int arr[n], arr2[n2];
    cout << "Enter the elements of the first array: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << "Enter the elements of the second array: ";
    for(int i=0; i<n2; i++){
        cin >> arr2[i];
    }

    int sum[n+n2];
    for(int i=0; i<n; i++){
        sum[i] = arr[i];
    }
    for(int i=0; i<n2; i++){
        sum[i+n] = arr2[i];
    }
    cout << "The sum of the two arrays is: ";
    for(int i=0; i<n+n2; i++){
        cout << sum[i] << " ";
    }
    return 0;
}