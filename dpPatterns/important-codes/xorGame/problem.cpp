#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> ip;


void solve(){
    cin>>n>>m;
    ip.resize(n,vector<int>(m));
    for(vector<int> & row: ip){
        for(int & ValAtRowAndCol: row){
            cin>>ValAtRowAndCol;
        }
    }
}
int main() {
    solve();
    return 0;
}