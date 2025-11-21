#include <iostream>
using namespace std;

class Edge {
public:
    int u, v, w;
};

int find(int parent[], int x) {
    while (parent[x] != x) x = parent[x];
    return x;
}

void unite(int parent[], int x, int y) {
    parent[find(parent, y)] = find(parent, x);
}

int main() {
    int n = 4;
    Edge edges[6] = {
        {0,1,10}, {0,2,6}, {0,3,5},
        {1,3,15}, {2,3,4}, {1,2,8}
    };

    // bubble sort edges by weight
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 5; j++)
            if (edges[j].w > edges[j+1].w) {
                Edge t = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = t;
            }

    int parent[4];
    for (int i = 0; i < n; i++) parent[i] = i;

    cout << "Kruskal MST:\n";
    for (int i = 0; i < 6; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(parent, u) != find(parent, v)) {
            cout << u << " - " << v << " : " << edges[i].w << "\n";
            unite(parent, u, v);
        }
    }
}
