#include<bits/stdc++.h>
using namespace std;
class dsu
{
    vector<int> parent, size, rank;
public:
    dsu(int n)
    {
        for (int i = 0; i < n; i++)
        {
            parent.push_back(i);
            size.push_back(1);
            rank.push_back(0);
        }
    }
    int findPar(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        // path compression
        return parent[node] = findPar(parent[node]);
    }
    void unionSize(int u, int v)
    {
        int pu = findPar(u);
        int pv = findPar(v);
        if (pu == pv)
            return;
        // attach smaller to bigger
        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
    void unionRank(int u, int v){
        int pu = findPar(u);
        int pv = findPar(v);
        if(pu == pv) return;

        if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu]) {
         parent[pv] = pu;
        }
        else {
            // attach pv under pu
            parent[pv] = pu;  
            // increase rank of new root
            rank[pu]++; 
        } 
    }
};
void solve() {
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0; i<m ; i++) {
        int u,v,w;cin>>u>>v>>w;
        u--;
        v--;
        edges.push_back({w,{u,v}});
    }
    sort(edges.begin(),edges.end());
    dsu d(n);
    long long sum = 0;
    for(auto& edge : edges){
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(d.findPar(u) != d.findPar(v)){
            sum += wt;
            d.unionRank(u,v);
            cout<<u<<" "<<v<<" "<<wt<<endl;
        }
    }
    cout<<sum<<endl;
}
int main() {
    solve();
    return 0;
}