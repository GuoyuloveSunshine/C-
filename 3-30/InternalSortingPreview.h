#include <stdlib.h>
#include <iostream>

#include "MaxHeap.h"

using namespace std;

// Swap two elements in a generic way
template <class Elem>
inline void swap(Elem A[], int i, int j){
	Elem temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

// Swap two objects passed by reference
template <class Elem>
inline void swap(Elem &e1, Elem &e2){
	Elem temp = e1;
	e1 = e2;
	e2 = temp;
}


/******************************************************
Exchange Sorting: (1) Bubble; (2) Bubble; (3) Selection
******************************************************/
// Insertion Sort
// Average: O(n^2) | Best: O(n) | Worst: O(n^2)
template <class Elem, class Comp>
void InsertionSort(Elem A[], int n){
	for (int i=1; i<n; i++)
		for(int j=i; (j>0) && (Comp::lt(A[j], A[j-1])); j--)
			swap(A, j, j-1);
}

// Bubble Sort
// Average: O(n^2) | Best: O(n^2) | Worst: O(n^2)
template <class Elem, class Comp>
void BubbleSort(Elem A[], int n){
	for (int i=0; i<n-1; i++)
		for(int j=n-1; j>i; j--)
			if (Comp::lt(A[j], A[j-1])) swap(A,j,j-1);
}

// Selection Sort
// Average: O(n^2) | Best: O(n^2) | Worst: O(n^2)
template <class Elem, class Comp>
void SelectionSort(Elem A[], int n){
	for(int i=0; i<n-1; i++){
		int minidx = i;
		for(int j=n-1; j>i; j--)
			if (Comp::lt(A[j], A[minidx])) minidx = j;
		swap(A,i,minidx);
	}
}
/******************************************************
END Exchange Sorting 
******************************************************/

/******************************************************
Shell Sort
******************************************************/
// Average: O(n^1.5)
// Modified version of insertion sort for varying increments
template <class Elem, class Comp>
void InsertionSort2(Elem A[], int n, int incr){
	for(int i=incr; i<n; i+=incr)
		for(int j=i; (j>=incr) && (Comp::lt(A[j],A[j-incr])); j-=incr)
			swap(A,j,j-incr);
}

template <class Elem, class Comp>
void ShellSort(Elem A[], int n){
	for (int incr=n/2; incr>2; incr/=2)
		for (int j=0; j<incr; j++)
			// InsertionSort2<Elem,Comp>(&A[j],n-j,incr);
			InsertionSort2<Elem,Comp>(A+j,n-j,incr);
	InsertionSort2<Elem,Comp>(A,n,1);
}
/******************************************************
END Shell Sort
******************************************************/

/******************************************************
Quick Sort
******************************************************/
template <class Elem> int FindPivot(Elem A[], int i, int j){ return (i+j)/2; }

// pivot is supposed to be located at the end i.e. position r by convention
template <class Elem, class Comp>
int Partition(Elem A[], int l, int r, Elem& pivot){
	--l;
	do {
		while (Comp::lt(A[++l], pivot));
		while ((r!=0) && Comp::gt(A[--r], pivot));
		swap(A,l,r);
	} while (l<r);
	swap(A,l,r);
	return l;
}

// Initial call: QuickSort(array,0,n-1)
template <class Elem, class Comp>
void QuickSort(Elem A[], int i, int j){
	if (j<=i) return;
	int pivotidx = FindPivot<Elem>(A,i,j);
	swap(A,pivotidx,j); // Put the pivot at the end
	int k = Partition<Elem,Comp>(A,i,j,A[j]);
	swap(A,k,j);
	QuickSort<Elem,Comp>(A,i,k-1);
	QuickSort<Elem,Comp>(A,k+1,j);
}

template <class Elem, class Comp>
void QuickSortDepth(Elem A[], int i, int j, int depth){
	if (depth<1) return;
	if (j<=i) return;
	int pivotidx = FindPivot<Elem>(A,i,j);
	swap(A,pivotidx,j); // Put the pivot at the end
	int k = Partition<Elem,Comp>(A,i,j,A[j]);
	swap(A,k,j);
	if (1==depth) cout << "Pivot : " << A[k] << "      ";
	QuickSortDepth<Elem,Comp>(A,i,k-1,depth-1);
	QuickSortDepth<Elem,Comp>(A,k+1,j,depth-1);
}
/******************************************************
END Quick Sort
******************************************************/

/******************************************************
Merge Sort
******************************************************/

template<class E,class Comp> void MergeSort(E A[],int i, int j){
	
}

/******************************************************
END Merge Sort
******************************************************/

/******************************************************
Heap Sort
******************************************************/
// The MaxHeap class is imported from MaxHeap.h
template <class Elem, class Comp>
void HeapSort(Elem A[], int n){
	MaxHeap<Elem,Comp> hp(A, n, n);
	Elem tmp;
	while (n--){
		hp.removemax(tmp);
		A[n] = tmp;
	}
}

template <class Elem, class Comp>
void HeapSortDemo(Elem A[], int n){
	MaxHeap<Elem,Comp> hp(A, n, n);
	cout << "Step 0 : ";
	for(int i=0; i<n; i++) cout << A[i] << " ";
	cout << endl;
	Elem tmp;
	int n_org = n;
	while (n--){
		hp.removemax(tmp);
		A[n] = tmp;
		cout << "Step " << n_org-n << " : ";
		for(int i=0; i<n; i++) cout << A[i] << " ";
		cout << "| ";
		for(int i=n; i<n_org; i++) cout << A[i] << " ";
		cout << endl;
	}
}
/******************************************************
END Heap Sort
******************************************************/

/******************************************************
Radix Sort
******************************************************/
template <class Elem, class Comp>
void RadixSort(Elem A[], Elem B[], int n, int k, int r, int cnt[]){
	// k denotes the number of digits
	// r denotes the base of digits
	// cnt[i] stores the number of records in bin[i]
	int j;
	for (int i=0, rtok=1; i<k; i++, rtok*=r){
		for (j=0; j<r; j++) cnt[j] = 0; // Reset cnt[]
		// Count the number of records for each bin on this pass
		for (j=0; j<n; j++) cnt[(A[j]/rtok)%r]++;
		// Index B: cnt[j] will be the index for the last last slot of bin[j]
		for (j=1; j<r; j++) cnt[j] += cnt[j-1];
		// Put records into bins, working from the bottom of each bin
		for (j=n-1; j>=0; j--) B[--cnt[(A[j]/rtok)%r]] = A[j];
		// Copy B back to A
		for (j=0; j<n; j++) A[j] = B[j];
	}
}

template <class Elem, class Comp>
void RadixSortDemo(Elem A[], Elem B[], int n, int k, int r, int cnt[]){
	// k denotes the number of digits
	// r denotes the base of digits
	// cnt[i] stores the number of records in bin[i]
	int j;
	for (int i=0, rtok=1; i<k; i++, rtok*=r){
		for (j=0; j<r; j++) cnt[j] = 0; // Reset cnt[]
		// Count the number of records for each bin on this pass
		for (j=0; j<n; j++) cnt[(A[j]/rtok)%r]++;
		// Index B: cnt[j] will be the index for the last last slot of bin[j]
		for (j=1; j<r; j++) cnt[j] += cnt[j-1];
		// Put records into bins, working from the bottom of each bin
		for (j=n-1; j>=0; j--) B[--cnt[(A[j]/rtok)%r]] = A[j];
		// Copy B back to A
		for (j=0; j<n; j++) A[j] = B[j];

		cout << "Sort digit (from small-end) " << i+1 << " : ";
		for (j=0; j<n; j++) cout << A[j] << " ";
		cout << "\n";
	}
}
/******************************************************
END Radix Sort
******************************************************/

