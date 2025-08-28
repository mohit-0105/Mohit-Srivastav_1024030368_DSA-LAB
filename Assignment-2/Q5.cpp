#include <iostream>
using namespace std;

class DiagonalMatrix {
    int *arr;
    int n;

public:
    DiagonalMatrix(int size) {
        n = size;
        arr = new int[n]();
    }

    void set(int i, int j, int val) {
        if (i == j)
            arr[i] = val;
    }

    int get(int i, int j) {
        if (i == j)
            return arr[i];
        return 0;
    }

    ~DiagonalMatrix() {
        delete[] arr;
    }
};

int main() {
    DiagonalMatrix d(4);
    d.set(0, 0, 5);
    d.set(1, 1, 10);

    cout << "Element at (1,1): " << d.get(1, 1) << endl;
    cout << "Element at (1,2): " << d.get(1, 2) << endl;  
    return 0;
}

