#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 5;

int grid[N][N];
int visited[N][N];
pair<int, int> src;
map<pair<int, int>, bool> dest;
pair<int, int> safeCoord;
stack<pair<int, int>> path;
vector<int> visitedNode(N);

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
char di[] = {'R', 'L', 'U', 'D'};
int n, m, f = 0;

bool isValidCoordinate(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
    {
        return false;
    }
    return true;
}

bool isMonster(int x, int y)
{
    if (grid[x][y] != 2)
        return false;
    return true;
}

bool isForbiddenCell(int x, int y)
{
    if (grid[x][y] != 0)
        return false;
    return true;
}

void bfs(int x, int y)
{
    visited[x][y] = 1;
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x1 = p.first + dx[i];
            int y1 = p.second + dy[i];
            if (isValidCoordinate(x1, y1))
            {
                if (!isMonster(x1, y1) && !isForbiddenCell(x1, y1) && !visited[x1][y1])
                {
                    visited[x1][y1] = visited[p.first][p.second] + 1;
                    q.push({x1, y1});
                    if (dest[{x1, y1}])
                    {
                        f = 1;
                        safeCoord.first = x1;
                        safeCoord.second = y1;
                        return;
                    }
                }
            }
        }
    }
}

void get_path(int x, int y)
{
    int node = visited[x][y];
    visitedNode[node] = 1;
    queue<pair<int, int>> q;
    q.push({x, y});
    path.push({x, y});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x1 = p.first + dx[i];
            int y1 = p.second + dy[i];
            if (isValidCoordinate(x1, y1))
            {
                int t = visited[x1][y1];
                if (t && !visitedNode[t])
                {
                    visitedNode[t] = 1;
                    q.push({x1, y1});
                    path.push({x1, y1});
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == 'A')
            {
                grid[i][j] = 1;
                src.first = i;
                src.second = j;
            }
            else if (c == 'M')
            {
                grid[i][j] = 2;
            }
            else if (c == '#')
            {
                grid[i][j] = 0;
            }
            else
            {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                {
                    grid[i][j] = 1;
                    dest[{i, j}] = 1;
                }
                else
                {
                    grid[i][j] = 1;
                }
            }
        }
    }

    bfs(src.first, src.second);
    
    if (!f)
    {
        cout << "NO\n";
        return 0;
    }

    get_path(safeCoord.first, safeCoord.second);

    cout << "YES\n";
    cout << path.size() - 1 << "\n";

    int x = path.top().first;
    int y = path.top().second;
    path.pop();
    while (!path.empty())
    {
        auto p = path.top();
        path.pop();
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] == p.first && y + dy[i] == p.second)
            {
                cout << di[i];
                x = p.first;
                y = p.second;
            }
        }
    }
    cout << "\n";

    return 0;
}