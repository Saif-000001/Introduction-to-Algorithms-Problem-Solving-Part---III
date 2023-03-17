#include <bits/stdc++.h>
using namespace std;

int power(int n, int m)
{
    if (m == 0)
        return 1;
    return (power(n, m - 1) * n);
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << power(n, m) << "\n";
    return 0;
}