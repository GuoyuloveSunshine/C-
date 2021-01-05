#include "Rect.h"
#include "Circle.h"

int main(int argn, char* argc[])
{	// Attention
	//   You cannot create an instance of an abstract type, but a reference of it
	//   This serves somewhat as the void* pointer in C programming language
	Shape* a_shape;

	if (1==argn || argc[1][0]=='r'){
		Rect a_rect;
		a_rect.Set(4,3,6,5);
		a_shape = &a_rect;
	}
	else{
		Circle a_circle;
		a_circle.Set(7,8,10);
		a_shape = &a_circle;
	}
	a_shape->Print();
	cout << "Shape area : " << a_shape->Area() << "\n";
	cout << "Shape circumference : " << a_shape->Circumference() << "\n";

	return 0;
}
