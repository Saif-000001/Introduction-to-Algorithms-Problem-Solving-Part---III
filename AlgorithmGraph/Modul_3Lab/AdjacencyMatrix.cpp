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

0-------1
       / \
      2---3

# total nodes = 4
# total edge  = 4
# Undirected + Unweighted


matrix -> #of nodes x #of nodes
       -> 4x4

matrix[i][j] = 1
         if and only if (i -> j)

0 -> 1
1 -> 0
1 -> 2
2 -> 1
1 -> 3
3 -> 1
2 -> 3
3 -> 2

*/

#include <bits/stdc++.h>
using namespace std;

/*
n -> #of nodes
E -> #of edge
*/

/*
time complexity -> O(n^2)
space complexity -> O(n^2)
*/

int main()
{
    int n = 4;                // O(1)
    int adjMatrix[n][n] = {}; // O(n^2)
    /*

    int adjMatrix[n][n];
    // O(n^2)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            adjMatrix[i][j] = 0;
    }

    */

    //    for(int i = 0; i<n;i++){
    //     for(int j = 0; j<n; j++){
    //         adjMatrix[i][j] = 1
    //     }
    //    }

    // O(E) -> #of edge
    adjMatrix[0][1] = 1;
    adjMatrix[1][0] = 1;

    adjMatrix[1][2] = 1;
    adjMatrix[1][3] = 1;

    adjMatrix[2][1] = 1;
    adjMatrix[2][3] = 1;

    adjMatrix[3][1] = 1;
    adjMatrix[3][2] = 1;

    // O(n^2)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << adjMatrix[i][j] << " ";
        cout << "\n";
    }
}