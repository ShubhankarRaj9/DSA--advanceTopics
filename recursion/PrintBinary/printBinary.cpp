#include <bits/stdc++.h>
using namespace std;

void solve(int ones, int zeros, int n, string op, vector<string> &res)
{
    if (n == 0)
    {
        res.push_back(op);
        return;
    }
    if (zeros < ones)
    {
        string op1 = op;
        op1.push_back('0');
        solve(ones, zeros + 1, n - 1, op1, res);
        return;
    }
    string op2 = op;
    op2.push_back('1');
    solve(ones + 1, zeros, n - 1, op2, res);
    return;
}
int main()
{
    int n;
    cin >> n;
    vector<string> res;
    string op = "";
    solve(0, 0, n, op, res);
    for (auto val : res)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}