#ifndef LLIST_H
#define	LLIST_H

#include "book.h"
#include "link.h"
#include "list.h"

// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Linked list implementation
template <typename E> 
class LList: public List<E> {
private:
  Link<E>* head;       // Pointer to list header
  Link<E>* tail;       // Pointer to last element
  Link<E>* curr;       // Access to current element
  int cnt;    	       // Size of list

  void init() {        // Intialization helper method
    curr = tail = head = new Link<E>;
    cnt = 0;
  }

  void removeall() {   // Return link nodes to free store
    while(head != NULL) {
      curr = head;
      head = head->next;
      delete curr;
    }
  }

public:
  LList() { init(); }    // Constructor
  ~LList() { removeall(); }                   // Destructor

  void print() { // Print list contents
	  moveToStart();
	  for (int i = 0; i < cnt; i++) {
		  cout << getValue() << "-" << curr->next->count << " ";
		  curr = curr->next;
	  }
  };

  void printFinite(int n) { // Prints 10 nodes
	  moveToStart();
	  for (int i = 0; i < n; i++) {
		  cout << getValue() << "-" << curr->next->count << " ";
		  curr = curr->next;
	  }
  }

  void clear() { // Clear list
	  removeall(); 
	  init(); 
  }       

  // Insert "it" at current position
  void insert(const E& it) {
    curr->next = new Link<E>(it, curr->next);  
    if (tail == curr) tail = curr->next;  // New tail
    cnt++;
  }

  void append(const E& it) { // Append "it" to list
    tail = tail->next = new Link<E>(it, NULL);
    cnt++;
  }

  // Remove and return current element
  E remove() {
    Assert(curr->next != NULL, "No element");
    E it = curr->next->element;      // Remember value
    Link<E>* ltemp = curr->next;     // Remember link node
    if (tail == curr->next) tail = curr; // Reset tail
    curr->next = curr->next->next;   // Remove from list
    delete ltemp;                    // Reclaim space
    cnt--;			     // Decrement the count
    return it;
  }

  void moveToStart() // Place curr at list start
    { curr = head; }

  void moveToEnd()   // Place curr at list end
    { curr = tail; }

  // Move curr one step left; no change if already at front
  void prev() {
    if (curr == head) return;       // No previous element
    Link<E>* temp = head;
    // March down list until we find the previous element
    while (temp->next!=curr) temp=temp->next;
    curr = temp;
  }

  // Move curr one step right; no change if already at end
  void next()
    { if (curr != tail) curr = curr->next; }

  int length() const  { return cnt; } // Return length

  // Return the position of the current element
  int currPos() const {
    Link<E>* temp = head;
    int i;
    for (i=0; curr != temp; i++)
      temp = temp->next;
    return i;
  }

  // Move down list to "pos" position
  void moveToPos(int pos) {
    Assert ((pos>=0)&&(pos<=cnt), "Position out of range");
    curr = head;
    for(int i=0; i<pos; i++) curr = curr->next;
  }

  const E& getValue() const { // Return current element
    Assert(curr->next != NULL, "No value");
    return curr->next->element;
  }

  bool isTail() {
	  if (curr->next == NULL) return true;
	  return false;
  }
  
  bool isEmpty() {
	  if (head->next == NULL) {
		  return true;
	  }
	  else {
		  return false;
	  }
  }

  int getCount() {
	  return curr->getCount();
  }

  int sizeOfList() {
	  return cnt;
  }

  int incrementCount() {
	  return curr->incrementCount();
  }
  void transpose(int accessedElementPos) {
	  moveToPos(accessedElementPos);
	  int currCount = curr->incrementCount();
	  if (curr == head || curr == head->next) return; // Already at the head or element 1, no changes

	  // Get some pointers
	  Link<E>* oneElementBeforeCurr = getPrev();
	  Link<E>* twoElementsBeforeCurr = getTwoPrev();
	  Link<E>* tempNext = curr->next;

	  // Make the swaps
	  twoElementsBeforeCurr->assignNext(curr);
	  oneElementBeforeCurr->assignNext(tempNext);
	  curr->assignNext(oneElementBeforeCurr);
	  // Reassign the tail
	  moveToPos(cnt);
	  tail = curr;
	  tail->assignNext(NULL);
	  return;
  }

  void moveToFront(int accessedElementPos) {
	  moveToPos(accessedElementPos);
	  int currCount = curr->incrementCount();
	  if (curr == head || curr == head->next) return; // Already at the head or element 1, no changes

	  // Get some pointers
	  Link<E>* oneElementBeforeCurr = getPrev();
	  Link<E>* previousStart = head->next;
	  Link<E>* tempNext = curr->next;

	  // Make the swaps
	  curr->assignNext(previousStart);
	  head->assignNext(curr);
	  oneElementBeforeCurr->assignNext(tempNext);
	  // Reassign the tail
	  moveToPos(cnt);
	  tail = curr;
	  tail->assignNext(NULL);
	  return;
  }

  void reorderCount(int accessedElementPos) {
	  // Get to the item accessed
	  moveToPos(accessedElementPos);
	  if (accessedElementPos > 156) {
		  int i = 0;
	  }
	  // Increment the count for that item
	  int currCount = curr->incrementCount();
	  if (curr == head || curr == head->next) return; // The item accessed is the first item, no changes
	  // Reorder according to the count variable
	  // Get a pointer to the previous element
	  Link<E>* prev = getPrev();
	  if (prev->count >= curr->count && (curr->next == NULL || curr->next->count <= curr->count)) return;
	  Link<E>* tempPrev = prev;
	  Link<E>* tempNext2 = curr->next;
	  // While the previous element's count is lower, keep going left
	  while (prev != head && prev->count < curr->count) {
		  prev = getPrevOf(prev);
	  }
	  // When a suitable insertion point is found, remove curr from its original position and reinsert it
	  Link<E>* tempNext = prev->next;
	  prev->assignNext(curr);
	  curr->assignNext(tempNext);
	  tempPrev->assignNext(tempNext2);
	  if (curr == nullptr) {
		  cout << "test" << endl;
	  }

	  // Reassign the tail
	  moveToPos(cnt);
	  tail = curr;
	  tail->assignNext(NULL);
	  return;
  }

  Link<E> * getPrev() {
	  if (curr == head) return head;       // No previous element
	  Link<E>* temp = head;
	  // March down list until we find the previous element
	  while (temp->next != curr) temp = temp->next;
	  return temp;
  }

  Link<E> * getPrevOf(Link<E>* temp) {
	  if (temp == head) return head;       // No previous element
	  Link<E>* temp2 = head;
	  // March down list until we find the previous element
	  while (temp2->next != temp) temp2 = temp2->next;
	  return temp2;
  }

  Link<E> * getTwoPrev() {
	  if (curr == head) return head;       // No previous element
	  Link<E>* temp = head;
	  // March down list until we find the previous element
	  while (temp->next->next != curr) temp = temp->next;
	  return temp;
  }
};

#endif