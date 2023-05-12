#include <bits/stdc++.h>
using namespace std;
#define Faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

const int N = 100;
const int M = 1e5;

bool dp[N + 1][M + 1];

int main()
{
    Faster;
    int n;
    cin >> n;

    vector<int> c_values(n);
    for (int i = 0; i < n; i++)
        cin >> c_values[i];

    dp[0][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int curr_sum = 0; curr_sum <= M; curr_sum++)
        {
            dp[i][curr_sum] = dp[i - 1][curr_sum];
            int prev_sum = curr_sum - c_values[i - 1];
            
            if (prev_sum >= 0 && dp[i - 1][prev_sum])
                dp[i][curr_sum] = true;
        }
    }

    vector<int> possible;
    for (int sum = 1; sum <= M; sum++)
    {
        if (dp[n][sum])
            possible.push_back(sum);
    }
    cout << (int)(possible.size()) << endl;

    for (int sum : possible)
        cout << sum << " ";
    cout << endl;
}