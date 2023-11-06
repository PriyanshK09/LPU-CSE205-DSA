#include <iostream>
#define n 4
#define INF 99999 // INF is a macro for infinity
using namespace std;

void Warshall(int g[][4])
{
    int i, j, k;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                g[i][j] = g[i][j] || (g[i][k] && g[k][j]);
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (g[i][j] == INF)
                cout << "INF" << "\t";
            else
                cout << g[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int g[n][n] =
    {
        // {7, 5, INF, INF},
        // {7, INF, INF, 2},
        // {INF, 3, INF, INF},
        // {4, INF, 1, INF}

        // {INF, 3, INF, 7},
        // {8, INF, 2, INF},
        // {5, INF, INF, 1},
        // {2, INF, INF, INF}

        {0, 1, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0},
        {1, 0, 1, 0}
    };

    Warshall(g);
    return 0;
}