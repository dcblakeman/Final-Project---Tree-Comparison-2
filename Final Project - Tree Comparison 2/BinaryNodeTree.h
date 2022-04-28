#pragma once
//Daniel Blakeman
//CIS 2207 502
//Create a function called bool isSameTree(Tree *); 
//that will take an argument of a tree.  It will return a true if the argument is the equivalent tree.
#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "PrecondViolatedExcept.h"
#include "NotFoundException.h"
#include <memory>
#include <vector>

template<class ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType>
{
private:
	

protected:
	int getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
	int getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
	auto balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, std::shared_ptr<BinaryNode<ItemType>> newNodePtr);
	auto removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType target, bool& isSuccessful);
	auto movesValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);
	auto removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr);
	auto removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr, ItemType& newNodeValue);
	auto copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const;
	void destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);
	void display(std:: string someItem);

public:
	std::shared_ptr<BinaryNode<ItemType>> rootPtr;
	std::vector<ItemType> vec;
	std::vector<ItemType> vec1;
	std::vector<ItemType> vec2;
	BinaryNodeTree();
	BinaryNodeTree(const ItemType& rootItem);
	BinaryNodeTree(const std::shared_ptr<BinaryNode<ItemType>>& treePtr);
	virtual ~BinaryNodeTree();
	auto findNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType& target) const;
	bool isEmpty() const;
	int getHeight() const;
	int getNumberOfNodes() const;
	ItemType getRootData() const throw(PrecondViolatedExcept);
	void setRootData(const ItemType& newData);
	bool remove(const ItemType& data);
	void clear();
	ItemType getEntry(const ItemType& anEntry) const throw(NotFoundException);
	bool contains(const ItemType& anEntry) const;
	bool add(const ItemType& newData);
	bool isSameTree(BinaryNodeTree<ItemType>* tree);
	void preorderTraverse(std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
	void inorderTraverse(std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
	void postorderTraverse(std::shared_ptr<BinaryNode<ItemType>> treePtr);
	
}; // end BinaryNodeTree