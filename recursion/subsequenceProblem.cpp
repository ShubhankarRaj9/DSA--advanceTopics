#include<bits/stdc++.h>
using namespace std;
void helper(string s, int idx, int n, string currSeq, vector<string>& res){
   if(idx == n){
    res.push_back(currSeq);
    return;
   }
    // include
    helper(s,idx+1,n,currSeq+s[idx],res);

    // exclude
    helper(s,idx+1,n,currSeq,res);
}

vector<string> AllPossibleString(string s){
    vector<string> res;
    helper(s,0,s.length(),"",res);
    return res;
}

int main(){
    string s;cin>>s;
    vector<string> ans = AllPossibleString(s);
    for(string st : ans) cout<<st<<endl;
    return 0;
}