#include <iostream>
#include <fstream>
#include <sstream>
#include "pharmacy.h"
using namespace std;

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
        cout <<
