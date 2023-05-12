#include <bits/stdc++.h>
using namespace std;

const int N = 3000;
string s, t;
int dp[N + 1][N + 1];

int lcs(int i, int j)
{
    if (i == 0 || j == 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if (s[i - 1] == t[j - 1])
    {
        ans = lcs(i - 1, j - 1) + 1;
        dp[i][j] = ans;
        return ans;
    }

    ans = max(lcs(i - 1, j), lcs(i, j - 1));
    dp[i][j] = ans;
    return ans;
}

int main()
{
    cin >> s >> t;
    int n = s.length(), m = t.length();
    memset(dp, -1, sizeof(dp));

    int len = lcs(n, m);
    string ans(len, ' ');
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            ans[len - 1] = s[i - 1];
            len--;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    cout << ans << "\n";
    return 0;
}
