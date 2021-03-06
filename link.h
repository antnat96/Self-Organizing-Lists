#ifndef LINK_H
#define	LINK_H

#include <cstdlib>

// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Singly linked list node
template <typename E> class Link {
public:
  E element;      // Value for this node
  int count;	   // Number of times this node has been accessed
  Link *next;        // Pointer to next node in list
  // Constructors
  Link(const E& elemval, Link* nextval =NULL) { 
	  element = elemval;  
	  next = nextval; 
	  count = 0;
  }
  Link(Link* nextval =NULL) { 
	  next = nextval; 
	  count = 0;
  }
  int incrementCount() {
	  count++;
	  return count;
  }
  void assignNext(Link* nextVal = NULL) {
	  next = nextVal;
  }

};

#endif