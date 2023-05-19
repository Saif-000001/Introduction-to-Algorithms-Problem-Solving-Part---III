#include <bits/stdc++.h>
using namespace std;
#define Faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
typedef long long int ll;

int main()
{
    Faster;

    ll T;
    cin >> T;
    ll result[T];
    for (ll t = 0; t < T; t++)
    {
        ll L, R;
        cin >> L >> R;
        if (L > R)
        {
            swap(L, R);
        }
        ll totalSum = (R * (R + 1)) / 2;
        L--;
        ll lSum = (L * (L + 1)) / 2;
        result[t] = totalSum - lSum;
    }

    for (ll i = 0; i < T; i++)
    {
        cout << result[i] << "\n";
    }

    return 0;
}