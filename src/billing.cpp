#include<iostream>
#include<fstream>
#include<string>
#include "billing.h"

using namespace std;

void addBill()
{
    ofstream file("billing.csv", ios::app);

    int bill_id;
    string patient_name;
    float service, doctor, pharmacy, lab, room, total;

    cout << "ENTER BILL ID: ";
    cin >> bill_id;
    cin.ignore();

    cout << "ENTER PATIENT NAME: ";
    getline(cin, patient_name);

    cout << "SERVICE CHARGES: ";
    cin >> service;
    cout << "DOCTOR FEE: ";
    cin >> doctor;
    cout << "PHARMACY CHARGES: ";
    cin >> pharmacy;
    cout << "LAB CHARGES: ";
    cin >> lab;
    cout << "ROOM CHARGES: ";
    cin >> room;

    total = service + doctor + pharmacy + lab + room;

    file << bill_id << ","
         << patient_name << ","
         << service << ","
         << doctor << ","
         << pharmacy << ","
         << lab << ","
         << room << ","
         << total << "\n";

    file.close();
    cout << "Bill added successfully!\n";
}

void viewBill()
{
    ifstream file("billing.csv");
    string line;

    cout << "\nBillID,Name,Service,Doctor,Pharmacy,Lab,Room,Total\n";
    while(getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
}

void updateBill()
{
    ifstream file("billing.csv");
    ofstream temp("temp.csv");

    int bill_id, searchid;
    string patient_name;
    float service, doctor, pharmacy, lab, room, total;
    bool found = false;

    cout << "ENTER BILL ID TO UPDATE: ";
    cin >> searchid;
    cin.ignore();

    while(file >> bill_id)
    {
        file.ignore();
        getline(file, patient_name, ',');
        file >> service; file.ignore();
        file >> doctor; file.ignore();
        file >> pharmacy; file.ignore();
        file >> lab; file.ignore();
        file >> room; file.ignore();
        file >> total;
        file.ignore(1000, '\n');

        if(bill_id == searchid)
        {
            found = true;

            cout << "ENTER NEW PATIENT NAME: ";
            getline(cin, patient_name);

            cout << "SERVICE CHARGES: ";
            cin >> service;
            cout << "DOCTOR FEE: ";
            cin >> doctor;
            cout << "PHARMACY CHARGES: ";
            cin >> pharmacy;
            cout << "LAB CHARGES: ";
            cin >> lab;
            cout << "ROOM CHARGES: ";
            cin >> room;
            cin.ignore();

            total = service + doctor + pharmacy + lab + room;
        }

        temp << bill_id << ","
             << patient_name << ","
             << service << ","
             << doctor << ","
             << pharmacy << ","
             << lab << ","
             << room << ","
             << total << "\n";
    }

    file.close();
    temp.close();
    remove("billing.csv");
    rename("temp.csv", "billing.csv");

    if(found)
        cout << "Bill updated successfully!\n";
    else
        cout << "Bill ID not found!\n";
}

void deleteBill()
{
    ifstream file("billing.csv");
    ofstream temp("temp.csv");

    int bill_id, searchid;
    string patient_name;
    float service, doctor, pharmacy, lab, room, total;

    cout << "ENTER BILL ID TO DELETE: ";
    cin >> searchid;

    while(file >> bill_id)
    {
        file.ignore();
        getline(file, patient_name, ',');
        file >> service; file.ignore();
        file >> doctor; file.ignore();
        file >> pharmacy; file.ignore();
        file >> lab; file.ignore();
        file >> room; file.ignore();
        file >> total;
        file.ignore(1000, '\n');

        if(bill_id != searchid)
        {
            temp << bill_id << ","
                 << patient_name << ","
                 << service << ","
                 << doctor << ","
                 << pharmacy << ","
                 << lab << ","
                 << room << ","
                 << total << "\n";
        }
    }

    file.close();
    temp.close();
    remove("billing.csv");
    rename("temp.csv", "billing.csv");

    cout << "Bill deleted successfully!\n";
}

void billingMenu()
{
    int choice;
    do
    {
        cout << "\n===== Hospital Billing System =====\n";
        cout << "1 - Add Bill\n";
        cout << "2 - View Bills\n";
        cout << "3 - Update Bill\n";
        cout << "4 - Delete Bill\n";
        cout << "5 - Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice)
        {
            case 1: addBill(); break;
            case 2: viewBill(); break;
            case 3: updateBill(); break;
            case 4: deleteBill(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 5);
}
