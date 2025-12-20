#include<bits/stdc++.h>
using namespace std;

void insert(stack<int>& st, int tar){
    if(st.size() == 0){
        st.push(tar);
        return;
    }
    int temp = st.top();st.pop();
    insert(st,tar);
    st.push(temp);
    return;
}

void reverse(stack<int>& st){
    if(st.size() == 1){
        return;
    }
    int temp = st.top();
    st.pop();
    reverse(st);
    insert(st,temp);
    return;
}
int main() {
    int n = 7;
    stack<int> st;
    for(int i=0 ; i<n; i++){
        int x;cin>>x;
        st.push(x);
    }


    while(!st.empty()){
        int top = st.top();
        st.pop();
        cout<<top<<" ";
    }
    cout<<endl;
    return 0;
}