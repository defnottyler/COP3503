#ifndef pa2_h
#define pa2_h

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Each node is a page that has a name
struct page {
	string programName;
	page *nextPage;
};

//Linked List class
class LinkedList {
private:
	page *head;
public:
	//default linked list constructor
	LinkedList() {
		head = NULL;
	}
	void addFree(string programName);									//fills list with 32 Free pages
	int listLength();													//returns length of LinkedList
	void insertBest(string programName, int numPages);					//adds a program to LinkedList using best fit algorithm
	void insertWorst(string programName, int numPages);					//adds a program to LinkedList using worst fit algorithm
	bool isUsed(string programName);									//returns true if the program is in use
	void killProgram(string programName);								//removes a program from LinkedList
	int numFragments();													//returns total number of used memory fragments
	void displayMemory();												//displays memory chart
};

void bestFit();										//if user opts to use best fit algorithm
void worstFit();									//if user opts to use worst fit algorithm
int kbToPages(int programSize);						//takes program size in KBs and returns program size in pages
void displayMenu();									//displays options menu

#endif
