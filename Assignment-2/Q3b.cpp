#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n-1];
    for (int i = 0; i < n-1; i++) cin >> arr[i];
    int l = 0, r = n - 2, mid, ans = n;
    while (l <= r) {
        mid = (l + r) / 2;
        if (arr[mid] == mid + 1) l = mid + 1;
        else {
            ans = mid + 1;
            r = mid - 1;
        }
    }
    cout << "Missing: " << ans;
}