#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

long long int dp[N], sum[N];

long long int total_point(long long int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return sum[1];

    if (dp[n] != -1)
        return dp[n];

    long long int take = sum[n] * n + total_point(n - 2);
    long long int leave = total_point(n - 1);

    long long int ans = max(take, leave);
    dp[n] = ans;
    return ans;
}

int main()
{
   long long int n;
    cin >> n;
    for (int i = 0; i < N; i++)
    {
        dp[i] = -1;
    }
    long long int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        long long int x;
        cin >> x;
        sum[x]++;
        ans = max(ans, x);
    }
    cout << total_point(ans) << "\n";
    return 0;
}