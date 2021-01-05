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
	int a_int[] = {42, 92, 79, 96, 66, 4, 85, 93, 68, 76, 74, 39, 63, 17, 71, 3};
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

	cout << "A set of integers: "; printA(a_int, n_int);
	ShellSort<int,IntCompare>(a_int, n_int);
	cout << "After ShellSort: "; printA(a_int, n_int);
	
	cout << "A set of strings: "; printA(a_char, n_char);
	ShellSort<char*,CharsCompare>(a_char, n_char);
	cout << "After ShellSort: "; printA(a_char, n_char);

	return 0;
}

