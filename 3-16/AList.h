#include <iostream>
using namespace std;

#include "List.h"

#define DEFAULT_LIST_SIZE 100

// Array-based list
template <class Elem>
class AList : public List<Elem> 
{
private:
	int maxSize;     // Maximum size of list
	int listSize;    // Actual elem count
	int fence;       // Position of fence
	Elem* listArray; // Array holding list
public:
	AList(int size=DEFAULT_LIST_SIZE) {
		maxSize = size;
		listSize = fence = 0;
		listArray = new Elem[maxSize];
	}
	~AList() { delete [] listArray; }
	void clear() {
		delete [] listArray;
		listSize = fence = 0;
		listArray = new Elem[maxSize];
	}
	bool insert(const Elem&);
	bool append(const Elem&);
	bool remove(Elem&);
	void setStart() { fence = 0; }
	void setEnd() { fence = listSize; }
	void prev()   { if (fence != 0) fence--; }
	void next()   { if (fence <= listSize) fence++; }
	int leftLength() const  { return fence; }
	int rightLength() const { return listSize - fence; }
	bool setPos(int pos) {
		if ((pos >= 0) && (pos <= listSize)) fence = pos;
		return (pos >= 0) && (pos <= listSize);
	}
	bool getValue(Elem& it) const {
		if (rightLength() == 0) return false;
		else {it = listArray[fence]; return true; }
	}
	void print() const{
		int temp = 0;
		cout << "< ";
		while(temp<fence) cout << listArray[temp++] << " ";
		cout << "| ";
		while(temp<listSize) cout << listArray[temp++] << " ";
		cout << ">\n";
	}
};

// Insert at front of right partition
template <class Elem>
bool AList<Elem>::insert(const Elem& item) {
	if (listSize == maxSize) return false; 
	for(int i=listSize; i>fence; i--) // Shift Elems up to make room
		listArray[i] = listArray[i-1]; 
	listArray[fence] = item;
	listSize++; // Increment list size
	return true;
}

// Append Elem to end of the list
template <class Elem>
bool AList<Elem>::append(const Elem& item) {
	if (listSize == maxSize) return false;
	listArray[listSize++] = item;
	return true;
}

// Remove and return first Elem in right partition
template <class Elem> 
bool AList<Elem>::remove(Elem& it) {
	if (rightLength() == 0) return false;
	it = listArray[fence]; // Copy Elem
	for(int i=fence; i<listSize-1; i++)
	// Shift them down
	listArray[i] = listArray[i+1];
	listSize--;    // Decrement size
	return true;
}


