#include <iostream>
using namespace std;

const int MAX = 100;
int arr[MAX];
int n = 0;

void create() {
    cout << "Enter number of elements: ";
    cin >> n;
    if(n > MAX) {
        cout << "Exceeded maximum limit of " << MAX << endl;
        n = 0;
        return;
    }
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void display() {
    if(n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array elements:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert() {
    if (n >= MAX) {
        cout << "Array is full.\n";
        return;
    }
    int pos, val;
    cout << "Enter position to insert (0 to " << n << "): ";
    cin >> pos;
    if(pos < 0 || pos > n) {
        cout << "Invalid position.\n";
        return;
    }
    cout << "Enter value to insert: ";
    cin >> val;
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = val;
    n++;
    cout << "Element inserted.\n";
}

void deleteElement() {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    int pos;
    cout << "Enter position to delete (0 to " << n-1 << "): ";
    cin >> pos;
    if(pos < 0 || pos >= n) {
        cout << "Invalid position.\n";
        return;
    }
    for (int i = pos; i < n-1; i++) {
        arr[i] = arr[i+1];
    }
    n--;
    cout << "Element deleted.\n";
}

void linearSearch() {
    if(n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    int key, found = 0;
    cout << "Enter value to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Value found at index " << i << endl;
            found = 1;
        }
    }
    if (!found) {
        cout << "Value not found.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\nMENU:\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
