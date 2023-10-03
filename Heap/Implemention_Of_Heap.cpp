#include<bits/stdc++.h>
using namespace std;

class heap {
public:
    vector<int> arr;
    int size;
    int capacity;

    heap(int c) {
        arr.resize(c, 0);
        capacity = c;
        size = 0;
    }

    int left(int i) {
        return (2 * i) + 1;
    }

    int right(int i) {
        return (2 * i) + 2;
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    //It works for MinHeap
    //Time C: O(log(h))
    void minHeapInsert(int x) {
        if(size == capacity) return;

        arr[size] = x;
        size++;

        for(int i=(size - 1); i != 0 and arr[parent(i)] > arr[i];) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    //It works for MaxHeap
    //Time C: O(log(h))
    void maxHeapInsert(int x) {
        if(size == capacity) return;

        arr[size] = x;
        size++;

        for(int i=(size - 1); i != 0 and arr[parent(i)] < arr[i];) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    ///Given a binary heap with one possible violation
    //Fix the heap
    void minHeapify(int i) {
        int lt = left(i);
        int rt = right(i);

        int smallest = i;
        if(lt < size and arr[lt] < arr[i]) {
            smallest = lt;
        }

        if(rt < size and arr[rt] < arr[smallest]) {
            smallest = rt;
        }


        if(smallest != i) {
            swap(arr[smallest], arr[i]);
            minHeapify(smallest);
        }
    }

    //Extract Min Element from the heap
    //We know that minm always present on the root
    int extractMin() {

        if(size == 0) {
            return INT_MAX;
        }

        if(size == 1) {
            size--;
            return arr[0];
        }

        swap(arr[0], arr[size - 1]);
        size--;
        minHeapify(0);

        return arr[size];
    }

    //At idx = i we have to replace with new value x
    void decreaseKey(int i, int x) {
        arr[i] = x;

        while(i != 0 and arr[parent(i)] > arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    //Delete element at particular idx
    void deleteMin(int i) {

        decreaseKey(i, INT_MIN);

        extractMin();
    }

    //Given a random array, rearrange its
    //element to form a minHeap
    void buildHeap() {

        //We need bottom right Most element...i.e, at idx (size - 2) / 2
        //We have a size and last node is at idx (size - 1)
        //then parent of (size - 1) = ( (size - 1) - 1 ) / 2 = (size - 2) / 2;
        for(int i=(size - 2) / 2; i>=0; i--) {
            minHeapify(i);
        }
    }
};

void bournVita() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif  
}

void solve() {
    heap h(10);

    for(int i=0; i<6; i++) {
        int x; cin >> x;
        h.minHeapInsert(x);
    }

    //h.minHeapInsert(12);

    for(int i=0; i<h.size; i++) {
        cout << h.arr[i] << " ";
    }
    cout << endl;

    h.decreaseKey(3, 5);
    h.deleteMin(3);

    for(int i=0; i<h.size; i++) {
        cout << h.arr[i] << " ";
    }
    cout << endl;
}

int main() {
    bournVita();

    solve();
}
