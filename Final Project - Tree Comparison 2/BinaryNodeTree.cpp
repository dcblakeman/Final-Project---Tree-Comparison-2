//Daniel Blakeman
//CIS 2207 502
//Create a function called bool isSameTree(Tree *); 
//that will take an argument of a tree.  It will return a true if the argument is the equivalent tree.
#include"BinaryNodeTree.h"
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
#include<sstream>

template<class ItemType>
inline int BinaryNodeTree<ItemType>::getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
	if (subTreePtr == nullptr)
		return 0;
	else
		return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));
}// end getHeightHelper

template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
	if (subTreePtr == nullptr)
		return subTreePtr;
	else
	{
		inorderTraverse(subTreePtr);
		return getNumberOfNodesHelper(subTreePtr);
	}
		
}

template<class ItemType>
auto BinaryNodeTree<ItemType>::balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
{
	if (subTreePtr == nullptr)
		return newNodePtr;
	else
	{
		auto leftPtr = subTreePtr->getLeftChildPtr();
		auto rightPtr = subTreePtr->getRightChildPtr();

		if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
		{
			rightPtr = balancedAdd(rightPtr, newNodePtr);
			subTreePtr->setRightChildPtr(rightPtr);
		}
		else
		{
			leftPtr = balancedAdd(leftPtr, newNodePtr);
			subTreePtr->setLeftChildPtr(leftPtr);
		}//end if

		return subTreePtr;
	} //end if
}// end balancedAdd

template<class ItemType>
auto BinaryNodeTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType target, bool& isSuccessful)
{
	if (subTreePtr == nullptr)
		isSuccessful = false;
	else
		return subTreePtr;

}

template<class ItemType>
auto BinaryNodeTree<ItemType>::removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr)
{

	if (nodePtr->isLeaf())
	{
		return nodePtr;
	}
	
}

template<class ItemType>
auto BinaryNodeTree<ItemType>::removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr, ItemType& inorderSuccessor)
{
	if (nodePtr->getLeftChildPtr() == nullptr)
	{
		//This is the node you want; it has no left child, but it might have a right subtree
		inorderSuccessor = nodePtr->getItem();
		return removeNode(nodePtr);
	}
	else
	{
		std::shared_ptr<BinaryNode<ItemType>> tempPtr = removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccessor);
		nodePtr->setLeftchildPtr(tempPtr);
		return nodePtr;
	}
}

template<class ItemType>
auto BinaryNodeTree<ItemType>::movesValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
}

template<class ItemType>
auto BinaryNodeTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType& target) const
{
	if (subTreePtr == nullptr)
		return nullptr; // not found
	else if (subTreePtr->getItem() == target)
		return subTreePtr; // found
	else if (subTreePtr->getItem() > target)
		return findNode(subTreePtr->getLeftChildPtr(), target); // search left subtree
	else
		return findNode(subTreePtr->getRightchildPtr(), target); // search right subtree
}

template<class ItemType>
auto BinaryNodeTree<ItemType>::copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const
{
	std::shared_ptr<BinaryNode<ItemType>> newTreePtr;

	//Copy tree nodes during preorder traversal
	if (oldTreeRootPtr != nullptr)
	{
		//copy node
		newTreePtr->std::make_shared<BinaryNode<ItemType>> (oldTreeRootPtr->getItem(), nullptr, nullptr);

		newTreePtr->setLeftChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr()));
		newTreePtr->setRightChildPtr(copyTree(oldTreeRootPtr->getRightChildPtr()));
	}// end if
	//Else tree is empty (newTreePtr is nullptr)

	return newTreePtr;
}// end copyTree

template<class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
	if (subTreePtr != nullptr)
	{
		destroyTree(subTreePtr->getLeftChildPtr());
		destroyTree(subTreePtr->getRightChildPtr());
		subTreePtr.reset(); // Decrement reference count to node
	}//end if
}// end destroyTree (destructor only needs to make the call destroyTree(rootPtr).



template<class ItemType>
void BinaryNodeTree<ItemType>::display(std::string someItem)
{
	std::cout << someItem << std::endl;
}

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPtr(nullptr)
{
}

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem)
{
	rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr));
}



template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const std::shared_ptr<BinaryNode<ItemType>>& treePtr)
{
	rootPtr = copyTree(treePtr.rootPtr);
} // end copy constructor

template<class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree()
{
}
// end default constructor

template<class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const
{
	if (rootPtr == nullptr)
		return true;
	else
		return false;
}	

template<class ItemType>
int BinaryNodeTree<ItemType>::getHeight() const
{
	return getHeightHelper(rootPtr);
}

template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const
{
	return 0;
}

template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const throw(PrecondViolatedExcept)
{
	ItemType theItem = rootPtr->getItem();
	return theItem;

}

template<class ItemType>
void BinaryNodeTree<ItemType>::setRootData(const ItemType& newData)
{
	rootPtr->setItem(newData);
}



template<class ItemType>
bool BinaryNodeTree<ItemType>::remove(const ItemType& data)
{
	bool isSuccessful = false;
	removeValue(rootPtr, data, isSuccessful);
	return isSuccessful;
}

template<class ItemType>
void BinaryNodeTree<ItemType>::clear()
{
}

template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry(const ItemType& anEntry) const throw(NotFoundException)
{
	ItemType theItem = rootPtr->getItem();
	return theItem;
}

template<class ItemType>
bool BinaryNodeTree<ItemType>::contains(const ItemType& anEntry) const
{
	return true;
}

template<class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
	if (treePtr != nullptr)
	{
		ItemType theItem = treePtr->getItem();
		std::cout << theItem;
		preorderTraverse(treePtr->getLeftChildPtr());
		preorderTraverse(treePtr->getRightChildPtr());
	}
}

template<class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
	if (treePtr != nullptr)
	{
		inorderTraverse(treePtr->getLeftChildPtr());
		ItemType theItem = treePtr->getItem();
		std::cout << theItem;
		inorderTraverse(treePtr->getRightChildPtr());
	}// end if
}

template<class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(std::shared_ptr<BinaryNode<ItemType>> treePtr)
{
	if (treePtr != nullptr)
	{
		postorderTraverse(treePtr->getLeftChildPtr());
		postorderTraverse(treePtr->getRightChildPtr());
		ItemType theItem = treePtr->getItem();
		vec.push_back(theItem);
	}
}

template<class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData)
{
	auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newData);
	rootPtr = balancedAdd(rootPtr, newNodePtr);
	return true;
}

template<class ItemType>
bool BinaryNodeTree<ItemType>::isSameTree(BinaryNodeTree<ItemType>* tree)
{
	if (this->rootPtr != nullptr && tree->rootPtr != nullptr)
	{
		//Push values to vectors
		postorderTraverse(tree->rootPtr);
		vec1 = vec;
		vec.clear();
		postorderTraverse(this->rootPtr);
		vec2 = vec;

		//Sort the vectors to make sure the values are the same
		sort(vec1.begin(), vec1.end());
		sort(vec2.begin(), vec2.end());
		std::cout << std::endl;

		//Convert vector 1 to string
		std::stringstream ss1;
		for (auto it = vec1.begin(); it != vec1.end(); it++) {
			if (it != vec1.begin()) {
				ss1 << " ";
			}
			ss1 << *it;
		}

		//Convert vector 2 to string
		std::stringstream ss2;
		for (auto it = vec2.begin(); it != vec2.end(); it++) {
			if (it != vec2.begin()) {
				ss2 << " ";
			}
			ss2 << *it;
		}
		
		//Assign string stream to strings
		std::string str1 = ss1.str();
		std::string str2 = ss2.str();
		std::cout << "String 1: " << str1 << std::endl;
		std::cout << "String 2: " << str2 << std::endl;

		//Compare the strings
		if (str1.compare(str2) == 0) {
			return true;
		}
			
	}
	return false;
}
