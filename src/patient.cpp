#include <iostream>
#include <fstream>
#include <string>
#include "patient.h"
using namespace std;

void addPatient()
{
    ofstream file("patients.csv", ios::app);

    if (!file)
    {
        cout << "File error!\n";
        return;
    }

    string id, name, age, gender, contact, disease;

    cout << "Enter Patient ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Gender: ";
    cin >> gender;
    cout << "Enter Contact: ";
    cin >> contact;
    cout << "Enter Disease: ";
    cin >> disease;

    file << id << "," << name << "," << age << ","
         << gender << "," << contact << "," << disease << endl;

    file.close();
    cout << "Patient added successfully.\n";
}

void viewPatient() {
    ifstream file("patients.csv"); 
    string id, name, age, gender, contact, disease, searchId;
    bool found = false;

    if (!file.is_open()) {
        cout << "Error: Could not open database.\n";
        return;
    }

    cout << "Enter Patient ID to search: ";
    cin >> searchId;

    while (getline(file, id, ',')) {
        getline(file, name, ',');
        getline(file, age, ',');
        getline(file, gender, ',');
        getline(file, contact, ',');
        getline(file, disease); 

        if (id == searchId) {
            found = true;
            cout << "\n--- Patient Record Found ---" << endl;
            cout << "ID:      " << id << endl;
            cout << "Name:    " << name << endl;
            cout << "Age:     " << age << endl;
            cout << "Gender:  " << gender << endl;
            cout << "Contact: " << contact << endl;
            cout << "Disease: " << disease << endl;
            break; 
        }
    }

    file.close();

    if (!found) {
        cout << "Patient not found.\n";
    }
}

void updatePatient()
{
    ifstream file("patients.csv");
    ofstream temp("temp.csv");

    string id, name, age, gender, contact, disease, searchId;
    char comma;
    bool found = false;

    cout << "Enter Patient ID to update: ";
    cin >> searchId;

    while (file >> id >> comma >> name >> comma >> age >> comma
                >> gender >> comma >> contact >> comma >> disease)
    {
        if (id == searchId)
        {
            cout << "Enter New Name: ";
            cin >> name;
            cout << "Enter New Age: ";
            cin >> age;
            cout << "Enter New Gender: ";
            cin >> gender;
            cout << "Enter New Contact: ";
            cin >> contact;
            cout << "Enter New Disease: ";
            cin >> disease;

            found = true;
        }

        temp << id << "," << name << "," << age << ","
             << gender << "," << contact << "," << disease << endl;
    }

    file.close();
    temp.close();

    remove("patients.csv");
    rename("temp.csv", "patients.csv");

    if (found)
        cout << "Patient record updated successfully.\n";
    else
        cout << "Patient not found.\n";
}

void deletePatient()
{
    ifstream file("patients.csv");
    ofstream temp("temp.csv");

    string id, name, age, gender, contact, disease, searchId;
    char comma;
    bool found = false;

    cout << "Enter Patient ID to delete: ";
    cin >> searchId;

    while (file >> id >> comma >> name >> comma >> age >> comma
                >> gender >> comma >> contact >> comma >> disease)
    {
        if (id == searchId) {
            found = true;
            continue;
        }

        temp << id << "," << name << "," << age << ","
             << gender << "," << contact << "," << disease << endl;
    }

    file.close();
    temp.close();

    remove("patients.csv");
    rename("temp.csv", "patients.csv");

    if (found)
        cout << "Patient record deleted successfully.\n";
    else
        cout << "Patient not found.\n";
}

void patientMenu()
{
    int choice;
    do {
        cout << "\n===== Patient Management Menu =====\n";
        cout << "1. Add Patient\n2. View Patient\n3. Update Patient\n"
             << "4. Delete Patient\n0. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        switch(choice) {
            case 1: addPatient(); break;
            case 2: viewPatient(); break;
            case 3: updatePatient(); break;
            case 4: deletePatient(); break;
            case 0: break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 0);
}