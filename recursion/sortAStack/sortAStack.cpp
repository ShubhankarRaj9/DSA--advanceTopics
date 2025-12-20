#include<bits/stdc++.h>
using namespace std;

void insert(stack<int>& st, int tar){
    if(st.size()==0 || st.top() <= tar){
        st.push(tar);
        return;
    }
    int val = st.top();st.pop();
    insert(st,tar);
    st.push(val);
    return;
}

void solve(stack<int>& st){
    if(st.size() == 1){
        return;
    }
    int val = st.top();st.pop();
    solve(st);
    insert(st,val);
    return;
}
int main() {
    stack<int> st;
    st.push(2);
    st.push(3);
    st.push(7);
    st.push(6);
    st.push(4);
    st.push(5);
    st.push(9);
    solve(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}