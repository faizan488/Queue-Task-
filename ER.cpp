#include <iostream>
#include "ER.h"

using namespace std;

void ER::addPatient(patient p)
{
    if (p.getSeverity() == 3) {
        critical.enqueue(p);
        cout << "Patient added to critical queue with arrival # "
             << p.getTime() << endl;
    }
    else if (p.getSeverity() == 2) {
        moderate.enqueue(p);
        cout << "Patient added to moderate queue with arrival # "
             << p.getTime() << endl;
    }
    else {
        minor.enqueue(p);
        cout << "Patient added to minor queue with arrival # "
             << p.getTime() << endl;
    }
}

void ER::serveNext()
{
    if (!critical.isEmpty()) {
        patient p = critical.dequeue();
        cout << "Serving " << p.getName()
             << " with arrival # " << p.getTime() << endl;
    }
    else if (!moderate.isEmpty()) {
        patient p = moderate.dequeue();
        cout << "Serving " << p.getName()
             << " with arrival # " << p.getTime() << endl;
    }
    else if (!minor.isEmpty()) {
        patient p = minor.dequeue();
        cout << "Serving " << p.getName()
             << " with arrival # " << p.getTime() << endl;
    }
    else {
        cout << "No patients in ER" << endl;
    }
}

void ER::viewNext()
{
    if (!critical.isEmpty())
        cout << "Next Patient: " << critical.peek().getName() << endl;
    else if (!moderate.isEmpty())
        cout << "Next Patient: " << moderate.peek().getName() << endl;
    else if (!minor.isEmpty())
        cout << "Next Patient: " << minor.peek().getName() << endl;
    else
        cout << "No patients in ER" << endl;
}

void ER::displayStatus()
{
    cout << "--- ER Status ---" << endl;

    cout << "Critical: ";
    critical.display();
    cout << endl;

    cout << "Moderate: ";
    moderate.display();
    cout << endl;

    cout << "Minor: ";
    minor.display();
    cout << endl;
}
