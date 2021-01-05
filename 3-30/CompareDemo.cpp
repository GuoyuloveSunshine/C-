#include "Compare.h"
#include <iostream>
using namespace std;

int main()
{
	// A double-quotes pair marked string terminates with '\0' by default
	char a[] = "atom"; // i.e. 'a','t','o','m','\0'
	char b[] = "bright";
	char b2[] = "bright";
	char c[] = "computer";
	char c2[] = "comauter";
	char c3[] = "comxuter";

	cout << a << " < " << b << " is " << CharsComp::lt(a,b) << endl;
	cout << b2 << " < " << a << " is " << CharsComp::lt(b2,a) << endl;
	cout << b << " == " << b2 << " is " << CharsComp::eq(b,b2) << endl;
	cout << b << " < " << b2 << " is " << CharsComp::lt(b,b2) << endl;
	cout << b << " > " << b2 << " is " << CharsComp::gt(b,b2) << endl;
	cout << c2 << " > " << c << " is " << CharsComp::gt(c2,c) << endl;
	cout << c2 << " > " << c3 << " is " << CharsComp::gt(c2,c3) << endl;
	cout << c << " == " << c << " is " << CharsComp::eq(c,c) << endl;
	cout << c2 << " < " << c << " is " << CharsComp::lt(c2,c) << endl;
	cout << c2 << " < " << c3 << " is " << CharsComp::lt(c2,c3) << endl;

	return 0;
}

