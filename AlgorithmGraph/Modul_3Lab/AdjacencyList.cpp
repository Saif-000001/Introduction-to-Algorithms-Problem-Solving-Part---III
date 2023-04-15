/*
Graph representation
====================

Topic: Adjacency Matrix -> linked list / c++ vector

A---------B
         / \
        C---D

A = 0
B = 1
C = 2
D = 3

0-------1
       / \
      2---3

0 -> 0
1 -> 0, 2, 3
2 -> 1, 3
3 -> 2, 1

*/

#include <bits/stdc++.h>
using namespace std;

/*
    Time complexity = O(1) + O(1) + O(n^2) + O(n^2) =  O(n^2)
    Space complexity = O(1) + O(n) + O(n^2) + O(1) =  O(n^2)
*/

int main()
{
    int nodes = 4; // O(1)  || O(1)

    vector<int> adjList[nodes]; // O(1)  || O(n)

    // O(E * 2) -> O(E) -> O(n^2)  || O(E * 2) -> O(E) -> O(n^2)
    adjList[0] = {0};
    adjList[1] = {0, 2, 3};
    adjList[2] = {1, 3};
    adjList[3] = {2, 1};

    // O(2*E) -> O(E) -> O(n^2)  || O(1)
    for (int i = 0; i < nodes; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << adjList[i][j] << " ";
        }
        cout << "\n";
    }
}