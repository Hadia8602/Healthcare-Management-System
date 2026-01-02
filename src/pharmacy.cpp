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


