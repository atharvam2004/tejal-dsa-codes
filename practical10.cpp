#include <iostream>
#include <queue>
#include <string>
using namespace std;
// Structure representing a patient
struct Patient {
    string name;
    int priority;  // Lower value indicates higher priority

    // Constructor
    Patient(const string& n, int p) : name(n), priority(p) {}

    // Overloading the less-than operator for priority comparison
    bool operator<(const Patient& other) const {
        return priority > other.priority;
    }
};

int main() {
    // Define the priority queue of patients
    priority_queue<Patient> patientQueue;

    // Enqueue patients with different priorities
    patientQueue.push(Patient("nikita", 2));    // Non-serious
    patientQueue.push(Patient("srushti", 1));   // Serious
    patientQueue.push(Patient("tejal", 3));   // General Checkup
    patientQueue.push(Patient("Aashu", 1));   // Serious

    // Serve patients in the order of priority
    while (!patientQueue.empty()) 
	{
        Patient patient = patientQueue.top();
        patientQueue.pop();
        cout << "Serving patient: " << patient.name << " (Priority: " << patient.priority << ")" << endl;
    }

    return 0;
}

