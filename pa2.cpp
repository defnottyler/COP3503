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
	LinkedList usedMemory;
	LinkedList freeMemory;
	// Add 32 pages of Free Memory
	for (int i = 0; i < 32; i++)
		freeMemory.addProgram("Free");
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
			// numPages will be the number of pages the program will occupy
			int numPages;
			numPages = kbToPages(programSize);
			// int variables to keep track of overall amount of used/free memory
			int usedCount = 0;
			int freeCount = 32;

			//if there is no used memory
			if (usedMemory.listLength() == 0) {
				// add program to used memory
				for (int i = 0; i < numPages; i++) {
					usedMemory.addProgram(programName);
					usedCount++;
					freeCount--;
				}//ends for loop
				break;
			}
			//if there is used memory
			else {
				usedMemory.insertBest(programName);
				break;
			}
		}//end case1
			//Case 2 kills a program
		case 2:
		{
			cout << "choice - " << choice << endl;
			string programName;
			cout << "Program name - ";
			cin >> programName;
			// if program is in used memory, kill it
			if (usedMemory.isUsed(programName))
				usedMemory.killProgram(programName);
			// if not, display error message
			else
				cout << "Error, no program called " << programName << " is running" << endl;
			break;
		}//ends case2
			//Case 3 displays number of fragments of used memory
		case 3:
		{
			cout << "choice - " << choice << endl;
			cout << "There are " << usedMemory.numFragments() << " fragment(s)" << endl;
		}//ends case3
			//Case 4 displays the memory in 4 lines
		case 4:
		{
			cout << "choice - " << choice << endl;
			usedMemory.displayMemory();
			break;
		}//ends case4
		default:
		{
			cout << "choice - " << choice << endl;
			break;
		}//ends default case

		}//ends switch
	} while (choice != 5);
}//end bestFit()

void worstFit() {
	// create 2 linked lists to represent the memory that is used and free
	LinkedList usedMemory;
	LinkedList freeMemory;
	// Add 32 pages of Free Memory
	for (int i = 0; i < 32; i++)
		freeMemory.addProgram("Free");
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
			cout << "choice - " << choice << endl;
			string programName;
			cout << "Program name - ";
			cin >> programName;
			int programSize;
			cout << "Program size - ";
			cin >> programSize;
			// numPages will be the number of pages the program will occupy
			int numPages;
			numPages = kbToPages(programSize);
			// int variables to keep track of overall amount of used/free memory
			int usedCount = 0;
			int freeCount = 32;

			//if there is no used memory
			if (usedMemory.listLength() == 0) {
				// add program to used memory
				for (int i = 0; i < numPages; i++) {
					usedMemory.addProgram(programName);
					usedCount++;
					freeCount--;
				}//ends for loop
				break;
			}
			//if there is used memory
			else {
				usedMemory.insertWorst(programName);
				break;
			}
		}//end case1
		 //Case 2 kills a program
		case 2:
		{
			cout << "choice - " << choice << endl;
			string programName;
			cout << "Program name - ";
			cin >> programName;
			// if program is in used memory, kill it
			if (usedMemory.isUsed(programName))
				usedMemory.killProgram(programName);
			// if not, display error message
			else
				cout << "Error, no program called " << programName << " is running" << endl;
			break;
		}//ends case2
		 //Case 3 displays number of fragments of used memory
		case 3:
		{
			cout << "choice - " << choice << endl;
			cout << "There are " << usedMemory.numFragments() << " fragment(s)" << endl;
		}//ends case3
		 //Case 4 displays the memory in 4 lines
		case 4:
		{
			cout << "choice - " << choice << endl;
			usedMemory.displayMemory();
			break;
		}//ends case4
		//Case 5 exits the program
		case 5:
		{
			cout << "choice - " << choice << endl;
			break;
		}//ends 5
		//Default case means wrong input, try again
		default:
		{
			cout << "Wrong input! Please try again." << endl;
		}
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

void LinkedList::addProgram(string programName) {

	//Check if head is null
	//if it is, create "temporary" page
	//Assign head values through this page and return
	if (head == NULL) {
		page *temp = new page;
		temp->programName = programName;
		temp->nextPage = NULL;
		head = temp;
		return;
	}
	//Create page to traverse through list, starting at head
	page *current = head;

	//Create new page
	page *newPage = new page;
	newPage->programName = programName;
	newPage->nextPage = NULL;
	//While the page after current has a name
	//continue to traverse through list
	while (current->nextPage != NULL) {
		current = current->nextPage;
	}
	//When the page past current is uninitialized
	//Use the new page created above to initialize it
	current->nextPage = newPage;
	current = NULL;
}

int LinkedList::listLength() {
	int count = 0;
	page *current = head;
	//while the page is initialized, increment the count variable
	while (current != NULL) {
		count++;
		current = current->nextPage;
	}
	current = NULL;
	return count;
}

void LinkedList::insertBest(string programName) {
	page *current = head;
	page *temp;
	page *endCheck;
	int countUsed = 0;
	int countFree = 0;
	int freeAtEnd = 0;
	int smallestFreeFrag = 40;

	for (int i = 0; i < 32; i++) {
		//if current page isn't Free
		if (current != NULL) {
			countUsed++;
			current = current->nextPage;
		}
		//if current page is Free
		else if (current == NULL) {
			countFree++;
			//if next page is Free and free memory counter is smaller than the smallest fragment of free memory
			//store that fragment as the smallest free fragment and mark the location using page *temp
			if (current->nextPage != NULL) {
				if (countFree < smallestFreeFrag) {
					temp = current;
					smallestFreeFrag = countFree;
					countFree = 0;
				}
			}
			current = current->nextPage;
		}
		//check if rest of pages from this point are Free
		endCheck = current;
		for (int k = i; k < 32; k++) {
			freeAtEnd++;
			//set freeAtEnd equal to 0 if there is a program in used memory before the end of the list
			if (endCheck != NULL) {
				freeAtEnd = 0;
				break;
			}
		}
		//if the program ends with at least 1 page of Free memory check if that fragment is the largest free memory fragment
		//if it is, mark the location with temp
		if (freeAtEnd != 0) {
			if (freeAtEnd < smallestFreeFrag) {
				smallestFreeFrag = freeAtEnd;
				temp = current;
			}
		}
		
	}
	
}

void LinkedList::insertWorst(string programName) {

}

bool LinkedList::isUsed(string programName) {
	page *current = head;

	for (int i = 0; i < 32; i++) {
		if (current->programName == programName)
			return true;
	}
	current = NULL;
	return false;
}

int LinkedList::killProgram(string programName) {
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
	current = NULL;
	return killingSpree;
}

int LinkedList::numFragments() {
	page *current = head;
	int numFrags = 0;

	if (current != NULL) {
		numFrags++;
		current = current->nextPage;
	}
	int i = 1;
	while(i<32) {
		while (current != NULL) {
			current = current->nextPage;
			i++;
		}
		while (current == NULL) {
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
		if (i > 0)
			cout << "\t";
		if (current != NULL)
			cout << current->programName;
		else
			cout << "Free";
		if ((i + 1) % 8 == 0)
			cout << endl;
	}
	current = NULL;
}
