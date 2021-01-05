#include "BinNodePtr.h"

int main()
{
	BinNodePtr<int> A(2);
	BinNodePtr<int> B(3);
	BinNodePtr<int> C(5);
	A.setLeft(&B);
	A.setRight(&C);
	BinNodePtr<int> D(7);
	BinNodePtr<int> E(11);
	BinNodePtr<int> F(13);
	BinNodePtr<int> G(17);
	B.setLeft(&D);
	B.setRight(&E);
	C.setLeft(&F);
	C.setRight(&G);
	BinNodePtr<int> H(19);
	BinNodePtr<int> I(23);
	BinNodePtr<int> J(29);
	BinNodePtr<int> K(31);
	E.setLeft(&H);
	E.setRight(&I);
	F.setRight(&J);
	G.setLeft(&K);

	cout << "Traversal in pre-order ==> \n";
	traversePreOrder(&A);

	cout << "Traversal in post-order ==> \n";
	traversePostOrder(&A);

	cout << "Traversal in in-order ==> \n";
	traverseInOrder(&A);
	return 0;
}
