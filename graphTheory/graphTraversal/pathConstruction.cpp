#include <bits/stdc++.h>
using namespace std;
void dfs(int curr, vector<vector<int>> &edges, vector<bool> &visited, vector<int>& parent)
{
    visited[curr] = true;
    for (int e : edges[curr])
    {
        if (!visited[e])
        {
            parent[e] = curr;
            dfs(e, edges, visited,parent);
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
    vector<int> parent(n,-1);
    vector<bool> visited(n, false);
    int start,end; cin>>start>>end;
    dfs(start,edges,visited,parent);
    if(parent[end] == -1) {
        cout<<"No Path"<<endl;
    }
    else{
        int curr= end;
        while(!parent[curr] != -1){
        cout<<curr<<" ";
        curr = parent[curr];
        }
    }
}

int main()
{
    solve();
    return 0;
}