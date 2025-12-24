#include <bits/stdc++.h>
#define nline  "\n"
using namespace std;
using ll = long long;
int n;
vector<ll> ip;
vector<vector<ll>> dp;
vector<vector<ll>> sum;
const ll NEG_INF = LLONG_MIN / 4;

ll fun(int i, int j)
{
    if (i == j)
        return ip[i];

    if (dp[i][j] != NEG_INF)
    {
        return dp[i][j];
    }
    dp[i][j] = max((ip[i] + (sum[i + 1][j] - fun(i + 1, j))),(ip[j] + (sum[i][j - 1] - fun(i, j - 1))));
   
    return dp[i][j];
}
void solve()
{
    cin >> n;
    ip.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> ip[i];

    dp.assign(n, vector<ll>(n, NEG_INF));
    sum.assign(n, vector<ll>(n, 0));

    for (int i = 0; i < n; i++)
    {
        ll curr = 0;
        for (int j = i; j < n; j++)
        {
            curr += ip[j];
            sum[i][j] = curr;
        }
    }

    cout << fun(0, n - 1) << nline;
}

int main()
{
    solve();
    return 0;
}