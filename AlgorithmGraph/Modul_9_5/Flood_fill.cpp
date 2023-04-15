/*
5 8
########
#..#...#
####.#.#
#..#...#
########

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int maze[N][N];
int visited[N][N];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int n, e;

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

void BFS(pair<int, int> src)
{
    queue<pair<int, int>> q;
    visited[src.first][src.second] = 1;
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

            if(is_inside(adj_node)&&is_safe(adj_node)&&visited[new_x][new_y]==0){
                visited[new_x][new_y] = 1;
                q.push(adj_node);
            }
        }
    }
}

pair<int, int> find_unvisited()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < e; j++)
        {
            if (maze[i][j] == 0 && visited[i][j] == 0)
                return {i, j};
        }
    }
    return {-1, -1};
}

int main()
{
    cin >> n >> e;
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < e; j++)
        {
            if (input[j] == '#')
                maze[i][j] = -1;
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < e; j++)
    //     {
    //         cout << maze[i][j] << "\t";
    //     }
    //     cout << "\n";
    // }

    int cont_room = 0;

    while (1)
    {
        pair<int, int> unvisited_pos = find_unvisited();
        if (unvisited_pos == pair<int, int>{-1, -1})
            break;
        else
        {
            BFS(unvisited_pos);
            cont_room++;
        }
    }
    cout << cont_room << "\n";
}