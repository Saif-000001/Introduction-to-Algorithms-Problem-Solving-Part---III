#include<bits/stdc++.h>
using namespace std;

const int N = 101;

/*

- fib(n) -> calculate the n-th fibonacci number
- fib(n) = fib(n-1) + fib(n-2)
- fib(1) = 1, fib(2) = 1

*/

int dp[N];

int main(){
    int n ;
    cin>>n;

    // 1. base case
    dp[1] = 1;
    dp[2] = 1;

    // loop through the states
    for(int i = 3; i<=n; i++){
        // and calculate the answer from smaller sub-problems
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<dp[n]<<"\n";

    return 0;
}