#include <iostream>
using namespace std;
int main() {
    int n = 7;
    int arr[7] = {64, 34, 25, 12, 22, 11, 90};
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}