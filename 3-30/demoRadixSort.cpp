#include <string.h>
#include "Compare.h"
#include "InternalSorting.h"
using namespace std;

template <class Elem>
void printA(Elem A[], int n){
	for(int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << "\n";
}

int main()
{
	int org_int[] = {423, 921, 964, 791, 935, 49, 852, 666, 685, 763, 745, 638, 399, 177, 719, 33};
	int a_int[50];
	int tmp_int[50];
	int n_int = 16, k = 3, r = 10, cnt[10];

	for(int i=0; i<n_int; i++){ a_int[i] = org_int[i]; }
	cout << "A set of integers: "; printA(a_int, n_int);
	RadixSort<int,IntCompare>(a_int, tmp_int, n_int, k, r, cnt);
	cout << "After RadixSort: "; printA(a_int, n_int);
	

	for(int i=0; i<n_int; i++){ a_int[i] = org_int[i]; }
	cout << "Original set of integers: "; printA(a_int, n_int);
	RadixSortDemo<int,IntCompare>(a_int, tmp_int, n_int, k, r, cnt);
	cout << "After RadixSort: "; printA(a_int, n_int);

	return 0;
}

