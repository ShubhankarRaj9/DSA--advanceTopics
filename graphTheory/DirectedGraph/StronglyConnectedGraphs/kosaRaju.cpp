#include<bits/stdc++.h>
using namespace std;

stack<int> st;
vector<int> temp;
vector<vector<int>> scc;
void dfs(int node, vector<int> adj[], vector<int>& vis){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(vis[it] == 0) {
            dfs(it,adj,vis);
        }
    }
    st.push(node);
}
void dfs2(int node, vector<int> tadj[], vector<int>& vis){
    vis[node] = 1;
    temp.push_back(node);
    for(auto it: tadj[node]){
        if(vis[it] == 0) {
            dfs2(it,tadj,vis);
        }
    }
}

void solve() {
    int n,m; cin>>n>>m;
    vector<int> adj[n+1],tadj[n+1];
    for(int i=0; i<m; i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        tadj[v].push_back(u);
    }

    vector<int> vis(n+1,0);
    for(int i=1; i<=n ; i++){
        if(vis[i] == 0) {
            dfs(i,adj,vis);
        }
    }
    fill(vis.begin(),vis.end(),0);
    while(!st.empty()){
        int node = st.top();st.pop();
        if(vis[node] == 0){
            dfs2(node,tadj,vis);
            scc.push_back(temp);
            temp.clear();
        }
    }
    cout<<scc.size()<<endl;
    for(auto it : scc){
        for(int j: it){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}



int main() {
    solve();
    return 0;
}