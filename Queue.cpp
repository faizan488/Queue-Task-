#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Node::Node(patient p)
{
    data = p;
    next = NULL;
}

Queue::Queue()
{
    front = rear = NULL;
}

bool Queue::isEmpty()
{
    return front == NULL;
}

void Queue::enqueue(patient p)
{
    Node* newNode = new Node(p);

    if (isEmpty())
        front = rear = newNode;
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

patient Queue::dequeue()
{
    Node* temp = front;
    patient p = temp->data;

    front = front->next;
    delete temp;

    if (front == NULL)
        rear = NULL;

    return p;
}

patient Queue::peek()
{
    return front->data;
}

void Queue::display()
{
    if (isEmpty()) {
        cout << "Empty";
        return;
    }

    Node* temp = front;

    while (temp != NULL)
    {
        cout << "Name: " << temp->data.getName()
             << ", Age: " << temp->data.getAge()
             << ", Arrival #: " << temp->data.getTime();

        if (temp->next != NULL)
            cout << " -> ";

        temp = temp->next;
    }
}
