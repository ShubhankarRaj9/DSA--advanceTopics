#include<bits/stdc++.h>
using namespace std;

void solve(stack<int>& st, int k){
    if(k == 1){
        st.pop();
        return;
    }
    int topEle = st.top();
    st.pop();
    solve(st,k-1);
    st.push(topEle);
    return;
}

stack<int> midDelete(stack<int>& st, int size){
    if(st.size() == 0){
        return st;
    }
    int k = (size/2) + 1;
    solve(st,k);
    return st;
}

int main() {
    int n = 7;
    stack<int> st;
    for(int i=0 ; i<n; i++){
        int x;cin>>x;
        st.push(x);
    }
    midDelete(st,n);
    while(!st.empty()){
        int top = st.top();
        st.pop();
        cout<<top<<" ";
    }
    cout<<endl;
    return 0;
}