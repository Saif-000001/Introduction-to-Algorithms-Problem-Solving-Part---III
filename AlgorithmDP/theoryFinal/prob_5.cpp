#include <bits/stdc++.h>
using namespace std;

const int N = 102;
int dp[N][2];

int sumMax(vector<int> &nums, int i, bool robFirst)
{
    if (i >= nums.size() || (i == nums.size() - 1 && robFirst))
        return 0;
    if (dp[i][robFirst] != -1)
        return dp[i][robFirst];

    int rob = 0, notRob = 0;
    if (i == 0)
        rob = sumMax(nums, i + 2, 1) + nums[i];
    else
        rob =sumMax(nums, i + 2, robFirst) + nums[i];

    notRob = sumMax(nums, i + 1, robFirst);
    return dp[i][robFirst] = max(rob, notRob);
}

int rob(vector<int> &nums)
{
    memset(dp, -1, sizeof dp);
    return sumMax(nums, 0, 0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << rob(nums) << "\n";
}