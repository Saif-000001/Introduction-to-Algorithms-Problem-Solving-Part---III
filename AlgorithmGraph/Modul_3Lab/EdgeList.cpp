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

[
    [0,1]
    [1,2]
    [1,3]
    [2,3]
]
// weighted
[
    [0,1,2]
    [1,2,4]
    [1,3,9]
    [2,3,1]
]

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nodes = 4;

    vector<vector<int>> edgeList{
        {0, 1, 2},
        {1, 2, 4},
        {1, 3, 9},
        {2, 3, 1}};
    // vector<vector<int>> edgeList{
    //     {0,1},
    //     {1,2},
    //     {1,3},
    //     {2,3}
    // };

    /*
    // O(E) -> O(n^2)
    edgeList.push_back({0, 1});
    edgeList.push_back({1, 2});
    edgeList.push_back({1, 3});
    edgeList.push_back({2, 3});
    */

    for (int i = 0; i < edgeList.size(); i++)
    {
        cout << edgeList[i][0] << " " << edgeList[i][1] << " | " << edgeList[i][2] << " \n";
    }
}