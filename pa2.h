#ifndef pa2_h
#define pa2_h
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct page {
	string programName;
	page *nextPage;
};

class LinkedList {
private:
	page *head;
public:
	LinkedList() {
		head = NULL;
	}

	void addProgram(string programName, int numPages);
	void displayList();
};

void bestFit();
void worstFit();
void displayMenu();
int kbToPages(int programSize);

#endif /* pa2_h */
