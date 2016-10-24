#include "pa2.h"

int main(int argc, char *argv[]) {

	// if user opts for best fit
	if (string(argv[1]) == "best") {
		bestFit();
	}
	//if user opts for worst fit
	else if (string(argv[1]) == "worst") {
		worstFit();
	}
	//if bad input is given, print error message and return -1
	else {
		cout << "Bad input" << endl;
		return -1;
	}

	return 0;
}

void bestFit() {
	// create 2 linked lists to represent the memory that is used and free
	LinkedList memory;
	// Add 32 pages of Free Memory
	for (int i = 0; i < 32; i++)
		memory.addFree("Free");
	cout << "Using best fit algorithm\n" << endl;
	// display input options
	displayMenu();

	int choice;
	// let user pick from displayed menu until they select 5 as their choice
	do {
		cout << "choice - ";
		cin >> choice;
		switch (choice) {
			// Case 1 adds a program to used memory
		case 1:
		{
			string programName;
			cout << "Program name - ";
			cin >> programName;
			int programSize;
			cout << "Program size - ";
			cin >> programSize;
			cout << endl;
			// numPages will be the number of pages the program will occupy
			int numPages;
			numPages = kbToPages(programSize);
			
			//if there is used memory
			if (!memory.isUsed(programName)) {
				memory.insertBest(programName, numPages);
				break;
			}
			else
				cout << "Error, Program " << programName << " is already running." << endl;
			break;
		}//end case1
			//Case 2 kills a program
		case 2:
		{
			string programName;
			cout << "Program name - ";
			cin >> programName;
			// if program is in used memory, kill it
			if (memory.isUsed(programName)) {
				memory.killProgram(programName);
				break;
			}
			// if not, display error message
			else
				cout << "Error, no program called " << programName << " is running" << endl;
			break;
		}//ends case2
			//Case 3 displays number of fragments of used memory
		case 3:
		{
			cout << "There are " << memory.numFragments() << " fragment(s)" << endl;
			break;
		}//ends case3
			//Case 4 displays the memory in 4 lines
		case 4:
		{
			memory.displayMemory();
			break;
		}//ends case4
		case 5:
			break;
		default:
		{
			cout << "choice - " << choice << endl;
			break;
		}//ends default case

		}//ends switch
	} while (choice != 5);
}//end bestFit()

void worstFit() {// create 2 linked lists to represent the memory that is used and free
	LinkedList memory;
	// Add 32 pages of Free Memory
	for (int i = 0; i < 32; i++)
		memory.addFree("Free");
	cout << "Using worst fit algorithm\n" << endl;
	// display input options
	displayMenu();

	int choice;
	// let user pick from displayed menu until they select 5 as their choice
	do {
		cout << "choice - ";
		cin >> choice;
		switch (choice) {
			// Case 1 adds a program to used memory
		case 1:
		{
			string programName;
			cout << "Program name - ";
			cin >> programName;
			int programSize;
			cout << "Program size - ";
			cin >> programSize;
			cout << endl;
			// numPages will be the number of pages the program will occupy
			int numPages;
			numPages = kbToPages(programSize);

			//if there is used memory
			if (!memory.isUsed(programName)) {
				memory.insertWorst(programName, numPages);
				break;
			}
			else
				cout << "Error, Program " << programName << " is already running." << endl;
			break;
		}//end case1
		 //Case 2 kills a program
		case 2:
		{
			string programName;
			cout << "Program name - ";
			cin >> programName;
			// if program is in used memory, kill it
			if (memory.isUsed(programName)) {
				memory.killProgram(programName);
				break;
			}
			// if not, display error message
			else
				cout << "Error, no program called " << programName << " is running" << endl;
			break;
		}//ends case2
		 //Case 3 displays number of fragments of used memory
		case 3:
		{
			cout << "There are " << memory.numFragments() << " fragment(s)" << endl;
			break;
		}//ends case3
		 //Case 4 displays the memory in 4 lines
		case 4:
		{
			memory.displayMemory();
			break;
		}//ends case4
		case 5:
			break;
		default:
		{
			cout << "choice - " << choice << endl;
			break;
		}//ends default case

		}//ends switch
	} while (choice != 5);
}//end worstFit()

int kbToPages(int programSize) {
	//4 kb's per page
	int pages = programSize / 4;

	//If program size isn't divisible by 4, must add extra page
	if ((programSize % 4) > 0)
		pages = pages + 1;

	return pages;
}

void displayMenu() {
	cout << "\n";
	cout << "1. Add Program" << endl;
	cout << "2. Kill Program" << endl;
	cout << "3. Fragmentation" << endl;
	cout << "4. Print memory" << endl;
	cout << "5. Exit" << endl;
	cout << "\n";
}

void LinkedList::addFree(string programName) {
	head = new page;
	page *current = head;
	for (int i = 0; i < 32; i++) {
		current->programName = programName;
		current->nextPage = new page;
		current = current->nextPage;
	}
	current->nextPage = NULL;
	current = NULL;
}

int LinkedList::listLength() {
	int count = 0;
	page *current = head;
	//while the page is initialized, increment the count variable
	while (current ->programName != "Free") {
		count++;
		current = current->nextPage;
	}
	current = NULL;
	return count;
}

void LinkedList::insertBest(string programName, int numPages) {
	page *current = head;
	int freeCount = 0;
	//count number of pages of free memory
	for (int i = 0; i < 32; i++) {
		if (current->programName == "Free")
			freeCount++;
		current = current->nextPage;
	}
	current = head;
	// if all memory is free
	if (freeCount == 32 && freeCount > numPages) {
		for (int i = 0; i < numPages; i++) {
			current->programName = programName;
			current = current->nextPage;
		}
		cout << "Program " << programName << " added successfully, " << numPages << " page(s) used." << endl;
		current = NULL;
		return;
	}



	

	current = NULL;
}

void LinkedList::insertWorst(string programName, int numPages) {

}

bool LinkedList::isUsed(string programName) {
	page *current = head;

	for (int i = 0; i < 32; i++) {
		if (current->programName == programName)
			return true;
		current = current->nextPage;
	}
	current = NULL;
	return false;
}

void LinkedList::killProgram(string programName) {
	page *current = head;
	int killingSpree = 0;

	for (int i = 0; i < 32; i++) {
		if (current->programName == programName) {
			killingSpree++;
			current = current->nextPage;
		}
		else
			current = current->nextPage;
	}
	cout << "Program " << programName << " successfully killed, " << killingSpree << " page(s) reclaimed." << endl;
	current = NULL;
}

int LinkedList::numFragments() {
	page *current = head;
	int numFrags = 0;

	if (current ->programName != "Free") {
		numFrags++;
		current = current->nextPage;
	}
	int i = 1;
	while(i<32) {
		while (current ->programName != "Free") {
			current = current->nextPage;
			i++;
		}
		while (current ->programName == "Free") {
			current = current->nextPage;
			i++;
		}
		if (i != 31) {
			numFrags++;
		}
	}
	current = NULL;
	return numFrags;
}

void LinkedList::displayMemory() {
	page *current = head;
	
	for (int i = 0; i < 32; i++) {
		cout << current->programName;
		cout << "\t";
		current = current->nextPage;
	
		if ((i + 1) % 8 == 0)
			cout << endl;
	}
	current = NULL;
}
