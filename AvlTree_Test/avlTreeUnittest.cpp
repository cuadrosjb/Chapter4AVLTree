#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
#include <string>
#include "AVLTree.h"
#include "AVLTree.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AvlTree_Test
{		
	class StringCompare
	{
	public:
		bool less(const std::string &lhs, const std::string &rhs) const
		{
			return (lhs < rhs);
		}
	};
	
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(AvlTreeEmpty_TEST)
		{
			AVLTree <std::string, StringCompare> myAVLTree{};
			int isEmpty = myAVLTree.isEmpty();
			Assert::AreEqual(1, isEmpty);
			
			
		}
		TEST_METHOD(AvlTreeNotEmpty_TEST)
		{
			AVLTree <std::string, StringCompare> myAVLTree{};
			
			myAVLTree.insert("A");
			int isEmpty = myAVLTree.isEmpty();
			Assert::AreEqual(0, isEmpty);

		}

		TEST_METHOD(AvlTreeContains_TEST)
		{
			AVLTree <std::string, StringCompare> myAVLTree{};

			myAVLTree.insert("A");
			int doesItContains = myAVLTree.contains("A");
			Assert::AreEqual(1, doesItContains);

		}
		TEST_METHOD(AvlTreeNotContains_TEST)
		{
			AVLTree <std::string, StringCompare> myAVLTree{};

			myAVLTree.insert("A");
			int doesItContains = myAVLTree.contains("W");
			Assert::AreEqual(0, doesItContains);

		}
		TEST_METHOD(AvlTreeFindMax_TEST)
		{
			AVLTree <std::string, StringCompare> myAVLTree{};

			myAVLTree.insert("A");
			myAVLTree.insert("B");
			myAVLTree.insert("C");
			myAVLTree.insert("D");
			//std::string str = myAVLTree.findMax(myAVLTree);
			Assert::IsTrue((myAVLTree.findMax(myAVLTree)) == "D");

		}
		TEST_METHOD(AvlTreeFindMin_TEST)
		{
			AVLTree <std::string, StringCompare> myAVLTree{};

			myAVLTree.insert("A");
			myAVLTree.insert("B");
			myAVLTree.insert("C");
			myAVLTree.insert("D");
			//std::string str = myAVLTree.findMax(myAVLTree);
			Assert::IsTrue((myAVLTree.findMin(myAVLTree)) == "A");

		}
		TEST_METHOD(AvlTreeRemove_TEST)
		{
			AVLTree <std::string, StringCompare> myAVLTree{};

			myAVLTree.insert("A");
			myAVLTree.insert("B");
			myAVLTree.insert("C");
			myAVLTree.insert("D");
			myAVLTree.remove("C");
			Assert::IsTrue(myAVLTree.contains("A"));

		}

	};
}