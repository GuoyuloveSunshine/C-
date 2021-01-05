#include <stdlib.h>
#include <iostream>
using namespace std;

// Min-heap class
//   arranged in an array starting from 0 upon
template <class Elem, class Comp> class MinHeap {
private:
	Elem* heap;		// Pointer to the heap array
	int size;		// Minimum size of the heap
	int n;			// Number of elements now in the heap
	void swap(Elem* h, int a, int b) // Swap two elements
	{ Elem tmp = h[a]; h[a] = h[b]; h[b] = tmp; }
	void shiftdown(int);	// Put element in its correct place
public:
	MinHeap(Elem* h, int num, int max)
	{ heap = h; n = num; size = max; buildheap(); }
	int heapsize() const {return n; }
	bool isLeaf(int pos) const {return (pos>=n/2) && (pos<n); }
	int leftchild(int pos) const { return 2*pos+1; }
	int rightchild(int pos) const { return 2*pos+2; }
	int parent(int pos) const { return (pos-1)/2; }
	bool insert (const Elem&);	// Insert value into heap
	bool removemin(Elem&);		// Remove minimum value
	bool remove(int, Elem&);	// remove from given position
	void buildheap()
	{ for (int i=n/2-1; i>=0; i--) shiftdown(i); }
	Elem get(int i){ return heap[i]; }
	void print(){ for(int i=0; i<n; i++){ cout << " | "; heap[i].print(); } cout << " | \n"; }
};

template <class Elem, class Comp>
void MinHeap<Elem, Comp>::shiftdown(int pos){
	while(!isLeaf(pos)){
		int j = leftchild(pos);
		int rc = rightchild(pos);
		if ((rc<n) && Comp::gt(heap[j], heap[rc])) j = rc; 
		if (!Comp::gt(heap[pos], heap[j])) return; // no need to swap
		swap(heap, pos, j);
		pos = j;	// Move down
	}
}

template <class Elem, class Comp>
bool MinHeap<Elem, Comp>::insert(const Elem& val){
	if (n>=size) return false;	// Heap is full
	int curr = n++;
	heap[curr] = val;
	// Sift upward until curr's parent >= curr
	while ((curr!=0) && (Comp::lt(heap[curr], heap[parent(curr)]))){
		swap(heap, curr, parent(curr));
		curr = parent(curr);
	}
	// Think why the Heap property can still be maintained after above while loop ?
	return true;
}

template <class Elem, class Comp>
bool MinHeap<Elem, Comp>::removemin(Elem& it){
	if (n==0) return false;	// Heap is empty
	swap(heap, 0, --n);	// Swap max with the last value
	if (n != 0) shiftdown(0);
	it = heap[n];
	return true;
}

template <class Elem, class Comp>
bool MinHeap<Elem, Comp>::remove(int pos, Elem& it){
	if ((pos<0) || (pos>=n)) return false; // Invalid pos
	swap(heap, pos, --n);
	while ((pos!=0) && (Comp::lt(heap[pos], heap[parent(pos)]))){ // Sift upward
		swap(heap, pos, parent(pos));
		pos = parent(pos);
	}
	shiftdown(pos);
	it = heap[n];
	return true;
}

