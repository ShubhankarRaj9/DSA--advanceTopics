#include <bits/stdc++.h>
using namespace std;
void dfs(int curr, vector<vector<int>> &edges, vector<bool> &visited)
{
    visited[curr] = true;
    cout << curr << " ";
    for (int e : edges[curr])
    {
        if (!visited[e])
        {
            dfs(e, edges, visited);
        }
    }
}
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
    dfs(0, edges, visited);
}

int main()
{
    solve();
    return 0;
}