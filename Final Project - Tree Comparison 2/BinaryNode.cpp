//Daniel Blakeman
//CIS 2207 502
//Create a function called bool isSameTree(Tree *); 
//that will take an argument of a tree.  It will return a true if the argument is the equivalent tree.

#include"BinaryNode.h"
#include<iostream>
#include<string>

template<class ItemType>
inline BinaryNode<ItemType>::BinaryNode()
{
}


template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem)
{
	item = anItem;
}

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem, std::shared_ptr<BinaryNode<ItemType>> leftPtr, std::shared_ptr<BinaryNode<ItemType>> rightPtr)
{
	item = anItem;
	leftChildPtr = leftPtr;
	rightChildPtr = rightPtr;
}

template<class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem)
{
	item = anItem;
}

template<class ItemType>
ItemType BinaryNode<ItemType>::getItem() const
{
	return ItemType(item);
}

template<class ItemType>
bool BinaryNode<ItemType>::isLeaf() const // A node with no children
{
	if (getLeftChildPtr == nullptr && getRightChildPtr == nullptr)
		return true;
	else
		return false;
}

template<class ItemType>
auto BinaryNode<ItemType>::getLeftChildPtr() const
{
	return leftChildPtr;
}

template<class ItemType>
auto BinaryNode<ItemType>::getRightChildPtr() const
{
	return rightChildPtr;
}

template<class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr)
{
	leftChildPtr = leftPtr;
}

template<class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr)
{
	rightChildPtr = rightPtr;
}

