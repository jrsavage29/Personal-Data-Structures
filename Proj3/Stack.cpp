#include "Stack.hpp"

template<typename T>
Stack< T >::Stack()	
{
	headPtr = nullptr;
	currentSize = 0;
}

template<typename T>
Stack< T >::Stack(const Stack< T > & rhs)
{
	Node<T>* origChainPtr = rhs.headPtr; //Points to nodes in original chain
	
	if(origChainPtr == nullptr)
	{
		headPtr = nullptr; //The original stack is empty
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
		
		currentSize = rhs.currentSize;
		
		newChainPtr->setNext(nullptr); //Flag end of chain
	}
}

template<typename T>
Stack< T >::~Stack()
{
	clear();
}

template<typename T>
void Stack< T >::clear()
{
	//currentSize = 0; //only use if going to test if the values were popped out of the stack.
	while(!isEmpty())
	{
		pop();
	}
}

template<typename T>
bool Stack< T >::isEmpty()const
{
	return currentSize == 0; //if the size of the stack is equal to 0 then return true, else false
}

template<typename T>
Stack<T>& Stack< T >::operator=(Stack <T> rhs	) //////////////////////////////
{
	//check for self assignment but don't really need to in this case
	//if ( this != rhs )
	//{
		//copy the auto variables
		swap(*this, rhs);
	//}
	return *this;//return me
}

template<typename T>
T Stack< T >::peek()const
throw(std::range_error)
{
	if (currentSize == 0) 
	{
		throw std::range_error("peek() called on empty stack");
	}
	
	return headPtr->getItem();//return the value that's being pointd to at the top of the stack.
}

template<typename T>
bool Stack< T >::pop()
{
	bool result = false; //If stack is not empty; delete top
	
	
	if (!isEmpty())
	{
		Node<T>* nodeToDeletePtr = headPtr;
		headPtr = headPtr->getNext();
		
		nodeToDeletePtr->setNext(nullptr); //Return deleted node to system
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;
		currentSize--;
		
		result = true;
	}
	
	return result;
}

template<typename T>
bool Stack< T >::push(const T & newItem) 
{
	Node<T>* newNodePtr = new Node<T>(newItem, headPtr);
	headPtr = newNodePtr;
	newNodePtr = nullptr;
	currentSize++;
	return true;
}

template<typename T>
int Stack< T >::size()const
{
	return currentSize;
}

template<typename T>
void Stack< T >::swap(Stack< T > & 	x, Stack< T > & y )	
{
	std::swap(x.currentSize, y.currentSize);
	std::swap(x.headPtr, y.headPtr);
}	



	
	




