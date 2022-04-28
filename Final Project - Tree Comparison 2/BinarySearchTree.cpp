//Daniel Blakeman
//CIS 2207 502
//Create a function called bool isSameTree(Tree *); 
//that will take an argument of a tree.  It will return a true if the argument is the equivalent tree.
#include "BinarySearchTree.h"

template<class ItemType>
inline auto BinarySearchTree<ItemType>::placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, std::shared_ptr<BinaryNode<ItemType>> newNode)
{
}

template<class ItemType>
auto BinarySearchTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType target, bool& isSuccessful)
{
}

template<class ItemType>
auto BinarySearchTree<ItemType>::removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr)
{
}

template<class ItemType>
auto BinarySearchTree<ItemType>::removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, ItemType& inorderSuccessor)
{
}

template<class ItemType>
auto BinarySearchTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr, const ItemType& target) const
{
}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
{
}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem)
{
	BinaryNodeTree<ItemType> nodeTree;
	nodeTree.setRootData(rootItem);
}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& tree)
{
}

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
}

template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
	return false;
}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
	return 0;
}

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const
{
	return 0;
}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const throw(PrecondViolatedExcept)
{
	BinaryNode<ItemType> node;
	return node.getItem();
}

template<class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newData)
{
	BinaryNode<ItemType> node;
	node.setItem(newData);
}

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newEntry)
{
	this->setRootData(newEntry);
	return true;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& target)
{
	return true;
}

template<class ItemType>
void BinarySearchTree<ItemType>::clear()
{
}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry) const throw(NotFoundException)
{
	return ItemType();
}

template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry) const
{
	return false;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::isSameTree(BinarySearchTree<ItemType>* tree)
{
	return false;
}

template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
	if (treePtr != nullptr)
	{
		ItemType theItem = treePtr->getItem();
		preorderTraverse(treePtr->getLeftChildPtr());
		preorderTraverse(treePtr->getRightChildPtr());
	}
}

template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
	BinaryNode<ItemType> node;
	if (treePtr != nullptr)
	{
		inorderTraverse(treePtr->getLeftChildPtr());
		ItemType theItem = treePtr->getItem();
		inorderTraverse(treePtr->getRightChildPtr());
	}// end if
}

template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(std::shared_ptr<BinaryNode<ItemType>> treePtr)
{
	if (treePtr != nullptr)
	{
		postorderTraverse(treePtr->getLeftChildPtr());
		postorderTraverse(treePtr->getRightChildPtr());
		ItemType theItem = treePtr->getItem();
	}
}

template<class ItemType>
void BinarySearchTree<ItemType>::visit(ItemType&) const
{
}
