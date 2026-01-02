#include <iostream>
#include <fstream>
#include <sstream>
#include "pharmacy.h"
using namespace std;

void view() {
    string line;
    ifstream file("pharmacy.csv", ios::in);
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}
