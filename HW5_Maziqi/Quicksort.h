#include <stdlib.h>
#include<iostream>
#include<string>
#include "Comp.h"
using namespace std;

template <class Elem> int FindPivot(Elem A[], int i, int j){ return (i+j)/2; }

// pivot is supposed to be located at the end i.e. position r by convention
template <class Elem, class Comp>
int Partition(Elem A[], int l, int r, Elem& pivot,map<string, int> a){
	--l;
	do {
		while (Comp::big(A[++l], pivot,a));
		while ((r!=0) && Comp::small(A[--r], pivot,a));
		swap(A,l,r);
	} while (l<r);
	swap(A,l,r);
	return l;
}

// Initial call: QuickSort(array,0,n-1)
template <class Elem, class Comp>
void QuickSort(Elem A[], int i, int j,map<string,int> a){
	if (j<=i) return;
	int pivotidx = FindPivot<Elem>(A,i,j);
	swap(A,pivotidx,j); // Put the pivot at the end
	int k = Partition<Elem,Comp>(A,i,j,A[j],a);
	swap(A,k,j);
	QuickSort<Elem,Comp>(A,i,k-1,a);
	QuickSort<Elem,Comp>(A,k+1,j,a);
}