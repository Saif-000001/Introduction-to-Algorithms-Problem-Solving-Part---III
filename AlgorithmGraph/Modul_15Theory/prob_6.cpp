#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
char grid[MAXN][MAXN];
int n, m, Arow, Acol, destRow, destCol;
bool vis[MAXN][MAXN];
int parent[MAXN][MAXN];
char dir[] = {'D', 'L', 'R', 'U'};
int dr[] = {1, 0, 0, -1};
int dc[] = {0, -1, 1, 0};

bool is_valid(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m && grid[r][c] != 'M' && grid[r][c] != '#';
}

bool bfs() {
    queue<pair<int, int>> q;
    q.push({Arow, Acol});
    vis[Arow][Acol] = true;
    while(!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        int row = curr.first, col = curr.second;
        if(row == 0 || row == n - 1 || col == 0 || col == m - 1) {
            destRow = row;
            destCol = col;
            return true;
        }
        for(int i = 0; i < 4; i++) {
            int new_row = row + dr[i], new_col = col + dc[i];
            if(is_valid(new_row, new_col) && !vis[new_row][new_col]) {
                vis[new_row][new_col] = true;
                parent[new_row][new_col] = i;
                q.push({new_row, new_col});
            }
        }
    }
    return false;
}

string get_path() {
    string path = "";
    int row = destRow, col = destCol;
    while(row != Arow || col != Acol) {
        int p = parent[row][col];
        path = dir[p] + path;
        row -= dr[p];
        col -= dc[p];
    }
    return path;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'A') {
                Arow = i;
                Acol = j;
            }
        }
    }
    if(bfs()) {
        cout << "YES\n";
        cout << get_path().length() << "\n";
        cout << get_path() << "\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
