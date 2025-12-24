#include<bits/stdc++.h>
using namespace std;
void dfs(int currNode, vector<vector<int>>& adjList, stack<int>& st, vector<bool>& visited){
    visited[currNode] = 1;
    for(auto edge: adjList[currNode]){
        if(!visited[edge]){
            dfs(edge,adjList,st,visited);
        }
    }
    st.push(currNode);
}
void solve(){

    int n,m;cin>>n>>m;
    vector<vector<int>> edge(n+1);

    for(int i=0 ; i<m ; i++){
        int u,v; cin>>u>>v;
        edge[u].push_back(v);
    }
    stack<int> st;
    vector<bool> vis(n+1,false);
    for(int i=1 ; i<=n ; i++){
        if(!vis[i]){
            dfs(i,edge,st,vis);
        }
    }
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main() {
    solve();
    return 0;
}