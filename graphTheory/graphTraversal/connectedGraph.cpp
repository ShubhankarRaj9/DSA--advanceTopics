#include <bits/stdc++.h>
using namespace std;
void dfs(int curr, vector<vector<int>> &edges, vector<bool> &visited, vector<int> & comp, int count)
{
    visited[curr] = true;
    comp[curr] = count;
    for (int e : edges[curr])
    {
        if (!visited[e])
        {
            dfs(e, edges, visited,comp,count);
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
    vector<int> component(n);
    int count = 0;
    vector<bool> visited(n, false);
    for(int i=0 ; i<n; i++){
        if(!visited[i]){
            dfs(i,edges,visited,component,count);
            count++;
        }
    }
    for(auto i: component){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main()
{
    solve();
    return 0;
}