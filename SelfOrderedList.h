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
	int listSize;
	
	void reorder(int i, const E& it, int pos = 0) {
		if (i == 0) {
			// Go to the front
			list[0]->moveToStart();
			// Reorder the list
			// Reorder the list
			reorderCount(it);
		}
		else if (i == 1) {
			list[1]->moveToStart();
			reorderMTF(pos);
		}
		else if (i == 2) {
			list[2]->moveToStart();
			reorderTranspose(it);
		}
		return;
	}

	void reorderCount(const E& it) {
		// if (!(list[0]->isNull())) {
			// Move to the start of the list
			// Increment and return the count variable for that item in the list
			//int currCount = list[0]->incrementCount();
			//list[0]->next();
			//int nextCount = list[0]->getCount();
			//if (nextCount > currCount) {
			//}
		// }
		// At the end of the list, give control back to reorder() function
		return;
	}

	void reorderMTF(int pos) {
		
	}

	void reorderTranspose(const E& it) {
		cout << "Transpose" << endl;
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
		//for (int i = 0; i < 3; i++) {
		//	list[i]->removeall();
		//}
	}
    
	// This function compares "it" with the values in the list
	// and returns true if the value is found, 
	// else it returns false
	bool find(const E& it) {

		// Bool to track if search fails at any point and "it" cannot be found
		bool itIsInList = true;

		// Check if list is uninitialized
		for (int i = 0; i < 3; i++) {
			if (list[i]->isNull()) {
				// Add it to each list
				list[i]->append(it);
				// And mark the lists as uninitialized before moving to the next list
				itIsInList = false;
			}
		}
		
		// If the list was previously null, return false, we're done here
		if (itIsInList == false) {
			return itIsInList;
		}
		// Otherwise, the lists are populated and we need to search for "it"
		else {
			// Declare an array whose variables are of type E (char or string)
			E val[3];
			//for (int i = 0; i < 3; i++) {
			for (int i = 1; i < 3; i++) {
				// Move to the front of the lists to prepare for the search
				list[i]->moveToStart();
				// fill val array with the current value of the list being searched
				val[i] = list[i]->getValue();
				// Get the position of the found item
				int pos = 0;
				// Check temp against "it"
				while (val[i] != it) {
					// Increment compareCount and pos
					compareCount[i]++; pos++;
					// If temp isn't it, move the linked list to the next item in the list
					list[i]->next();
					// Check if we've reached the end of the list, if so, add "it" to the end of the list and return false
					// because "it" wasn't previously in the list
					if (list[i]->isNull()) {
						// Add it
						list[i]->append(it);
						itIsInList = false;
						break; // break out of the while loop - no need to reassign value if we've already determined it's not in the list
					}
					// Reassign val for next iteration of while loop
					val[i] = list[i]->getValue();
				}
				// When "it" is found in a list, reorder that list according to its heuristic
				reorder(i, it, pos);
				// And then continue to the next list to do the same thing
			}
		}		
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
		return listSize;
	}
    
    // In order print of the list
	void printlist() {

	}

	// prints n nodes.
	void printlist(int n) {

	}
};


#endif	/* SELFORDEREDLIST_H */

