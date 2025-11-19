#include <iostream>
using namespace std;

class HeapSorter {
    static void swapInt(int &a, int &b){ int t=a; a=b; b=t; }
    static void heapifyMax(int arr[], int n, int i){
        int largest=i;
        int l=2*i+1;
        int r=2*i+2;
        if(l<n && arr[l]>arr[largest]) largest=l;
        if(r<n && arr[r]>arr[largest]) largest=r;
        if(largest!=i){ swapInt(arr[i], arr[largest]); heapifyMax(arr,n,largest); }
    }
    static void heapifyMin(int arr[], int n, int i){
        int smallest=i;
        int l=2*i+1;
        int r=2*i+2;
        if(l<n && arr[l]<arr[smallest]) smallest=l;
        if(r<n && arr[r]<arr[smallest]) smallest=r;
        if(smallest!=i){ swapInt(arr[i], arr[smallest]); heapifyMin(arr,n,smallest); }
    }
public:
    static void sortIncreasing(int arr[], int n){
        for(int i=n/2-1;i>=0;--i) heapifyMax(arr,n,i);
        for(int i=n-1;i>0;--i){ swapInt(arr[0], arr[i]); heapifyMax(arr,i,0); }
    }
    static void sortDecreasing(int arr[], int n){
        for(int i=n/2-1;i>=0;--i) heapifyMin(arr,n,i);
        for(int i=n-1;i>0;--i){ swapInt(arr[0], arr[i]); heapifyMin(arr,i,0); }
    }
};

int main(){
    int a1[] = {12, 11, 13, 5, 6, 7};
    int n1 = sizeof(a1)/sizeof(a1[0]);
    HeapSorter::sortIncreasing(a1,n1);
    for(int i=0;i<n1;++i) cout<<a1[i]<<" ";
    cout<<"\n";
    int a2[] = {3, 19, 1, 14, 8, 7};
    int n2 = sizeof(a2)/sizeof(a2[0]);
    HeapSorter::sortDecreasing(a2,n2);
    for(int i=0;i<n2;++i) cout<<a2[i]<<" ";
    cout<<"\n";
    return 0;
}
