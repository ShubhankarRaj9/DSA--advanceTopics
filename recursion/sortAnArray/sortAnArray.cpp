#include<bits/stdc++.h>
using namespace std;
void insert(vector<int>& v, int tar){
    if(v.size() == 0 || v[v.size()-1]<=tar){
        v.push_back(tar);
        return ;
    }
    int val = v[v.size()-1];v.pop_back();
    insert(v,tar);
    v.push_back(val);
    return;
}
void sort(vector<int>& v){
    if(v.size() == 1) {
        return ;
    }
    int val = v[v.size()-1];
    v.pop_back();
    sort(v);
    insert(v,val);
}
int main() {
    int n=7;
    vector<int> v= {2,3,7,6,4,5,9};
    sort(v);
    for(int x: v){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
