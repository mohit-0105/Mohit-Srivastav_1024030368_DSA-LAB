#include <iostream>
using namespace std;

#define INF 999

int main() {
    int n = 5;
    int cost[5][5] = {
        {0,2,INF,6,INF},
        {2,0,3,8,5},
        {INF,3,0,INF,7},
        {6,8,INF,0,9},
        {INF,5,7,9,0}
    };

    int selected[5] = {0};
    selected[0] = 1;

    cout << "Prim MST:\n";

    for (int k = 0; k < n-1; k++) {
        int min = INF, u = -1, v = -1;
        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        cout << u << " - " << v << " : " << min << "\n";
        selected[v] = 1;
    }
}
