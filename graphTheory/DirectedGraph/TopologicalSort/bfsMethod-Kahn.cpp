#include <bits/stdc++.h>
using namespace std;

void bfs(int currNode, vector<vector<int>> &adjList, vector<int> &indeg, vector<int> &vis, vector<int> &st)
{
    queue<int> q;
    q.push(currNode);
    vis[currNode] = 1;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        st.push_back(front);
        for (auto nextNode : adjList[front])
        {
            indeg[nextNode]--;
            if (indeg[nextNode] == 0 && !vis[nextNode])
            {
                q.push(nextNode);
                vis[nextNode] = 1;
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(n + 1);
    vector<int> indeg(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        indeg[v]++;
    }

    vector<int> vis(n + 1, 0);
    vector<int> st;
    for (int i = 1; i <= n; i++)
    {
        if (!indeg[i] && !vis[i])
        {
            bfs(i, edges, indeg, vis, st);
        }
    }
    for (auto val : st)
    {
        cout << val << " ";
    }
}

int main()
{
    solve();
    return 0;
}