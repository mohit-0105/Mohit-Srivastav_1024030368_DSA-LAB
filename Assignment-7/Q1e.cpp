#include <iostream>
using namespace std;

int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; ++j) {
        if (arr[j] < pivot) {
            ++i;
            int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
        }
    }
    int tmp = arr[i+1]; arr[i+1] = arr[r]; arr[r] = tmp;
    return i + 1;
}

void quickSort(int arr[], int l, int r) {
    if (l >= r) return;
    int p = partition(arr, l, r);
    quickSort(arr, l, p-1);
    quickSort(arr, p+1, r);
}

int main() {
    int orig[] = {64, 25, 12, 22, 11};
    const int n = sizeof(orig)/sizeof(orig[0]);
    int arr[n];
    for (int i=0;i<n;++i) arr[i]=orig[i];

    quickSort(arr, 0, n-1);

    for (int i=0;i<n;++i) cout << arr[i] << (i+1<n ? ' ' : '\n');
    return 0;
}
