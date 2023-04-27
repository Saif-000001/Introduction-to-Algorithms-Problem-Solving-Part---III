#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long int dp[N], sum[N];

int main()
{
    int n;
    cin >> n;
    long long int ans = 0;
    for (int i = 0; i < n; i++)
    {
        long long int x;
        cin >> x;
        sum[x]++;
        ans = max(ans, x);
    }

    dp[1] = sum[1];

    for (int i = 2; i <= ans; i++)
    {
        dp[i] = max(dp[i - 2] + sum[i] * i, dp[i - 1]);
    }
    cout << dp[ans] << "\n";
    return 0;
}