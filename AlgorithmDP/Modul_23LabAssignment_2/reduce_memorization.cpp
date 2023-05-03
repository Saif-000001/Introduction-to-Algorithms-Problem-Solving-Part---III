#include <bits/stdc++.h>
using namespace std;

const int N = 102;
int dp[N];

int countways(int n)
{
    if (n == 1)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int ans = countways(n - 1) + 1;

    if (n % 3 == 0)
        ans = min(ans, countways(n / 3) + 1);

    if (n % 2 == 0)
        ans = min(ans, countways(n / 2) + 1);

    dp[n] = ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        dp[i] = -1;

    cout << countways(n) << "\n";
    return 0;
}