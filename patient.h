#ifndef PATIENT_H
#define PATIENT_H

#include <string>
using namespace std;

class patient
{
    string name;
    int age;
    int severityLevel;
    int arrivalTime;
    static int counter;

public:
    patient(string n="", int a=0, int s=1);

    string getName();
    int getAge();
    int getSeverity();
    int getTime();
};

#endif
