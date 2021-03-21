#include "LinkedList.hpp"

template<typename T>
LinkedList<T>::LinkedList() : headPtr(nullptr), itemCount(0)
{
} // end default constructor

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &rhs)//copy constructor
{
	Node<T>* origChainPtr = rhs.headPtr; //Points to nodes in original chain
	
	if(origChainPtr == nullptr)
	{
		headPtr = nullptr; //The original list is empty
	}
	
	else
	{
		headPtr = new Node<T>(); // copy the first node
		headPtr -> setItem(origChainPtr -> getItem());
		
		Node<T>* newChainPtr = headPtr; //Point to the first node in new chain
		
		origChainPtr = origChainPtr-> getNext(); //Advance original-chain pointer
		
		while(origChainPtr != nullptr) //copying remaining nodes
		{
			T nextItem = origChainPtr -> getItem(); //Get next item from original chain
			
			Node<T>* newNodePtr = new Node<T>(nextItem); //Create a new node containing the next item
			
			newChainPtr ->setNext(newNodePtr); //Link new node to end of new chain
			
			newChainPtr = newChainPtr->getNext(); // Advance pointer to new last node
			
			origChainPtr = origChainPtr->getNext(); // Advance original-chain pointer
		}
		
		itemCount = rhs.itemCount;
		
		newChainPtr->setNext(nullptr); //Flag end of chain
	}
}


template<typename T>
LinkedList< T > & LinkedList< T >::operator=(LinkedList< T > rhs)
{
	swap(*this, rhs);

	return *this;
}


template<typename T>
Node<T>* LinkedList<T>::getNodeAt(int position) const
{
   // Debugging check of precondition
   assert( (position >= 1) && (position <= itemCount) );
   
   // Count from the beginning of the chain
   Node<T>* curPtr = headPtr;
   for (int skip = 1; skip < position; skip++)
      curPtr = curPtr->getNext();
      
   return curPtr;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	clear();
} // end destructor


template<typename T>
void LinkedList<T>::clear()
{
   while (!isEmpty())
      remove(1);
} // end clear


template<typename T>
T LinkedList<T>::getEntry(int position) const
{
   // Enforce precondition
   bool ableToGet = (position >= 1) && (position <= itemCount);
   if (ableToGet)
   {
      Node<T>* nodePtr = getNodeAt(position);
      return nodePtr -> getItem();
   }
   else
   {
      std::string message = "getEntry() called with an empty list or ";
      message = message + "invalid position.";
      throw(PrecondViolatedExcept(message));
   } // end if
} // end getEntry


template<typename T>
int LinkedList< T >::getLength()const
{
	return itemCount;
}


template<typename T>
bool LinkedList<T>::insert(int newPosition, const T& newEntry)
{
   bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
                       
   if (ableToInsert)
   {
      // Create a new node containing the new entry
      Node<T>* newNodePtr = new Node<T>(newEntry);
      // Attach new node to chain
      if (newPosition == 1)
      {
         // Insert new node at beginning of chain
         newNodePtr -> setNext(headPtr);
         headPtr = newNodePtr;
      }
      else
      {
         // Find node that will be before new node
         Node<T>* prevPtr = getNodeAt(newPosition - 1);
         
         // Insert new node after node to which prevPtr points
         newNodePtr -> setNext(prevPtr -> getNext());
         prevPtr -> setNext(newNodePtr);
      } // end if
      
      itemCount++; // Increase count of entries
      }  // end if
   
   return ableToInsert;
}  // end insert



template<typename T>
bool LinkedList< T >::isEmpty()const
{
	return itemCount == 0; //if the size of the stack is equal to 0 then return true, else false
}


template<typename T>
bool LinkedList<T>::remove(int position)
{
   bool ableToRemove = (position >= 1) && (position <= itemCount);
   if (ableToRemove)
   {
      Node<T>* curPtr = nullptr;
      if (position == 1)
      {
         // Remove the first node in the chain
         curPtr = headPtr; // Save pointer to node
         headPtr = headPtr -> getNext();
      }
      else
      {
         // Find node that is before the one to remove
         Node<T>* prevPtr = getNodeAt(position - 1);
         
         // Point to node to remove
         curPtr = prevPtr -> getNext();
         
         // Disconnect indicated node from chain by connecting the
         // prior node with the one after
         prevPtr -> setNext(curPtr -> getNext());
      } // end if
      
      // Return node to system
      curPtr -> setNext(nullptr);
      delete curPtr;
      curPtr = nullptr;
      itemCount--; // Decrease count of entries
   } // end if
   
   return ableToRemove;
} // end remove


//replace() not legit yet/////////////////////////////
////////////////////////////////////////SIMILAR TO GETENTRY METHOD
template<typename T>
T LinkedList<T>::replace(int position, const T& newEntry)
{
		//Enforcing Precondition
		bool ableToSet = (position >= 1) && (position <= itemCount);
		if(ableToSet)
		{
			/*T oldEntry = items[position];
			items[position] = newEntry;
			return oldEntry;
			*/;
			 
			 Node<T>* nodePtr = getNodeAt(position);
			  T newItem = nodePtr -> getItem();
			  nodePtr-> setItem(newEntry);
			 
			return newItem;
		}
		
		else
		{
			std::string message = "replace() called with an empty list or ";
			message = message + "invalid position.";
			throw(PrecondViolatedExcept(message));
		}
}				


template<typename T>
void LinkedList< T >::swap(LinkedList< T > & lhs, LinkedList< T > & rhs )	
{
	std::swap(lhs.itemCount, rhs.itemCount);
	std::swap(lhs.headPtr, rhs.headPtr);
}	
