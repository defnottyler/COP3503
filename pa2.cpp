#include "pa2.h"

LinkedList::LinkedList() {
	head->nextPage = NULL;
}

int main(int argc, char *argv[]) {

	if (string(argv[1]) == "best") {
		bestFit();
	}
	else if (string(argv[1]) == "worst") {
		worstFit();
	}
	else {
		cout << "Bad input" << endl;
		return -1;
	}

	return 0;
}

void bestFit() {
	LinkedList usedMemory;
	LinkedList freeMemory;
	cout << "Using best fit algorithm" << endl;
	displayMenu();

	int choice;
	cout << "choice - ";
	cin >> choice;

	while (choice != 5) {
		switch (choice) {
			// Add Program
		case 1:
		{
			string programName;
			cout << "Program name - ";
			cin >> programName;

			int programSize;
			cout << "Program size - ";
			cin >> programSize;

			int numPages;
			numPages = kbToPages(programSize);

			usedMemory.addProgram(programName, numPages);
			usedMemory.displayList();
		}
		}
	}



}

void worstFit() {
	LinkedList usedMemory;
	LinkedList freeMemory;
	cout << "Using worst fit algorithm" << endl;
	displayMenu();

	int choice;
	cout << "choice - ";
	cin >> choice;

	while (choice != 5) {
		switch (choice) {
			// Add Program
		case 1:
		{
			string programName;
			cout << "Program name - ";
			cin >> programName;

			int programSize;
			cout << "Program size - ";
			cin >> programSize;

			int numPages;
			numPages = kbToPages(programSize);

			for(int i=0; i<programSize; i++)
			usedMemory.addProgram(programName, numPages);
			usedMemory.displayList();
		}
		}
	}



}

int kbToPages(int programSize) {
	//4 kb's per page
	int pages = programSize / 4;

	//If program size isn't divisible by 4, must add extra page
	if ((programSize % 4) > 0)
		pages = pages + 1;

	return pages;
}

void LinkedList::addProgram(string programName, int numPages) {

	//Check if head is null
	//if it is, create new node object

	if (head == NULL) {
		page *newPage = new page;
		newPage->programName = programName;
		newPage->nextPage = NULL;
		return;
	}

		page *current = head;
		
		page *newPage = new page;
		newPage->programName = programName;
		newPage->nextPage = NULL;

		while (current->nextPage != NULL) {
			current = current->nextPage;
		}
		current->nextPage = newPage;
	
}


void LinkedList::displayList() {

	page *current = head;
	while (current != NULL) {
		cout << "1" << endl;
	}
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

