#include "pa3.h"

int main() {

	string fileName = getFileName();

	stack<string> lines = readLines(fileName);

	return 0;
}

string getFileName() {
	string fileName;

	cout << "Enter name of file: ";
	cin >> fileName;
	cout << endl;

	return fileName;
}

stack<string> readLines(string fileName) {
	
	ifstream textFile;
	string textLine;
	stack<string> fileLines;

	textFile.open(fileName);

	if (!textFile.is_open()) {
		cout << "No text file found!" << endl;
		exit(1);
	}

	while (getline(textFile, textLine)) {

		fileLines.push(textLine);

	}

	textFile.close();

	return fileLines;
}

vector<vector<string>> lineTokens(stack<string> fileLines) {

	vector<string> keywords;
	keywords.push_back("BEGIN");
	keywords.push_back("END");
	keywords.push_back("FOR");
	keywords.push_back("WHILE");
	keywords.push_back("IF");
	keywords.push_back("ELSE");
	keywords.push_back("ELSEIF");
	

	vector<string> delimiters;
	delimiters.push_back(";");
	delimiters.push_back(",");

	vector<string> operators;
	operators.push_back("*");
	operators.push_back("/");
	operators.push_back("++");
	operators.push_back("--");
	operators.push_back("==");
	operators.push_back("+");
	operators.push_back("-");
	operators.push_back("=");
	operators.push_back("<");
	operators.push_back(">");
	operators.push_back("&&");
	operators.push_back("||");
	operators.push_back("!");

	vector<string> keywordsInFile;
	vector<string> delimitersInFile;
	vector<string> operatorsInFile;
	vector<string> identifiersInFile;
	vector<string> constantsInFile;
	vector<string> errorsInFile;

	for (int i = 0; i < fileLines.size(); i++) {

		string currentLine = fileLines.top();

		fileLines.
	}
}
