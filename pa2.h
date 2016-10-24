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
	LinkedList();

	//add a program to list
	void addProgram(string programName);
	//return length of linked list
	int listLength();
	void insertBest();

};

//Functions explained in pa2.cpp
void bestFit();
void worstFit();
void displayMenu();
int kbToPages(int programSize);

#endif
