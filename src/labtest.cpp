#include <iostream>
#include <fstream>
#include <string>
#include "labtest.h"
using namespace std;

void addLabTest() {
    int n;
    cout << "Please enter number of tests you want to add: ";
    cin >> n;
    cin.ignore();
    ofstream fout("labreport.csv", ios::app);

    for(int i = 1; i <= n; i++) {
        string testid, patientname, testname, testdate;
        cout << "\nADD LAB TEST " << i << endl;
        cout << "Please enter test ID: ";
        cin >> testid;
        cin.ignore();
        cout << "Please enter patient name: ";
        getline(cin, patientname);
        cout << "Please enter test name: ";
        getline(cin, testname);
        cout << "Please enter test date: ";
        getline(cin, testdate);

        fout << testid << "," << patientname << "," << testname << "," 
             << testdate << ",pending" << endl;
    }

    fout.close();
    cout << "Lab test records added successfully!\n";
}

void viewLabTest() {
    ifstream fin("labreport.csv");
    string line;
    cout << "\n--- Lab Test Records ---\n";
    while(getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
}

void editLabTest() {
    ifstream file("labreport.csv");
    ofstream temp("temp.csv");
    string searchtestid;
    cout << "Please enter test ID to edit: ";
    cin >> searchtestid;
    cin.ignore();
    string testid, patientname, testname, testdate, status;
    bool exist = false;

    while(getline(file, testid, ',') &&
          getline(file, patientname, ',') &&
          getline(file, testname, ',') &&
          getline(file, testdate, ',') &&
          getline(file, status)) 
    {
        if(testid == searchtestid) {
            exist = true;
            cout << "Enter new test name: ";
            string newtestname;
            getline(cin, newtestname);
            testname = newtestname;
        }
        temp << testid << "," << patientname << "," << testname << ","
             << testdate << "," << status << endl;
    }

    file.close();
    temp.close();
    remove("labreport.csv");
    rename("temp.csv", "labreport.csv");

    if(exist)
        cout << "Lab test edited successfully.\n";
    else
        cout << "Test ID not found.\n";
}

void updateLabTest() {
    ifstream file("labreport.csv");
    ofstream temp("temp.csv");
    string searchtestid;
    cout << "Please enter test ID to update: ";
    cin >> searchtestid;
    cin.ignore();
    string testid, patientname, testname, testdate, status;
    bool exist = false;

    while(getline(file, testid, ',') &&
          getline(file, patientname, ',') &&
          getline(file, testname, ',') &&
          getline(file, testdate, ',') &&
          getline(file, status)) 
    {
        if(testid == searchtestid) {
            exist = true;
            status = "completed";
        }
        temp << testid << "," << patientname << "," << testname << ","
             << testdate << "," << status << endl;
    }

    file.close();
    temp.close();
    remove("labreport.csv");
    rename("temp.csv", "labreport.csv");

    if(exist)
        cout << "Lab test status updated.\n";
    else
        cout << "Test ID not found.\n";
}

void deleteLabTest() {
    ifstream file("labreport.csv");
    ofstream temp("temp.csv");
    string searchtestid;
    cout << "Enter test ID to delete: ";
    cin >> searchtestid;
    cin.ignore();
    string testid, patientname, testname, testdate, status;
    bool exist = false;

    while(getline(file, testid, ',') &&
          getline(file, patientname, ',') &&
          getline(file, testname, ',') &&
          getline(file, testdate, ',') &&
          getline(file, status)) 
    {
        if(testid == searchtestid) {
            exist = true;
            continue; // skip writing this record
        }
        temp << testid << "," << patientname << "," << testname << ","
             << testdate << "," << status << endl;
    }

    file.close();
    temp.close();
    remove("labreport.csv");
    rename("temp.csv", "labreport.csv");

    if(exist)
        cout << "Lab test deleted successfully.\n";
    else
        cout << "Test ID not found.\n";
}

void clearLabRecords() {
    ofstream fout("labreport.csv");
    fout.close();
    cout << "All lab test records cleared.\n";
}

void labTestMenu() {
    int choice;
    do {
        cout << "\n===== Lab Test Menu =====\n";
        cout << "1. Add Lab Test\n2. View Lab Tests\n3. Edit Lab Test\n"
             << "4. Update Lab Test\n5. Delete Lab Test\n6. Clear Records\n0. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        switch(choice) {
            case 1: addLabTest(); break;
            case 2: viewLabTest(); break;
            case 3: editLabTest(); break;
            case 4: updateLabTest(); break;
            case 5: deleteLabTest(); break;
            case 6: clearLabRecords(); break;
            case 0: break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 0);
}