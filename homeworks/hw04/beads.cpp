#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int n, k;
vector<long long> dp, prev_blue, prev_other;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    dp.resize(n + 1);
    prev_blue.resize(n + 1);
    prev_other.resize(n + 1);

    dp[1] = k;
    prev_blue[1] = 1;
    prev_other[1] = k - 1;

    for (int i = 2; i <= n; i++)
    {
        prev_blue[i] = prev_other[i - 1];

        dp[i] = ((prev_blue[i - 1] * (k - 1)) % MOD + (prev_other[i - 1] * k) % MOD) % MOD;

        prev_other[i] = (dp[i] - prev_blue[i] + MOD) % MOD;
    }

    cout << dp[n] << '\n';
}