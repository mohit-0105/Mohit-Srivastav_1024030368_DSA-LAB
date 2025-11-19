#include <iostream>
int main() {
    int orig[] = {64, 25, 12, 22, 11};
    const int n = sizeof(orig)/sizeof(orig[0]);
    int arr[n];
    for (int i=0;i<n;++i) arr[i]=orig[i];
    for (int pass = 0; pass < n-1; ++pass) {
        bool swapped = false;
        for (int j = 0; j < n-pass-1; ++j) {
            if (arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    return 0;
  }