#include <bits/stdc++.h>
using namespace std;
#define Faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

const int N = 1e5 + 5;
const int INF = 1e9;
vector<vector<pair<int, int>>> graph(N);
vector<int> dist(N, INF);
int n, m, k;

int networkDelayTime(vector<vector<int>> &times)
{
    for (auto &time : times)
    {
        int u = time[0];
        int v = time[1];
        int w = time[2];
        graph[u].push_back({v, w});
    }

    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k});
    dist[k] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto &neighbor : graph[u])
        {
            int v = neighbor.first;
            int w = neighbor.second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    int maxDist = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INF)
        {
            return -1;
        }
        maxDist = max(maxDist, dist[i]);
    }

    return maxDist;
}

int main()
{
    Faster;
    cin >> n >> m >> k;

    vector<vector<int>> times(m, vector<int>(3));
    for (int i = 0; i < m; i++)
    {
        cin >> times[i][0] >> times[i][1] >> times[i][2];
    }

    int result = networkDelayTime(times);
    cout << result << endl;

    return 0;
}

/*
4 3 2
2 1 1
2 3 1
3 4 1
*/
