#include <iostream>
using namespace std;

int adj[5][5] = {
    {0,1,1,0,0},
    {1,0,1,0,0},
    {1,1,0,1,0},
    {0,0,1,0,1},
    {0,0,0,1,0}
};

int visited[5] = {0};

void dfs(int v) {
    cout << v << " ";
    visited[v] = 1;

    for (int i = 0; i < 5; i++)
        if (!visited[i] && adj[v][i])
            dfs(i);
}

int main() {
    dfs(0);
}
