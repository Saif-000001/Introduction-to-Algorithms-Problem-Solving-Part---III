#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int>adj_list[N];
int visited[N];
int level[N];
int n, e;

void BFS(int src){
    queue<int>q;
    visited[src] = 1;
    level[src] = 0;
    q.push(src);

    while(!q.empty()){
        int head = q.front();
        q.pop();

        for(auto adj_node : adj_list[head]){
            if(visited[adj_node]==0){
                visited[adj_node]=1;
                level[adj_node] = level[head]+1;
                q.push(adj_node);
            }
        }
    }
}

int main(){
    cin>>n>>e;
    for(int i = 0; i<e; i++)
    {
        int u, v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    BFS(3);

    for(int i = 0; i<n;i++){
        cout<<"node " <<i<<"-> "<<" level "<<level[i]<<" \n\n";
    }
}

/*
8 11
3 1
3 2
3 6
3 7
1 4
1 2
2 0
6 0
6 7
4 0
7 8
*/