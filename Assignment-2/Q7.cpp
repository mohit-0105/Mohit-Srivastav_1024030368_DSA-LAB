#include<iostream>
using namespace std;

long long mergeAndCount(int arr[], int l, int m, int r) {
    int n1 = m-l+1, n2 = r-m;
    int L[n1], R[n2];
    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int i=0;i<n2;i++) R[i]=arr[m+1+i];

    int i=0,j=0,k=l;
    long long inv=0;

    while(i<n1 && j<n2) {
        if(L[i] <= R[j]) arr[k++] = L[i++];
        else {
            arr[k++] = R[j++];
            inv += (n1 - i); 
        }
    }
    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
    return inv;
}

long long mergeSortAndCount(int arr[], int l, int r) {
    long long inv = 0;
    if(l<r) {
        int m = (l+r)/2;
        inv += mergeSortAndCount(arr,l,m);
        inv += mergeSortAndCount(arr,m+1,r);
        inv += mergeAndCount(arr,l,m,r);
    }
    return inv;
}

int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Number of inversions: "<<mergeSortAndCount(arr,0,n-1)<<endl;
}
