//Daniel Blakeman
//CIS 2207 502
//Create a function called bool isSameTree(Tree *); 
//that will take an argument of a tree.  It will return a true if the argument is the equivalent tree.

#include "BinaryNode.cpp"
#include "BinaryNodeTree.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Main Function
int main() 
{
	//Comparison Vectors
	/*shared_ptr<BinaryNode<string>> tree1Ptr;
	shared_ptr<BinaryNode<string>> tree2Ptr;
	shared_ptr<BinaryNode<string>> tree3Ptr;
	shared_ptr<BinaryNode<string>> tree4Ptr;*/

	//Comparison 1
	BinaryNodeTree<string>* tree1 = new BinaryNodeTree<string>();
	tree1->add("abc");
	tree1->add("def");
	tree1->add("ghi");
	cout << "Preorder Traverse: ";
	tree1->preorderTraverse(tree1->rootPtr);
	cout << endl;

	BinaryNodeTree<string>* tree2 = new BinaryNodeTree<string>();
	tree2->add("def");
	tree2->add("abc");
	tree2->add("ghi");
	cout << "Inorder Traverse: ";
	tree2->inorderTraverse(tree2->rootPtr);
	cout << endl;

	//Conditional Statement 1
	
	if (tree1->isSameTree(tree2) == 1)
	{
		cout << "Comparison 1 Result: ";
		cout << "true" << endl;
	}
	else
	{
		cout << "Comparison 1 Result: ";
		cout << "false" << endl;
	}
	cout << endl;

	//Comparison 2
	BinaryNodeTree<string>* tree3 = new BinaryNodeTree<string>();
	tree3->add("abc");
	tree3->add("ghi");
	tree3->add("def");
	cout << "Preorder Traverse: ";
	tree3->preorderTraverse(tree3->rootPtr);
	cout << endl;

	BinaryNodeTree<string>* tree4 = new BinaryNodeTree<string>();
	tree4->add("abc");
	tree4->add("ghi");
	cout << "Preorder Traverse: ";
	tree4->preorderTraverse(tree4->rootPtr);
	cout << endl;
	
	//Conditional Statement 2
	if (tree3->isSameTree(tree4) == 1)
	{
		cout << "Comparison 2 Result: ";
		cout << "true" << endl;
	}
	else
	{
		cout << "Comparison 2 Result: ";
		cout << "false" << endl;
	}
	return 0;
}