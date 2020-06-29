/* 
 * File:   SelfOrderedList.h
 * Author: Anthony Natale
 *
 * Created on June 28th, 2020
 */

#ifndef SELFORDEREDLIST_H
#define	SELFORDEREDLIST_H

#include "SelfOrderedListADT.h"

template <typename E> class SelfOrderedList : public SelfOrderedListADT<E> {

public:
    //Default constructor/destructor
    SelfOrderedList(){}
    ~SelfOrderedList() {}
    
    //Look for 'it'.  If found return true and execute the self-ordering
    //heuristic used for ordering the list: count, move-to-front, or transpose.
    //Increments the compare instance variable every time it compares 'it' to
    //other members of the list. Returns true if 'it' is found.
	bool find(const E& it) {
	
	}
    
    //Called by find if 'it' is not in the list. Adds the new 'it' to the list
    //Can also be called independently when initially loading the list with
    //unique values and when you want to load the list in the order 'it' is 
    //read without your re-order method being called (or the number of compares
    //being incremented.
	void add(const E& it) {  //Add new 'it' to the list

	}

	int getCompares() const {  //Returns the number of accumulated compares

	}

	int size() const {       //Returns the size of the list

	}
    
    //Print the list
    //In order print of the list.  printlist() prints the entire list
    //whereas printlist(n) prints n nodes.
	void printlist() {

	}

	void printlist(int n) {

	}
    
};


#endif	/* SELFORDEREDLIST_H */

