#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long int dp[N], arr[N];
long long int max_coins(long long int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return arr[0];
    if (n == 2)
        return max(arr[0], arr[1]);
    if (dp[n] != -1)
        return dp[n];

    long long int take = arr[n - 1] + max_coins(n - 2);
    long long int leave = max_coins(n - 1);
    long long int ans = max(take, leave);
    dp[n] = ans;
    return ans;
}
int main()
{
    int t;
    cin >> t;
    int i = 1;
    while (t--)
    {
        long long int n;
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            dp[i] = -1;
        }

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << "Case " << i << ": " << max_coins(n) << endl;
        i++;
    }
    return 0;
}