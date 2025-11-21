#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int adj[5][5] = {
        {0,1,1,0,0},
        {1,0,1,0,0},
        {1,1,0,1,0},
        {0,0,1,0,1},
        {0,0,0,1,0}
    };

    int visited[5] = {0};
    int queue[10], front = 0, rear = 0;

    int start = 0;
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int node = queue[front++];
        cout << node << " ";

        for (int i = 0; i < n; i++) {
            if (!visited[i] && adj[node][i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}
