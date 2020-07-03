/* 
 * File:   SelfOrderedList.h
 * Author: Anthony Natale
 *
 * Created on June 28th, 2020
 */

#ifndef SELFORDEREDLIST_H
#define	SELFORDEREDLIST_H

#include <string>
#include "llist.h"
#include "SelfOrderedListADT.h"

template <typename E> 
class SelfOrderedList: public SelfOrderedListADT<E> {

private:

	// Arrays Legend:
	// 0: Count heuristic
	// 1: Move-To-Front heuristic
	// 2: Transpose heuristic

	LList<E>* list[3];
	int compareCount[3];
	
	void reorder(int i, int accessedElementPos = 0) {
		if (i == 0) {
			list[0]->reorderCount(accessedElementPos);
		}
		else if (i == 1) {
			list[1]->moveToFront(accessedElementPos);
		}
		else if (i == 2) {
			list[2]->transpose(accessedElementPos);
		}
		return;
	}

public:

    SelfOrderedList() {
		for (int i = 0; i < 3; i++) {
			list[i] = new LList<E>();
			compareCount[i] = 0;
		}
		
	}
    ~SelfOrderedList() {

	}
    
	// This function compares "it" with the values in the list
	// and returns true if the value is found, 
	// else it returns false
	bool find(const E& it) {

		// Bool to track if search fails at any point and "it" cannot be found
		bool itIsInList = true; bool added = false;

		// Check if list is uninitialized
		//for (int i = 0; i < 3; i++) {
		//	if (list[i]->isNull()) {
		//		// Add it to each list
		//		list[i]->append(it);
		//		// And mark the lists as uninitialized before moving to the next list
		//		itIsInList = false;
		//	}
		//}
		
		// If the list was previously null, return false, we're done here
		//if (itIsInList == false) {
		//	return itIsInList;
		//}
		// Otherwise, the lists are populated and we need to search for "it"
		//else {
			// Declare an array whose variables are of type E (char or string)
			E val[3];
			for (int i = 0; i < 3; i++) {
				// Move to the front of the lists to prepare for the search
				list[i]->moveToStart();
				// fill val array with the current value of the list being searched
				val[i] = list[i]->getValue();
				// Get the position of the found item, skipping head
				int pos = 1;
				// Check temp against "it"
				while (val[i] != it) {
					// Increment compareCount and pos
					compareCount[i]++; pos++;
					// If temp isn't it, move the linked list to the next item in the list
					list[i]->next();
					// Check if we've reached the end of the list, if so, add "it" to the end of the list and return false
					// because "it" wasn't previously in the list
					if (list[i]->isTail()) {
						// Add it
						list[i]->append(it);
						added = true;
						itIsInList = false;
						break; // break out of the while loop - no need to reassign value if we've already determined it's not in the list
					}
					// Reassign val for next iteration of while loop
					val[i] = list[i]->getValue();
				}
				// When "it" is found in a list, reorder that list according to its heuristic
				reorder(i, pos);
				// And then continue to the next list to do the same thing
			}
		//}		
		// Return true if the value was previously in the list and false if it had to be added
		return itIsInList;
	}
    
    //Can also be called independently when initially loading the list with
    //unique values and when you want to load the list in the order 'it' is 
    //read without your re-order method being called (or the number of compares
    //being incremented.
	void add(const E& it) {  // Called by find if "it" is not in the list
		// Add "it" to the lists
		for (int i = 0; i < 3; i++) {
			list[i]->append(it);
		}
	}

	int getCompares() const {  //Returns the number of accumulated compares
		//return compareCount;
		return 1;
	}

	int size() const { //Returns the size of the list
		return list[0]->sizeOfList();
	}
    
    // In order print of the list
	void printlist() {
		cout << "Count Heuristic: Size of List: " << list[0]->sizeOfList() << endl;
		cout << "Number of Compares: " << compareCount[0] << endl;
		list[0]->print();
		cout << "\n\n";

		cout << "MTF Heuristic: Size of List: " << list[1]->sizeOfList() << endl;
		cout << "Number of Compares: " << compareCount[1] << endl;
		list[1]->print();
		cout << "\n\n";

		cout << "Transpose Heuristic: Size of List: " << list[2]->sizeOfList() << endl;
		cout << "Number of Compares: " << compareCount[2] << endl;
		list[2]->print();
		cout << "\n";

	}

	// prints n nodes.
	void printlist(int n) {

	}
};


#endif	/* SELFORDEREDLIST_H */

