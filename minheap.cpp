#include "MinHeap.h"

// Constructor
MinHeap::MinHeap() {}

// Insert a patient into the heap
void MinHeap::insert(const Patient& p) {
    heap.push_back(p);                 // Step 1: Insert at end
    heapifyUp(heap.size() - 1);         // Step 2: Restore min-heap property
}

// Heapify-up operation
// Swaps the node with its parent if priority is smaller
void MinHeap::heapifyUp(int index) {
    while (index != 0 && heap[parent(index)].priority > heap[index].priority) {
        std::swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}

// Remove and return the patient with highest priority (min value)
Patient MinHeap::extractMin() {
    if (isEmpty()) {
        std::cout << "Heap is empty!\n";
        return Patient();
    }

    Patient root = heap[0];             // Highest priority patient
    heap[0] = heap.back();              // Move last to root
    heap.pop_back();                    // Remove last element
    heapifyDown(0);                     // Restore heap property

    return root;
}

// Heapify-down operation
// Pushes the node down to correct position
void MinHeap::heapifyDown(int index) {
    int smallest = index;
    int l = left(index);
    int r = right(index);

    if (l < heap.size() && heap[l].priority < heap[smallest].priority)
        smallest = l;

    if (r < heap.size() && heap[r].priority < heap[smallest].priority)
        smallest = r;

    if (smallest != index) {
        std::swap(heap[index], heap[smallest]);
        heapifyDown(smallest);
    }
}

// Display patients in heap order
void MinHeap::display() const {
    if (isEmpty()) {
        std::cout << "No patients in the queue.\n";
        return;
    }

    for (const auto& p : heap) {
        std::cout << "ID: " << p.id
                  << ", Name: " << p.name
                  << ", Priority: " << p.priority << std::endl;
    }
}

// Check if heap is empty
bool MinHeap::isEmpty() const {
    return heap.empty();
}
