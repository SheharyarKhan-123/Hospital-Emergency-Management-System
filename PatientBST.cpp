#include "PatientBST.h"
#include <iostream>
#include <fstream>
using namespace std;

//BST Node Constructor
BSTNode::BSTNode(const Patient& p) {
    data = p;
    left = NULL;
    right = NULL;
}

// BST Constructor
PatientBST::PatientBST() {
    root = NULL;
}

//Private Insert Helper
BSTNode* PatientBST::insert(BSTNode* node, const Patient& p) {
    if (node == NULL) {
        return new BSTNode(p);
    }

    if (p.id < node->data.id) {
        node->left = insert(node->left, p);
    }
    else if (p.id > node->data.id) {
        node->right = insert(node->right, p);
    }

    return node;
}

// ===== Load Records From File =====
void PatientBST::loadFromFile(const string& filename) {
    ifstream file(filename.c_str());

    if (!file.is_open()) {
        cout << "File could not be opened." << endl;
        return;
    }

    Patient p;

    // file format:
    // id name age symptoms priority
    while (file >> p.id >> p.name >> p.age >> p.symptoms >> p.priority) {
        root = insert(root, p);
    }

    file.close();
}

// ===== Private Search Helper =====
BSTNode* PatientBST::search(BSTNode* node, int id) {
    if (node == NULL) {
        return NULL;
    }

    if (node->data.id == id) {
        return node;
    }

    if (id < node->data.id) {
        return search(node->left, id);
    }
    else {
        return search(node->right, id);
    }
}

//Public Search
Patient* PatientBST::search(int id) {
    BSTNode* result = search(root, id);

    if (result != NULL) {
        return &result->data;
    }

    return NULL;
}
