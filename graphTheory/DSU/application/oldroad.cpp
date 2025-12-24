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

void solve(){
    int n; cin>>n;
    dsu d(n);
    vector<pair<int,int>> oldPath;
    for(int i=0 ;i<n ; i++){
        int u,v;cin>>u>>v;
        u--;
        v--;
        if(d.findPar(u)  == d.findPar(v)){
            oldPath.push_back({u,v});
        }else{
            d.unionRank(u,v);
        }
    }
    set<int> st;
    vector<int> temp;

    for(int i=1 ; i<n; i++){
        if(st.find(d.findPar(i)) == st.end()) {
            st.insert(d.findPar(i));
            temp.push_back(d.findPar(i));
        }
    }
    cout<<temp.size()-1<<endl;
    for(int i=0 ; i<n; i++){
        cout<<oldPath[i].first<<" "<<oldPath[i].second<<" "<<temp[i+1]<<endl;
    }
}