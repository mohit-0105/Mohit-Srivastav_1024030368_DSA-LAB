#include <iostream>
using namespace std;

#define INF 999

int main() {
    int n = 5;
    int adj[5][5] = {
        {0,10,0,30,100},
        {10,0,50,0,0},
        {0,50,0,20,10},
        {30,0,20,0,60},
        {100,0,10,60,0}
    };

    int dist[5], visited[5] = {0};
    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[0] = 0;

    for (int k = 0; k < n; k++) {
        int min = INF, u = -1;
        for (int i = 0; i < n; i++)
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] && dist[v] > dist[u] + adj[u][v])
                dist[v] = dist[u] + adj[u][v];
        }
    }

    cout << "Dijkstra shortest distances:\n";
    for (int i = 0; i < n; i++)
        cout << "0 -> " << i << " = " << dist[i] << "\n";
}
