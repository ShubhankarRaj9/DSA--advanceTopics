#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void dfs(int node, vector<vector<pair<int, int>>> &adj, vector<int> &vis, int j)
{
    vis[node] = 1;
    cnt++;
    for (auto it : adj[node])
    {
        if (vis[it.first])
            continue;
        dfs(it.first, adj, vis, j);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    int ans = (1 << 30) - 1;
    vector<int> visited(n + 1);
    vector<vector<pair<int, int>>> temp(n + 1);

    for (int via = 29; via >= 0; via--)
    {
        for (int i = 1; i <= 29; i++)
        {
            temp[i].clear();
            for (auto it : adj[i])
            {
                if (((it.second >> 1) & 1) == 0)
                    temp[i].push_back(it);
            }
        }
        ans -= (1 << via);
        fill(visited.begin(), visited.end(), 0);
        cnt = 0;
        dfs(1, temp, visited, via);
        if (cnt < n)
        {
            ans += (1 << via);
        }
        if (((ans >> via) & 1) == 0)
            adj = temp;
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}