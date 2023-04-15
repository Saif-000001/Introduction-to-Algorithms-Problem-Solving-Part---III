#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int maze[N][N];
bool visited[N][N];
int level[N][N];
int parent[N][N];
int n, e;

char ch[] = {'D', 'L', 'R', 'U'};
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

bool is_inside(pair<int, int> coord)
{
    int x = coord.first;
    int y = coord.second;

    if (x >= 0 && x < n && y >= 0 && y < e)
        return true;
    return false;
}

bool is_safe(pair<int, int> coord)
{
    int x = coord.first;
    int y = coord.second;
    if (maze[x][y] == -1)
        return false;
    return true;
}

bool bfs(pair<int, int> src)
{
    queue<pair<int, int>> q;
    visited[src.first][src.second] = true;
    parent[src.first][src.second] = -1;
    q.push(src);

    while (!q.empty())
    {
        pair<int, int> head = q.front();
        q.pop();

        int x = head.first;
        int y = head.second;

        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            pair<int, int> adj_node = {new_x, new_y};

            if (is_inside(adj_node) && is_safe(adj_node) && !visited[new_x][new_y])
            {
                visited[new_x][new_y] = true;
                parent[new_x][new_y] = i;
                q.push(adj_node);
                return true;
            }
        }
    }
    return false;
}

string get_path(pair<char, char> src)
{
    string path = "";
    int x = src.first;
    int y = src.second;

    while (x != n || y != e)
    {
        int p = parent[x][y];
        path = ch[p] + path;
        x -= dx[p];
        y -= dy[p];
    }
    return path;
}

int main()
{
    cin >> n >> e;

    pair<int, int> src;
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < e; j++)
        {
            // if (input[j] == '#' || input[j] == 'M')
            //     maze[i][j] = -1;
            if (input[j] == 'A')
                src = {i, j};
        }
    }

    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<e; j++){
    //         cout<<maze[i][j]<<"\t";
    //     }
    //     cout<<"\n";
    // }

    // bfs(src);

    if (bfs(src))
    {
        cout << "YES\n";
        cout << get_path(src) << "\n";
    }
}