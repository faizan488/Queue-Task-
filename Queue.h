#ifndef QUEUE_H
#define QUEUE_H

#include "patient.h"

class Queue
{
    struct Node {
        patient data;
        Node* next;
        Node(patient p);
    };

    Node* front;
    Node* rear;

public:
    Queue();
    bool isEmpty();
    void enqueue(patient p);
    patient dequeue();
    patient peek();
    void display();
};

#endif
