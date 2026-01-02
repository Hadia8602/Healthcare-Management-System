#include <iostream>
#include <fstream>
#include <sstream>
#include "pharmacy.h"
using namespace std;


void add() {
    string amount, name, expiry, mg;
    cout << "Enter name of new medicine: ";
    getline(cin, name);
    cout << "Enter the number of medicines: ";
    getline(cin, amount);
    cout << "Enter the expiry date: ";
    getline(cin, expiry);
    cout << "Enter the mg of medicine: ";
    getline(cin, mg);

    ofstream file("pharmacy.csv", ios::app);
    file << amount << "," << name << "," << mg << "," << expiry << "\n";
    file.close();
    cout << "The medicine is added successfully\n";
}


void view() {
    string line;
    ifstream file("pharmacy.csv", ios::in);
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}


void edit() {
    string line, noOfTablets, expiry_date, mg, name;
    string nameToUpdate, expiry, amount;
    cout << "Enter the name of medicine you want to edit\n";
    getline(cin, nameToUpdate);
    cout << "Enter the number of tablets\n";
    getline(cin, amount);
    cout << "Enter the new expiry date\n";
    getline(cin, expiry);
    cout << "Enter the new mg\n";
    getline(cin, mg);

    bool found = false;
    ifstream file("pharmacy.csv");
    ofstream temp("temp.csv");
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, noOfTablets, ',');
        getline(ss, name, ',');
        getline(ss, mg, ',');
        getline(ss, expiry_date, ',');
        if (nameToUpdate == name) {
            temp << amount << "," << nameToUpdate << "," << mg << "," << expiry << "\n";
            found = true;
        } else {
            temp << line << "\n";
        }
    }
    file.close();
    temp.close();
    remove("pharmacy.csv");
    rename("temp.csv", "pharmacy.csv");
    if (found)
        cout << "medicine updated successfully\n";
    else
        cout << "invalid name!\n";
}


void del() {
    string line, name_to_del, noOfTablets, expiry_date, mg, name;
    cout << "Enter the name of medicine you want to delete: ";
    getline(cin, name_to_del);

    bool found = false;
    ifstream file("pharmacy.csv");
    ofstream temp("temp.csv");

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, noOfTablets, ',');
        getline(ss, name, ',');
        getline(ss, mg, ',');
        getline(ss, expiry_date, ',');
        if (name_to_del == name) {
            found = true;
            continue;
        }
        temp << line << "\n";
    }

    file.close();
    temp.close();
    remove("pharmacy.csv");
    rename("temp.csv", "pharmacy.csv");

    if (found)
        cout << "medicine deleted successfully\n";
    else
        cout << "invalid name!\n";
}


void pharmacyMenu() {
    char choice;
    do {
        cout << "\n1. Add new medicine";
        cout << "\n2. Edit medicine";
        cout << "\n3. Delete medicine";
        cout << "\n4. View all medicines";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case '1': add(); break;
            case '2': edit(); break;
            case '3': del(); break;
            case '4': view(); break;
            case '5': cout << "Exiting menu...\n"; break;
            default: cout << "Invalid choice!\n"; break;
        }
    } while(choice != '5');
}

