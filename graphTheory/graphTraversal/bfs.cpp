#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    if (n == 0)
        return;
    vector<vector<int>> edges(n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<bool> visited(n, false);
    queue<int> qu;
    qu.push(0);
    while (!qu.empty())
    {
        int top = qu.front();
        cout << top << " ";
        for (int e : edges[top])
        {
            if (!visited[e])
            {
                visited[e] = true;
                qu.push(e);
            }
        }
    }
}

int main()
{
    solve();
    return 0;
}