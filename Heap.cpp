#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class MinHeap {
private:
    vector<int> heap;   // array that holds the heap

    // Get parent index in the array
    int parent(int i) { return (i - 1) / 2; }
    // Get left child index
    int left(int i)   { return 2 * i + 1; }
    // Get right child index
    int right(int i)  { return 2 * i + 2; }

    // "Bubble up" – used after inserting a new element.
    // Moves the element at index i up until heap property is restored.
    void siftUp(int i) {
        while (i > 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // "Bubble down" – used after extracting the minimum or during heap building.
    // Moves the element at index i down until heap property is restored.
    void siftDown(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i);
        int n = heap.size();

        if (l < n && heap[l] < heap[smallest])
            smallest = l;
        if (r < n && heap[r] < heap[smallest])
            smallest = r;

        // If the smallest is not the current node, swap and continue
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            siftDown(smallest);   // recursively fix the affected subtree
        }
    }

public:
    // Default constructor: empty heap
    MinHeap() {}

    // Build heap from an existing array in O(n) time
    MinHeap(const vector<int>& arr) {
        heap = arr;                           // copy the array
        int n = heap.size();
        // Start from the last non‑leaf node and siftDown each
        for (int i = n / 2 - 1; i >= 0; i--) {
            siftDown(i);
        }
    }

    // Insert a new value into the heap
    void insert(int val) {
        heap.push_back(val);     // add at the end
        siftUp(heap.size() - 1); // bubble it up to its correct position
    }

    // Get the minimum value (root) without removing it
    int getMin() const {
        if (heap.empty()) throw runtime_error("Heap is empty");
        return heap[0];
    }

    // Remove and return the minimum value (root)
    int extractMin() {
        if (heap.empty()) throw runtime_error("Heap is empty");
        int minVal = heap[0];
        // Move the last element to the root, then remove the last
        heap[0] = heap.back();
        heap.pop_back();
        // Restore heap property by bubbling the new root down
        if (!heap.empty())
            siftDown(0);
        return minVal;
    }

    // Check if the heap is empty
    bool isEmpty() const { return heap.empty(); }

    // Return the number of elements in the heap
    int size() const { return heap.size(); }
};

// ---------- Example usage ----------
int main() {
    // Build a heap from an array
    vector<int> arr = {10, 3, 8, 2, 7};
    MinHeap heap(arr);

    cout << "Heap built from array [10,3,8,2,7]" << endl;
    cout << "Minimum: " << heap.getMin() << endl;  // should be 2

    cout << "Extracting min: " << heap.extractMin() << endl;
    cout << "New minimum: " << heap.getMin() << endl; // should be 3

    heap.insert(1);
    cout << "After inserting 1, min becomes: " << heap.getMin() << endl; // 1

    cout << "Extracting all elements: ";
    while (!heap.isEmpty()) {
        cout << heap.extractMin() << " ";
    }
    cout << endl;

    return 0;
}