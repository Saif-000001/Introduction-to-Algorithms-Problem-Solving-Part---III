#include <bits/stdc++.h>
using namespace std;
#define Faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define ll long long int

const int MOD = (int)1e9 + 7;
const int N = 1e7 + 5;
ll dp[N];

int main()
{
    Faster;
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    dp[0] = 1;
    for (int weight = 0; weight <= x; weight++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (weight - coins[i - 1] >= 0)
            {
                dp[weight] += dp[weight - coins[i - 1]];
                dp[weight] %= MOD;
            }
        }
    }
    cout << dp[x] << '\n';
}