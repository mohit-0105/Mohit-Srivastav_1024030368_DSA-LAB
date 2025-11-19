#include <iostream>
using namespace std;

class MaxPriorityQueue {
    int *data;
    int cap;
    int sz;
    void swapInt(int &a,int &b){ int t=a; a=b; b=t; }
    void siftUp(int i){
        while(i>0){
            int p=(i-1)/2;
            if(data[p]<data[i]){ swapInt(data[p],data[i]); i=p; } else break;
        }
    }
    void siftDown(int i){
        while(true){
            int l=2*i+1;
            int r=2*i+2;
            int largest=i;
            if(l<sz && data[l]>data[largest]) largest=l;
            if(r<sz && data[r]>data[largest]) largest=r;
            if(largest!=i){ swapInt(data[i], data[largest]); i=largest; } else break;
        }
    }
public:
    MaxPriorityQueue(int capacity){
        cap = capacity;
        data = new int[cap];
        sz = 0;
    }
    ~MaxPriorityQueue(){ delete [] data; }
    bool empty(){ return sz==0; }
    bool full(){ return sz==cap; }
    void insert(int v){
        if(full()) return;
        data[sz++] = v;
        siftUp(sz-1);
    }
    int extractMax(){
        if(empty()) return -2147483648;
        int root = data[0];
        data[0] = data[--sz];
        siftDown(0);
        return root;
    }
    int peek(){ return empty() ? -2147483648 : data[0]; }
    int size(){ return sz; }
};

int main(){
    MaxPriorityQueue pq(20);
    pq.insert(15);
    pq.insert(10);
    pq.insert(30);
    pq.insert(40);
    pq.insert(5);
    while(!pq.empty()){
        cout<<pq.extractMax()<<" ";
    }
    cout<<"\n";
    return 0;
}
