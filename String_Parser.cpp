#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 
using namespace std;

string getValue(string pair) {
    size_t colonPos = pair.find(':');
    if (colonPos != string::npos) {
        return pair.substr(colonPos + 1);
    }
    return "";
}

void parseCSV(const string& filename) {
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string namePair, agePair, initialPair, isStudentPair, gradePair;

        if (ss >> namePair >> agePair >> initialPair >> isStudentPair >> gradePair) {
            cout << "Name: " << getValue(namePair) << endl;
            cout << "Age: " << getValue(agePair) << endl;
            cout << "Initial: " << getValue(initialPair) << endl;
            cout << "IsStudent: " << getValue(isStudentPair) << endl;
            cout << "Grade: " << getValue(gradePair) << " ." << endl;
            cout << "-----------------" << endl;
        }
    }

    file.close();
}

int main() {
    parseCSV("students.csv");
    return 0;
}
