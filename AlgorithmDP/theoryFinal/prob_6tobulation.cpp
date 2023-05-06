#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 5;
const int N = 1e3 + 5;
int dp[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char x;
            cin >> x;

            if (x != '.')
                dp[i][j] = 0;
            else
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
                if (i == 1 && j == 1)
                    dp[i][j] = 1;
            }
        }
    }
    cout << dp[n][n] << "\n";
    return 0;
}