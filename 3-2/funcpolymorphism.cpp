#include <iostream>
using namespace std;

void func(int);
void func(int, int);
void func(int, int, int);

int main()
{
	func(3);
	func(3,1);
	func(3,1,4);
	return 0;
}

void func(int a){
	cout << "func("<<a<<") = ";
	cout << a << endl;
}
void func(int a, int b){
	cout << "func("<<a<<","<<b<<") = ";
	cout << a+b << endl;
}
void func(int a, int b, int c){
	cout << "func("<<a<<","<<b<<","<<c<<") = ";
	cout << a+b*c << endl;
}
