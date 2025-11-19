#include <iostream>
int main() {
    int orig[] = {64, 25, 12, 22, 11};
    const int n = sizeof(orig)/sizeof(orig[0]);
    int arr[n];
    for (int i=0;i<n;++i) arr[i]=orig[i];
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
    return 0;
  }