#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;

        a = abs(a);
        b = abs(b);

        int ans = a + b;
        int diff = max(a, b) - min(a, b);
        ans += max(0, diff-1);
        cout << ans << "\n";
    }

    return 0;
}