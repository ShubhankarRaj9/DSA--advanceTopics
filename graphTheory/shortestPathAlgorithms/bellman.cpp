#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ss second
#define ff first
#define INF INT_MAX

void BellmanFord(int n, int src, vector<pair<int, ll>> *edges, vector<ll>& dist, set<int>& negCycle) {
	fill(dist.begin(),dist.end(), INF);
	dist[src] = 0;
	vector<pair<ll, pair<int, int>>> e;
    vector<int> parent(n,-1);
	for (int i = 0; i < n; i++) {
		for (auto j : edges[i]) {
			e.pb({j.ss, {i, j.ff}});
		}
	}
    bool changed = true;
	for (int i = 0; i < n - 1; i++) {
        changed = false;
		for (auto j : e) {
            if (dist[j.ss.ss] > dist[j.ss.ff] + j.ff) 
                changed=true;
                parent[j.ss.ss] = j.ss.ff;
			dist[j.ss.ss] = min(dist[j.ss.ss], dist[j.ss.ff] + j.ff);
		}
        if(!changed)
            break;
	}
	//checking negative cycle
	for (int i = 0; i < n; i++) {
		for (auto j : e) {
			if (dist[j.ss.ss] > dist[j.ss.ff] + j.ff) {
				dist[j.ss.ss] = dist[j.ss.ff] + j.ff;
				negCycle.insert(j.ss.ss);
			}
		}
	}
}