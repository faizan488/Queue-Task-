#ifndef ER_H
#define ER_H

#include "Queue.h"

class ER
{
    Queue critical;
    Queue moderate;
    Queue minor;

public:
    void addPatient(patient p);
    void serveNext();
    void viewNext();
    void displayStatus();
};

#endif
