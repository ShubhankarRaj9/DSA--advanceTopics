#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void Dikjstra(int srcNode, int n, vector<vector<pair<int, ll>>> &edges, vector<ll> dist)
{
    fill(dist.begin(), dist.end(), INT_MAX);
    vector<bool> marked(n, false);
    dist[srcNode] = 0;
    set<pair<ll, int>> toExplore;
    toExplore.insert({0LL, srcNode});
    while (toExplore.size() > 0)
    {
        pair<ll, int> top = *toExplore.begin();
        int poppedNode = top.second;
        ll distSoFar = top.first;
        marked[poppedNode] = true;
        for (auto e : edges[poppedNode])
        {
            int node = e.first;
            ll addedDist = e.second;
            if (marked[node])
                continue;
            if (dist[node] > (distSoFar + addedDist))
            {
                toExplore.erase({dist[node], node});
                dist[node] = (distSoFar + addedDist);
                toExplore.insert({dist[node], node});
            }
        }
    }
}

void DikjstraByPriority(int srcNode, int n, vector<vector<pair<int, ll>>> &edges, vector<ll> dist)
{
    fill(dist.begin(), dist.end(), INT_MAX);
    vector<bool> marked(n, false);
    dist[srcNode] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<int, int>>> q;
    q.push({0LL, srcNode});
    while (!q.empty())
    { // O(N) runs
        pair<ll, int> here = q.top();
        q.pop();
        int v = here.second;
        ll d_v = here.first;
        if (d_v != dist[v])
            continue;
        for (auto edge : edges[v])
        { // O(M) in total for all the steps.
            if (dist[v] + edge.first < dist[edge.second])
            {
                dist[edge.second] = dist[v] + edge.first;
                q.push({dist[edge.second], edge.second}); // O(logN)
            }
        }
    }
    // O(nlogn + mlogn) = O((n+m)logn)
}

void getPath(int node, vector<int> &parent)
{
    while (node != -1)
    {
        cout << node << " ";
        node = parent[node];
    }
}

void solve()
{
    int n;
    cin >> n;
}

int main()
{
    solve();
    return 0;
}