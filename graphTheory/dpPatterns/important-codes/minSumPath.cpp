#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> ip(n, vector<int>(m));
vector<vector<int>> dp(n + 1, vector<int>(m + 1));

int fun(int i, int j)
{
    if (i >= n || j >= m)
        return INT_MAX;
    if (i == n - 1 && j == n - 1)
        return ip[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = ip[i][j] + min(dp[i][j + 1], dp[i + 1][j]);
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ip[i][j];
        }
    }
    fill(dp.begin(), dp.end(), -1);
    cout << fun(0, 0) << endl;
}

int main()
{
    solve();
    return 0;
}