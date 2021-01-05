#include <string.h>
#include "Compare.h"
#include "InternalSortingPreview.h"
using namespace std;

template <class Elem>
void printA(Elem A[], int n){
	for(int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << "\n";
}

int main()
{
	int org_int[] = {42, 92, 96, 79, 93, 4, 85, 66, 68, 76, 74, 63, 39, 3, 71, 3};
	int a_int[50];
	int n_int = 16;

#ifdef DIRECT_CONST_CHARS_CONVERSION
	// A double-quotes pair marked string terminates with '\0' by default
	char *a_char[] = {"machine", "intelligence", "system", "automation", "program", "technique", "computer", "data"};
	int n_char = 8;
#else
	// A double-quotes pair marked string terminates with '\0' by default
	const char *c_char[] = {"machine", "intelligence", "system", "automation", "program", "technique", "computer", "data"};
	char *a_char[50];
	int n_char = 8;
	for (int i=0; i<n_char; i++){
		a_char[i] = new char(100);
		strcpy(a_char[i], c_char[i]);
	}
#endif

	for(int i=0; i<n_int; i++){ a_int[i] = org_int[i]; }
	cout << "A set of integers: "; printA(a_int, n_int);
	QuickSort<int,IntCompare>(a_int, 0, n_int-1);
	cout << "After QuickSort: "; printA(a_int, n_int);
	
	cout << "A set of strings: "; printA(a_char, n_char);
	QuickSort<char*,CharsCompare>(a_char, 0, n_char-1);
	cout << "After QuickSort: "; printA(a_char, n_char);

	for(int i=0; i<n_int; i++){ a_int[i] = org_int[i]; }
	cout << "Original set of integers: "; printA(a_int, n_int);
	for(int i=1;i<=6;i++){
		for(int i=0; i<n_int; i++){ a_int[i] = org_int[i]; }
		QuickSortDepth<int,IntCompare>(a_int,0,n_int-1,i);
		cout << "\nQuickSort after " << i << " round(s): "; printA(a_int, n_int);
	}

	return 0;
}

