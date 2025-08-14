#include <iostream>
using namespace std;

int removeDuplicates(int arr[], int n) {
    if (n == 0) return 0;

    int temp[n];
    int j = 0;

    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int k = 0; k < j; k++) {
            if (arr[i] == temp[k]) {
                found = true;
                break;
            }
        }
        if (!found) {
            temp[j++] = arr[i];
        }
    }

    
    for (int i = 0; i < j; i++) {
        arr[i] = temp[i];
    }

    return j; 
}

int main() {
    int arr[] = {1, 2, 2, 4, 1, 5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    n = removeDuplicates(arr, n);

    cout << "Array after removing duplicates:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
