#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <deque>

using namespace std;

string getFileName();
deque<string> getLines(string fileName);
void printLines(deque<string> lines);

int main() {
    
    string fileName = getFileName();
    deque<string> lines = getLines(fileName);
    printLines(lines);
    
    return 0;
}

string getFileName() {
    
    string fileName;
    
    cout << "Enter text file name: ";
    cin >> fileName;
    cout << endl;
    
    return fileName;
}

deque<string> getLines(string fileName) {
    
    deque<string> allLinesInText;
    string line;
    
    ifstream infile(fileName);
    
    while (getline(infile, line)) {
        allLinesInText.push_back(line);
    }
    
    infile.close();
    
    return allLinesInText;
}


