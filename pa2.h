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

	//add a program to list
	void addProgram(string programName);
	//return length of linked list
	int listLength();
	void insertBest(string programName);
};

//Functions explained in pa2.cpp
void displayMenu();
void bestFit();
void worstFit();
int kbToPages(int programSize);

#endif
