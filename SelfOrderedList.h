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
    
	bool find(const E& it) {
		// Look for "it"
		//E temp = linkedList->curr;
		//while (temp->getValue() != it) {
		//	temp = temp->next();
		//}

		//for (int i = 0; i < linkedList->cnt(); i++) {
		//	// if found
		//		// execute self ordering heuristic
		//	// Return true
		//	// else {
		//		// add(it);
		//	// }

		//	// Increment the compare instance variable each time "it" is compared to another member of the list
		//	compareCount++;
		//}

		return true;
	}
    
    //Can also be called independently when initially loading the list with
    //unique values and when you want to load the list in the order 'it' is 
    //read without your re-order method being called (or the number of compares
    //being incremented.
	void add(const E& it) {  // Called by find if "it" is not in the list
		// Add new 'it' to the list


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

