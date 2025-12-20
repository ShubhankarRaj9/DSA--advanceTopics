#include <bits/stdc++.h>
using namespace std;
void dfs(int curr, vector<vector<int>>& edges,  vector<int>& color)
{
    for (int e : edges[curr])
    {
        if (!color[e])
        {
            color[e] = color[curr] == 1 ? 2:1;
            dfs(e, edges, color);
        }
        else if(color[e] == color[curr]){
            cout<<"NOT A Bipartite"<<endl;
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<int> colors(n,0);
    for(int i=0 ;i<n ;i++){
        if(colors[i]==0){
            colors[i] = 1;
            dfs(i,edges,colors);
        }
    }
    for(auto color: colors){
        cout<<color<<" ";
    }
}

int main()
{
    solve();
    return 0;
}