#ifndef PATIENT_BST_H
#define PATIENT_BST_H

#include "patient.h"
#include <string>
using namespace std;

// BST Node
struct BSTNode {
    Patient data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(const Patient& p);   // constructor
};

//Patient BST Class
class PatientBST {
private:
    BSTNode* root;

    // helper functions (not accessible outside)
    BSTNode* insert(BSTNode* node, const Patient& p);
    BSTNode* search(BSTNode* node, int id);

public:
    PatientBST();                         // constructor
    void insert(const Patient& p);
	Patient* search(int id);              // search by ID
};

#endif
