#include <stdlib.h>
#include <iostream>
#include "BinNode.h"
using namespace std;

template <class Elem>
class BinNodePtr : public BinNode<Elem> {
private:
	Elem it; 	// The node's value
	BinNodePtr* lc;	// Pointer to left child
	BinNodePtr* rc;	// Pointer to right child
public:
	BinNodePtr() { lc = rc = NULL; }
	BinNodePtr(Elem e, BinNodePtr* l=NULL, BinNodePtr* r=NULL)
	{ it = e; lc = l; rc = r; }
	~BinNodePtr(){}
	Elem& val(){ return it; }
	void setVal(const Elem& e){ it = e; }
	inline BinNode<Elem>* left() const { return lc; }
	//inline BinNodePtr<Elem>* left() const { return lc; }
	void setLeft(BinNode<Elem>* b){ lc = (BinNodePtr*)b; }
	inline BinNode<Elem>* right() const { return rc; }
	//inline BinNodePtr<Elem>* right() const { return rc; }
	void setRight(BinNode<Elem>* b){ rc = (BinNodePtr*)b; }
	bool isLeaf() { return (NULL==lc) && (NULL==rc); }
};

template <class Elem>
void traversePreOrder(BinNode<Elem>* subroot){
//void traversePreOrder(BinNodePtr<Elem>* subroot){
	if (subroot==NULL) return; // an empty subtree branch
	if (subroot->isLeaf())
		cout << "Leaf node: " << subroot->val() << "\n";
	else{
		cout << "Internal node: " << subroot->val() << "\n";
		traversePreOrder(subroot->left());
		traversePreOrder(subroot->right());
	}
}

template <class Elem>
void traversePostOrder(BinNode<Elem>* subroot){
	if (subroot==NULL) return; // an empty subtree branch
	if (subroot->isLeaf())
		cout << "Leaf node: " << subroot->val() << "\n";
	else{
		traversePostOrder(subroot->left());
		traversePostOrder(subroot->right());
		cout << "Internal node: " << subroot->val() << "\n";
	}
}

template <class Elem>
void traverseInOrder(BinNode<Elem>* subroot){
	if (subroot==NULL) return; // an empty subtree branch
	if (subroot->isLeaf())
		cout << "Leaf node: " << subroot->val() << "\n";
	else{
		traverseInOrder(subroot->left());
		cout << "Internal node: " << subroot->val() << "\n";
		traverseInOrder(subroot->right());
	}
}



