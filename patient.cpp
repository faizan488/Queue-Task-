#include "patient.h"

int patient::counter = 0;

patient::patient(string n, int a, int s)
{
    name = n;
    age = a;
    severityLevel = s;
    arrivalTime = ++counter;
}

string patient::getName() { return name; }
int patient::getAge() { return age; }
int patient::getSeverity() { return severityLevel; }
int patient::getTime() { return arrivalTime; }
