#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 102;
int dp[N];

int numSquar(int n)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int minCount = INF;
    for (int num = 1; num <= sqrt(n); num++)
    {
        int sqNum = num * num;

        int currentCount = numSquar(n - sqNum) + 1;
        minCount = min(minCount, currentCount);
    }
    dp[n] = minCount;
    return minCount;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        dp[i] = -1;
    cout << numSquar(n) << "\n";
}