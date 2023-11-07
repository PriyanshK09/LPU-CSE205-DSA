// You are using GCC
// Division Method
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of Array: " << endl;
    cin >> n;
    
    int arr[n];
    cout << "Enter the elements of Array: " << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cout << "The Hash Table is: " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << i << " --> " << arr[i] % 10 << endl;
    }
    
    return 0;
}