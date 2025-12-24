#include<bits/stdc++.h>
using namespace std;

int getIndex(char ch){
    return ch-'a';
}

bool cycledetect(int node, int vis[], vector<int> adjList[]){
    vis[node] = 2;
    for(auto it : adjList[node]){
        if(vis[it] == 0){
            if(cycledetect(it,vis,adjList)){
                return true;
            }
        }else if(vis[it] == 2){
            return true;
        }
    }
    vis[node] = 1;
    return false;
}

void topoSort(int currNode,vector<int> adjList[], int indeg[], int vis[]){
    queue<int> q;
    q.push(currNode);
    cout<<char('a'+currNode);
    vis[currNode] = 1;
    while(q.size() !=0){
        int a = q.front();
        q.pop();
        for(auto v: adjList[a]){
            indeg[v]--;
            if(indeg[v] == 0){
                q.push(v);
                cout<<char('a'+v);
                vis[v] = 1;
            }
        }
    }
}

void solve(){
    int n;cin>>n;
    vector<string> names(n);
    for(int i=0; i<n; i++){
        string s; cin>>s;
        names[i] = s;
    }

    vector<int> adjList[26];
    int indeg[26] = {0};
    
    for(int i=0 ; i<n-1; i++) {
        string s1 = names[i];
        string s2 = names[i+1];

        for(int j=0; j<s1.size() ; j++){
            if(j > s2.size()){
                cout<<"Impossible"<<endl;
                return ;
            }
            if(s1[j] != s2[j]){
                adjList[getIndex(s1[j])].push_back(getIndex(s2[j]));
                indeg[getIndex(s2[j])]++;
                break;
            }
        }
    }
    int vis[26] = {0};
    for(int i=0; i<26; i++){
        if(vis[i] == 0){
            if(cycledetect(i,vis,adjList)){
                cout<<"Impossible"<<endl;
                return;
            }
        }
    }
    for(int i=0; i< 26; i++){
        vis[i] = 0;
    }
    for(int i=0; i<26 ; i++){
        if(indeg[i]==0 && vis[i] != 1){
            topoSort(i,adjList,indeg,vis);
        }
    }
}
int main() {
    solve();
    return 0;
}