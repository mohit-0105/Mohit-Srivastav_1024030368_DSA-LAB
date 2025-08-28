#include <iostream>
#include <vector>
using namespace std;

long long merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    long long inv_count = 0;
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else {
            arr[k++] = R[j++];
            inv_count += (n1 - i);
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    return inv_count;
}

long long mergeSort(vector<int> &arr, int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        inv_count += mergeSort(arr, left, mid);
        inv_count += mergeSort(arr, mid + 1, right);
        inv_count += merge(arr, left, mid, right);
    }
    return inv_count;
}

int main() {
    vector<int> arr = {2, 4, 1, 3, 5};
    long long inversions = mergeSort(arr, 0, arr.size() - 1);

    cout << "Number of inversions: " << inversions << endl;
    return 0;
}
