#include <bits/stdc++.h>
using namespace std;
const int N = 101;

/*

- fib(n) -> calculate the n-th fibonacci number
- fib(n) = fib(n-1) + fib(n-2)
- fib(1) = 1, fib(2) = 1

*/

int dp[N];

int fib(int n)
{
    // 1. base case
    if (n <= 2)
        return 1;

    // 2. check if current state is already solved
    if (dp[n] != -1)
        return dp[n];
    
    // 3. calculate from smaller sub-problem
    int ans = fib(n-1) + fib(n-2);
    dp[n] = ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        dp[i] = -1;  // mark all states as unvisited
    
    // memset(dp, -1, sizeof(dp));

    cout<<fib(n)<<"\n";
    return 0;
}