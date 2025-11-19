#include <iostream>
int main() {
    int orig[] = {64, 25, 12, 22, 11};
    const int n = sizeof(orig)/sizeof(orig[0]);
    int arr[n];
    for (int i=0;i<n;++i) arr[i]=orig[i];
    for (int i = 0; i < n-1; ++i) {
        int minIdx = i;
        for (int j = i+1; j < n; ++j)
            if (arr[j] < arr[minIdx]) minIdx = j;
        if (minIdx != i) {
            int tmp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = tmp;
        }
    }
    return 0;
  }
