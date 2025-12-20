#include <bits/stdc++.h>
using namespace std;

void solve(int open, int close, string op, vector<string> &res)
{
    if (open == 0 && close == 0)
    {
        res.push_back(op);
        return;
    }
    if (open)
    {
        string op1 = op;
        op1.push_back('(');
        solve(open - 1, close, op, res);
    }
    if (close > open)
    {
        string op2 = op;
        op2.push_back(')');
        solve(open, close - 1, op, res);
    }
    return;
}
int main()
{
    int n;
    vector<string> res;
    string op = "";
    solve(n, n, op, res);
    return 0;
}