#include<bits/stdc++.h>
using namespace std;
void solve(string ip, string op){
    if(ip.size() == 0){
        cout<<op<<" ";
        return;
    }
    string op1 = op ;
    op1.push_back('_');
    op1.push_back(ip[0]);

    string op2 = op;
    op2.push_back(ip[0]);

    ip.erase(ip.begin());
    
    solve(ip,op1);
    solve(ip,op2);
    return;
}
int main() {
    string ip;cin>>ip;
    string op ="";
    op.push_back(ip[0]);
    ip.erase(ip.begin());
    solve(ip,op);
    return 0;
}