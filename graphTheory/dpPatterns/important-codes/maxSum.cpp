#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> ip(n);
vector<int> dp(n+1);

int findMaxSum(int idx){
    if(idx >= n) return 0;
    if(dp[idx] != -1) return dp[idx];
    return dp[idx] = max(ip[idx]+findMaxSum(idx+2),findMaxSum(idx+1));
}

void solve(){
    cin>>n;
    ip.resize(n);
    fill(dp.begin(),dp.end(),-1);
    for(auto & x: ip) cin>>x;
    int res = findMaxSum(0);
    cout<<res<<endl;
}

int main() {
    solve();
    return 0;
}