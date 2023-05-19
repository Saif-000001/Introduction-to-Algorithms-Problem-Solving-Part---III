#include <bits/stdc++.h>
using namespace std;
#define Faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

const int N = 1005;
int profit[N];
int weight[N];


int knapsack(int W, int idx, vector<vector<int>> &dp)
{

    if (idx == 0)
        return (W / weight[0]) * profit[0];
    if (dp[idx][W] != -1)
        return dp[idx][W];

    int notTake = 0 + knapsack(W, idx - 1, dp);

    int take = INT_MIN;
    if (weight[idx] <= W)
        take = profit[idx] + knapsack(W - weight[idx], idx, dp);
    return dp[idx][W] = max(take, notTake);
}

int main()
{
    Faster;
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; i++)
        cin >> profit[i];
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));
    cout << knapsack(w, n - 1, dp) << "\n";
    return 0;
}