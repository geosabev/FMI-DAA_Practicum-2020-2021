#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> lengths, prefix_sum;
vector<vector<int>> dp;

int get_min(int l = 0, int r = n - 1)
{
    if (l >= r)
        return 0;

    if (dp[l][r] != 0)
        return dp[l][r];

    int current_min = get_min(l + 1, r);

    for (int i = l + 1; i < r; i++)
    {
        if ((get_min(l, i) + get_min(i + 1, r)) < current_min)
        {
            current_min = get_min(l, i) + get_min(i + 1, r);
        }
    }

    if (l == 0)
        dp[l][r] = current_min + prefix_sum[r];
    else
        dp[l][r] = current_min + prefix_sum[r] - prefix_sum[l - 1];

    return dp[l][r];
}

void solve()
{
    get_min();

    cout << dp[0][n - 1] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    lengths.resize(n);
    prefix_sum.resize(n);
    dp.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        cin >> lengths[i];

    prefix_sum[0] = lengths[0];

    for (int i = 1; i < n; i++)
        prefix_sum[i] = prefix_sum[i - 1] + lengths[i];

    solve();
}