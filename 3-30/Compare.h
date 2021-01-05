#include <iostream>
using namespace std;

// Integer comparison class
class IntCompare{
public:
	static bool lt(int x, int y){ return x < y; }
	static bool eq(int x, int y){ return x == y; }
	static bool gt(int x, int y){ return x > y; }
};

// Char comparison class
class CharCompare{
public:
	static bool lt(char x, char y){ return x < y; }
	static bool eq(char x, char y){ return x == y; }
	static bool gt(char x, char y){ return x > y; }
};

// Chars comparison class
// Each chain of chars terminates with '\0'
class CharsCompare{
public:
	static bool lt(char* x, char* y){
		while (*x!='\0' && *y!='\0' && *x==*y){x++;y++;}
		if (*x < *y) return true;
		return false;
	}
	static bool eq(char* x, char* y){
		while (*x!='\0' && *y!='\0' && *x==*y){x++;y++;}
		if (*x == *y) return true;
		return false;
	}
	static bool gt(char* x, char* y){
		while (*x!='\0' && *y!='\0' && *x==*y){x++;y++;}
		if (*x > *y) return true;
		return false;
	}
};


