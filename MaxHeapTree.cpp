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
}

void buildMaxHeap(int a[], int n)
{
    for(int i=n/2-1;i>=0;i--)
        heapify(a,n,i);
}

int main()
{
    int n;
    cin >> n;
    int a[n];

    for(int i=0;i<n;i++)
        cin >> a[i];

    buildMaxHeap(a,n);

    for(int i=0;i<n;i++)
        cout << a[i] << " ";

    return 0;
}