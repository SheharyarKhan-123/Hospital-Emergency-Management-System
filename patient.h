#ifndef PATIENT_H
#define PATIENT_H

#include <string>

struct Patient {
    int id;
    std::string name;
    int age;
    std::string symptoms;
    int priority; // 1 = Critical, 2 = Urgent, 3 = Standard
};

#endif

