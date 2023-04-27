#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;

/*
- state: stone(n) -> cost of reaching n-th stone from 1st stone
- recurrance: stone(n) = for i = 1 to k:
                             min(
                                stone(n-i) + abs(h[n]- h[n-i])
                             )
- base case stone(1) = 0

i   <====(i-1), (i-2) ... (i-k)

k = 4

i = 2

i   <====(2-1), (2-2) ... (2-4)
            1      0        -2

- corner case => cant jum from stones with number <= 0
*/

int h[N], dp[N];

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> h[i];


    // 1. base case
    dp[1] = 0;

    // 2. loop over the states
    for (int i = 2; i <= n; i++)
    {
        dp[i] = INF;

        // 2.1 calculate answer from smaller sub-problem
        for (int j = 1; j <= k; j++)
        {
            int from_stone = i - j;
            if (from_stone<=0)
                break;

            int candidate_ans = dp[from_stone] + abs(h[i] - h[from_stone]);
            dp[i] = min(dp[i], candidate_ans);
        }
    }
    cout << dp[n] << "\n";
    return 0;
}