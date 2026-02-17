#include<iostream>
using namespace std;

class patient
{
string name;
int age;
int severityLevel;
int arrivalTime;
static int counter;
public:
patient(string n ="", int a=0, int s=1){
    name=n;
    age=a;
    severityLevel=s;
    arrivalTime=++counter;
}

string getName(){
    return name;
}

int getAge(){ 
    return age;
}

int getSeverity(){
    return severityLevel;
}

int getTime(){
    return arrivalTime;
}
};

int patient :: counter=0;

class Queue
{
struct Node{
    patient data;
    Node * next;
    Node(patient p) {
     data=p;
     next=NULL;
    }
};
Node * front;
Node * rear;

public:

Queue(){
    front=NULL;
    rear=NULL;
}

bool isEmpty(){
    return front==NULL;
}

void enqueue(patient p){
    Node * newNode = new Node(p);
    if (isEmpty())
    {
        front=rear=newNode;
    } else {
        rear->next=newNode;
        rear=newNode;
    }
}

patient dequeue(){
    Node * temp = front;
    patient p=temp->data;

    front = front->next;
    delete temp;
    return p;
}

patient peek(){
    return front->data;
}

void display(){
    if (isEmpty())
    {
        cout<<"Empty";
        return;
    }
    
    Node * temp = front;
    while (temp!=NULL)
    {
        cout<<"Name: "<<temp->data.getName()
            <<  ", Age : "<<temp->data.getAge()
            <<  ", Arrival # "<<temp->data.getTime();
    }
    
    if (temp->next != NULL)
    {
        cout<<"->";
    }

    temp=temp->next;
}

};

class ER{
Queue critical;
Queue moderate;
Queue minor;
public:
void addPatient(patient p){
    if (p.getSeverity() == 3)
    {
        critical.enqueue(p);
        cout<<"Patient added to critical queue with arrival # "<<p.getTime()<<endl;
    }
    else if(p.getSeverity()==2){
        moderate.enqueue(p);
        cout<<"Patient added to moderate queue with arrival # "<<p.getTime()<<endl;
    }
    else
    {
        minor.enqueue(p);
        cout<<"Patient added to minor queue with arrival # "<<p.getTime()<<endl;
    }
}

void serveNext(){
    if (!critical.isEmpty())
    {
     patient p = critical.dequeue();
     cout<<"Serving "<<p.getName()<<" with arrival # "<<p.getTime()<<endl;   
    }
    
    else if (!moderate.isEmpty())
    {
     patient p = moderate.dequeue();
     cout<<"Serving "<<p.getName()<<" with arrival # "<<p.getTime()<<endl;   
    }

    else if (!minor.isEmpty())
    {
     patient p = minor.dequeue();
     cout<<"Serving "<<p.getName()<<" with arrival # "<<p.getTime()<<endl;   
    }
    else
    {
        cout<<"No patients in ER"<<endl;
    }
}

void viewNext(){
    if (!critical.isEmpty())
    {
        patient p = critical.peek();
        cout<<"Next Patient: "<<p.getName()<<endl;
    }
    else if (!moderate.isEmpty())
    {
        patient p = moderate.peek();
        cout<<"Next Patient: "<<p.getName()<<endl;
    } 
    else if (!minor.isEmpty())
    {
        patient p = minor.peek();
        cout<<"Next Patient: "<<p.getName()<<endl;
    }
    else
    {
        cout<<"No patients in ER"<<endl;
    }
}

void displayStatus(){
    cout<<"--- ER Status --- "<<endl;
    cout<<"Critical: ";
    critical.display();
    cout<<endl;
    cout<<"Moderate: ";
    moderate.display();
    cout<<endl;
    cout<<"Minor: ";
    minor.display();
    cout<<endl;
}

};

int main(){
    ER a;
    int choice;
    do
    {
        cout<<"---ER System---"<<endl;
        cout<<"1- New patient arrives "<<endl;
        cout<<"2- Serve next patient "<<endl;
        cout<<"3-View next patient"<<endl;
        cout<<"4-Display ER status "<<endl;
        cout<<"5-Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        if (choice==1)
        {
            string name;
            int age , severity;
            cout<<"Enter your name : ";
            cin>>name;
            cout<<endl;
            cout<<" Enter your age : ";
            cin>>age;
            cout<<endl;
            cout<<"/n Enter severity 1- Minor 2- Moderate 3- Critical : ";
            cin>>severity;
            if (severity<1 || severity>3)
            {
                cout<<"Invalid severity /n";
            } else {
                patient p ( name , age , severity);
                a.addPatient(p);
            }
        }

        else if ( choice == 2){
            a.serveNext();
        }

        else if(choice == 3){
            a.viewNext();
        }
        
        else if (choice == 4){
            a.displayStatus();
        }
    } while (choice!=5);
    
    cout<<"Goodbye";
    return 0;
}

