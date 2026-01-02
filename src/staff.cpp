#include<iostream>
#include<fstream>
#include<string>
#include "staff.h"
using namespace std;

void addStaff()
{
    ofstream file("staffs.csv", ios::app);
    int staff_id;
    string name, gender, department, profession, available, shift;
    cout << "ENTER THE STAFF ID: ";
    cin >> staff_id;
    cin.ignore();
    cout << "Enter the name: ";
    getline(cin, name);
    cout << "Enter the gender: ";
    getline(cin, gender);
    cout << "ENTER THE DEPARTMENT: ";
    getline(cin, department);
    cout << "ENTER THE STAFF PROFESSION: ";
    getline(cin, profession);
    cout << "IS STAFF AVAILABLE: ";
    getline(cin, available);
    cout << "ENTER THE STAFF SHIFT: ";
    getline(cin, shift);

    file << staff_id << ",";
    file << name << ",";
    file << gender << ",";
    file << department << ",";
    file << profession << ",";
    file << available << ",";
    file << shift << "\n";
    file.close();
    cout << "Data is added successfully!\n";
}

void viewStaff()
{
    ifstream file("staffs.csv");
    string line;
    while(getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
}

void updateStaff()
{
    ifstream file("staffs.csv");
    ofstream temp("temp.csv");
    int staff_id, searchid;
    string name, gender, department, profession, available, shift;
    bool found = false;

    cout << "ENTER THE SEARCH ID: ";
    cin >> searchid;
    cin.ignore();

    temp << "staff_id,name,gender,department,profession,available,shift\n";
    file.ignore(1000, '\n'); // skip header

    while(file >> staff_id)
    {
        file.ignore();
        getline(file, name, ',');
        getline(file, gender, ',');
        getline(file, department, ',');
        getline(file, profession, ',');
        getline(file, available, ',');
        getline(file, shift, ',');

        if(staff_id == searchid)
        {
            found = true;
            cout << "Enter the name: ";
            getline(cin, name);
            cout << "Enter the gender: ";
            getline(cin, gender);
            cout << "ENTER THE DEPARTMENT: ";
            getline(cin, department);
            cout << "ENTER THE STAFF PROFESSION: ";
            getline(cin, profession);
            cout << "IS STAFF AVAILABLE: ";
            getline(cin, available);
            cout << "ENTER THE STAFF SHIFT: ";
            getline(cin, shift);
        }

        temp << staff_id << ",";
        temp << name << ",";
        temp << gender << ",";
        temp << department << ",";
        temp << profession << ",";
        temp << available << ",";
        temp << shift << "\n";
    }

    file.close();
    temp.close();
    remove("staffs.csv");
    rename("temp.csv", "staffs.csv");

    if(found)
        cout << "Successfully updated!\n";
    else
        cout << "Not updated successfully!\n";
}

void deleteStaff()
{
    ifstream file("staffs.csv");
    ofstream temp("temp.csv");
    int staff_id, searchid;
    string name, gender, department, profession, available, shift;

    cout << "ENTER THE SEARCH ID: ";
    cin >> searchid;
    cin.ignore();

    temp << "staff_id,name,gender,department,profession,available,shift\n";
    file.ignore(1000, '\n'); // skip header

    while(file >> staff_id)
    {
        file.ignore();
        getline(file, name, ',');
        getline(file, gender, ',');
        getline(file, department, ',');
        getline(file, profession, ',');
        getline(file, available, ',');
        getline(file, shift, ',');

        if(staff_id != searchid)
        {
            temp << staff_id << ",";
            temp << name << ",";
            temp << gender << ",";
            temp << department << ",";
            temp << profession << ",";
            temp << available << ",";
            temp << shift << "\n";
        }
    }

    file.close();
    temp.close();
    remove("staffs.csv");
    rename("temp.csv", "staffs.csv");

    cout << "Data deleted successfully!\n";
}

void staffMenu()
{
    int choice;
    do
    {
        cout << "\nStaff Management System\n";
        cout << "1 - Add Staff\n";
        cout << "2 - View Staff\n";
        cout << "3 - Update Staff\n";
        cout << "4 - Delete Staff\n";
        cout << "5 - Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice)
        {
            case 1: addStaff(); break;
            case 2: viewStaff(); break;
            case 3: updateStaff(); break;
            case 4: deleteStaff(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 5);
}