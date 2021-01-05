#include "AList.h"

int main()
{
	int a = 0;
	AList<int> aL(50);
	aL.insert(3);
	aL.print();
	aL.insert(1);
	aL.print();
	aL.insert(4);
	aL.print();
	aL.insert(1);
	aL.print();
	aL.insert(5);
	aL.print();
	aL.insert(9);
	aL.print();
	aL.insert(2);
	aL.print();
	aL.insert(6);
	aL.print();
	aL.setPos(3);
	aL.print();
	aL.remove(a);
	aL.print();
	cout << "The number just removed is " << a << endl;

	aL.clear();
	aL.append(3);
	aL.print();
	aL.append(1);
	aL.print();
	aL.append(4);
	aL.print();
	aL.append(1);
	aL.print();
	aL.append(5);
	aL.print();
	aL.append(9);
	aL.print();
	aL.append(2);
	aL.print();
	aL.append(6);
	aL.print();
	aL.setPos(3);
	aL.print();
	aL.remove(a);
	aL.print();
	cout << "The number just removed is " << a << endl;

	return 0;
}
