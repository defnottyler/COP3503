#include "pa2.h"

//Default linked list constructor


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

//if user opts for best fit algorithm
void bestFit() {
	// create 2 linked lists to represent the memory that is used and free
	LinkedList usedMemory;
	LinkedList freeMemory;
	// Add 32 pages of Free Memory
	for (int i = 0; i < 32; i++)
		freeMemory.addProgram("Free");
	cout << "Using best fit algorithm" << endl;
	// display input options
	displayMenu();

	int choice;
	// let user pick from displayed menu until they select 5 as their choice
	while (choice != 5) {
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
			if (usedMemory.listLength == 0) {
				// add program to used memory
				for (int i = 0; i < numPages; i++) {
					usedMemory.addProgram(programName);
					usedCount++;
					freeCount--;
				}
			}
			//if there is used memory
			else {
				usedMemory.insertBest(programName);
			}//end else
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

				for (int i = 0; i < numPages; i++)
					usedMemory.addProgram(programName);
				//usedMemory.displayList();
			}
			}
		}



	}

	int LinkedList::kbToPages(int programSize) {
		//4 kb's per page
		int pages = programSize / 4;

		//If program size isn't divisible by 4, must add extra page
		if ((programSize % 4) > 0)
			pages = pages + 1;

		return pages;
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

	}

	int LinkedList::listLength() {
		int count = 0;
		page *current = head;
		//while the page is initialized, increment the count variable
		while (current != NULL) {
			count++;
			current = current->nextPage;
		}
		return count;
	}

	void LinkedList::insertBest(string programName) {
		page *current = head;
		int countUsed = 0;
		int countFree = 0;
		int freeAtEnd = 0;
		int smallestFreeFrag = 40;

		for (int i = 0; i < 32; i++) {
			//if current page isn't NULL
			if (current != NULL) {
				countUsed++;
				current = current->nextPage;
			}
			//if current page is NULL
			else if (current == NULL) {
				countFree++;
				//if next page is NULL and free memory counter is smaller than the smallest fragment of free memory
				//store that fragment as the smallest free fragment and mark the location using page *temp
				if (current->nextPage != NULL) {
					if (countFree < smallestFreeFrag) {
						smallestFreeFrag = countFree;
						countFree = 0;
					}
				}
				current = current->nextPage;
			}
			//if page doesn't exist
			else {
				freeAtEnd++;
			}
		}
		//if free memory at end
		if (freeAtEnd < smallestFreeFrag) {
			smallestFreeFrag = freeAtEnd;
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

