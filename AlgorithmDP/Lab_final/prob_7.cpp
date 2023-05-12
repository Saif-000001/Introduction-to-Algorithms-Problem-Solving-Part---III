#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

const ll maxn = 110;
const ll inf = 1e17 + 10;

map<ll, int> visited;
ll n, m, nn = 1;
ll cnt[11];

int bfs(ll s)
{
    queue<pair<ll, ll>> q;
    q.push(make_pair(s, 0));

    while (q.size())
    {
        pair<ll, ll> now = q.front();
        q.pop();

        if (now.first == 0)
            return now.second;
        if (visited[now.first])
            continue;

        visited[now.first] = now.second;
        ll t = now.first, len = 0;

        while (t)
        {
            cnt[t % 10] = 1;
            t /= 10;
            len++;
        }
        if (len >= n)
            return now.second;
        for (int i = 2; i <= 9; i++)
            if (cnt[i])
                q.push(make_pair(now.first * i, now.second + 1));
        for (int i = 0; i <= 9; i++)
            cnt[i] = 0;
    }
    return -1;
}

int main()
{
    Faster;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        nn *= 10;
    cout << bfs(m) << endl;
    return 0;
}
