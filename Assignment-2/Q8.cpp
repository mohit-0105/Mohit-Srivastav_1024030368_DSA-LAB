#include <iostream>
using namespace std;

int countDistinct(int arr[], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        bool isDistinct = true;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDistinct = false;
                break;
            }
        }
         if (isDistinct) {
            count++;
        }
    }
       return count;
}
int main() {
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int totalDistinct = countDistinct(arr, n);
    cout << "Total number of distinct elements: " << totalDistinct << endl;
    return 0;
}