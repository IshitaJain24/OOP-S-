#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("logfile.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening logfile.txt" << endl;
        return 1;
    }

    ofstream outputFile("error.txt");

    if (!outputFile.is_open()) {
        cerr << "Error opening error.txt" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        if (line.find("error") != string::npos) {
            outputFile << line << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    cout << "Log entries containing 'error' have been written to error.txt" << endl;

    return 0;
}
