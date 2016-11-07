/**
  * @file AVLTree.h
  * @version 1.0
  * @date 11/06/2016
  * @author Jeffrey B Cuadros
  * @title AVL Tree
  * @brief Implementation of a AVL Tree.
*/


#pragma once
#include <iostream>

template <typename object, typename comparator = less<object>>
class AVLTree
{
private:
	struct AvlNode {
		object element;
		AvlNode *Left;
		AvlNode *Right;
		int height;
		/**
		*@brief Copy constructor for the AvlNode struct
		*@param theElement object
		*@param tl AvlNode
		*@param rt AvlNode
		*@param h int
		*/
		AvlNode(const object & theElement, AvlNode *lt, AvlNode *rt, int h = 0)
			:element{ theElement }, Left{ lt }, Right{ rt }, height{ h } {};
		/**
		*@brief Move constructor for the AvlNode struct
		*@param theElement object
		*@param tl AvlNode
		*@param rt AvlNode
		*@param h int
		*/
		AvlNode(const object && theElement, AvlNode *lt, AvlNode *rt, int h = 0)
			:element{ std::move(theElement) }, Left{ lt }, Right{ rt }, height{ h } {};
	};

	AvlNode *root;
	comparator isLessThan;

	/**
	*@brief Find the minimun value in the AvlTree
	*@param t AvlNode
	*/
	AvlNode * findMin(AvlNode *t) const
	{
		if (t == nullptr)
			return nullptr;
		if (t->Left == nullptr)
			return t;
		return(findMin(t->Left));
	};
	/**
	*@brief Find the max the element in the AVLTree
	*@param t AvlNode
	*/
	AvlNode * findMax(AvlNode *t) const
	{
		if (t == nullptr)
			return nullptr;
		if (t->Right == nullptr)
			return t;
		return(findMax(t->Right));
	};
	/**
	*@brief returns true if element is inside the AvlTree
	*@param x object
	*@param t AvlNode
	*@return bool
	*/
	bool contains(const object & x, AvlNode *t) const;
	/**
	*@brief insert element into the AvlTree
	*@param x object
	*@param t AvlNode
	*/
	void insert(const object & x, AvlNode * & t);
	/**
	*@brief move insert element into the AvlTree
	*@param x object
	*@param t AvlNode
	*/
	void insert(const object && x, AvlNode * & t);
	/**
	*@brief Internal method to remove from a subtree.
	* x is the item to remove.
	* t is the node that roots the subtree.
	* Set the new root of the subtree.
	*@param x object
	*@param t AvlNode
	*/
	void remove(const object & x, AvlNode *t);
	/**
	*@brief remove every element from the AvlTree
	*@param t AvlNode
	*/
	void makeEmpty(AvlNode * & t);
	/**
	*@brief Return the height of node t or -1 if nullptr
	*@param t AvlNode
	*/
	int height(AvlNode *t)const
	{
		return t == nullptr ? -1 : t->height;
	}
	/**
	*@brief balane AvlTree to try keep log(n) efficiency 
	*@param t AvlNode
	*/
	void balance(AvlNode * & t);
	/**
	*@brief Rotate binary tree node with left child.
	* For AVL trees, this is a single rotation for case 1.
	* Update heights, then set new root.
	*@param k2 AvlNode
	*/
	void rotateWithLeftChild(AvlNode * & k2);
	/**
	*@brief Double rotate binary tree node: first left child
	* with its right child; then node k3 with new left child.
	* For AVL trees, this is a double rotation for case 2.
	* Update heights, then set new root.
	*@param k3 AvlNode
	*/
	void doubleWithLeftChild(AvlNode * & k3);
	/**
	*@brief Rotate binary tree node with left child.
	* For AVL trees, this is a single rotation for case 1.
	* Update heights, then set new root.
	*@param k2 AvlNode
	*/
	void rotateWithRightChild(AvlNode * & k2);
	/**
	*@brief Double rotate binary tree node: first left child
	* with its right child; then node k3 with new left child.
	* For AVL trees, this is a double rotation for case 2.
	* Update heights, then set new root.
	*@param k3 AvlNode
	*/
	void doubleWithRightChild(AvlNode * & k3);
	/**
	*@brief clone AvlNode
	*@param t AvlNode
	*/
	AvlNode * clone(AvlNode *t) const
	{
		if (t == NULL)
			return NULL;
		else
			return new AvlNode(t->element, clone(t->Left), clone(t->Right));
	};
	/**
	*@brief print to the console all the elements in the AvlTree
	*@param out std::ostream
	*@param t AvlNode
	*/
	void printTree(AvlNode *t, std::ostream & out) const
	{
		if (t != NULL)
		{
			printTree(t->Left, out);
			out << t->element << std::endl;
			printTree(t->Right, out);
		}
	}
	/**
	*@brief determine side is bigger
	*@param lhs int
	*@param rhs int
	*@return int
	*/
	int max(int lhs, int rhs) const
	{
		return lhs > rhs ? lhs : rhs;
	}
public:
	/**
	*@brief AVLTree constructor
	*/
	AVLTree() :root{ nullptr } {};
	/**
	*@brief AVLTree destructor
	*/
	~AVLTree() { makeEmpty(); };

	/**
	*@brief copy AvlTree
	*@param rhs AVLTree
	*/
	AVLTree(const AVLTree & rhs) :root{ nullptr } { root = clone(rhs.root); };

	/**
	*@brief find minimun value in the AvlTree
	*@param rhs AVLTree
	*@return object
	*/
	const object & findMin(const AVLTree & rhs) { return findMin(root)->element;};
	/**
	*@brief find maximun value in the AvlTree
	*@param rhs AVLTree
	*@return object
	*/
	const object & findMax(const AVLTree & rhs) { return findMax(root)->element; };
	/**
	*@brief removes all the elements in the AVLTree 
	*/
	void makeEmpty() { makeEmpty(root); };
	/**
	*@brief insert element into the AvlTree
	*@param x object
	*/
	void insert(const object & x) { insert(x, root); }
	/**
	*@brief move insert element into the AvlTree
	*@param x object
	*/
	void insert(const object && x) { insert(x, root); }
	/**
	*@brief remove element from AvlTree
	*@param x object
	*/
	void remove(const object & x) { remove(x, root); }
	/**
	*@brief checks if the AvlTree is empty
	*@return boolean
	*/
	bool isEmpty() const { return root == nullptr; };
	/**
	*@brief checks if AvlTree contains the element
	*@param x object
	*@return boolean
	*/
	bool contains(const object & x) { return(contains(x, root)); }
	/**
	*@brief
	*@param rhs AVLTree
	*/
	AVLTree & operator= (const AVLTree & rhs) { AVLTree(rhs); }
	/**
	*@brief Print elemenets of the AVLTree in order
	*@param out std::ostream
	*/
	void printTree(std::ostream & out = std::cout) const
	{
		if (isEmpty())
			out << "Empty tree" << std::endl;
		else
			printTree(root, out);
	}
};