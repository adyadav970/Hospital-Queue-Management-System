#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

// Patient structure
struct Patient
{
    int id;
    string name;
    int age;
    string problem;
    int priority;
};

// Comparator for Emergency Priority Queue
struct Compare
{
    bool operator()(Patient a, Patient b)
    {
        return a.priority > b.priority;
    }
};

// Queues
queue<Patient> normalQueue;

priority_queue<Patient, vector<Patient>, Compare> emergencyQueue;

// Automatically generated Patient ID
int nextPatientId = 1001;

// Function to convert priority number into text
string getPriorityName(int priority)
{
    if (priority == 1)
        return "HIGH";

    if (priority == 2)
        return "MEDIUM";

    return "LOW";
}

// Press Enter function
void pressEnter()
{
    cout << "\nPress Enter to continue...";
    cin.ignore(1000, '\n');
    cin.get();
}

// Display patient details
void displayPatient(Patient p)
{
    cout << "--------------------------------------------\n";

    cout << "Patient ID : " << p.id << endl;
    cout << "Name       : " << p.name << endl;
    cout << "Age        : " << p.age << endl;
    cout << "Problem    : " << p.problem << endl;

    if (p.priority == 0)
    {
        cout << "Type       : Normal" << endl;
    }
    else
    {
        cout << "Type       : Emergency" << endl;
        cout << "Priority   : " << getPriorityName(p.priority) << endl;
    }

    cout << "--------------------------------------------\n";
}

// Add Normal Patient
void addNormalPatient()
{
    Patient p;

    cout << "\n============================================\n";
    cout << "           ADD NORMAL PATIENT\n";
    cout << "============================================\n";

    p.id = nextPatientId;
    nextPatientId++;

    cout << "Enter patient name: ";
    cin.ignore(1000, '\n');
    getline(cin, p.name);

    cout << "Enter age: ";
    cin >> p.age;

    cout << "Enter problem: ";
    cin.ignore(1000, '\n');
    getline(cin, p.problem);

    p.priority = 0;

    normalQueue.push(p);

    cout << "\n============================================\n";
    cout << "           PATIENT REGISTERED\n";
    cout << "============================================\n";

    cout << "\n       Patient added successfully!\n\n";

    displayPatient(p);

    cout << "\n       Please wait for your turn.\n";

    cout << "\n============================================\n";

    pressEnter();
}

// Add Emergency Patient
void addEmergencyPatient()
{
    Patient p;
    int choice;

    cout << "\n============================================\n";
    cout << "        ADD EMERGENCY PATIENT\n";
    cout << "============================================\n";

    p.id = nextPatientId;
    nextPatientId++;

    cout << "Enter patient name: ";
    cin.ignore(1000, '\n');
    getline(cin, p.name);

    cout << "Enter age: ";
    cin >> p.age;

    cout << "Enter problem: ";
    cin.ignore(1000, '\n');
    getline(cin, p.problem);

    cout << "\nSelect Priority:\n";
    cout << "1. High\n";
    cout << "2. Medium\n";
    cout << "3. Low\n";
    cout << "Enter choice: ";

    if (!(cin >> choice))
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "\nInvalid input. Please enter a number.\n";
        pressEnter();
        return;
    }

    while (choice < 1 || choice > 3)
    {
        cout << "Invalid choice. Enter 1, 2 or 3: ";
        cin >> choice;
    }

    p.priority = choice;

    emergencyQueue.push(p);

    cout << "\n============================================\n";
    cout << "       EMERGENCY PATIENT REGISTERED\n";
    cout << "============================================\n";

    cout << "\n       Patient added successfully!\n\n";

    displayPatient(p);

    cout << "\n       Patient will be served\n";
    cout << "       according to priority.\n";

    cout << "\n============================================\n";

    pressEnter();
}

// Serve Next Patient
void serveNextPatient()
{
    Patient p;

    cout << "\n============================================\n";
    cout << "               NEXT PATIENT\n";
    cout << "============================================\n\n";

    // Emergency patients get priority
    if (!emergencyQueue.empty())
    {
        p = emergencyQueue.top();
        emergencyQueue.pop();

        displayPatient(p);
    }

    // If no emergency patient, serve normal patient
    else if (!normalQueue.empty())
    {
        p = normalQueue.front();
        normalQueue.pop();

        displayPatient(p);
    }

    else
    {
        cout << "       No patients in the queue.\n";
    }

    cout << "\n============================================\n";

    pressEnter();
}

// Display Normal Queue
void displayNormalQueue()
{
    cout << "\n============================================\n";
    cout << "             NORMAL PATIENT QUEUE\n";
    cout << "============================================\n\n";

    if (normalQueue.empty())
    {
        cout << "       No patients in the queue.\n";
    }
    else
    {
        queue<Patient> temp = normalQueue;

        while (!temp.empty())
        {
            Patient p = temp.front();
            temp.pop();

            cout << "Patient ID : " << p.id << endl;
            cout << "Name       : " << p.name << endl;
            cout << "Age        : " << p.age << endl;
            cout << "Problem    : " << p.problem << endl;

            cout << "--------------------------------------------\n";
        }
    }

    cout << "\n============================================\n";

    pressEnter();
}

// Display Emergency Queue
void displayEmergencyQueue()
{
    cout << "\n============================================\n";
    cout << "          EMERGENCY PATIENT QUEUE\n";
    cout << "============================================\n\n";

    if (emergencyQueue.empty())
    {
        cout << "       No patients in the queue.\n";
    }
    else
    {
        priority_queue<Patient, vector<Patient>, Compare> temp = emergencyQueue;

        while (!temp.empty())
        {
            Patient p = temp.top();
            temp.pop();

            cout << "Patient ID : " << p.id << endl;
            cout << "Name       : " << p.name << endl;
            cout << "Age        : " << p.age << endl;
            cout << "Problem    : " << p.problem << endl;
            cout << "Priority   : " << getPriorityName(p.priority) << endl;

            cout << "--------------------------------------------\n";
        }
    }

    cout << "\n============================================\n";

    pressEnter();
}

// Search Patient by ID
void searchById()
{
    int id;
    bool found = false;

    cout << "\nEnter Patient ID: ";
    cin >> id;

    // Search in normal queue
    queue<Patient> tempNormal = normalQueue;

    while (!tempNormal.empty())
    {
        Patient p = tempNormal.front();
        tempNormal.pop();

        if (p.id == id)
        {
            cout << "\n============================================\n";
            cout << "             PATIENT FOUND\n";
            cout << "============================================\n\n";

            displayPatient(p);

            cout << "\n============================================\n";

            found = true;
            break;
        }
    }

    // Search in emergency queue
    if (!found)
    {
        priority_queue<Patient, vector<Patient>, Compare> tempEmergency = emergencyQueue;

        while (!tempEmergency.empty())
        {
            Patient p = tempEmergency.top();
            tempEmergency.pop();

            if (p.id == id)
            {
                cout << "\n============================================\n";
                cout << "             PATIENT FOUND\n";
                cout << "============================================\n\n";

                displayPatient(p);

                cout << "\n============================================\n";

                found = true;
                break;
            }
        }
    }

    if (!found)
    {
        cout << "\nPatient not found.\n";
    }
}

// Search Patient by Name
void searchByName()
{
    string name;
    bool found = false;

    cout << "\nEnter Patient Name: ";
    cin.ignore(1000, '\n');
    getline(cin, name);

    // Search in normal queue
    queue<Patient> tempNormal = normalQueue;

    while (!tempNormal.empty())
    {
        Patient p = tempNormal.front();
        tempNormal.pop();

        if (p.name == name)
        {
            if (!found)
            {
                cout << "\n============================================\n";
                cout << "             PATIENT FOUND\n";
                cout << "============================================\n";
            }

            cout << endl;
            displayPatient(p);

            found = true;
        }
    }

    // Search in emergency queue
    priority_queue<Patient, vector<Patient>, Compare> tempEmergency = emergencyQueue;

    while (!tempEmergency.empty())
    {
        Patient p = tempEmergency.top();
        tempEmergency.pop();

        if (p.name == name)
        {
            if (!found)
            {
                cout << "\n============================================\n";
                cout << "             PATIENT FOUND\n";
                cout << "============================================\n";
            }

            cout << endl;
            displayPatient(p);

            found = true;
        }
    }

    if (!found)
    {
        cout << "\nPatient not found.\n";
    }
    else
    {
        cout << "\n============================================\n";
    }
}

// Search Menu
void searchPatient()
{
    int choice;

    cout << "\n============================================\n";
    cout << "              SEARCH PATIENT\n";
    cout << "============================================\n";

    cout << "1. Search by Patient ID\n";
    cout << "2. Search by Patient Name\n";

    cout << "\nEnter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        searchById();
    }
    else if (choice == 2)
    {
        searchByName();
    }
    else
    {
        cout << "\nInvalid choice.\n";
    }

    pressEnter();
}

// Main Function
int main()
{
    int choice;

    while (true)
    {
        cout << "\n\n";
        cout << "============================================\n";
        cout << "       HOSPITAL QUEUE MANAGEMENT SYSTEM\n";
        cout << "============================================\n\n";

        cout << "1. Add Normal Patient\n";
        cout << "2. Add Emergency Patient\n";
        cout << "3. Serve Next Patient\n";
        cout << "4. View Normal Queue\n";
        cout << "5. View Emergency Queue\n";
        cout << "6. Search Patient\n";
        cout << "7. Exit\n";

        cout << "\n============================================\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "\nInvalid input. Please enter a number.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            addNormalPatient();
            break;

        case 2:
            addEmergencyPatient();
            break;

        case 3:
            serveNextPatient();
            break;

        case 4:
            displayNormalQueue();
            break;

        case 5:
            displayEmergencyQueue();
            break;

        case 6:
            searchPatient();
            break;

        case 7:
            cout << "\nThank you for using Hospital Queue Management System!\n";
            return 0;

        default:
            cout << "\nInvalid choice. Please try again.\n";
            pressEnter();
        }
    }

    return 0;
}