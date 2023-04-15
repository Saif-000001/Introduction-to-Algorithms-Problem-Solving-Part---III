/*
Graph representation
====================

Topic: Adjacency Matrix -> 2d Array

A---------B
         / \
        C---D

A = 0
B = 1
C = 2
D = 3

    2
0-------1
      4/8\7
      2---3
0 -> (1,2)
1 -> (2,4)
2 ->
3 -> (2,8), (1,7)


*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nodes = 4;
    vector<pair<int, int>> adjList[nodes];

    adjList[0] = {{1,2}};
    adjList[1] = {{2,4}};
    adjList[3] = {{2,8},{1,7}};

    // adjList[0].push_back({1, 2});
    // adjList[1].push_back({2, 4});
    // adjList[3].push_back({2, 8});
    // adjList[3].push_back({1, 7});

    for (int i = 0; i < nodes; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << "{" << adjList[i][j].first << "," << adjList[i][j].second << "}";
        }
        cout << "\n";
    }
}