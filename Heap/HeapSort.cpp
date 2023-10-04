//Heap Sort --> We have given a random array sort it
//Step 1: Build MaxHeap, If You want to sort in Increasing Order
//For Decreasing Order->Build MinHeap
//After that next Step
//Use Selection Sort and MaxHeapify to hold maxHeap Property
//Time Complexity: O(nlog(n))

#include<bits/stdc++.h>
using namespace std;


int left(int i) {
    return (2 * i) + 1;
}

int right(int i) {
    return (2 * i) + 2;
}

int parent(int i) {
    return (i - 1) / 2;
}

void maxHeapify(vector<int>& arr,int n, int i) {
    int lt = left(i), rt = right(i);

    int largest = i;
    if(lt < n and arr[lt] > arr[largest]) {
        largest = lt;
    }

    if(rt < n and arr[rt] > arr[largest]) {
        largest = rt;
    }

    if(largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildHeap(vector<int>& nums) {

    int n = nums.size();
    for(int i=(n - 2) / 2; i>=0; i--) {
        maxHeapify(nums, n, i);
    }
}

void heapSort(vector<int>& nums) {
    int n = nums.size();

    //Maxm Element is on the top
    buildHeap(nums);

    //Use Selection Sort
    for(int i=n-1; i>=1; i--) {
        swap(nums[0], nums[i]);
        maxHeapify(nums, i, 0);
    }
}

void bournVita() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif  
}

void solve() {

    vector<int> arr = {20, 10, 30, 70, 15, 52};

    heapSort(arr);

    for(int i=0; i<6; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    bournVita();

    solve();
}
