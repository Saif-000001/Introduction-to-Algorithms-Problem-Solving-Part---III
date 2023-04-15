#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1005;


bool visited[MAXN][MAXN];
char maze[MAXN][MAXN];
int n, m, rooms, max_length;

int dx[] = {-1, 0, 1, 0}; 
int dy[] = {0, 1, 0, -1}; 

void bfs(pair<int,int>src, int& size) {
    queue<pair<int,int>> q;
    q.push(src);
    visited[src.first][src.second] = true;
    size++;

    while (!q.empty()) {
        pair<int,int>head = q.front();
        q.pop();

        int x = head.first;
        int y = head.second;

        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            pair<int,int>adj_node ={new_x, new_y};
            if (new_x < 1 || new_x > n || new_y < 1 || new_y > m) continue;
            if (visited[new_x][new_y] || maze[new_x][new_y] == '#') continue;
            visited[new_x][new_y] = true;
            size++;
            q.push(adj_node);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> maze[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!visited[i][j] && maze[i][j] == '.') {
                rooms++;
                int size = 0;
                bfs({i, j}, size);
                max_length = max(max_length, size);
            }
        }
    }

    cout << "Rooms - " << rooms << "\n";
    cout << "Length of the longest room - " << max_length<<"\n";

    return 0;
}
