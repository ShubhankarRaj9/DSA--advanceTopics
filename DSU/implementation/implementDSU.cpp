#include <bits/stdc++.h>
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
        return parent[node] = findPar(parent[node]); // path compression
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
        if(pu == pv) {
            return;
        }
        if(rank[pu] == rank[pv]){
            parent[pu] = pv;
            rank[pu]++;
        }else if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }else{
            parent[pv] = pu; 
        }
    }
};

int main()
{

    return 0;
}