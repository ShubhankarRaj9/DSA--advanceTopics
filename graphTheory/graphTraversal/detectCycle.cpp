#include <bits/stdc++.h>
using namespace std;
void dfs(int curr, vector<vector<int>> &edges, vector<bool> &visited, int parent)
{
    visited[curr] = true;
    for (int e : edges[curr])
    {
        if(e == parent){
            continue;
        }
        if (!visited[e])
        {
            dfs(e, edges, visited,curr);
        }else{
            cout<<"Cycle Found"<<endl;
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
    for(int i=0 ; i<n; i++){
        if(!visited[i]){
            dfs(i,edges,visited,-1);
            
        }
    }
   
    cout<<endl;
}

int main()
{
    solve();
    return 0;
}