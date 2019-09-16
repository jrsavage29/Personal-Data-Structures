#ifndef _DOUBLENODE_HPP
#define _DOUBLENODE_HPP

template<typename ItemType>
class DoubleNode
{
private: 
    ItemType item; // A data item 
    DoubleNode <ItemType>* Right; // Pointer to next node RIGHT
    DoubleNode <ItemType>* Left; // Pointer to previous node LEFT
public: 
  DoubleNode();
  DoubleNode(const ItemType& anItem);
  DoubleNode(const ItemType& anItem, DoubleNode <ItemType>* nextNodePtr, DoubleNode <ItemType>* prevNodePtr); 
  void setItem(const ItemType& anItem);
  void setNext(DoubleNode <ItemType>* nextNodePtr);
  void setPrev(DoubleNode <ItemType>* prevNodePtr);
  ItemType getItem() const;
  DoubleNode<ItemType>* getNext() const;
  DoubleNode<ItemType>* getPrev() const;
};
#include "DoubleNode.hpp"


template<class ItemType>
DoubleNode<ItemType>::DoubleNode() : Right(nullptr), Left(nullptr)
{
	
}

template<class ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType& anItem) : item(anItem), Right(nullptr), Left(nullptr)
{
	
}

template<class ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType& anItem, DoubleNode <ItemType>* nextNodePtr, DoubleNode <ItemType>* prevNodePtr) : item(anItem), Right(nextNodePtr), Left(prevNodePtr) 
{

}

template<class ItemType>	
void DoubleNode<ItemType>::setItem(const ItemType& anItem)
{
	item = anItem;
}

template<class ItemType>
void DoubleNode<ItemType>:: setNext(DoubleNode <ItemType>* nextNodePtr)
{
	Right = nextNodePtr;
}

template<class ItemType>
void DoubleNode<ItemType>::setPrev(DoubleNode <ItemType>* prevNodePtr)
{
	Left = prevNodePtr;
}

template<class ItemType>
ItemType DoubleNode<ItemType>::getItem() const
{
	return item;
}

template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getNext() const
{
	return Right;
}

template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getPrev() const
{
	return Left;
}



#endif
