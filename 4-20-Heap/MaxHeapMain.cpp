#include "Compare.h"
#include "MaxHeap.h"

int main()
{
	const int size = 63, n=7;

	// Initialize int data
	int h[size], a;
	cout << "Batch initial int data loading ...\n";
	for(int i=0; i<n; i++)
	{ h[i] = i+1; cout << " | " << h[i]; } cout << " | \n";

	// Create an int maxheap tree
	MaxHeap<int,IntCompare> hp(h,n, size);
	cout << "After fast heap construction ...\n";
	hp.print();

	cout << "Insert 12 into the heap \n";
	hp.insert(12);
	hp.print();
	cout << "Insert 10 into the heap \n";
	hp.insert(10);
	hp.print();
	cout << "Insert 9 into the heap \n";
	hp.insert(9);
	hp.print();

	cout << "Remove max \n";
	hp.removemax(a);
	hp.print();
	cout << "Remove node indexed 1 \n";
	hp.remove(1,a);
	hp.print();

	cout << "========================================\n";

	// Initialize char data
	char h2[size], a2;
	cout << "Batch initial char data loading ...\n";
	for(int i=0; i<n; i++)
	{ h2[i] = i+0x41; cout << " | " << h2[i]; } cout << " | \n";

	// Create an int maxheap tree
	MaxHeap<char,CharCompare> hp2(h2,n, size);
	cout << "After fast heap construction ...\n";
	hp2.print();

	cout << "Insert L into the heap \n";
	hp2.insert('L');
	hp2.print();
	cout << "Insert J into the heap \n";
	hp2.insert('J');
	hp2.print();
	cout << "Insert I into the heap \n";
	hp2.insert('I');
	hp2.print();

	cout << "Remove max \n";
	hp2.removemax(a2);
	hp2.print();
	cout << "Remove node indexed 1 \n";
	hp2.remove(1,a2);
	hp2.print();

	return 0;
}

