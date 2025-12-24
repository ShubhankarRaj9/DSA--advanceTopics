#include<bits/stdc++.h>
using namespace std;
const int n = 4;
vector<int> segTree(4 * n);  

void buildTree(int idx, int low, int high, vector<int>& arr) {
    if (low == high) {
        segTree[idx] = arr[low];
        return;  
    }
    int mid = (low + high) / 2;
    buildTree(2 * idx + 1, low, mid, arr);
    buildTree(2 * idx + 2, mid + 1, high, arr);
    segTree[idx] = segTree[2 * idx + 1] + segTree[2 * idx + 2];
}

int Query(int start, int end, int idx, int low, int high){
    // Case-1 no overlap
    if(low>end || high<start) return 0;
    // Case-2 completely overlap
    if(low>=start && high<=end) return segTree[idx];
    // case-3 partial overlap
    int mid = (low+high)/2;
    int leftSum = Query(start,end,2*idx+1,low,mid) ;
    int rightSum = Query(start,end,2*idx+2,mid+1,high) ;
    return (leftSum+rightSum);
}

int main() {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    buildTree(0, 0, n - 1, arr);
    int query;
    cin>>query;
    while(query--){
        int start,end;cin>>start>>end;
        int ans = Query(start,end,0,0,n-1);
        cout<<ans<<endl;
    }
    return 0;
}