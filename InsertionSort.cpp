// Problem Statement
// Given an array of integers, sort the odd positions in descending order and even positions in ascending order using insertion sort.
// Example 1:
// Input Format:
// • The first line of input should contain an integer n, representing the number of elements in the array.
// • The second line of input should contain n space-separated integers, representing the elements of the array.
// Input:
// N: 10
// Array Element: 25 36 96 58 74 14 35 15 75 95
// Output Format:
// • The program will sort the array using the even-odd insertion sort algorithm and print the sorted array.
// Output:
// 96 14 75 15 74 36 35 58 25 95 
// Input format :
// The first line of input consists of the number of integers N.
// The second line of input consists of the array of elements separated by space.
// Output format :
// The output displays the sorted array using the even-odd insertion sort algorithm and prints the sorted array.
// Sample test cases :
// Input 1 :
// 10 25 36 96 58 74 14 35 15 75 95
// Output 1 :
// 96 14 75 15 74 36 35 58 25 95 

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while ((temp > arr[j]) && (j >= 0))
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}

int main()
{
    int n, i, j, temp;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int even[n / 2], odd[n / 2];
    int e = 0, o = 0;
    for (i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            even[e] = arr[i];
            e++;
        }
        else
        {
            odd[o] = arr[i];
            o++;
        }
    }

    insertionSort(even, e);
    insertionSort(odd, o);

    int k = 0;
    for (i = 0; i < e; i++)
    {
        arr[k] = even[i];
        k++;
    }
    for (i = 0; i < o; i++)
    {
        arr[k] = odd[i];
        k++;
    }

    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}