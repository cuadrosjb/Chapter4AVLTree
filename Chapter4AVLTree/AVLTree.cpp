#include "stdafx.h"
#include "AVLTree.h"

template <typename object, typename comparator = less<object>>
bool AVLTree<object, comparator>::contains(const object & x, AvlNode *t) const
{
	if (t == nullptr)
		return false;
	if (isLessThan.less(x, t->element))
		return contains(x, t->Left); // left
	else if (isLessThan.less(t->element, x))
		return contains(x, t->Right); // right
	else
		return true;
}

template <typename object, typename comparator = less<object>>
void AVLTree<object, comparator>::insert(const object & x, AvlNode * & t)
{
	if (t == nullptr)
		t = new AvlNode{ x, nullptr, nullptr };
	if (isLessThan.less(x, t->element))
		insert(x, t->Left); // left
	else if (isLessThan.less(t->element, x))
		insert(x, t->Right); // right
	
	balance(t);
}

template <typename object, typename comparator = less<object>>
void AVLTree<object, comparator>::insert(const object && x, AvlNode * & t)
{
	if (t == nullptr)
		t = new AvlNode{ std::move(x), nullptr, nullptr };
	if (isLessThan.less(x, t->element))
		insert(x, t->Left); // left
	else if (isLessThan.less(t->element, x))
		insert(x, t->Right); // right
	
	balance(t);
}
static const int ALLOWED_IMBALANCE = 1;

//Assume t is balanced or within one of being balanced
template <typename object, typename comparator = less<object>>
void AVLTree<object, comparator>::balance(AvlNode * & t)
{
	if (t == nullptr)
		return;

	if (height(t->Left) - height(t->Right) > ALLOWED_IMBALANCE)
		if (height(t->Left->Left) >= height(t->Left->Right))
			rotateWithLeftChild(t);
		else
			doubleWithLeftChild(t);
	else
	if (height(t->Right) - height(t->Left) > ALLOWED_IMBALANCE)
		if (height(t->Right->Right) >= height(t->Right->Left))
			rotateWithRightChild(t);
		else
			doubleWithRightChild(t);

	t->height = max(height(t->Left), height(t->Right)) + 1;
}

/**
  * Rotate binary tree node with left child.
  * For AVL trees, this is a single rotation for case 1.
  * Update heights, then set new root.
  */
template <typename object, typename comparator = less<object>>
void AVLTree<object, comparator>::rotateWithLeftChild(AvlNode * & k2)
{
	AvlNode *k1 = k2->Left;
	k2->Left = k1->Right;
	k1->Right = k2;
	k2->height = max(height(k2->Left), height(k2->Right)) + 1;
	k1->height = max(height(k1->Left), k2->height) + 1;
	k2 = k1;
}
/**
* Rotate binary tree node with left child.
* For AVL trees, this is a single rotation for case 1.
* Update heights, then set new root.
*/
template <typename object, typename comparator = less<object>>
void AVLTree<object, comparator>::rotateWithRightChild(AvlNode * & k2)
{
	AvlNode *k1 = k2->Right;
	k2->Right = k1->Left;
	k1->Left = k2;
	k2->height = max(height(k2->Left), height(k2->Right)) + 1;
	k1->height = max(height(k1->Right), k2->height) + 1;
	k2 = k1;
}
/**
* Double rotate binary tree node: first left child
* with its right child; then node k3 with new left child.
* For AVL trees, this is a double rotation for case 2.
* Update heights, then set new root.
*/
template <typename object, typename comparator = less<object>>
void AVLTree<object, comparator>::doubleWithLeftChild(AvlNode * & k3)
{
	rotateWithRightChild(k3->Left);
	rotateWithLeftChild(k3);
}
/**
* Double rotate binary tree node: first left child
* with its right child; then node k3 with new left child.
* For AVL trees, this is a double rotation for case 2.
* Update heights, then set new root.
*/
template <typename object, typename comparator = less<object>>
void AVLTree<object, comparator>::doubleWithRightChild(AvlNode * & k3)
{
	rotateWithLeftChild(k3->Right);
	rotateWithRightChild(k3);
}

//template <typename object, typename comparator = less<object>>
//AvlNode * AVLTree<object, comparator>::findMin(AvlNode * t) const

/**
* Internal method to remove from a subtree.
* x is the item to remove.
* t is the node that roots the subtree.
* Set the new root of the subtree.
*/

template <typename object, typename comparator = less<object>>
void AVLTree<object, comparator>::remove(const object & x, AvlNode *t)
{
	
	std::cout << "-------------------------------------------------------" << x << std::endl;
	std::cout << "AvlNode *t: " << t->element << std::endl;
	std::cout << "x: " << x << std::endl;
	
	if (t == nullptr) return;
	if (isLessThan.less(x, t->element)) {
		std::cout << x <<" < " << t->element << std::endl;
		remove(x, t->Left);
	}
	else if (isLessThan.less(t->element, x)) {
		std::cout << x << " > " << t->element << std::endl;
		remove(x, t->Right);
	}
	else if (t->Left != nullptr && t->Right != nullptr)
	{
		t->element = findMin(t->Right)->element;
		remove(t->element, t->Right);
		
	}
	else
	{
		AvlNode *oldNode = t;
		t = (t->Left != nullptr) ? t->Left : t->Right;
		delete oldNode;
		
	}
	balance(t);
}

template <typename object, typename comparator = less<object>>
void AVLTree<object, comparator>::makeEmpty(AvlNode * & t)
{
	if (t != nullptr)
	{
		makeEmpty(t->Left);
		makeEmpty(t->Right);
		delete t;
	}
	t = nullptr;

}
