#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

string getFileName();
vector<string> getLines(string fileName);

int main() {

	string fileName = getFileName();
	vector<string> lines = getLines(fileName);

	return 0;
}

string getFileName() {

	string fileName;

	cout << "Enter text file name: ";
	cin >> fileName;
	cout << endl;

	return fileName;
}

vector<string> getLines(string fileName) {
	vector<string> allLinesInText;
	string line;
	ifstream infile(fileName);
	
	while (getline(infile, line)) {
		allLinesInText.push_back(line);
	}

	return allLinesInText;
}
