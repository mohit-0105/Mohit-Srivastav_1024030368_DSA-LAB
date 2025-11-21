#include <iostream>
using namespace std;

class Graph {
    int n;
    int adj[20][20];
public:
    Graph(int v) {
        n = v;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adj[i][j] = 0;
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;   
    }

    int degree(int v) {
        int d = 0;
        for (int i = 0; i < n; i++)
            d += adj[v][i];
        return d;
    }

    int countEdges() {
        int c = 0;
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                if (adj[i][j] == 1) c++;
        return c;
    }

    void adjacentVertices(int v) {
        for (int i = 0; i < n; i++)
            if (adj[v][i]) cout << i << " ";
        cout << "\n";
    }
};

int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);

    cout << "Degree of vertex 1: " << g.degree(1) << "\n";
    cout << "Adjacent to 2: "; g.adjacentVertices(2);
    cout << "Number of edges: " << g.countEdges() << "\n";
}
