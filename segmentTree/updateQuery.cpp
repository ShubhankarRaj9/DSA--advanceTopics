#include <bits/stdc++.h>
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


void update(int idx, int val, int i, int low, int high, vector<int> &arr)
{
    if(low == high){
        segTree[i] = val;
        return ;
    }
    int mid = (high+low)/2;
    if(idx <= mid) {
        update(idx,val,2*i+1,low,mid,arr);
    }else{
        update(idx,val,2*i+2,mid+1,high,arr);
    }
    segTree[i] = segTree[2*i+1]+segTree[2*i+2];
}


int main() {
    // ✅ input of the array 
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // ✅ function call
    buildTree(0, 0, n - 1, arr);
    for (int i = 0; i < 2 * n; i++) {
        cout << "Value at index " << i << ": " << segTree[i] << "\n";
    }
    cout<<"After updating the array value: "<<endl;
    // ✅ update the array
    update(1,5,0,0,n-1,arr);
    for (int i = 0; i < 2 * n; i++) {
        cout << "Value at index " << i << ": " << segTree[i] << "\n";
    }
    return 0;
}
