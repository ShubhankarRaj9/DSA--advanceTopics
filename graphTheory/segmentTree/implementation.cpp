#include <bits/stdc++.h>
using namespace std;

const int n = 4;
vector<int> segTree(4 * n);   // ✅ FIXED SIZE

void buildTree(int idx, int low, int high, vector<int>& arr) {
    if (low == high) {
        segTree[idx] = arr[low];
        return;   // ✅ stop recursion
    }
    // ✅ 1st - find mid-idx
    int mid = (low + high) / 2;
    // ✅ 2nd - left-child
    buildTree(2 * idx + 1, low, mid, arr);
    // ✅ 3rd - right-child
    buildTree(2 * idx + 2, mid + 1, high, arr);
    segTree[idx] = segTree[2 * idx + 1] + segTree[2 * idx + 2];
}

int main() {
    // ✅ input of the array 
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // ✅ function call
    buildTree(0, 0, n - 1, arr);
    // ✅ print the segment Tree.
    for (int i = 0; i < 2 * n; i++) {
        cout << "Value at index " << i << ": " << segTree[i] << "\n";
    }
    return 0;
}
