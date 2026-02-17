#include <iostream>
#include "ER.h"

using namespace std;

int main()
{
    ER a;
    int choice;

    do {
        cout << "\n--- ER System ---" << endl;
        cout << "1- New patient arrives" << endl;
        cout << "2- Serve next patient" << endl;
        cout << "3- View next patient" << endl;
        cout << "4- Display ER status" << endl;
        cout << "5- Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int age, severity;

            cout << "Enter name: ";
            cin >> name;

            cout << "Enter age: ";
            cin >> age;

            cout << "Enter severity (1-Minor, 2-Moderate, 3-Critical): ";
            cin >> severity;

            if (severity < 1 || severity > 3)
                cout << "Invalid severity!" << endl;
            else {
                patient p(name, age, severity);
                a.addPatient(p);
            }
        }
        else if (choice == 2)
            a.serveNext();
        else if (choice == 3)
            a.viewNext();
        else if (choice == 4)
            a.displayStatus();

    } while (choice != 5);

    cout << "Goodbye!" << endl;
    return 0;
}
