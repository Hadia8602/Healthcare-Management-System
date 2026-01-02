#include <iostream>
#include <fstream>
#include <sstream>
#include "pharmacy.h"
using namespace std;

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
