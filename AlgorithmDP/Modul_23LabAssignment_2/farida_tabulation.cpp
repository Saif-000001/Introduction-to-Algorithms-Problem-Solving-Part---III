#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

long long int dp[N], arr[N];

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
       long long int n;
        cin >> n;
        if (n == 0)
        {
            cout << "Case " << i << ": " << n << "\n";
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        dp[0] = arr[0];
        dp[1] = max(dp[0], arr[1]);

        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
        }
        cout << "Case " << i << ": " << dp[n - 1] << "\n";
    }
    return 0;
}