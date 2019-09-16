/** ADT list: Link-based implementation.
    Listing 9-2.
    @file LinkedList.h */

#ifndef LINKED_LIST_
#define LINKED_LIST_

#include "ListInterface.hpp"
#include "Node.hpp"
#include "PrecondViolatedExcept.h"

template<typename T>
class LinkedList : public ListInterface<T>
{
private:
   Node<T>* headPtr; // Pointer to first node in the chain;
                            // (contains the first entry in the list)
   int itemCount;           // Current count of list items 
	
	// Locates a specified node in this linked list.
	// @pre  position is the number of the desired node;
	//  position >= 1 and position <= itemCount.
	// @post  The node is found and a pointer to it is returned.
	// @param position  The number of the node to locate.
	// @return  A pointer to the node at the given position.
	Node<T>* getNodeAt(int position) const;
	
public:
   LinkedList();
   LinkedList(const LinkedList<T> &rhs);
   LinkedList &operator= (LinkedList rhs);
   virtual ~LinkedList();

   bool isEmpty() const;
   int getLength() const;
   bool insert(int newPosition, const T& newEntry);
   bool remove(int position);
   void clear();
   
   /** @throw PrecondViolatedExcept if position < 1 or
                                       position > getLength(). */
   T getEntry(int position) const;

   /** @throw PrecondViolatedExcept if position < 1 or
                                       position > getLength(). */
	T replace(int position, const T& newEntry);
							  
	void swap(LinkedList &lhs, LinkedList &rhs);
	
}; // end LinkedList

#include "LinkedList.cpp"
#endif 
