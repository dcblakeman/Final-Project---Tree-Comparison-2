#pragma once
//Daniel Blakeman
//CIS 2207 502
//Create a function called bool isSameTree(Tree *); 
//that will take an argument of a tree.  It will return a true if the argument is the equivalent tree.
#include <memory>
template<class ItemType>
class BinaryNode
{
private:
	ItemType item; //Data Portion
	std::shared_ptr<BinaryNode<ItemType>> leftChildPtr; //Pointer to left child
	std::shared_ptr<BinaryNode<ItemType>> rightChildPtr; //Pointer to right child

public:
	BinaryNode();
	BinaryNode(const ItemType& anItem);
	BinaryNode(const ItemType& anItem, std::shared_ptr<BinaryNode<ItemType>> leftPtr, std::shared_ptr<BinaryNode<ItemType>> rightPtr);
	void setItem(const ItemType& anItem);
	ItemType getItem() const;
	bool isLeaf() const;
	auto getLeftChildPtr() const;
	auto getRightChildPtr() const;
	void setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr);
	void setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr);
};