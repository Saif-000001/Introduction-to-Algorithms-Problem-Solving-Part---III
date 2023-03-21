
/*
5 8
########
#..#...#
####.#.#
#..#...#
########

output : 3


10 10
####.###..
#.######.#
##.######.
###.###..#
##.####..#
#####..###
#.########
#.####.#.#
#####..##.
######.###

output = 14
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int maze[N][N];
int visited[N][N];
int row, col;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool is_coordinate(pair<int, int> coord)
{
    int x = coord.first;
    int y = coord.second;

    if (x < 0 || y < 0 || x > row || y > col)
        return false;
    if (maze[x][y] == -1)
        return false;
    return true;
}

void dfs(pair<int, int> nodes)
{
    int x = nodes.first;
    int y = nodes.second;
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        pair<int, int> adj_node = {new_x, new_y};
        if (is_coordinate(adj_node) && visited[new_x][new_y] == 0)
            dfs(adj_node);
    }
}

int main()
{
    cin >> row >> col;

    for (int i = 0; i < row; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < col; j++)
        {
            if (input[j] == '#')
                maze[i][j] = -1;
        }
    }

    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         cout << maze[i][j] << "\t";
    //     }
    //     cout << "\n";
    // }

    int cnt_room = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (is_coordinate({i, j}) && visited[i][j] == 0)
            {
                dfs({i, j});
                cnt_room++;
            }
        }
    }
    cout << cnt_room << "\n";
}