#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int maze[N][N];
int vistided[N][N];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int r, c;
bool is_inside(pair<int, int> coord)
{
    int x = coord.first;
    int y = coord.second;

    if (x >= 0 && x < r && y >= 0 && y < c)
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

void BFS(pair<int, int> src)
{
    queue<pair<int, int>> q;
    vistided[src.first][src.second] = 1;
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
            if (is_inside(adj_node) && is_safe(adj_node) && vistided[new_x][new_y] == 0)
            {
                vistided[new_x][new_y] = 1;
                q.push(adj_node);
            }
        }
    }
}

pair<int, int> find_unvisited()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (vistided[i][j] == 0 && maze[i][j] == 0)
                return {i, j};
        }
    }
    return {-1, -1};
}
int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < c; j++)
        {
            if (input[j] == '#')
            {
                maze[i][j] = -1;
            }
        }
    }

    int room_count = 0;

    while (1)
    {
        pair<int, int> unvisited_pos = find_unvisited();
        if (unvisited_pos == pair<int, int>{-1, -1})
            break;
        else
        {
            BFS(unvisited_pos);
            room_count++;
        }
    }
    cout << room_count << "\n";
}