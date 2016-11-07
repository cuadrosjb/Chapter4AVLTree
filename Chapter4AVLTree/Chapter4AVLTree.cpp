// ConsoleApplication4.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include "AVLTree.h"
#include "AVLTree.cpp"


class StringCompare
{
public:
	bool less(const std::string &lhs, const std::string &rhs) const
	{
		return (lhs < rhs);
	}
};


AVLTree < std::string, StringCompare >;
int _tmain(int argc, _TCHAR* argv[])
{
	AVLTree < std::string, StringCompare > myAVLTree{};

	myAVLTree.insert("Q");
	myAVLTree.insert("F");
	//myAVLTree.printTree();
	myAVLTree.insert("C");
	myAVLTree.insert("D");
	myAVLTree.insert("A");
	//std::cout << "myAVLTree.isEmpty(): " << myAVLTree.isEmpty() << std::endl;
	//myAVLTree.makeEmpty();
	//std::cout << "myAVLTree.isEmpty(): " << myAVLTree.isEmpty() << std::endl;
	myAVLTree.insert("Z");
	myAVLTree.insert("B");
	myAVLTree.insert("X");
	//std::cout << "myAVLTree.contains(Z): " << myAVLTree.contains("Z") << std::endl;
	myAVLTree.printTree();
	
	myAVLTree.remove("X");
	std::cout << "-------------------------" << std::endl;
	myAVLTree.printTree();
	std::cout << "-------------------------" << std::endl;
	//std::cout << "-Max element: " << myAVLTree.findMax(myAVLTree) << std::endl;
	//std::cout << "-Min element: " << myAVLTree.findMin(myAVLTree) << std::endl;
	//myAVLTree.printTree();


	return 0;
}

