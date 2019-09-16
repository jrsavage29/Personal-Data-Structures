#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "abstract_deque.hpp"
#include "DoubleNode.hpp"
#include <stdexcept>

template <typename T>
class Deque: public AbstractDeque<T>
{

private:
	DoubleNode<T>* FrontPtr; //make nullptrs
	
	DoubleNode<T>* BackPtr;
	
	
public:
	
	Deque();
	
	virtual ~Deque();
	
	Deque(const Deque& rhs );
	
	Deque& operator=(Deque rhs);
   
	bool isEmpty() const noexcept;

	void pushFront(const T & item);

	void popFront();

	T front() const; //peak return the front element but not remove it

	void pushBack(const T & item);

	void popBack();

	T back() const; //peak return the back element but not remove it
	
	void clear();
	
	void swap(Deque <T> &x, Deque <T> &y);
  
};

#include "deque.hpp"

template<typename T>
Deque<T>::Deque() : FrontPtr(nullptr), BackPtr(nullptr)
{

}


template<typename T>
Deque<T>::~Deque()
{
	clear();
}


template<typename T>
Deque< T >::Deque(const Deque < T > & rhs)
{
	DoubleNode<T>* origChainPtr = rhs.FrontPtr; //Points to nodes in original chain

	if (origChainPtr == nullptr)
	{
		FrontPtr = BackPtr = nullptr; //The original list is empty
	}

	else
	{
		FrontPtr = new DoubleNode<T>(rhs.FrontPtr->getItem());
		DoubleNode<T>* rhscurrent = rhs.FrontPtr;
		DoubleNode<T>* current = FrontPtr;
		DoubleNode<T>* previous = FrontPtr;

		while (rhscurrent->getNext() != nullptr)
		{
			rhscurrent = rhscurrent->getNext();
			current->setNext(new DoubleNode<T>(rhscurrent->getItem()));
			current = current->getNext();
			current->setPrev(previous);
			previous = current;
		}

		BackPtr = current;
	}

}


template<typename T>
Deque<T>& Deque< T >::operator=(Deque <T> rhs)
{
	swap(*this, rhs);

	return *this;
}


template<typename T>
void Deque< T >::swap(Deque< T > & 	x, Deque< T > & y)
{
	std::swap(x.FrontPtr, y.FrontPtr);
	std::swap(x.BackPtr, y.BackPtr);

}


template<typename T>
void Deque< T >::clear()
{
	DoubleNode<T> *curr = FrontPtr;
	while (curr != nullptr)
	{
		DoubleNode<T> *del = curr;
		curr = curr->getNext();
		delete del;
	}
	FrontPtr = BackPtr = nullptr;

	/*while(!isEmpty())
	{
		popFront();
	}*/
}


template<typename T>
bool Deque<T>::isEmpty() const noexcept
{
	if (FrontPtr == nullptr && BackPtr == nullptr)
		return true;

	else
		return false;
}


template<typename T>
void Deque<T>::pushFront(const T & item)
{
	if (isEmpty())
	{
		FrontPtr = BackPtr = new DoubleNode <T>(item);
	}

	else
	{
		DoubleNode<T>* newNodePtr = new DoubleNode<T>(item, FrontPtr, nullptr);
		FrontPtr->setPrev(newNodePtr);
		FrontPtr = newNodePtr; //the new FrontPtr is the newNodePtr 

	}
}


template<typename T>
void Deque<T>::popFront()
{

	if (isEmpty())
	{
		throw std::runtime_error("Can't pop from the front since the deque is empty");
	}

	if (FrontPtr == BackPtr)
	{
		delete FrontPtr;
		FrontPtr = nullptr;
		BackPtr = nullptr;
	}
	else if (FrontPtr != nullptr)
	{
		DoubleNode<T>* nodeToDeletePtr = FrontPtr;
		FrontPtr = FrontPtr->getNext();

		nodeToDeletePtr->setNext(nullptr);
		FrontPtr->setPrev(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;

	}

}


template<typename T>
T Deque<T>::front() const //peak return the front element but not remove it
{
	if (isEmpty())
	{
		throw std::runtime_error("Can't peek from the front since the deque is empty");
	}

	return FrontPtr->getItem();
}


template<typename T>
void Deque<T>::pushBack(const T & item)
{
	if (isEmpty())
	{
		FrontPtr = BackPtr = new DoubleNode <T>(item);
	}

	else
	{
		DoubleNode<T>* newNodePtr = new DoubleNode<T>(item, nullptr, BackPtr);
		BackPtr->setNext(newNodePtr);
		BackPtr = newNodePtr;

	}

}


template<typename T>
void Deque<T>::popBack()
{
	if (isEmpty())
	{
		throw std::runtime_error("Can't pop from the back since the deque is empty");
	}


	else if (FrontPtr == BackPtr)
	{
		return popFront();
	}

	else if (BackPtr)
	{
		DoubleNode<T>* nodeToDeletePtr = BackPtr;
		BackPtr = BackPtr->getPrev();
		nodeToDeletePtr->setPrev(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;
	}
}


template<typename T>
T Deque<T>::back() const //peak return the back element but not remove it
{
	if (FrontPtr == nullptr && BackPtr == nullptr)
	{
		throw std::runtime_error("Can't peek from the back since the deque is empty");
	}

	return BackPtr->getItem();
}


#endif
