
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 5;
const int N = 1e3 + 5;
char G[N][N];
int dp[N][N];

int count_paths(int i, int j){

    if(dp[i][j]) return dp[i][j];

    if(!i || !j || G[i][j] == '*') return 0;

    G[i][j] = '*';

    return dp[i][j] = (count_paths(i, j - 1) + count_paths(i - 1, j)) % MOD;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> G[i][j];
        }
    }
    dp[1][1] = G[1][1] == '*'? 0 : 1;
    cout << count_paths(n, n) << "\n";
    return 0;
}