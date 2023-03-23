#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> adj_matrix(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int u;
            cin >> u;
            adj_matrix[i].push_back(u);
        }
    }

    vector<vector<int>> adj_list(adj_matrix.size());
    for (int i = 0; i < adj_matrix.size(); i++)
    {
        for (int j = 0; j < adj_matrix.size(); j++)
        {
            if (adj_matrix[i][j] != 0)
                adj_list[i].push_back(j);
        }
    }

    for (int i = 0; i < adj_list.size(); i++)
    {
        cout << i << ": ";
        for (auto adj_node : adj_list[i])
            cout << adj_node << " ";
        cout << "\n";
    }

    return 0;
}