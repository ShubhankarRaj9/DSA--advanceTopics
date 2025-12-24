#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;cin>>n>>m;
    vector<pair<int,int>> edges[n+1];
    for(int i=0 ; i<m; i++){
        int u,v,wt;cin>>u>>v>>wt;
        edges[u].push_back({v,wt});
        edges[v].push_back({u,wt});
    }
   priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>> pq;

    vector<int> visited(n+1,0);
    pq.push({0,{1,-1}});
    int sum = 0;
    vector<pair<int,int>> finalEdges;
    while(!pq.empty()){
        int node = pq.top().second.first;
        int dist = pq.top().first;
        int par = pq.top().second.second;
        pq.pop();
        if(visited[node] == 1) continue;
        visited[node] = 1;
        finalEdges.push_back({par,node});
        sum += dist;
        for(auto edge : edges[node]){
            if(visited[edge.first] == 0)
                pq.push({edge.second,{edge.first,node}});
        }
    }
    cout<<sum<<"\n";
    for(auto p: finalEdges){
        cout<<p.first<<" "<<p.second<<endl;
    }
}
int main() {
    solve();
    return 0;
}