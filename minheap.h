#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>
#include <iostream>
#include "Patient.h"   // Using the Patient structure

// MinHeap class for patient prioritization
// Lower priority value means higher treatment priority
class MinHeap {
private:
    std::vector<Patient> heap;

    // Helper functions to navigate the heap tree
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    // Moves a node upward to restore heap property
    void heapifyUp(int index);

    // Moves a node downward to restore heap property
    void heapifyDown(int index);

public:
    // Constructor
    MinHeap();

    // Insert a new patient into the heap
    void insert(const Patient& p);

    // Remove and return the highest priority patient
    Patient extractMin();

    // Display all patients in heap order
    void display() const;

    // Utility
    bool isEmpty() const;
};

#endif
