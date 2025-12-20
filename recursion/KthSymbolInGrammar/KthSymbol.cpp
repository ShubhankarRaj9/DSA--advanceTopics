/* Leetcode --> medium problem */ 
#include<bits/stdc++.h>
using namespace std;


int kthGrammar(int n, int k) {
    if(n==1 && k==1) return 0;
    int mid = pow(2,n-1);
    if(k<= mid/2 )  return  kthGrammar(n-1,k);
    else return !kthGrammar(n-1,k-(mid/2));
}


int main() {
    int n,k;cin>>n>>k;
    int res = kthGrammar(n,k);
    cout<<res<<endl;
    return 0;
}