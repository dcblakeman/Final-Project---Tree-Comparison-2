#pragma once
//Daniel Blakeman
//CIS 2207 502
//Create a function called bool isSameTree(Tree *); 
//that will take an argument of a tree.  It will return a true if the argument is the equivalent tree.
#include "NotFoundException.h"
template<class ItemType>
class BinaryTreeInterface
{
public:
	virtual bool isEmpty() const = 0; //Tests whether this binary tree is empty - return true if it is and false if not
	virtual int getHeight() const = 0; // gets the height of this binary tree
	virtual int getNumberOfNodes() const = 0; // gets number of nodes in this binary tree
	virtual ItemType getRootData() const = 0; //gets data in the root of the binary tree if its not empty
	virtual void setRootData(const ItemType& newData) = 0; //replaces the data in the root of this tree if not empty. if it is empty, insert a new root node with data
	virtual bool add(const ItemType& newData) = 0; // adds data to this binary tree
	virtual bool remove(const ItemType& target) = 0; //remove specified data from the binary tree. then return true if removed, false if not.
	virtual void clear() = 0; //Removes all data from the binary tree
	virtual ItemType getEntry(const ItemType& target) const = 0; //Retrieves the specified data from this binary tree
	virtual bool contains(const ItemType& target) const = 0; //Tests whether the specific data occurs in this binary tree

	virtual ~BinaryTreeInterface() {};
};