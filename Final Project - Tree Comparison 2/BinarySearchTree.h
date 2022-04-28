#pragma once
//Daniel Blakeman
//CIS 2207 502
//Create a function called bool isSameTree(Tree *); 
//that will take an argument of a tree.  It will return a true if the argument is the equivalent tree.

#include "BinaryNode.h"
#include "BinaryNodeTree.h"
#include "NotFoundException.h"
#include "BinaryTreeInterface.h"
#include "PrecondViolatedExcept.h"
#include <memory.h>

template<class ItemType>
class BinarySearchTree : public BinaryNodeTree<ItemType>
{
private:
	std::shared_ptr<BinaryNode<ItemType>> rootPtr;
protected:
	auto placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, std::shared_ptr<BinaryNode<ItemType>> newNode);
	auto removeValue(std:: shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType target, bool& isSuccessful);
	auto removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr);
	auto removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>>subTreePtr, ItemType& inorderSuccessor);
	auto findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr, const ItemType& target) const;

public:
	BinarySearchTree();
	BinarySearchTree(const ItemType& rootItem);
	BinarySearchTree(const BinarySearchTree<ItemType>& tree);
	virtual ~BinarySearchTree();

	bool isEmpty() const;
	int getHeight() const;
	int getNumberOfNodes() const;
	ItemType getRootData() const throw(PrecondViolatedExcept);
	void setRootData(const ItemType& newData);
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& target);
	void clear();
	ItemType getEntry(const ItemType& anEntry) const throw(NotFoundException);
	bool contains(const ItemType& anEntry) const;
	bool isSameTree(BinarySearchTree<ItemType>* tree);
	void preorderTraverse(std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
	void inorderTraverse(std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
	void postorderTraverse(std::shared_ptr<BinaryNode<ItemType>> treePtr);
	void visit(ItemType&) const;
};

