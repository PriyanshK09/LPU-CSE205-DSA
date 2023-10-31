// #include <iostream>
// using namespace std;

// int main()
// {
//     int v,e;
//     cout << "Enter the number of Vertex : ";
//     cin >> v;
//     int matrix[v][v];
//     cout << "Enter the number of Edges : ";
//     cin >> e;

//     for (int i = 1; i <= v; i++)
//     {
//         for (int j = 1; j <= v; j++)
//             matrix[i][j] = 0;
//     }

//     for (int i = 1; i <= e; i++)
//     {
//         int r,c;
//         cin >> r >> c;
//         matrix[r][c] = 1;

//         for (int i = 1; i <= e; i++)
//         {
//             for (int j = 1; i <= e; i++)
//             {
//                 cout << matrix[i][j] << " ";
//             }
//             cout << endl;
//         }
//     }

// }

// Input :
// 4
// 4
// 1 2
// 2 3
// 3 4
// 4 1

// Output :
// 0 1 0 0
// 0 0 1 0
// 0 0 0 1
// 1 0 0 0


#include <iostream>
using namespace std;

int main()
{
    int v,e;
    cout << "Enter the number of Vertex : ";
    cin >> v;
    int matrix[v][v];
    cout << "Enter the number of Edges : ";
    cin >> e;

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            matrix[i][j] = 0;
    }

    for (int i = 0; i < e; i++)
    {
        int r,c;
        cin >> r >> c;
        matrix[r-1][c-1] = 1;
    }

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}