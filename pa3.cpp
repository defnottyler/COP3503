#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <deque>
#include <string>
#include <stdlib.h>

using namespace std;

string getFileName();
deque<string> getLines(string fileName);
vector<string> getKeywords(string lines);
vector<string> getIdentifiers(string lines);
vector<string> getConstants(string lines);
vector<string> getOperators(string lines);
vector<string> getDelimiters(string lines);


int main() {

	string fileName = getFileName();

	deque<string> linesInFile = getLines(fileName);

	vector<vector<string>> keywordsInFile;
	vector<vector<string>> identifiersInFile;
	vector<vector<string>> constantsInFile;
	vector<vector<string>> operatorsInFile;
	vector<vector<string>> delimitersInFile;
	vector<string> simpleLines;

	int i = 0;
	while (!linesInFile.empty()) {
			keywordsInFile.at(i) = getKeywords(linesInFile.at(0));
			operatorsInFile.at(i) = getOperators(linesInFile.at(0));
			delimitersInFile.at(i) = getDelimiters(linesInFile.at(0));
			identifiersInFile.at(i) = getIdentifiers(linesInFile.at(0));
			constantsInFile.at(i) = getConstants(linesInFile.at(0));


			linesInFile.pop_front();
			i++;
	}


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

	ifstream textFile(fileName);

	while (getline(textFile, line)) {
		allLinesInText.push_back(line);
	}

	textFile.close();

	return allLinesInText;
}

vector<string> getKeywords(string lines) {
	vector<string> keywords;

	vector<string> keyTokens;
	keyTokens.push_back("BEGIN");
	keyTokens.push_back("END");
	keyTokens.push_back("FOR");

	for (int j = 0; j < 3; j++) {
		//check each string in the deque for each of the keyword tokens
		//erase the individual occurence in the string as we count them to prevent recounts
		//and simplify the string as we go
		string keyword = keyTokens.at(j);
		while (lines.find(keyword) != string::npos) {
			keywords.push_back(keyword);
			//erase keyword at index j of keytokens vector from the temporary string
			lines.replace(lines.find(keyword), keyword.length(), "");
		}
	}

	return keywords;
}

vector<string> getIdentifiers(string lines) {
	vector<string> identifiers;

	int j;
	for (int i = 0; i < lines.size(); i++) {
		j = i;
		if (islower(lines.at(i))) {

		}
	}
		 
	return identifiers;
}

vector<string> getConstants(string lines) {
	vector<string> constants;


	return constants;
}

vector<string> getOperators(string lines) {
	vector<string> operators;

	vector<string> opTokens;
	opTokens.push_back("*");
	opTokens.push_back("/");
	opTokens.push_back("++");
	opTokens.push_back("--");
	opTokens.push_back("==");
	opTokens.push_back("+");
	opTokens.push_back("-");
	opTokens.push_back("=");
	opTokens.push_back("<");
	opTokens.push_back(">");
	opTokens.push_back("&&");
	opTokens.push_back("||");
	opTokens.push_back("!");


	for (int j = 0; j < 13; j++) {
		//check each string in the deque for each of the keyword tokens
		//erase the individual occurence in the string as we count them to prevent recounts
		//and simplify the string as we go
		string op = opTokens.at(j);
		while (lines.find(op) != string::npos) {
			operators.push_back(op);
			//erase keyword at index j of keytokens vector from the temporary string
			lines.replace(lines.find(op), op.length(), "");
		}
	}

	return operators;
}

vector<string> getDelimiters(string lines) {
	vector<string> delimiters;

	vector<string> delTokens;
	delTokens.push_back(";");
	delTokens.push_back(",");

	for (int j = 0; j < 2; j++) {
		//check each string in the deque for each of the keyword tokens
		//erase the individual occurence in the string as we count them to prevent recounts
		//and simplify the string as we go
		string del = delTokens.at(j);
		while (lines.find(del) != string::npos) {
			delimiters.push_back(del);
			//erase keyword at index j of keytokens vector from the temporary string
			lines.replace(lines.find(del), del.length(), "");
		}
	}

	return delimiters;
}



/*
string simplifyLines(string lines) {
	string simpleLines = lines;

	for (int i = 0; i < lines.size(); i++) {

		if (isupper(lines.at(i))) {
			simpleLines.replace(simpleLines.at(i), 1, "");
		}
		else if (simpleLines.at(i) == ' ') {
			simpleLines.replace(simpleLines.at(i), 1, "");
		}
		else if (simpleLines.at(i) == '\t') {
			simpleLines.replace(simpleLines.at(i), 1, "");
		}
		else if (simpleLines.at(i) == '\n') {
			simpleLines.replace(simpleLines.at(i), 1, "");
		}
		else if (simpleLines.at(i) == '\v') {
			simpleLines.replace(simpleLines.at(i), 1, "");
		}
		else if (simpleLines.at(i) == '\f') {
			simpleLines.replace(simpleLines.at(i), 1, "");
		}
		else if (simpleLines.at(i) == '\r') {
			simpleLines.replace(simpleLines.at(i), 1, "");
		}
		else if (simpleLines.at(i) == ('*' || '/' || '++' || '--' || '==' || '+' || '-' || '=' || '<>' || '&&' || '||' || '!')) {
			simpleLines.replace(simpleLines.at(i), 1, "");
		}

	}

	return simpleLines;
}
*/
