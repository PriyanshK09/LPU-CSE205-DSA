#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    int key;
    cin >> key;
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == key){
            cout << "Found at index " << mid << endl;
            return 0;
        }
        else if(arr[mid] > key) high = mid - 1;
        else low = mid + 1;
    }
    cout << "Not Found" << endl;
    return 0;
}