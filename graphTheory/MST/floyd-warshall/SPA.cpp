/* Brute force Dp algo in graph */

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjMatrix(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++)
    {
        adjMatrix[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adjMatrix[u][v] = min(wt, INT_MAX);
    }
    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adjMatrix[i][via] == INT_MAX || adjMatrix[via][j] == INT_MAX)
                    continue;
                adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][via] + adjMatrix[via][j]);
            }
        }
    }
    for (auto &cost : adjMatrix)
    {
        for (int val : cost)
        {
            if (val == INT_MAX)
                cout << "INF ";
            else
                cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    solve();
    return 0;
}