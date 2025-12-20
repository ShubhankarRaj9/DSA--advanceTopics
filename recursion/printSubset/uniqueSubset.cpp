#include<bits/stdc++.h>
using namespace std;
void solve(string input, string output, set<string>& st){
    if(input.length() == 0){
        st.insert(output);
        return;
    }
    string op1 = output;
    string op2 = output + input[0];
    input.erase(input.begin());
    solve(input,op1,st);
    solve(input,op2,st);
    return;
}
int main() {
    string ip;cin>>ip;
    set<string> st;
    solve(ip,"",st);
    for(auto &s: st){
        cout<<s<<" ";
    }
    return 0;
}