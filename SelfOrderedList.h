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

	int compareCount;
	int linkedListSize;
	LList<E>* linkedList;

	void reorder(int n) {
		if (n == 0) { // Count

		}
		else if (n == 1) { // MTF

		}
		else if (n == 2) { // Transpose

		}
		return;
	}

public:

    SelfOrderedList() {
		linkedList = new LList<E>();
	}
    ~SelfOrderedList() {

	}
    
	// This function compares "it" with the values in the list
	// and returns true if the value is found, 
	// else it returns false
	bool find(const E& it) {
		// Move to the front of the list
		linkedList->moveToStart();
		// Check if list is uninitialized
		if (linkedList->isNull()) {
			// Add it
			add(it);
			return false;
		}
		// Declare a temp variable of type E
		E val;
		// fill temp with the current value of the list
		val = linkedList->getValue();

		// Check temp against the value being searched for
		while (val != it) {
			// Increment compareCount
			compareCount++;
			// If temp isn't it, move the linked list to the next item in the list
			linkedList->next();
			// Check if we've reached the end of the list, if so, "it" is not in the list, return false
			if (linkedList->isNull()) { 
				// Add it
				add(it);
				return false; 
			}
			// Reassign temp
			val = linkedList->getValue();
		}

		return true;
	}
    
    //Can also be called independently when initially loading the list with
    //unique values and when you want to load the list in the order 'it' is 
    //read without your re-order method being called (or the number of compares
    //being incremented.
	void add(const E& it) {  // Called by find if "it" is not in the list
		// Add new 'it' to the list
		linkedList->append(it);
	}

	int getCompares() const {  //Returns the number of accumulated compares
		return compareCount;
	}

	int size() const { //Returns the size of the list
		return linkedListSize;
	}
    
    // In order print of the list
	void printlist() {

	}

	// prints n nodes.
	void printlist(int n) {

	}
};


#endif	/* SELFORDEREDLIST_H */

