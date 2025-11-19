#include <iostream>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    int *a = new int[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n/2; ++i) {
        int left = i;
        int right = n - 1 - i;
        int minIndex = left;
        int maxIndex = left;
        for (int j = left + 1; j <= right; ++j) {
            if (a[j] < a[minIndex]) minIndex = j;
            if (a[j] > a[maxIndex]) maxIndex = j;
        }
        if (minIndex != left) {
            int temp = a[left];
            a[left] = a[minIndex];
            a[minIndex] = temp;
        }

        if (maxIndex == left) maxIndex = minIndex;
        if (maxIndex != right) {
            int temp = a[right];
            a[right] = a[maxIndex];
            a[maxIndex] = temp;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << "\n";

    delete[] a;
    return 0;
}
