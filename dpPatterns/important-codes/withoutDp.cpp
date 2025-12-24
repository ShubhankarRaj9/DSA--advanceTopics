#include<bits/stdc++.h>
using namespace std;

int functionEntered = 0;
int dp[40];
int helper(int n){
    functionEntered++;
    if(n == 1 || n == 2)return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = helper(n - 1) + helper(n - 2);
}

void solve(){
    int n;cin>>n;
    for(int i=0; i<=n ; i++) dp[i] = -1;
    cout<<helper(n)<<endl;
    cout<<functionEntered<<endl;
}

int main() {
    solve();
    return 0;
}