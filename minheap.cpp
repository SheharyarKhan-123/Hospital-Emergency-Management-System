#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "MinHeap.h"

using namespace std;

// ----------------- MinHeap Implementation -----------------
MinHeap::MinHeap() {}

void MinHeap::insert(const Patient& p) {
    heap.push_back(p);
    heapifyUp(heap.size() - 1);
}

void MinHeap::heapifyUp(int index) {
    while (index != 0 && heap[parent(index)].priority > heap[index].priority) {
        swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}

Patient MinHeap::extractMin() {
    if (isEmpty()) {
        cout << "Heap is empty!\n";
        return Patient();
    }

    Patient root = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
    return root;
}

void MinHeap::heapifyDown(int index) {
    int smallest = index;
    int l = left(index);
    int r = right(index);

    if (l < heap.size() && heap[l].priority < heap[smallest].priority)
        smallest = l;
    if (r < heap.size() && heap[r].priority < heap[smallest].priority)
        smallest = r;

    if (smallest != index) {
        swap(heap[index], heap[smallest]);
        heapifyDown(smallest);
    }
}

void MinHeap::display() const {
    if (isEmpty()) {
        cout << "No patients in the queue.\n";
        return;
    }
    for (const auto& p : heap) {
        cout << "ID: " << p.id
             << ", Name: " << p.name
             << ", Age: " << p.age
             << ", Symptoms: " << p.symptoms
             << ", Priority: " << p.priority << endl;
    }
}

bool MinHeap::isEmpty() const {
    return heap.empty();
}

// ----------------- Main Program -----------------
int main() {
    MinHeap pq;
    int choice;
    int nextID = 1;

    do {
        cout << "\n--- Hospital Patient Management ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Display Patients in Heap\n";
        cout << "3. Treat Highest Priority Patient\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        cin.ignore(); // clear input buffer

        switch(choice) {
            case 1: {
                Patient p;
                p.id = nextID++;

                cout << "Enter Name: ";
                getline(cin, p.name);
                cout << "Enter Age: ";
                cin >> p.age;
                cin.ignore();
                cout << "Enter Symptoms: ";
                getline(cin, p.symptoms);
                cout << "Enter Priority (1=Critical,2=Urgent,3=Standard): ";
                cin >> p.priority;
                cin.ignore();

                pq.insert(p);
                cout << "Patient added to heap.\n";
                break;
            }
            case 2: {
                cout << "\nPatients in Heap:\n";
                pq.display();
                break;
            }
            case 3: {
                if (pq.isEmpty()) {
                    cout << "No patients to treat.\n";
                } else {
                    Patient treated = pq.extractMin();
                    cout << "Treating -> ID: " << treated.id
                         << ", Name: " << treated.name
                         << ", Priority: " << treated.priority << endl;
                }
                break;
            }
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}

