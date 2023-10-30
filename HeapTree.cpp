#include <iostream>
using namespace std;

void heapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2*i+1; // left child index
    int r = 2*i+2; // right child index
    if (l<n && a[l]>a[largest])
        largest = l;
    if (r<n && a[r]>a[largest])
        largest = r;
    if (largest != i)
    {
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }

    // Explanation of Code (Heapify Function) :-
    // We defined a function named heapify which has largest, l, r as variables.
    // largest : It is used to store the index of the largest element.
    // l : It is used to store the index of the left child.
    // r : It is used to store the index of the right child.
    // In the first IF statement we are checking if the left child is greater than the parent node.
    // In the second IF statement we are checking if the right child is greater than the parent node.
    // In the third IF statement we are checking if the largest element is not equal to the parent node.
    // If the largest element is not equal to the parent node then we are swapping the parent node with the largest element.
    // We are calling heapify function again to check if the child node is greater than the parent node.
    // We are doing this recursively.

    // Swap is a function which swaps the value of two variables. Its syntax is :-
    // swap(a,b);
    // This is a inbuilt function in C++.

    // Time Complexity :-
    // Best Case :- O(nlogn)
    // Average Case :- O(nlogn)
    // Worst Case :- O(nlogn)
    // Space Complexity :- O(1)
}

void heapSort(int a[], int n)
{
    for(int i=n/2-1;i>=0;i--)
        heapify(a,n,i);
    for(int i=n-1;i>=0;i--)
    {
        swap(a[0],a[i]);
        heapify(a,i,0);
    }

    // Explanation of Code (HeapSort Function) :-
    // First for loop is used to build the heap tree.
    // Second for loop is used to sort the heap tree.
    // We are swapping the first element with the last element.
    // We are calling heapify function again to check if the child node is greater than the parent node.
    // We are doing this recursively 

    // Time Complexity :-
    // Best Case :- O(nlogn)
    // Average Case :- O(nlogn)
    // Worst Case :- O(nlogn)
    // Space Complexity :- O(1)    
}


int main()
{
    int n;
    cin >> n;
    int a[n];

    for(int i=0;i<n;i++)
        cin >> a[i];

    heapSort(a,n);

    for(int i=0;i<n;i++)
        cout << a[i] << " ";

    return 0;
}