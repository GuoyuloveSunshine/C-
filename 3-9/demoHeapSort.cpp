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
	int org_int[] = {42, 92, 96, 79, 93, 4, 85, 66, 68, 76, 74, 63, 39, 17, 71, 3};
	int a_int[50];
	int tmp_int[50];
	int n_int = 16;

#ifdef DIRECT_CONST_CHARS_CONVERSION
	// A double-quotes pair marked string terminates with '\0' by default
	char *a_char[] = {"machine", "intelligence", "system", "automation", "program", "technique", "computer", "data"};
	char *tmp_char[50];
	int n_char = 8;
#else
	// A double-quotes pair marked string terminates with '\0' by default
	const char *c_char[] = {"machine", "intelligence", "system", "automation", "program", "technique", "computer", "data"};
	char *a_char[50];
	char *tmp_char[50];
	int n_char = 8;
	for (int i=0; i<n_char; i++){
		a_char[i] = new char(100);
		strcpy(a_char[i], c_char[i]);
	}
#endif

	for(int i=0; i<n_int; i++){ a_int[i] = org_int[i]; }
	cout << "A set of integers: "; printA(a_int, n_int);
	HeapSort<int,IntCompare>(a_int, n_int);
	cout << "After HeapSort: "; printA(a_int, n_int);
	
	cout << "A set of strings: "; printA(a_char, n_char);
	HeapSort<char*,CharsCompare>(a_char, n_char);
	cout << "After HeapSort: "; printA(a_char, n_char);

	for(int i=0; i<n_int; i++){ a_int[i] = org_int[i]; }
	cout << "Original set of integers: "; printA(a_int, n_int);
	HeapSortDemo<int,IntCompare>(a_int, n_int);
	cout << "After HeapSort: "; printA(a_int, n_int);

	return 0;
}

