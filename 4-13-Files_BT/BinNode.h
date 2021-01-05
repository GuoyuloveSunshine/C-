

template <class Elem> class BinNode{
public:
	virtual Elem& val() = 0; // Return the node's element
	virtual void setVal(const Elem&) = 0; //Set the node's element
	virtual BinNode* left() const = 0; // Return the node's left child
	virtual void setLeft(BinNode*) = 0; // Set the node's left child
	virtual BinNode* right() const = 0; // Return the node's right child
	virtual void setRight(BinNode*) = 0; // Set the node's right child
	virtual bool isLeaf() = 0; // Return true iff the node is a leaf
};

